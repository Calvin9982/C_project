struct Good * Increase_good (struct Good * head) //������Ʒ����Ϣ 
{
	int a; 
	char c;
	printf("�������Ƿ���Ҫ¼����Ʒ��Ϣ����Y/N��");
	scanf(" %c",&c);
	for(a=0;c=='Y'||c=='y';a++)
	{
		struct Good *p=NULL;
	    struct Good *q=NULL;
		p=(struct Good *)malloc(GOOD);
		if(!p)       //������ʧ��Ӧ���˳� 
		{
			printf("¼����Ϣʧ��\n");
		    return head;
		}
		p->next=NULL;
		printf("���������Ʒ�������Ϣ\n");
		printf("�������볧�ҵı�ţ�");
		scanf("%d",&p->group_number);
		printf("�������볧�ҵ����ƣ�");
		scanf("%s",p->group_name) ;
		printf("����������Ʒ��ţ�");
	    scanf("%d",&p->number) ; 
	    printf("����������Ʒ���ƣ�");
	    scanf("%s",p->name); 
	    printf("����������Ʒ���أ�");
	    scanf("%s",p->place); 
	    printf("����������Ʒ���ࣺ");
	    scanf("%d",&p->kind); 
	    printf("����������Ʒ���ۣ�");
     	scanf("%lf",&p->cost);
    	printf("����������Ʒ�ۼۣ�");
	    scanf("%lf",&p->price);
	    printf("����������Ʒ������");
		scanf("%d",&p->sale_number);
		if(!head)
		{
			head=p;
		}
		else
		{
			for(q=head;q->next;q=q->next);
			q->next=p;
		} 
	   	printf("�������Ƿ���Ҫ����¼����Ʒ��Ϣ�أ���Y/N��");
	    scanf(" %c",&c);
	}
	printf("%d����Ʒ����Ϣ�Ѿ�¼��ɹ���\n",a);  //�������û���Ϣ�洢��� 
	return head;
}
void Show_Good(struct Good *head)   //��ʾ��������Ʒ����Ϣ 
{
	if(!head)  //���������ڿ����������Ʒ��Ϣ 
	{
		printf("û�пɹ��������Ʒ��Ϣ��");
		return ; 
	}
    struct Good *p=NULL;
    printf("  ���ұ��  ��������  ��Ʒ���  ��Ʒ����  ��Ʒ����  ��Ʒ����  ��Ʒ����  ��Ʒ�ۼ�  ��Ʒ����\n");
    for(p=head;p;p=p->next) //���������ע���ʽ 
    {
       printf("%8d  %10s  %8d  %8s  %8s   %6d   %6g   %6g    %6d\n",p->group_number,p->group_name,p->number,p->name,p->place,p->kind,p->cost,p->price,p->sale_number);
	}
}
void searchGood(struct Good *head)  //��ѯ��Ʒ��Ϣ�Ĺ��ܺ��� 
{
	if(!head)  //�������޿ɲ�ѯ����Ʒ��Ϣ 
	{
		printf("û����Ʒ��Ϣ�ɹ���ѯ");
		return ;
	}
	char c;
	int a;
	struct Good *p=NULL;
	printf("�������Ƿ���Ҫ��ѯ��Ʒ��Ϣ����Y/N��");
	scanf(" %c",&c);      
	for(;c=='Y'||c=='y';)
	{
	    printf("�����������ѯ����Ʒ�ı��:");       //���ݱ���ҵ�ָ����Ʒ 
	    scanf("%d",&a);
		for(p=head;p;p=p->next)
		{
			if(a==p->number)
	        {
			 printf("����Ʒ��Ϣ���£�\n");
	         printf("���ұ��  ��������  ��Ʒ���  ��Ʒ����  ��Ʒ����  ��Ʒ����  ��Ʒ����  ��Ʒ�ۼ�  ��Ʒ����\n");
		     printf("%8d  %8s  %8d  %8s  %8s   %6d   %6g   %6g    %6d\n",p->group_number,p->group_name,p->number,p->name,p->place,p->kind,p->cost,p->price,p->sale_number);
			 break;	
	        }
		} 
	    if(p==NULL) printf("û���ҵ�����Ʒ����Ϣ\n");     //δ�ҵ�ָ������Ʒ��Ϣ�������䲢������ 
		printf("�������������ѯ�𣿣�Y/N��");
		scanf(" %c",&c); 
	}
}
struct Good* Deletegood(struct Good *head)  //ɾ��ָ����Ʒ����Ϣ 
{
	if(!head)    //�������޿�ɾ������Ʒ��Ϣ 
	{
		printf("��Ǹ,û�пɹ�ɾ������Ʒ��Ϣ\n");
		return head;
	}
	int a,b;
	char c;
	printf("��������ɾ����Ʒ��Ϣ�𣿣�Y/N��");
	scanf(" %c",&c);
	for(a=0;c=='Y'||c=='y';a++)
	{
	   struct Good *p=NULL;
	   struct Good *q=NULL;
	   printf("������������ɾ������Ʒ�ı��:");    //������Ʒ����ҵ���Ҫɾ������Ʒ 
	   scanf("%d",&b);
	    for(p=head;p;q=p,p=p->next)
	    {
	   	    if(b==p->number)
	        {
	         	if(q!=NULL) q->next=p->next;
	            else        head=p->next;
		        free(p);    //�ͷŸÿռ� 
		        printf("����Ʒ����Ϣɾ���ɹ���\n");
		        break;
	        } 
	    }  
	    if(p==NULL)                //δ�ҵ�ָ����Ʒ�������䲻�����޷�ɾ�� 
	    {
		 printf("û���ҵ�������ɾ������Ʒ\n"); 
		 a--;
	    }
	    printf("�������������ɾ����Ʒ��Ϣ�𣿣�Y/N��");
	    scanf(" %c",&c);
	}	
	printf("%d����Ʒ����Ϣ�Ѿ�ɾ���ɹ���\n",a);   //��ʱ�������û�ɾ�����
	return head;
}
struct Good * modifygood(struct Good *head)  //�޸���Ʒ����Ϣ 
{
	if(!head)           //�������޿������޸ĵ���Ʒ��Ϣ 
	{
		printf("û����Ʒ��Ϣ�ɹ��޸�\n");
		return head; 
	}
	char c;
	printf("���������޸���Ʒ��Ϣ��(Y/N)��");
	scanf(" %c",&c);
	int a,b;
	for(b=0;c=='Y'||c=='y';b++)
	{   
	    struct Good *p=NULL;
		printf("���������Ʒ�ı�ţ�");
		scanf("%d",&a);
	    for(p=head;p;p=p->next) //�ҵ�ָ����Ʒ��λ�� 
	    {
	    	if(a==p->number)   
	        {
	         printf("��������Ʒ������Ϣ\n");      //����Ʒ���е���Ϣ���������� 
	         printf("�������볧�ҵı�ţ�");
		     scanf("%d",&p->group_number);
		     printf("�������볧�ҵ����ƣ�");
		     scanf("%s",p->group_name) ;
		     printf("����������Ʒ��ţ�");
	         scanf("%d",&p->number) ; 
	         printf("����������Ʒ���ƣ�");
	         scanf("%s",p->name); 
	         printf("����������Ʒ���أ�");
	         scanf("%s",p->place); 
	         printf("����������Ʒ���ࣺ");
	         scanf("%d",&p->kind); 
	         printf("����������Ʒ���ۣ�");
     	     scanf("%lf",&p->cost);
    	     printf("����������Ʒ�ۼۣ�");
	         scanf("%lf",&p->price);
	         printf("����������Ʒ������");
		     scanf("%d",&p->sale_number); 
		     break;
	        }
		}
	    if(p==NULL)      //�Ҳ���ָ����Ʒ���޸� 
	    {
	    	printf("δ�鵽����Ʒ���޸�\n");
            b--;
		}
	    printf("������������޸���Ʒ��Ϣ��(Y/N)");
		scanf(" %c",&c); 
		getchar();
	} 
	printf("%d����Ʒ����Ϣ�Ѿ��޸ĳɹ�!\n",b);  //��ʱ������Ʒ�޸���Ϣ 
	return head; 
}
void sale_sum(struct Good * head) //ͳ����Ʒ����Ϣ 
{
	int a=0; //���������ܺ�  
	double b=0; //���۽���ܺ�  
	int c=0;  //��Ʒ�����ܺ�
	double d=0;  //��������ܺ� 
	struct Good *p=NULL;
	for(p=head;p;p=p->next)
	{
		a+=p->sale_number;
		b+=p->price;
		c++;
		d+=p->cost; 
	}
	printf("ͳ�����ݺ��֪��\n");       //ͳ���Ժ󽫽���������û� 
	printf("1������%d����Ʒ\n",c);
	printf("2����Ʒ�Ľ�������ܺ�Ϊ��%g\n",d);
	printf("3����Ʒ�����������ܺ�Ϊ��%d\n",a); 
	printf("4����Ʒ�����۽���ܺ�Ϊ��%g\n",b);
}
void storage_good (struct Good * head) //������Ʒ��Ϣ 
{
	if(!head) 
	{
		printf("û����Ʒ��Ϣ�ɹ�����\n");
		return ;
	}
	struct Good * p=NULL;
	FILE *fp;
	if((fp=fopen("C:\\good.txt","wb"))==NULL)
	{
		printf("���ܴ���Ʒ��Ϣ�ļ�\n");
		return ;
	}
	for(p=head;p;p=p->next)
	{
		fwrite(p,GOOD,1,fp);
	}
	fclose(fp);
	printf("������Ʒ��Ϣ�ѳɹ������ļ���\n");
}
struct Good *open_good(struct Good *head)
{
	FILE *fp;
	struct Good *p,*q;
	if((fp=fopen("C:\\good.txt","rb"))==NULL)
	{
		printf("�򲻿���Ʒ��Ϣ�ļ���\n");
		return head;
	}
    p=(struct Good *)malloc(GOOD);
	head=p;
	q=head;
	while(!feof(fp))
	{
		if(fread(p,GOOD,1,fp)!=1) break;
	    p->next=(struct Good *)malloc(GOOD);
        q=p->next;
        q=p;
        p=p->next;
	}
	q->next=NULL;
	fclose(fp);
	printf("��ȡ��Ʒ��Ϣ�ļ��ɹ�\n");
	return head;
}
