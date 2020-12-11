#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>

using namespace std;
class Test
{
    public:
    Test()
    {
        _a = 10;
        _b = 20;
    }

    Test(Test &_t)
    {
        _a = _t._a;
        _b = _t._b;
        cout << "拷贝" << endl;
    }

    private:
        int _a;
        int _b;
};

int main()
{
    Test t1;
    Test &t2 = t1;
    boost::shared_ptr<Test> t3Ptr = boost::make_shared<Test>(t2);
}