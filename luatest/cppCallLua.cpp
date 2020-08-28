#include <iostream>  
#include <string.h>  
using namespace std;  
  
extern "C"  
{  
    #include "lua.h"  
    #include "lauxlib.h"  
    #include "lualib.h"  
}  
int test()  
{  
    //1.创建一个state  
	lua_State *L = luaL_newstate();  

	//2.入栈操作  
	lua_pushstring(L, "I am so cool~");   
	lua_pushnumber(L,20);  

	//3.取值操作  
	if( lua_isstring(L,1) ){             //判断是否可以转为string  
		cout<<lua_tostring(L,1)<<endl;  //转为string并返回  
	}  
	if( lua_isnumber(L,2) ){  
		cout<<lua_tonumber(L,2)<<endl;  
	}  

	//4.关闭state  
	lua_close(L);  
	return 0;  
}  

/*
int   lua_gettop (lua_State *L);            //返回栈顶索引（即栈长度）  
void  lua_settop (lua_State *L, int idx);   //                
void  lua_pushvalue (lua_State *L, int idx);//将idx索引上的值的副本压入栈顶  
void  lua_remove (lua_State *L, int idx);   //移除idx索引上的值  
void  lua_insert (lua_State *L, int idx);   //弹出栈顶元素，并插入索引idx位置  
void  lua_replace (lua_State *L, int idx);  //弹出栈顶元素，并替换索引idx位置的值 
*/

int test1()  
{  
    //1.创建Lua状态  
	lua_State *L = luaL_newstate();  
	if (L == NULL)  
	{  
		return 0;  
	}  

	//2.加载lua文件  
	int bRet = luaL_loadfile(L,"hello.lua");  
	if(bRet)  
	{  
		cout<<"load file error"<<endl;  
		return 0;  
	}  

	//3.运行lua文件  
	bRet = lua_pcall(L,0,0,0);  
	if(bRet)  
	{  
		cout<<"pcall error"<<endl;  
		return 0;  
	}  

	//4.读取变量  
	lua_getglobal(L,"str");  
	string str = lua_tostring(L,-1);  
	cout<<"str = "<<str.c_str()<<endl;        //str = I am so cool~  

	//5.读取table  
	lua_getglobal(L,"tbl");   
	lua_getfield(L,-1,"name");  
	str = lua_tostring(L,-1);  
	cout<<"tbl:name = "<<str.c_str()<<endl; //tbl:name = shun  

	//6.读取函数  
	lua_getglobal(L, "add");        // 获取函数，压入栈中  
	lua_pushnumber(L, 10);          // 压入第一个参数  
	lua_pushnumber(L, 20);          // 压入第二个参数  
	int iRet= lua_pcall(L, 2, 1, 0);// 调用函数，调用完成以后，会将返回值压入栈中，2表示参数个数，1表示返回结果个数。  
	if (iRet)                       // 调用出错  
	{  
		const char *pErrorMsg = lua_tostring(L, -1);  
		cout << pErrorMsg << endl;  
		lua_close(L);  
		return 0;  
	}  
	if (lua_isnumber(L, -1))        //取值输出  
	{  
		double fValue = lua_tonumber(L, -1);  
		cout << "Result is " << fValue << endl;  
	}  

	//至此，栈中的情况是：  
	//=================== 栈顶 ===================   
	//  索引  类型      值  
	//   4   int：      30   
	//   3   string：   shun   
	//   2   table:     tbl  
	//   1   string:    I am so cool~  
	//=================== 栈底 ===================   

	// 将需要设置的值设置到栈中  
	lua_pushstring(L, "我是一个大帅锅～");  
	// 将这个值设置到table中（此时tbl在栈的位置为2）  
	lua_setfield(L, 2, "name");  

	lua_getglobal(L,"tbl");   
	lua_getfield(L,-1,"name");  
	str = lua_tostring(L,-1);  
	cout<<"tbl:name = "<<str.c_str()<<endl;

	//7.关闭state  
	lua_close(L);  
	return 0;  
}  


