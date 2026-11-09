#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct computer)
void mainMenu()
{
    printf("          			 笔记本电脑销售管理系统菜单\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---信息展示                   2---插入功能\n");
	printf("\n");
	printf("             3---删除功能                   4---修改功能 \n");
	printf("\n");
	printf("             5---进销管理                   6---品牌查询\n");
	printf("\n");	
	printf("             7---进货提醒                   8---型号查询\n");
	printf("\n");				
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
}

struct computer
{	int brank; 			//品牌代号: 1-华硕；2-联想；3-惠普；4-戴尔。 
	int model;	    	//产品型号代号：1-高端机；2-普通机；3-低端机；	
	int bid;		   //进价	
	int num; 			//库存数量
	int output;			//销售数量	  	
	int price;		   //售价 
	int total;		   //总金额（销售数量*进价）
	struct computer *next;
};

/*函数声明*/ 
struct computer *creat();					//创建一个电脑信息链表 
void list(struct computer *head);	//输出电脑信息 
struct computer *insert(struct computer *head); //电脑信息插入操作，插入指令ch=y?n 
struct computer *del(struct computer *head, int a, int b); 	//删除电脑信息操作
struct computer *findbrank(struct computer *head,int l);    //输入牌代号l，查找相应的笔记本电脑信息并输出
struct computer *findmodel(struct computer *head,int l);    //输入型号代号l，查找相应的笔记本电脑信息并输出
void liststock(struct computer *head);  			//进货提醒
struct computer *manage(struct computer *head,int a,int b,int c,int d);
 //进出货管理 
  //a=1:进货  a=0:出货 b:进出货数量 c:品牌代号  d:型号代号 

int main()						//主函数！ 
{	struct computer *head,*p;
	int  a=1;					//插入字符标志 
	int  b=1;					//删除字符标志 
	int  c1=1,c2,c3;			//修改字符标志  //修改数据编号  //修改成为的数据 
	int  d1=1,d2=1;				//查询字符标志 	d1-品牌代号  d2-型号代号 
	int  f1,f2;				//进出货提示标志1/0  f1-进/出货  f2-进/出货数量	
	int brank1,model1;		//删除的产品品牌和型号代号-1
	int	brank2,model2;		//修改的产品品牌和型号代号-2 
	int	brank3,model3;		//查询的产品品牌和型号代号-3
	int	brank4,model4;		//进出货管理的产品品牌和型号代号-4
	head=creat(  );	
	while (1)
	{	mainMenu();
		printf("请输入你要选择的功能序号：");
		int ch;
		scanf("%d",&ch);
		if (ch == 1)
			list(head); 
			 
		if (ch == 2)
			{
			 while(a==1)
			 	{head=insert(head);
	 			 printf("继续插入电脑信息吗？(Yes=1/No=0):");
				 scanf("%d",&a);
				}
			 printf("插入电脑信息操作完成!\n");
			}

		
		if (ch == 3)
		{
			while(b==1)
				{ printf("请输入你要删除电脑信息的品牌和型号的数字代号:\n");
	 			  printf("并且再输出一个数字决定是否再次执行删除操作!(Yes=1/No=0):\n");
	 			  scanf("%d %d %d", &brank1,&model1,&b);
      			  head = del(head,brank1,model1);
				}
				printf("电脑信息删除已完成!\n");
		} 

		if (ch == 4)
				{
					while(c1==1)
						 {  printf("请输入你要修改电脑的品牌代号和型号代号:"); 
	   						scanf("%d %d",&brank2,&model2); 
	 						p=head; 
							while( ((p->brank!=brank2) || (p->model!=model2)) && (p->next!=NULL) )
								p=p->next;
	    			if( (p->brank==brank2) && (p->model==model2) )
		{
	   		  printf("请输入一个数字代号:1-进价.2-库存数量.3-售价:");
			  scanf("%d",&c2);
			  switch(c2)
			  { case 1 :
			  	{printf("请输入要更换的数:");
			  	 scanf("%d",&c3);
				 p->bid=c3; 
				 break;}
				 case 2 : 
				{printf("请输入要更换的数:");
			  	 scanf("%d",&c3);
				 p->num=c3; 
				 break;}
				 case 3 :
				 {printf("请输入要更换的数:");
			  	 scanf("%d",&c3);
				 p->price=c3; 
				 break;}
			  }
		}
				else
					 printf("没有该信息，无法修改！\n"); 
			
					 printf("是否继续修改文件(Yes=1/No=0):");
	 				 scanf("%d",&c1);		  
	 			} 
					 printf("电脑信息修改操作已完成!\n");
		}
		
		if (ch == 5)
		{	printf("进出货管理系统!进货请输入1,出货请输入0:");
			scanf("%d",&f1);
			switch(f1)
			{
				case 1 :
					{
						printf("请分别输入进货数量,品牌代号,型号代号:");
						scanf("%d %d %d",&f2,&brank4,&model4); 
						head=manage(head,1,f2,brank4,model4);
						break;
					}
				case 0 :
					{
						printf("请分别输入出货数量,品牌代号,型号代号:");
						scanf("%d %d %d",&f2,&brank4,&model4); 
						head=manage(head,0,f2,brank4,model4); 
						break;	
					}
			}
			
		}
		if (ch == 6)
		{
		while(d1==1)
		{	printf("请输入你要查询的电脑品牌代号");
			scanf("%d",&brank3);
			head=findbrank(head,brank3); 
	    	printf("是否继续查询信息(Yes=1/No=0):");
	    	scanf("%d",&d1);	
		}
		printf("品牌查询操作已完成!\n"); 
		 } 
		 
		if (ch== 7)
		{
		printf("执行进货提醒:\n"); 
		liststock(head);
		}
		
		if (ch == 8)
		{
		while(d2==1)
		{	printf("请输入你要查询的电脑型号代号");
			scanf("%d",&model3);
			head=findmodel(head,model3); 
	 	    printf("是否继续查询信息(Yes=1/No=0):");
	 	    scanf("%d",&d2);	
		}
		printf("型号查询操作已完成!\n"); 	
			
		}
	}
	return 0;
}
 
