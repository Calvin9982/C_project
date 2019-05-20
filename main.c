#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Good    //商品结构体 
{  
	int group_number;//集团编号 
	char group_name[10];//集团名称 
	int number;  //商品编号 
    char name[10];//商品名称 
    char place[10]; //商品产地 
    int kind;//商品种类编号，用种类编号给商品分类，编号含义请见文档 
    double cost; //商品的进价 
    double price;//商品的售价 
    int   sale_number;//商品的销售数量
    struct Good *next; 
};
struct shop  //店铺结构体 
{
	int number; //店铺编号 
	char name[20]; //店铺名称 
	int stock;   //当月进货量 
	int sale;    //当月售货量
	double  cost ;//进货金额 (以万为单位)
	int left;    //目前库存量 
	double money;//库存金额 （以万为单位） 
	double benefit; //当月店铺收入 （以万为单位） 
	struct shop *next; 
};
struct staff  //员工结构体 
{
	int number;  //员工编号 
	char name[20]; //员工姓名 
	char origin[20];    //员工源店铺编号 
	double grade;   //员工业绩（即销售金额，以K为单位）
	int  count;    //员工销售数量  
	struct staff *next; 
}; 
#define  GOOD  sizeof(struct Good)   //宏定义商品信息结构体的长度 
#define  SHOP  sizeof(struct shop)   //宏定义店铺信息结构体的长度 
#define  STAFF sizeof(struct staff)  //宏定义员工信息结构体的长度 
#include "memu.h"     //菜单头文件 
#include "good.h"     //含有管理商品信息的函数 
#include "shop.h"     //含有管理店铺信息的函数 
#include "staff.h"    //含有管理员工信息的函数 
int main() 
{
	system("color 0F");   //使用system函数调界面颜色，增加用户的体验 
	int choice;           //记录用户的功能选项 
	int i;
	char c;
	static struct Good *goodhead=NULL; //定义商品信息头指针 
    static struct shop *shophead=NULL; //定义店铺信息头指针 
    static struct staff *staffhead=NULL; //定义员工信息头指针 
    while(1)
    { 
	    choice=memu();  //主界面函数调用 
	    system("cls");  //及时清屏以美化界面 
	    while(choice==1) //进入商品信息管理 
	    {
	 	 i=goodmemu(); //选择商品管理的有关功能 
		 if(i==1)  //进入商品信息增添模块 
		 {
			system("cls");
			goodhead=Increase_good(goodhead); //调用增加商品信息的函数 
			system("pause");  
			system("cls");    //及时清屏以美化界面
		 } 
		 if(i==2) //进入查询商品信息模块 
		 {
			system("cls");
			searchGood(goodhead); //调用查询商品信息的函数 
			system("cls");	
		 }
		 if(i==3)  //进入修改商品信息模块 
		 {
			system("cls");
		    goodhead=modifygood(goodhead);  //调用修改商品信息的函数 
		    system("pause");
		    system("cls");
		 }
		 if(i==4)  //进入删除商品信息模块 
		 {
			system("cls");
			goodhead=Deletegood(goodhead);  //调用删除商品信息的函数 
			system("pause");
			system("cls");
		 }
		if(i==5) //显示商品信息和统计情况 
		 {
			system("cls");
			Show_Good(goodhead); //调用显示商品信息的函数 
			system("pause");
			system("cls");
		 } 
		 if(i==6)    //显示商品统计信息
		 { 
		    system("cls");
		 	sale_sum(goodhead);  //调用统计商品信息的函数 
		 	system("pause"); 
			system("cls");
		 }
		 if(i==7)   //将商品信息储存到文件中保存 
		 {
		 	system("cls");
		 	storage_good(goodhead);    //调用商品信息保存函数 
		 	system("pause");
			system("cls");
		 }
		 if(i==8)   //从文件中导出商品信息 
		 {
		 	system("cls");
		 	goodhead=open_good(goodhead);  //调用导出商品信息的函数 
		 	system("pause");
			system("cls");
		 }
		 if(i==9)  //正常退出系统 
		 {
			system("cls");
			printf("商品信息管理系统欢迎再次为您服务！\n");
			system("pause");
			system("cls"); 
			break; 
		 } 
  	    }
	   while(choice==2)  //店铺信息管理 
	    {
		i=shopmemu();
		if(i==1)           //进入增添店铺信息模块 
		{ 
		    system("cls");
			shophead=Increase_shop(shophead); //调用增加店铺信息的函数 
	        system("pause");
	        system("cls");
		}
		if(i==2)  //查询指定的店铺信息 
		{
			system("cls");
		    searchshop(shophead); //调用查找店铺信息的函数 
		    system("pause");
			system("cls");		    
		}
		if(i==3)  //查看店铺的排名 
		{	system("cls");
			printf("请问您是否想要查看店铺业绩排名情况呢？（Y/N）");
			scanf(" %c",&c);
			sort_shop(shophead);    //调用店铺排序函数 
			system("pause"); 
			system("cls");
		}
		if(i==4)  //删除指定店铺的信息 
		{
			system("cls");
		    shophead=Deleteshop(shophead); //调用删除店铺信息的函数 
	        system("pause");
	        system("cls");
		}
		if(i==5)  //修改指定店铺的信息 
		{
			 system("cls");
			 shophead=modifyshop(shophead); //调用修改店铺信息的函数 
			 system("pause");
	         system("cls");
		} 
		if(i==6)  //显示店铺的信息 
		{
			system("cls");
			print_shop(shophead); //调用输出店铺信息的函数 
			system("pause");
	        system("cls");
		} 
		if(i==7)    //店铺信息统计情况展示 
		{
			system("cls");
			shop_sum(shophead);  //调用统计店铺信息的函数 
			system("pause");
	        system("cls");
		} 
		if(i==8)  //保存店铺信息到文件中去 
		{
		    system("cls");
			save_shop(shophead);  //调用保存店铺信息的函数 
			system("pause");
	        system("cls");
		}
		if(i==9)  //从文件中导出店铺信息 
	    {
	   	    system("cls");
			shophead=open_shop(shophead);  //调用导出店铺信息的函数 
			system("pause");
	        system("cls");
	    }
		if(i==10)  //退出系统 
		{
			system("cls");
			printf("店铺信息管理系统欢迎再次为您服务，再见~\n"); 
			system("pause");
			system("cls"); 
			break;
		} 
	    }
	while(choice==3)  //员工信息管理 
	{
		i=staffmemu();
		if(i==1)  //增添员工的信息 
		{ 
		    system("cls");
			staffhead=Add_staff(staffhead); //调用增加员工信息的函数 
	        system("pause");
	        system("cls");
		}
		if(i==2)  //查询指定员工的信息 
		{
			system("cls");
		    search_staff(staffhead); //调用查询员工信息的函数 
		    system("pause");
		    system("cls");
		}
		if(i==3)  //查看员工的排名情况 
		{	system("cls");
			printf("请问您是否想要查看员工业绩排名情况呢？（Y/N）");
			scanf(" %c",&c);
			sort_staff(staffhead); //调用对员工信息排序的函数 
			system("pause"); 
			system("cls");
		}
		if(i==4) //删除指定员工的信息 
		{
			system("cls");
		    staffhead=Delete_staff(staffhead); //调用删除员工信息的函数 
	        system("pause");
	        system("cls");
		}
		if(i==5)  //修改指定员工的信息 
		{
			 system("cls");
			 staffhead=modify_staff(staffhead); //调用修改员工信息的函数 
			 system("pause");
	         system("cls");
		} 
		if(i==6)  //展示员工的信息 
		{
		   system("cls");
		   showstaff(staffhead); //调用展示员工信息的函数 
		   system("pause");
		   system("cls");
		} 
		if(i==7)   //展示员工信息统计情况 
		{
			system("cls");
			benefit_sum(staffhead); //调用统计员工信息的函数 
			system("pause");
		    system("cls");
		}
		if(i==8)  //保存员工信息至文件 
		{
			system("cls");
			storage_staff(staffhead);  //调用保存员工信息的函数 
			system("pause");
		    system("cls");
		}
		if(i==9) //导出员工信息 
		{
			system("cls");
			staffhead=open_staff(staffhead); //调用导出员工信息的函数 
			system("pause");
		    system("cls");
		}
		if(i==10) //退出系统 
		{
			system("cls");
			printf("员工信息管理系统欢迎再次为您服务，再见~\n"); 
			system("pause");
		    system("cls");
			break;
		} 
	}
	while(choice==4) //退出系统 
	{
		system("cls");
		printf("超市管理系统欢迎再次为您服务，再见~\n"); 
		exit(0);
	}
   }
	return 0;
}
