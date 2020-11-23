#include <vector>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>
#include <string>
using namespace std;

// 定时器只有两种状态：expired, not expired。如果过了超时时间调用定时器的wait()，则立即调用；如果没有超过定时器的超时时间，则会一直等到过了超时时间才会调用。
//
// 同步定时器
int test1(){
	boost::asio::io_service io;
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	cout << "start" << endl;
	t.wait();		// 阻塞等待
	cout << "end" << endl;
	return 0;
}

void Print(const boost::system::error_code &ec){
	cout <<"hello world" << endl;
	cout << boost::this_thread::get_id() << endl;
}

// 异步定时器
int test2(){
	cout << boost::this_thread::get_id() << endl;
	boost::asio::io_service io;
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	sleep(4);
	cout << "to cancel" << endl;
	t.cancel();
	t.async_wait(Print);
	cout << "to run" << endl;
	io.run();
	cout << "exit" << endl;
	return 0;
}

// 什么是wait completion：定时器超时后要调用的句柄。
// io.run调用wait completion句柄，如果不run，则定时器即使expired也没人调用print
// 只有在io.run的时候才会调用定时器的异步wait所绑定的句柄，但是如果此时定时器的状态是unexpired，还需要等待直到expired才会调用

// 如果有work，io.run()就会一直run下去。此时的work就是定时器的异步等待。一旦没有work去做，此时io.run()就会结束。
// 在调用io_service::run()之前，一定要给他一些工作（work）去做，例如本例中的deadline_timer::async_wait()

void print(const boost::system::error_code& /*e*/)
{
	std::cout << "Hello, world!" << std::endl;
}

void test3(){
	boost::asio::io_service io;
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	cout << "before" << endl;
	t.async_wait(&print);
	sleep(3);
	cout << "after" << endl;
	io.run();
}

// 1. 在定时器绑定的函数里面重置了定时器，实现5次调用定时器绑定的函数
// 2. 注意这5次调用虽然是异步的，但是都在同一个线程里面（线程号一样），同步异步和转不转线程无关
// 3. expires_at() 在什么时候过期
// 4. expires_from_now() 距离现在还有多长时间过期，如果是负数意味着已经过期了几秒
void Print(const boost::system::error_code &ec,
		boost::asio::deadline_timer* t,
		int * count)
{
	cout << "begin print =====" << endl;
	cout << "expires_at: " << t->expires_at() << endl; 
	// cout << "sleep 3s" << endl;
	// sleep(3);
	if (*count < 4)
	{
		cout<<"count = "<<*count<<endl;
		// cout<<boost::this_thread::get_id()<<endl;
		(*count) ++;

		cout << "expires_from_now: " << t->expires_from_now() << endl;
		cout << "before expires_at: " << t->expires_at() << endl;
		t->expires_at(t->expires_at() + boost::posix_time::seconds(1)) ;	// 重置定时器为2秒
		cout << "after  expires_at: " << t->expires_at() << endl;

		t->async_wait(boost::bind(Print, boost::asio::placeholders::error, t, count));
	}
}

int test4()
{
	cout<< "first thread: " << boost::this_thread::get_id()<<endl;
	boost::asio::io_service io;
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(3));
	int count = 0;
	t.async_wait(boost::bind(Print, boost::asio::placeholders::error, &t, &count));
	cout << "expires_from_now: " << t.expires_from_now() << endl;
	cout<<"to run"<<endl;
	io.run();
	cout << "Final count is " << count << "\n";
	cout<<"exit"<<endl;
	return 0;

}

class printer_0
{
	public:
		printer_0(boost::asio::io_service& io)
			: timer_(io, boost::posix_time::seconds(1)),
			count_(0)
		{
			timer_.async_wait(boost::bind(&printer_0::print, this));
		}
		~printer_0()
		{
			std::cout << "Final count is " << count_ << std::endl;
		}
		// 所有的非静态成员函数都有一个隐含的this参数
		// boost::bind()把回调函数print转换成了函数对象（function object）
		void print()
		{
			if (count_ < 5)
			{
				std::cout << count_ << std::endl;
				++count_;
				timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
				timer_.async_wait(boost::bind(&printer_0::print, this));
			}
		}
	private:
		boost::asio::deadline_timer timer_;
		int count_;
};

void test5(){
	boost::asio::io_service io;
	printer_0 p(io);
	io.run();
}
// callback handler 只能通过io_service::run()在线程中调用.

// 前面几个例子都是单线程调用cb句柄，这样调用有以下缺点：
// 	1. 当cb句柄执行时间太长时，响应性太低；
// 	2. 对于多核处理器没有可扩展性。
//
// 为了解决上述问题，可以使用线程池来调用io_service::run()，注意此时要访问共享的非线程安全的资源。
// boost::asio::strand 可以确保句柄的调用是保序的，一个后开始的句柄一定在前一个句柄执行结束之后才开始。
// strand::wrap()返回一个包含原句柄的新的句柄，通过wrap后的句柄能够保证，顺序执行，不并发执行。在多线程应用中，如果要访问共享变量，此时可以通过此方法把异步操作同步化。
class printer
{
public:
	printer(boost::asio::io_service& io)
		: strand_(io),
		timer1_(io, boost::posix_time::seconds(1)),
		timer2_(io, boost::posix_time::seconds(1)),
		count_(0)
	{
		timer1_.async_wait(strand_.wrap(boost::bind(&printer::print1, this)));
		timer2_.async_wait(strand_.wrap(boost::bind(&printer::print2, this)));
	}
	~printer()
	{
		std::cout << "Final count is " << count_ << std::endl;
	}
	void print1()
	{
		if (count_ < 10)
		{
			std::cout << "Timer 1: " << count_ << " thread:" << boost::this_thread::get_id() << std::endl;
			++count_;
			// 此处虽然要等待三秒但是不会阻塞，因为是异步的等待，意思是3s之后才会调用strand.wrap()
			timer1_.expires_at(timer1_.expires_at() + boost::posix_time::seconds(3));
			timer1_.async_wait(strand_.wrap(boost::bind(&printer::print1, this)));
		}
	}
	void print2()
	{
		if (count_ < 10)
		{
			std::cout << "Timer 2: " << count_ << " thread:" << boost::this_thread::get_id()<< std::endl;
			++count_;
			timer2_.expires_at(timer2_.expires_at() + boost::posix_time::seconds(1));
			timer2_.async_wait(strand_.wrap(boost::bind(&printer::print2, this)));
		}
	}
private:
	boost::asio::io_service::strand strand_;
	boost::asio::deadline_timer timer1_;
	boost::asio::deadline_timer timer2_;
	int count_;
};

// io_service::run()被两个线程调用，一个是主线程，一个是t线程
// strand是一个线程池，所谓保序，意思是先进入这个线程池的句柄被先调用。
void test6(){
	boost::asio::io_service io;
	printer p(io);
	boost::thread t(boost::bind(&boost::asio::io_service::run, &io));
	io.run();
	t.join();
}

int main(){
	test6();
	return 0;
}





