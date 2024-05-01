#include<stdio.h>

  typedef struct node{
      char  name;   //进程标识符
      int comet;       //进程到来时间
      char state;       //进程状态
      struct node*next;
 };

 typedef struct
{
	node *head;//指向头节点
	int size;//节点个数
 } ReadyList;     //就绪链表

 typedef struct
{
	node *head;//指向头节点
	int size;//节点个数
 } RunList;     //运行链表

  typedef struct
{
	node *head;//指向头节点
	int size;//节点个数
 } BarrList;     //阻塞链表


void initReadyList(ReadyList*Lre)//初始化就绪链表
{
	Lre->head=NULL;
	Lre->size=0;
}

void initBarrList(BarrList*Lba)//初始化阻塞链表
{
	Lba->head=NULL;
	Lba->size=0;
}

void initRunList(RunList*Lru)//初始化运行链表
{
	Lru->head=NULL;
	Lru->size=0;
}

node* makenode(char Nname,int Ncomet,char Nstate)//创建节点
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->name=Nname;
	newnode->comet=Ncomet;
	newnode->state=Nstate;
	return newnode;
 }

void addrlist(RunList*Lru,int i,char Nname,int Ncomet,char Nstate)//运行链表插入节点
{
    int j=0;
    node*newnode=makenode(Nname,Ncomet,Nstate);
    if(Lru->head==NULL)
    {
        Lru->head->next=newcode;
        newcode->next=NULL;
    }

     node*p=makenode();
     p=Lru->head->next;
     while(p&&(j<i-1))
     {
         p=p->next;
         ++j;
     }
     newcode->next=p->next;
     p->next=newcode;

      Lru->size++;
}

