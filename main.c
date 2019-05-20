#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Good    //��Ʒ�ṹ�� 
{  
	int group_number;//���ű�� 
	char group_name[10];//�������� 
	int number;  //��Ʒ��� 
    char name[10];//��Ʒ���� 
    char place[10]; //��Ʒ���� 
    int kind;//��Ʒ�����ţ��������Ÿ���Ʒ���࣬��ź�������ĵ� 
    double cost; //��Ʒ�Ľ��� 
    double price;//��Ʒ���ۼ� 
    int   sale_number;//��Ʒ����������
    struct Good *next; 
};
struct shop  //���̽ṹ�� 
{
	int number; //���̱�� 
	char name[20]; //�������� 
	int stock;   //���½����� 
	int sale;    //�����ۻ���
	double  cost ;//������� (����Ϊ��λ)
	int left;    //Ŀǰ����� 
	double money;//����� ������Ϊ��λ�� 
	double benefit; //���µ������� ������Ϊ��λ�� 
	struct shop *next; 
};
struct staff  //Ա���ṹ�� 
{
	int number;  //Ա����� 
	char name[20]; //Ա������ 
	char origin[20];    //Ա��Դ���̱�� 
	double grade;   //Ա��ҵ���������۽���KΪ��λ��
	int  count;    //Ա����������  
	struct staff *next; 
}; 
#define  GOOD  sizeof(struct Good)   //�궨����Ʒ��Ϣ�ṹ��ĳ��� 
#define  SHOP  sizeof(struct shop)   //�궨�������Ϣ�ṹ��ĳ��� 
#define  STAFF sizeof(struct staff)  //�궨��Ա����Ϣ�ṹ��ĳ��� 
#include "memu.h"     //�˵�ͷ�ļ� 
#include "good.h"     //���й�����Ʒ��Ϣ�ĺ��� 
#include "shop.h"     //���й��������Ϣ�ĺ��� 
#include "staff.h"    //���й���Ա����Ϣ�ĺ��� 
int main() 
{
	system("color 0F");   //ʹ��system������������ɫ�������û������� 
	int choice;           //��¼�û��Ĺ���ѡ�� 
	int i;
	char c;
	static struct Good *goodhead=NULL; //������Ʒ��Ϣͷָ�� 
    static struct shop *shophead=NULL; //���������Ϣͷָ�� 
    static struct staff *staffhead=NULL; //����Ա����Ϣͷָ�� 
    while(1)
    { 
	    choice=memu();  //�����溯������ 
	    system("cls");  //��ʱ�������������� 
	    while(choice==1) //������Ʒ��Ϣ���� 
	    {
	 	 i=goodmemu(); //ѡ����Ʒ������йع��� 
		 if(i==1)  //������Ʒ��Ϣ����ģ�� 
		 {
			system("cls");
			goodhead=Increase_good(goodhead); //����������Ʒ��Ϣ�ĺ��� 
			system("pause");  
			system("cls");    //��ʱ��������������
		 } 
		 if(i==2) //�����ѯ��Ʒ��Ϣģ�� 
		 {
			system("cls");
			searchGood(goodhead); //���ò�ѯ��Ʒ��Ϣ�ĺ��� 
			system("cls");	
		 }
		 if(i==3)  //�����޸���Ʒ��Ϣģ�� 
		 {
			system("cls");
		    goodhead=modifygood(goodhead);  //�����޸���Ʒ��Ϣ�ĺ��� 
		    system("pause");
		    system("cls");
		 }
		 if(i==4)  //����ɾ����Ʒ��Ϣģ�� 
		 {
			system("cls");
			goodhead=Deletegood(goodhead);  //����ɾ����Ʒ��Ϣ�ĺ��� 
			system("pause");
			system("cls");
		 }
		if(i==5) //��ʾ��Ʒ��Ϣ��ͳ����� 
		 {
			system("cls");
			Show_Good(goodhead); //������ʾ��Ʒ��Ϣ�ĺ��� 
			system("pause");
			system("cls");
		 } 
		 if(i==6)    //��ʾ��Ʒͳ����Ϣ
		 { 
		    system("cls");
		 	sale_sum(goodhead);  //����ͳ����Ʒ��Ϣ�ĺ��� 
		 	system("pause"); 
			system("cls");
		 }
		 if(i==7)   //����Ʒ��Ϣ���浽�ļ��б��� 
		 {
		 	system("cls");
		 	storage_good(goodhead);    //������Ʒ��Ϣ���溯�� 
		 	system("pause");
			system("cls");
		 }
		 if(i==8)   //���ļ��е�����Ʒ��Ϣ 
		 {
		 	system("cls");
		 	goodhead=open_good(goodhead);  //���õ�����Ʒ��Ϣ�ĺ��� 
		 	system("pause");
			system("cls");
		 }
		 if(i==9)  //�����˳�ϵͳ 
		 {
			system("cls");
			printf("��Ʒ��Ϣ����ϵͳ��ӭ�ٴ�Ϊ������\n");
			system("pause");
			system("cls"); 
			break; 
		 } 
  	    }
	   while(choice==2)  //������Ϣ���� 
	    {
		i=shopmemu();
		if(i==1)           //�������������Ϣģ�� 
		{ 
		    system("cls");
			shophead=Increase_shop(shophead); //�������ӵ�����Ϣ�ĺ��� 
	        system("pause");
	        system("cls");
		}
		if(i==2)  //��ѯָ���ĵ�����Ϣ 
		{
			system("cls");
		    searchshop(shophead); //���ò��ҵ�����Ϣ�ĺ��� 
		    system("pause");
			system("cls");		    
		}
		if(i==3)  //�鿴���̵����� 
		{	system("cls");
			printf("�������Ƿ���Ҫ�鿴����ҵ����������أ���Y/N��");
			scanf(" %c",&c);
			sort_shop(shophead);    //���õ��������� 
			system("pause"); 
			system("cls");
		}
		if(i==4)  //ɾ��ָ�����̵���Ϣ 
		{
			system("cls");
		    shophead=Deleteshop(shophead); //����ɾ��������Ϣ�ĺ��� 
	        system("pause");
	        system("cls");
		}
		if(i==5)  //�޸�ָ�����̵���Ϣ 
		{
			 system("cls");
			 shophead=modifyshop(shophead); //�����޸ĵ�����Ϣ�ĺ��� 
			 system("pause");
	         system("cls");
		} 
		if(i==6)  //��ʾ���̵���Ϣ 
		{
			system("cls");
			print_shop(shophead); //�������������Ϣ�ĺ��� 
			system("pause");
	        system("cls");
		} 
		if(i==7)    //������Ϣͳ�����չʾ 
		{
			system("cls");
			shop_sum(shophead);  //����ͳ�Ƶ�����Ϣ�ĺ��� 
			system("pause");
	        system("cls");
		} 
		if(i==8)  //���������Ϣ���ļ���ȥ 
		{
		    system("cls");
			save_shop(shophead);  //���ñ��������Ϣ�ĺ��� 
			system("pause");
	        system("cls");
		}
		if(i==9)  //���ļ��е���������Ϣ 
	    {
	   	    system("cls");
			shophead=open_shop(shophead);  //���õ���������Ϣ�ĺ��� 
			system("pause");
	        system("cls");
	    }
		if(i==10)  //�˳�ϵͳ 
		{
			system("cls");
			printf("������Ϣ����ϵͳ��ӭ�ٴ�Ϊ�������ټ�~\n"); 
			system("pause");
			system("cls"); 
			break;
		} 
	    }
	while(choice==3)  //Ա����Ϣ���� 
	{
		i=staffmemu();
		if(i==1)  //����Ա������Ϣ 
		{ 
		    system("cls");
			staffhead=Add_staff(staffhead); //��������Ա����Ϣ�ĺ��� 
	        system("pause");
	        system("cls");
		}
		if(i==2)  //��ѯָ��Ա������Ϣ 
		{
			system("cls");
		    search_staff(staffhead); //���ò�ѯԱ����Ϣ�ĺ��� 
		    system("pause");
		    system("cls");
		}
		if(i==3)  //�鿴Ա����������� 
		{	system("cls");
			printf("�������Ƿ���Ҫ�鿴Ա��ҵ����������أ���Y/N��");
			scanf(" %c",&c);
			sort_staff(staffhead); //���ö�Ա����Ϣ����ĺ��� 
			system("pause"); 
			system("cls");
		}
		if(i==4) //ɾ��ָ��Ա������Ϣ 
		{
			system("cls");
		    staffhead=Delete_staff(staffhead); //����ɾ��Ա����Ϣ�ĺ��� 
	        system("pause");
	        system("cls");
		}
		if(i==5)  //�޸�ָ��Ա������Ϣ 
		{
			 system("cls");
			 staffhead=modify_staff(staffhead); //�����޸�Ա����Ϣ�ĺ��� 
			 system("pause");
	         system("cls");
		} 
		if(i==6)  //չʾԱ������Ϣ 
		{
		   system("cls");
		   showstaff(staffhead); //����չʾԱ����Ϣ�ĺ��� 
		   system("pause");
		   system("cls");
		} 
		if(i==7)   //չʾԱ����Ϣͳ����� 
		{
			system("cls");
			benefit_sum(staffhead); //����ͳ��Ա����Ϣ�ĺ��� 
			system("pause");
		    system("cls");
		}
		if(i==8)  //����Ա����Ϣ���ļ� 
		{
			system("cls");
			storage_staff(staffhead);  //���ñ���Ա����Ϣ�ĺ��� 
			system("pause");
		    system("cls");
		}
		if(i==9) //����Ա����Ϣ 
		{
			system("cls");
			staffhead=open_staff(staffhead); //���õ���Ա����Ϣ�ĺ��� 
			system("pause");
		    system("cls");
		}
		if(i==10) //�˳�ϵͳ 
		{
			system("cls");
			printf("Ա����Ϣ����ϵͳ��ӭ�ٴ�Ϊ�������ټ�~\n"); 
			system("pause");
		    system("cls");
			break;
		} 
	}
	while(choice==4) //�˳�ϵͳ 
	{
		system("cls");
		printf("���й���ϵͳ��ӭ�ٴ�Ϊ�������ټ�~\n"); 
		exit(0);
	}
   }
	return 0;
}
