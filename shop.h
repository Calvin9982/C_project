struct shop *Increase_shop(struct shop *shophead)  //���ӵ��̵���Ϣ 
{
	int a;
	char c;
	printf("�����������ӵ�����Ϣ��(Y/N)��");
    scanf(" %c",&c);
	for(a=0;c=='Y'||c=='y';a++) 
	{
		struct shop *p1=NULL;
	    struct shop *p2=NULL; 
	    p1=(struct shop *)malloc(SHOP);   //����ռ� 
		if(!p1)
	    {
	    	printf("�����ڴ治���ʧ���ˣ�");
		    return shophead;
	    }  //�����ڴ�ʧ�� 
	    p1->next=NULL;
	    printf("��������̵��й���Ϣ\n");   //���������Ϣ 
    	printf("����������̵ı�ţ�");
	    scanf("%d",&p1->number) ;
	    printf("����������̵����ƣ�");
	    scanf("%s",p1->name) ;
	    printf("����������̱��µĽ�������");
	    scanf("%d",&p1->stock) ;
	    printf("����������̵Ľ�����");
		scanf("%lf",&p1->cost);
	    printf("����������̱��µ��ۻ�����"); 
	    scanf("%d",&p1->sale) ;
	    printf("�����������Ŀǰ�������");
	    scanf("%d",&p1->left); 
	    printf("����������̵Ŀ���");
		scanf("%lf",&p1->money);
	    printf("����������̱��µ�����");
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
		printf("��������������ӵ�����Ϣ��(Y/N)");
		scanf(" %c",&c);
	}   
	printf("%d �����̵���Ϣ�Ѿ�¼���\n",a);   //��ʱ�����û���Ϣ¼�����
	return shophead;
}
void shop_sum(struct shop *head)   //ͳ�Ƶ����й���Ϣ 
{
	int a=0,b=0;   //ͳ�Ƶ��̽������Լ��ۻ��� 
	double c=0,d=0;    //ͳ�Ƶ��̵������Լ�������� 
	struct shop *p=NULL;
	for(p=head;p;p=p->next)   
	{
		a+=p->stock;
		b+=p->sale;
		c+=p->benefit; 
		d+=p->cost; 
	}
	printf("����ͳ�ƺ󣬿�֪��\n");    //��ʾͳ����� 
	printf("1�����̽�������Ϊ��%d\n",a);
	printf("2�����̽������Ϊ��%g\n",d);
	printf("3�������ۻ�����Ϊ��%d\n",b);
	printf("4������������Ϊ��%g\n",c); 
}
void print_shop(struct shop * shophead)  //���������Ϣ 
{
	if(!shophead)   //������û�п�����ĵ�����Ϣ��Ӧ�˳� 
	{
		printf("��Ǹ��û�п�����ĵ�����Ϣ��");
		return ; 
	}
	struct shop *p=NULL;
	printf("���̱��  ��������  ������  �������  �ۻ���  �����  �����  ��������\n");
	for(p=shophead;p;p=p->next)
	{
	  printf("%6d  %8s  %7d  %6g  %6d  %6d  %6g  %8g\n",p->number,p->name,p->stock,p->cost,p->sale,p->left,p->money,p->benefit);
	}
}
void searchshop(struct shop *shophead) //��ѯָ�����̵���Ϣ 
{
	if(!shophead)  //�������޿ɲ�ѯ�ĵ�����Ϣ 
	{
		printf("û�е�����Ϣ�ɹ���ѯ");
		return  ;
	}
	int a;
	char c;
	struct shop *p=NULL;
	printf("�������Ƿ���Ҫ��ѯ������Ϣ��(Y/y)"); 
	scanf(" %c",&c);
	for(;c=='y'||c=='Y';)
    {
	   printf("������õ��̵ı�ţ�");
	   scanf("%d",&a);
	   for(p=shophead;p;p=p->next)  //���ݱ���ҵ�����Ϣ 
	   {
	   	 if(a==p->number)
	     {
	     printf("����ѯ�ĵ�����Ϣ���£�\n");
		 printf("���̱��  ��������  ������  �������  �ۻ���  �����  �����  ��������\n");
	     printf("%6d  %8s  %7d  %6g  %6d  %6d  %6g  %8g\n",p->number,p->name,p->stock,p->cost,p->sale,p->left,p->money,p->benefit); 	
	     break;
	     } 
	   }
	    if(p==NULL)
	    {
	    	printf("û���ҵ��õ��̵��й���Ϣ,��ȷ�ϱ���Ƿ���ȷ��\n");
    	} 
	    printf("�������Ƿ���Ҫ������ѯ������Ϣ��(Y/y)");
	    scanf(" %c",&c);
	}
}
void sort_shop(struct shop *head) //ѡ�����򷨣����ý������ķ�ʽ���� 
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
	printf("�����ĵ������Ϊ��\n");
	print_shop(a);
    printf("����ҵ����ѵĵ���Ϊ%d�ŵ���\n",b->number); 
}
struct shop *Deleteshop (struct shop * head) //ɾ��ָ�����̵���Ϣ 
{
	if(!head) //����Ϊ�գ��޿ɱ�ɾ���ĵ�����Ϣ 
	{
		printf("��Ǹ����û�п���ɾ���ĵ�����Ϣ\n");
		return head;
    }
	char c;
	int a,b;
	printf("��������ɾ��������Ϣ�𣿣�Y/N��");
	scanf(" %c",&c);
    for(b=0;c=='Y'||c=='y';b++) 
	{ 
		struct shop *p=NULL;
	    struct shop *q=NULL;
	    printf("������������ɾ���ĵ��̵ı��:");
	    scanf("%d",&a);
	    for(p=head;p;q=p,p=p->next)//Ѱ��ָ�������������е�λ�� 
		{
			if(a==p->number)
	        {
	         	if(q!=NULL) q->next=p->next;
	            else        head=p->next;
		        free(p);    //�ͷŸÿռ� 
		        printf("�õ��̵���Ϣɾ���ɹ���\n");
		        break;
	        } 
		}  
	    if(p==NULL)
	    {
		    printf("û���ҵ�������ɾ���ĵ���\n"); 
		    b--;
	    }
	    printf("�������������ɾ��������Ϣ�𣿣�Y/N��");
	    scanf(" %c",&c);
	}
	printf("%d�����̵���Ϣ�Ѿ�ɾ���ɹ�\n",b);   //��ʱ�����û�ɾ����� 
	return head;
}
struct shop *modifyshop(struct shop *head) //�޸�ָ�����̵���Ϣ 
{
	if(!head)
	{
		printf("û�е�����Ϣ�ɹ��޸�");
		return head;
	}
	int a,b;
	char c;
	printf("���������޸ĵ�����Ϣ��(Y/N)��");
	scanf(" %c",&c);
	for(a=0;c=='Y'||c=='y';a++)
	{
	   struct shop *p=NULL;
	   printf("������õ��̵ı�ţ�");
	   scanf("%d",&b);
	   for(p=head;p;p=p->next) //�ҵ�ָ���������޸� 
	   {
	   	   if(b==p->number)
	       {
	        printf("����������µ���Ϣ\n");
	        printf("����������̵ı�ţ�");
	        scanf("%d",&p->number) ;
	        printf("����������̵����ƣ�");
	        scanf("%s",p->name) ;
	        printf("����������̱��µĽ�������");
	        scanf("%d",&p->stock) ;
	        printf("����������̵Ľ�����");
	        scanf("%lf",&p->cost);
	        printf("����������̱��µ��ۻ�����"); 
	        scanf("%d",&p->sale) ;
	        printf("�����������Ŀǰ�������");
	        scanf("%d",&p->left); 
	        printf("����������̵Ŀ���");
		    scanf("%lf",&p->money);
	        printf("����������̱��µ�����");
	        scanf("%lf",&p->benefit);
	        break;
	       } 
        }
       if(p==NULL)
	   {
	   	 printf("δ��ѯ���������޸ĵĵ��̣��������Ƿ�������ȷ��\n");
	   	 a--;
	   }
	   printf("������������޸ĵ�����Ϣ��(Y/N)");
	   scanf(" %c",&c);
	} 
	printf("%d�����̵���Ϣ�Ѿ��޸ĳɹ���\n",a);
	return head; 
}
void save_shop (struct shop * head) //���������Ϣ 
{
	struct shop * p=NULL;
	FILE *fp;
	if(!head) 
	{
		printf("û�е�����Ϣ�ɹ�����\n");
		return ;
	}
	if((fp=fopen("C:\\shop.txt","wb"))==NULL)
	{
		printf("�򲻿�������Ϣ�ļ�\n");
		return ;
	}
	for(p=head;p;p=p->next)
	{
		fwrite(p,SHOP,1,fp);
	}
	fclose(fp);
	printf("���е�����Ϣ�ѳɹ������ļ���\n");
}
struct shop *open_shop(struct shop *head)
{
	FILE *fp;
	struct shop *p,*q;
	if((fp=fopen("C:\\shop.txt","rb"))==NULL)
	{
		printf("�򲻿�������Ϣ�ļ���\n");
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
	printf("��ȡ������Ϣ�ļ��ɹ�\n");
	return head;
}
