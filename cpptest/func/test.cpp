#include<iostream>
#include<boost/function>
#include<boost/asio.hpp>
#include<boost/thread.hpp>

typedef boost::function<void (bool)> UserLoginFunc;
typedef boost::shared_ptr<boost::asio::strand> StrandPtr;

void loadConfig(UserLoginFunc loginFunc)
{
	StrandPtr m_ptrStrand = 
	m_ptrStrand->post(boost::bind(&CTradeUser::do_loadConfig, this, loginFunc));
}	

void do_loadConfig(UserLoginFunc loginFunc)
{
	if (NULL != loginFunc)
	{	
		loginFunc(true);
	}
}

int main(){
	
	loadConfig(boost::bind(&CConfigScheduler::testAccountReload, this, pnLeft, accountInfo, cb));
	return 0;
}
