#include<stdio.h>

  typedef struct node{
      char  name;   //���̱�ʶ��
      int comet;       //���̵���ʱ��
      char state;       //����״̬
      struct node*next;
 };

 typedef struct
{
	node *head;//ָ��ͷ�ڵ�
	int size;//�ڵ����
 } ReadyList;     //��������

 typedef struct
{
	node *head;//ָ��ͷ�ڵ�
	int size;//�ڵ����
 } RunList;     //��������

  typedef struct
{
	node *head;//ָ��ͷ�ڵ�
	int size;//�ڵ����
 } BarrList;     //��������


void initReadyList(ReadyList*Lre)//��ʼ����������
{
	Lre->head=NULL;
	Lre->size=0;
}

void initBarrList(BarrList*Lba)//��ʼ����������
{
	Lba->head=NULL;
	Lba->size=0;
}

void initRunList(RunList*Lru)//��ʼ����������
{
	Lru->head=NULL;
	Lru->size=0;
}

node* makenode(char Nname,int Ncomet,char Nstate)//�����ڵ�
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->name=Nname;
	newnode->comet=Ncomet;
	newnode->state=Nstate;
	return newnode;
 }

void addrlist(RunList*Lru,int i,char Nname,int Ncomet,char Nstate)//�����������ڵ�
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

