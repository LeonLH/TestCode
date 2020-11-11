#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>


class Test
{
	public:
		//析构函数
		~Test() { std::cout << "Test Destructor." << std::endl;  }
		//获取指向当前对象的指针
		boost::shared_ptr<Test> GetObject()
		{
			boost::shared_ptr<Test> pTest(this);
			return pTest;
		}
};

class TestEN: public boost::enable_shared_from_this<TestEN>
{
	public:
		//析构函数
		~TestEN() { std::cout << "TestEN Destructor." << std::endl;  }
		//获取指向当前对象的指针
		boost::shared_ptr<TestEN> GetObject()
		{
			return shared_from_this();
		}
};
int main(int argc, char *argv[])
{
	/*
	{ 
		boost::shared_ptr<Test> p( new Test(  ) );
		std::cout << "p.use_count(): " << p.use_count() << std::endl;
		boost::shared_ptr<Test> q = p->GetObject();
		std::cout << "q.use_count(): " << q.use_count() << std::endl;
	}
	*/
	{
		boost::shared_ptr<TestEN> p( new TestEN(  ) );
		std::cout << "p.use_count(): " << p.use_count() << std::endl;
		boost::shared_ptr<TestEN> q = p->GetObject();
		std::cout << "q.use_count(): " << q.use_count() << std::endl;
	}
	return 0;

	/*
	Test* test = new Test();
	boost::shared_ptr<Test> p(test);
	boost::shared_ptr<Test> q(test);
	// boost::shared_ptr<Test> q = p;
	std::cout << "p.use_count(): " << p.use_count() << std::endl;
	std::cout << "q.use_count(): " << q.use_count() << std::endl;
	return 0;
	*/
}

// 在类对象（Test）内部中获得一个指向当前对象的shared_ptr 







































