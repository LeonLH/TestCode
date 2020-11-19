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

void Print(const boost::system::error_code &ec,
		boost::asio::deadline_timer* pt,
		int * pcount)
{
	if (*pcount < 3)
	{
		cout<<"count = "<<*pcount<<endl;
		cout<<boost::this_thread::get_id()<<endl;
		(*pcount) ++;

		pt->expires_at(pt->expires_at() + boost::posix_time::seconds(5)) ;

		pt->async_wait(boost::bind(Print, boost::asio::placeholders::error, pt, pcount));
	}
}

int test3()
{
	cout<<boost::this_thread::get_id()<<endl;
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


void print(const boost::system::error_code& /*e*/)
{
	std::cout << "Hello, world!" << std::endl;
}

// 只有在io.run的时候才会调用定时器的异步wait所绑定的句柄，但是如果此时定时器的状态是unexpired，还需要等待直到expired才会调用
// 什么是wait completion：定时器超时后要调用的句柄。
void test4(){
	boost::asio::io_service io;
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	cout << "before" << endl;
	t.async_wait(&print);
	sleep(3);
	cout << "after" << endl;
	io.run();
}

int main(){
	test4();
	return 0;
}
