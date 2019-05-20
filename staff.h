struct staff * Add_staff(struct staff *staffhead)   //增加员工的信息 
{
	int a;
	char c;
	printf("请问您想增加员工信息吗(Y/N)？");
    scanf(" %c",&c);
	for(a=0;c=='Y'||c=='y';a++)
	{
		struct staff *p=NULL;
	    struct staff *q=staffhead;
	    p=(struct staff *)malloc(STAFF);  //申请空间 
		if(!p)
	    {
	    	printf("录入失败！\n");
		    return staffhead;
	    }
	    p->next=NULL;
	    printf("请输入该员工的有关信息\n");
    	printf("①请输入该员工的编号：");
	    scanf("%d",&p->number) ;
	    printf("②请输入该员工的名字：");
	    scanf("%s",p->name) ;
	    printf("③请输入该员工来源的店铺：");
	    scanf("%s",p->origin) ;
	    printf("④请输入该员工的销售金额："); 
	    scanf("%lf",&p->grade) ;
	    printf("⑤请输入该员工的销售数量：");
		scanf("%d",&p->count);
	    if(!staffhead)
	    {
		    staffhead=p;
      	}   
	    else
	    {
		  for(;q->next;q=q->next);
		  q->next=p;
	    }
		printf("请问您想继续增加员工信息吗？(Y/N)");
		scanf(" %c",&c); 
	}  
	printf("%d 个员工的信息已经录入好\n",a); 
	return staffhead;
}
void benefit_sum(struct staff *head) //求出员工的销售数量总和以及销售金额总和 
{
	int sale_number=0;  //销售数量总和 
	double a=0;         //销售金额总和 
	struct staff *p=NULL;
	for(p=head;p;p=p->next)
	{
		a+=p->grade;
		sale_number+=p->count;
	}
	printf("经统计以后可知：\n");     //及时反馈用户统计情况 
	printf("1、员工销售数量总和为：%d\n",sale_number);
	printf("2、员工销售金额总和为：%g\n",a);                                    
}
void showstaff(struct staff * staffhead)  //展示员工的信息 
{
	if(!staffhead)    //空链表没有可以输出的员工信息 
	{
		printf("没有可输出的员工信息！");
		return ; 
	}
	struct staff *p=NULL;
	printf("员工编号  员工姓名  源店铺  销售金额  销售数量\n");
	for(p=staffhead;p;p=p->next)
	{
	   printf("%6d   %9s  %6s  %8g  %8d\n",p->number,p->name,p->origin,p->grade,p->count);
	}
}
void search_staff(struct staff *staffhead)  //寻找指定员工的信息 
{
	if(!staffhead)     //空链表无信息以查询 
	{
		printf("没有员工信息可供查询!");
		return  ;
	}
	char c;
    int a;
    struct staff *p=NULL;
	printf("请问您是否想要查询员工信息？(Y/y)");
	scanf(" %c",&c);
	for(;c=='y'||c=='Y';)
    {
	   printf("请输入该员工的编号：");
	   scanf("%d",&a); 
	   for(p=staffhead;p;p=p->next)     //根据编号寻找指定员工 
	   { 
	      if(a==p->number)
	     {
	       printf("您查询的员工信息如下：\n");
		   printf("员工编号  员工姓名  源店铺  销售金额  销售数量\n");
		   printf("%6d   %9s  %6s  %8g  %8d\n",p->number,p->name,p->origin,p->grade,p->count);	
		   break; 
	     } 
	   }
	   if(p==NULL)  printf("没有找到该员工的相关信息！\n"); 
	   printf("请问您是否想要继续查询员工信息？(Y/y)");
	   scanf(" %c",&c);
	}
}
void sort_staff(struct staff *head)  //对员工信息进行插入排序(根据销售金额) 
{
	struct staff *a=NULL,*t=NULL;
	struct staff *p=NULL,*q=NULL;
    a=head->next;
	head->next=NULL;
	while(a!=NULL)
	{
		for(t=a,q=head;q&&(q->grade<t->grade);p=q,q=q->next);
		a=a->next;
		if(q==head)
		{
			head=t;
		}
		else
		{
			p->next=t;
		}
		t->next=q;
	} 
	showstaff(head);
}
struct staff *Delete_staff (struct staff * head)  //删除指定员工的信息 
{
	if(!head)      //空链表无信息可删除 
	{
		printf("抱歉，您没有可以删除的员工信息\n");
		return head;
    }
	char c;
	int a,b;
	printf("请问您想删除员工信息吗？（Y/N）");
	scanf(" %c",&c);
    for(b=0;c=='Y'||c=='y';b++)
	{ 
		struct staff *p=NULL;
	    struct staff *q=NULL;
	    printf("请输入您所想删除的员工的编号:");    //根据编号删除指定员工的信息 
	    scanf("%d",&a);                             //寻找指定员工在链表中的位置 
	    for(p=head;p;q=p,p=p->next)   
	    {
	    	if(a==p->number)
	        {
	         	if(q!=NULL) q->next=p->next;
	            else        head=p->next;
		        free(p);    //释放该空间 
		        printf("该员工信息删除成功！\n");
		        break;
	        }  
		}
	    if(p==NULL)         //没有找到指定员工 
	    {
		    printf("没有找到您所想删除的员工\n"); 
	        b--;
	    }
	    printf("请问您还想继续删除员工信息吗？（Y/N）");
	    scanf(" %c",&c);
	}
	printf("%d个员工的信息已经删除成功\n",b);   //及时反馈删除情况 
	return head;
}
struct staff  *modify_staff(struct staff *head)  //修改指定员工的信息 
{
	if(!head)    //空链表无可修改的员工信息 
	{
		printf("没有员工的信息可供修改");
		return head;
	}
	int a,b;
	char c;
	printf("请问您想修改员工信息吗(Y/N)？"); 
	scanf(" %c",&c);
	for(a=0;c=='Y'||c=='y';a++)
	{
	   struct staff *p=NULL;
	   printf("请输入该员工的编号：");    //根据员工编号找到员工对信息进行修改 
	   scanf("%d",&b);
	   for(p=head;p;p=p->next)
       {
	   	if(b==p->number) 
	    {
	     printf("请输入员工新的信息\n");    //重新去录入员工的信息 
	     printf("①请输入该员工的编号：");
	     scanf("%d",&p->number) ;
	     printf("②请输入该员工的名字：");
	     scanf(" %s",p->name) ;
	     printf("③请输入该员工来源的店铺：");
	     scanf("%s",p->origin) ;
	     printf("④请输入该员工的销售金额："); 
	     scanf("%lf",&p->grade) ;
	     printf("⑤请输入该员工的销售数量：");
		 scanf("%d",&p->count); 
		 break;
	    }
	   } 
	   if(p==NULL) //没有找到要修改的员工 
	   {
		 printf("未查询到您所想修改的员工，请检查编号是否输入正确！\n");
		 a--;
		}  
	    printf("请问您想继续修改员工信息吗？(Y/N)");
	    scanf(" %c",&c);
	} 
	printf("%d个员工的信息已经修改成功！\n",a);  //及时反馈员工信息 
	return head; 
}
void storage_staff(struct staff  * head) //保存员工信息 
{
	if(!head) 
	{
		printf("没有员工信息可供储存\n");
		return ;
	}
	struct staff  *p=NULL;
	FILE *fp;
	if((fp=fopen("C:\\staff.txt","wb"))==NULL)
	{
		printf("不能打开员工信息文件\n");
		return ;
	}
	for(p=head;p;p=p->next)
	{
		fwrite(p,STAFF,1,fp);
	}
	fclose(fp);
	printf("所有员工信息已成功存入文件！\n");
}
struct staff  * open_staff(struct staff  *head)
{
	FILE *fp;
	struct staff  *p,*q;
	if((fp=fopen("C:\\staff.txt","rb"))==NULL)
	{
		printf("打不开员工信息文件！\n");
		return head;
	}
    p=(struct staff *)malloc(STAFF);
	head=p;
	q=head;
	while(!feof(fp))
	{
		if(fread(p,STAFF,1,fp)!=1) break;
	    p->next=(struct staff  *)malloc(STAFF);
        q=p->next;
        q=p;
        p=p->next;
	}
	q->next=NULL;
	fclose(fp);
	printf("读取员工信息文件成功\n");
	return head;
}