struct computer *creat() 	//创建一个电脑信息链表 
{
  struct computer *p1,*p2,*head=NULL;
  p1=p2=(struct computer *)malloc(LEN);
  printf("1.请分别输入笔记本电脑信息:1-品牌代号 2-产品型号代号 3-进价 4-库存数量 5-销售数量 6-售价.\n");
  printf("2.数据之间请用空格隔开!\n"); 
  printf("3.当输入产品型号代号为0时停止录入信息!\n");
  scanf("%d %d %d %d %d %d",&p1->brank,&p1->model,&p1->bid,&p1->num,&p1->output,&p1->price);
  while(p1->model!=0)
  {	if(head==NULL)
    	head=p1;
    else
     {p2->next=p1;
      p2=p1;
      p1=(struct computer *)malloc(LEN);
      scanf("%d %d %d %d %d %d",&p1->brank,&p1->model,&p1->bid,&p1->num,&p1->output,&p1->price);}
  }
    p2->next=NULL;
    free(p1);
    return (head);
} 

void list(struct computer *head) 		//输出电脑信息 
{ struct computer *p;
  if(head==NULL)
      printf("没有电脑信息.\n");
  else
  	  {printf("笔记本电脑信息如下:\n");
  	   p=head;		//head=p死循环
  	  while(p!=NULL)
  	    {p->total=p->output*p->price; 
  	     printf("************************\n");
		 printf("*   【品牌代号】:%d     *\n",p->brank);
	 	 printf("*  1.产品型号代号:%d    *\n",p->model); 
		 printf("*  2.进价:%d            *\n",p->bid); 
		 printf("*  3.库存数量:%d        *\n",p->num); 
		 printf("*  4.销售数量:%d        *\n",p->output); 
		 printf("*  5.售价:%d            *\n",p->price); 
		 printf("*  6.总金额:%d          *\n",p->total); 
		 printf("************************\n");
		 printf("\n");
  	     p=p->next;}
  	  }
}

struct computer *insert(struct computer *head)    //电脑信息插入操作，插入指令ch=y?n 
{	struct computer *p0,*p1,*p2;				//按品牌代号顺序插入 
 	p0=(struct computer*)malloc(LEN);
 	p0->next=NULL;
 	printf("请分别输入笔记本电脑信息:1.品牌代号 2.产品型号代号 3.进价 4.库存数量 5-销售数量 6.售价.\n") ;
	scanf("%d %d %d %d %d %d",&p0->brank,&p0->model,&p0->bid,&p0->num,&p0->output,&p0->price);
	getchar();
	if(head==NULL)
		head=p0;
 	else                          //链表不为空时，执行以下插入操作
         {p1=head;                   //p1 指向表头结点
            while ((p0->brank>p1->brank) && (p1->next!=NULL)) 
              {p2 = p1;       p1 = p1->next;}
            if ( p0->brank<=p1->brank )     
            { if ( head==p1)  
                     { head = p0; p0->next = p1; }    //插入表头结点
              else
                     { p2->next =p0; p0->next = p1; }  //插入中间结点
			}
              else   
			    	p1->next=p0;          //插入表尾结点
         }  
       return (head);
}

