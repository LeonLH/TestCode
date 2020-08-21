#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>
#include <string>
using namespace std;

// 同步定时器
int test1(){
	boost::asio::io_service io;
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	cout << "start" << endl;
	t.wait();		// 阻塞等待
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
	t.async_wait(Print);
	cout << "to run" << endl;
	io.run();
	cout << "exit" << endl;
	return 0;
}
