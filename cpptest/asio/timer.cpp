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
// 
void Print(const boost::system::error_code &ec,
		boost::asio::deadline_timer* t,
		int * count)
{
	if (*count < 5)
	{
		cout<<"count = "<<*count<<endl;
		cout<<boost::this_thread::get_id()<<endl;
		(*count) ++;

		t->expires_at(t->expires_at() + boost::posix_time::seconds(2)) ;

		t->async_wait(boost::bind(Print, boost::asio::placeholders::error, t, count));
	}
}

int test4()
{
	cout<< "first thread: " << boost::this_thread::get_id()<<endl;
	boost::asio::io_service io;
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	int count = 0;
	t.async_wait(boost::bind(Print, boost::asio::placeholders::error, &t, &count));
	cout<<"to run"<<endl;
	io.run();
	cout << "Final count is " << count << "\n";
	cout<<"exit"<<endl;
	return 0;

}
int main(){
	test4();
	return 0;
}





