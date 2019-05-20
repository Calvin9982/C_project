struct shop *Increase_shop(struct shop *shophead)  //增加店铺的信息 
{
	int a;
	char c;
	printf("请问您想增加店铺信息吗(Y/N)？");
    scanf(" %c",&c);
	for(a=0;c=='Y'||c=='y';a++) 
	{
		struct shop *p1=NULL;
	    struct shop *p2=NULL; 
	    p1=(struct shop *)malloc(SHOP);   //申请空间 
		if(!p1)
	    {
	    	printf("由于内存不足而失败了！");
		    return shophead;
	    }  //申请内存失败 
	    p1->next=NULL;
	    printf("请输入店铺的有关信息\n");   //输入店铺信息 
    	printf("①请输入店铺的编号：");
	    scanf("%d",&p1->number) ;
	    printf("②请输入店铺的名称：");
	    scanf("%s",p1->name) ;
	    printf("③请输入店铺本月的进货量：");
	    scanf("%d",&p1->stock) ;
	    printf("④请输入店铺的进货金额：");
		scanf("%lf",&p1->cost);
	    printf("⑤请输入店铺本月的售货量："); 
	    scanf("%d",&p1->sale) ;
	    printf("⑥请输入店铺目前存货量：");
	    scanf("%d",&p1->left); 
	    printf("⑦请输入店铺的库存金额：");
		scanf("%lf",&p1->money);
	    printf("⑧请输入店铺本月的利润：");
	    scanf("%lf",&p1->benefit);
	    if(!shophead)
	    {
		    shophead=p1;
      	}   
	    else
	    {
		  for(p2=shophead;p2->next;p2=p2->next);
		  p2->next=p1;
	    }
		printf("请问您想继续增加店铺信息吗？(Y/N)");
		scanf(" %c",&c);
	}   
	printf("%d 个店铺的信息已经录入好\n",a);   //及时反馈用户信息录入情况
	return shophead;
}
void shop_sum(struct shop *head)   //统计店铺有关信息 
{
	int a=0,b=0;   //统计店铺进货量以及售货量 
	double c=0,d=0;    //统计店铺的收入以及进货金额 
	struct shop *p=NULL;
	for(p=head;p;p=p->next)   
	{
		a+=p->stock;
		b+=p->sale;
		c+=p->benefit; 
		d+=p->cost; 
	}
	printf("经过统计后，可知：\n");    //显示统计情况 
	printf("1、店铺进货总量为：%d\n",a);
	printf("2、店铺进货金额为：%g\n",d);
	printf("3、店铺售货总量为：%d\n",b);
	printf("4、店铺总收入为：%g\n",c); 
}
void print_shop(struct shop * shophead)  //输出店铺信息 
{
	if(!shophead)   //空链表没有可输出的店铺信息，应退出 
	{
		printf("抱歉，没有可输出的店铺信息！");
		return ; 
	}
	struct shop *p=NULL;
	printf("店铺编号  店铺名称  进货量  进货金额  售货量  库存量  库存金额  店铺收入\n");
	for(p=shophead;p;p=p->next)
	{
	  printf("%6d  %8s  %7d  %6g  %6d  %6d  %6g  %8g\n",p->number,p->name,p->stock,p->cost,p->sale,p->left,p->money,p->benefit);
	}
}
void searchshop(struct shop *shophead) //查询指定店铺的信息 
{
	if(!shophead)  //空链表无可查询的店铺信息 
	{
		printf("没有店铺信息可供查询");
		return  ;
	}
	int a;
	char c;
	struct shop *p=NULL;
	printf("请问您是否想要查询店铺信息？(Y/y)"); 
	scanf(" %c",&c);
	for(;c=='y'||c=='Y';)
    {
	   printf("请输入该店铺的编号：");
	   scanf("%d",&a);
	   for(p=shophead;p;p=p->next)  //根据编号找店铺信息 
	   {
	   	 if(a==p->number)
	     {
	     printf("您查询的店铺信息如下：\n");
		 printf("店铺编号  店铺名称  进货量  进货金额  售货量  库存量  库存金额  店铺收入\n");
	     printf("%6d  %8s  %7d  %6g  %6d  %6d  %6g  %8g\n",p->number,p->name,p->stock,p->cost,p->sale,p->left,p->money,p->benefit); 	
	     break;
	     } 
	   }
	    if(p==NULL)
	    {
	    	printf("没有找到该店铺的有关信息,请确认编号是否正确！\n");
    	} 
	    printf("请问您是否想要继续查询店铺信息？(Y/y)");
	    scanf(" %c",&c);
	}
}
void sort_shop(struct shop *head) //选择排序法，采用交换结点的方式排序 
{
	if(!head)    return ;
	struct shop *a=NULL,*b=NULL;
	struct shop *p;
	struct shop *m,*q;
	while(head)
	{
		p=head;
		m=p;
		while(p->next)
		{
			if(m->benefit>p->next->benefit)
			{
				q=p;
				m=p->next;
			}
			p=p->next;
		}
		if(!a)
		{
			a=b=m;	
		}
		else
		{
			b->next=m;
			b=m;
		}
		if(m==head)
		{
			head=m->next;
		}
		else
		{
			q->next=m->next;
		}
	} 
	b->next=NULL;
	printf("排序后的店铺情况为：\n");
	print_shop(a);
    printf("其中业绩最佳的店铺为%d号店铺\n",b->number); 
}
struct shop *Deleteshop (struct shop * head) //删除指定店铺的信息 
{
	if(!head) //链表为空，无可被删除的店铺信息 
	{
		printf("抱歉，您没有可以删除的店铺信息\n");
		return head;
    }
	char c;
	int a,b;
	printf("请问您想删除店铺信息吗？（Y/N）");
	scanf(" %c",&c);
    for(b=0;c=='Y'||c=='y';b++) 
	{ 
		struct shop *p=NULL;
	    struct shop *q=NULL;
	    printf("请输入您所想删除的店铺的编号:");
	    scanf("%d",&a);
	    for(p=head;p;q=p,p=p->next)//寻找指定店铺在链表中的位置 
		{
			if(a==p->number)
	        {
	         	if(q!=NULL) q->next=p->next;
	            else        head=p->next;
		        free(p);    //释放该空间 
		        printf("该店铺的信息删除成功！\n");
		        break;
	        } 
		}  
	    if(p==NULL)
	    {
		    printf("没有找到您所想删除的店铺\n"); 
		    b--;
	    }
	    printf("请问您还想继续删除店铺信息吗？（Y/N）");
	    scanf(" %c",&c);
	}
	printf("%d个店铺的信息已经删除成功\n",b);   //及时反馈用户删除情况 
	return head;
}
struct shop *modifyshop(struct shop *head) //修改指定店铺的信息 
{
	if(!head)
	{
		printf("没有店铺信息可供修改");
		return head;
	}
	int a,b;
	char c;
	printf("请问您想修改店铺信息吗(Y/N)？");
	scanf(" %c",&c);
	for(a=0;c=='Y'||c=='y';a++)
	{
	   struct shop *p=NULL;
	   printf("请输入该店铺的编号：");
	   scanf("%d",&b);
	   for(p=head;p;p=p->next) //找到指定店铺以修改 
	   {
	   	   if(b==p->number)
	       {
	        printf("请输入店铺新的信息\n");
	        printf("①请输入店铺的编号：");
	        scanf("%d",&p->number) ;
	        printf("②请输入店铺的名称：");
	        scanf("%s",p->name) ;
	        printf("③请输入店铺本月的进货量：");
	        scanf("%d",&p->stock) ;
	        printf("④请输入店铺的进货金额：");
	        scanf("%lf",&p->cost);
	        printf("⑤请输入店铺本月的售货量："); 
	        scanf("%d",&p->sale) ;
	        printf("⑥请输入店铺目前存货量：");
	        scanf("%d",&p->left); 
	        printf("⑦请输入店铺的库存金额：");
		    scanf("%lf",&p->money);
	        printf("⑧请输入店铺本月的利润：");
	        scanf("%lf",&p->benefit);
	        break;
	       } 
        }
       if(p==NULL)
	   {
	   	 printf("未查询到您所想修改的店铺，请检查编号是否输入正确！\n");
	   	 a--;
	   }
	   printf("请问您想继续修改店铺信息吗？(Y/N)");
	   scanf(" %c",&c);
	} 
	printf("%d个店铺的信息已经修改成功！\n",a);
	return head; 
}
void save_shop (struct shop * head) //保存店铺信息 
{
	struct shop * p=NULL;
	FILE *fp;
	if(!head) 
	{
		printf("没有店铺信息可供储存\n");
		return ;
	}
	if((fp=fopen("C:\\shop.txt","wb"))==NULL)
	{
		printf("打不开店铺信息文件\n");
		return ;
	}
	for(p=head;p;p=p->next)
	{
		fwrite(p,SHOP,1,fp);
	}
	fclose(fp);
	printf("所有店铺信息已成功存入文件！\n");
}
struct shop *open_shop(struct shop *head)
{
	FILE *fp;
	struct shop *p,*q;
	if((fp=fopen("C:\\shop.txt","rb"))==NULL)
	{
		printf("打不开店铺信息文件！\n");
		return head;
	}
    p=(struct shop *)malloc(SHOP);
	head=p;
	q=head;
	while(!feof(fp))
	{
		if(fread(p,SHOP,1,fp)!=1) break;
	    p->next=(struct shop *)malloc(SHOP);
        q=p->next;
        q=p;
        p=p->next;
	}
	q->next=NULL;
	fclose(fp);
	printf("读取店铺信息文件成功\n");
	return head;
}
