int memu()  //主目录 
{
	int a;     //用以记录用户在主目录的抉择 
	printf("\n\n\n\n\n\t\t*************************************************\t\t\n") ;
    printf("\t\t*\t\t超市管理系统\t\t\t*\t\n");
	printf("\t\t*1、商品管理\t\t\t\t\t*\n");
	printf("\t\t*2、店铺管理\t\t\t\t\t*\n");
	printf("\t\t*3、员工管理\t\t\t\t\t*\n");
	printf("\t\t*4、退出系统\t\t\t\t\t*\n");
	printf("\t\t*************************************************\t\t\n") ;
	printf("请输入您的选择：");
	scanf("%d",&a);
	return a;
}
int goodmemu()    //商品信息管理目录 
{
	int a;        //定义变量记录用户在商品管理上的选择 
	printf("\n\n\n\n\n\n\t\t*************************************************\t\t\n") ;
    printf("\t\t*\t\t商品管理系统\t\t\t*\n");
	printf("\t\t*1、商品信息录入\t\t\t\t*\n");
	printf("\t\t*2、商品信息查询\t\t\t\t*\n");
	printf("\t\t*3、商品信息修改\t\t\t\t*\n");
	printf("\t\t*4、商品信息删除\t\t\t\t*\n");
	printf("\t\t*5、商品信息展示\t\t\t\t*\n"); 
	printf("\t\t*6、商品信息统计\t\t\t\t*\n");
	printf("\t\t*7、商品信息储存入文件\t\t\t\t*\n"); 
	printf("\t\t*8、文件中导出商品信息\t\t\t\t*\n");
	printf("\t\t*9、退出\t\t\t\t\t*\n");
	printf("\t\t*************************************************\t\t\n") ;
	printf("请输入你的选择：");
	scanf("%d",&a);
	return a;
} 
int shopmemu()  //店铺信息管理目录 
{
	int a;     //定义一个变量记录用户在店铺信息管理上的抉择 
	printf("\n\n\n\n\n\t\t*************************************************\t\t\n") ;
    printf("\t\t*\t\t店铺管理\t\t\t*\t\n");   
	printf("\t\t*1、店铺信息录入\t\t\t\t*\n");
	printf("\t\t*2、店铺信息查询\t\t\t\t*\n");
	printf("\t\t*3、店铺业绩排名\t\t\t\t*\n");
	printf("\t\t*4、店铺信息删除\t\t\t\t*\n");
	printf("\t\t*5、店铺信息修改\t\t\t\t*\n"); 
	printf("\t\t*6、店铺信息展示\t\t\t\t*\n"); 
	printf("\t\t*7、店铺信息统计\t\t\t\t*\n");
	printf("\t\t*8、店铺信息储存入文件\t\t\t\t*\n"); 
	printf("\t\t*9、文件中导出店铺信息\t\t\t\t*\n");
	printf("\t\t*10、退出\t\t\t\t\t*\n");
	printf("\t\t*************************************************\t\t\n") ;
	printf("请输入你的选择：");
	scanf("%d",&a);
	return a;
}
int staffmemu()  //员工信息管理目录 
{
	int a;       //定义一个变量记录用户在员工信息管理上的抉择 
	printf("\n\n\n\n\n\t\t*************************************************\t\t\n") ;
    printf("\t\t*\t\t员工管理\t\t\t*\t\n");
	printf("\t\t*1、员工信息录入\t\t\t\t*\n");
	printf("\t\t*2、员工信息查询\t\t\t\t*\n");
	printf("\t\t*3、员工业绩排名\t\t\t\t*\n");
	printf("\t\t*4、员工信息删除\t\t\t\t*\n");
	printf("\t\t*5、员工信息修改\t\t\t\t*\n");
	printf("\t\t*6、员工信息展示\t\t\t\t*\n");
	printf("\t\t*7、员工信息统计\t\t\t\t*\n");
	printf("\t\t*8、员工信息储存入文件\t\t\t\t*\n");
	printf("\t\t*9、文件中导出员工信息\t\t\t\t*\n");
	printf("\t\t*10、退出\t\t\t\t\t*\n");
	printf("\t\t*************************************************\t\t\n") ;
	printf("请输入你的选择：");
	scanf("%d",&a);
	return a;
}