struct computer *del(struct computer *head, int a, int b) 	//删除电脑信息操作
{	struct computer *p1,*p2=NULL;							//a为品牌代号，b为型号代号 
	if(head==NULL)
		printf("电脑信息为空不能进行删除操作!\n");
	else
		{ p1=head;					 //p1指向表头结点
		  while( ((p1->brank!=a) || (p1->model!=b)) && (p1->next!=NULL) )
		   { p2=p1;					//p2指向p1所指向的结点
		     p1=p1->next;		 	//p1指向下一个结点
		   }
		   if((p1->brank==a)&&(p1->model==b))		//判断p1是否指向要删除的结点
		   	{   if(p1==head)
		   	   		head=p1->next;			//删除表头结点
			  
				else
			 		p2->next=p1->next;		//删除中间或表尾结点
			free(p1);					//释放已删除的结点空间
			printf("该电脑信息已删除!\n");
			}
		 	else
		 		printf("该数据不存在,不能删除!\n");      
		}	
		return (head);
} 

struct computer *findbrank(struct computer *head,int l)    //输入牌代号l，查找相应的笔记本电脑信息并输出
{	struct computer *p=NULL;
	int x=0;						//判断是否有该查询信息的标志！ 
	p=head;
	while(p!=NULL)
	 {	if(p->brank==l)
  	    {	p->total=p->output*p->price; 
  	     	printf("************************\n");
		 	printf("*   【品牌代号】:%d     *\n",p->brank);
	 		printf("*  1.产品型号代号:%d    *\n",p->model); 
			printf("*  2.进价:%d            *\n",p->bid); 
			printf("*  3.库存数量:%d        *\n",p->num);
		    printf("*  4.销售数量:%d        *\n",p->output);  
			printf("*  5.售价:%d            *\n",p->price); 
			printf("*  6.总金额:%d          *\n",p->total); 
			printf("************************\n");
			printf("\n");
			x++; 
  	    	p=p->next;
		}
		else
			p=p->next;
	}
	if(x==0)
	printf("信息不存在！\n");	
	return (head);	
} 
	
struct computer *findmodel(struct computer *head,int l)    //输入型号代号l，查找相应的笔记本电脑信息并输出
{	struct computer *p=NULL;
	int x=0;						//判断是否有该查询信息的标志！ 
	p=head;	
	while(p!=NULL)
	 {	if(p->brank==l)
  	    {	p->total=p->output*p->price; 
  	     	printf("************************\n");
		 	printf("*   【品牌代号】:%d     *\n",p->brank);
	 		printf("*  1.产品型号代号:%d    *\n",p->model); 
			printf("*  2.进价:%d            *\n",p->bid); 
			printf("*  3.库存数量:%d        *\n",p->num); 
	  	    printf("*  4.销售数量:%d        *\n",p->output); 
			printf("*  5.售价:%d            *\n",p->price); 
			printf("*  6.总金额:%d          *\n",p->total); 
			printf("************************\n");
			printf("\n");
			x++; 
  	    	p=p->next;
		}
		else
			p=p->next;
	}
	if(x==0)
	printf("信息不存在！\n");	
	return (head);	
} 
void liststock(struct computer *head)  			//进货提醒
{ struct computer *p;
  if(head==NULL)
      printf("没有电脑信息.\n");
  else	
	{ p=head;	
	  while(p!=NULL) 
  	 { 
    	if(p->num<=5)
  	    	{p->total = p->output * p->price; 
  	     	 printf("************************\n");
			 printf("*   【品牌代号】:%d     *\n",p->brank);
	 		 printf("*  1.产品型号代号:%d    *\n",p->model); 
			 printf("*  2.进价:%d            *\n",p->bid); 
			 printf("*  3.库存数量:%d        *\n",p->num); 
			 printf("*  4.销售数量:%d        *\n",p->output); 
			 printf("*  5.售价:%d            *\n",p->price); 
			 printf("*  6.总金额:%d          *\n",p->total); 
			 printf("************************\n");
			 printf("\n");
  	     	 p=p->next;}
  		else
			p=p->next;
		}
	}
}
	
struct computer *manage(struct computer *head,int a,int b,int c,int d)	 //进出货管理 
  //a=1:进货  a=0:出货 b:进出货数量 c:品牌代号  d:型号代号 
{	struct computer *p;
	if(head==NULL)
		printf("电脑信息为空不能进行存货管理操作!\n");
 	else
	{	if(a==1)
		{ p=head;					 //p指向表头结点
		  while( ((p->brank!=c) || (p->model!=d)) && (p->next!=NULL) )
		    p=p->next;		 	//p指向下一个结点
		   if( (p->brank==c) && (p->model==d) )		//判断p1是否指向要更改的结点
		   	    p->num = p->num + b;
		 	else
		 		printf("该数据不存在,不能更改!\n");      
		}	
		if(a==0)
		{ p=head;					 //p1指向表头结点
		  while( ((p->brank!=c) || (p->model!=d)) && (p->next!=NULL) )					
		     p=p->next;		 	//p1指向下一个结点
		   if( (p->brank==c) && (p->model==d) )		//判断p1是否指向要更改的结点
		   	   {p->num = p->num- b ;
		   	    p->output = p->output + b;}
		 	else
		 		printf("该数据不存在,不能更改!\n");      
		}	
	} 
} 

