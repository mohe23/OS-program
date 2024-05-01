#include<stdio.h>

typedef struct {
      char  name;   //进程标识符
      int comet;       //进程到来时间
      char state;       //进程状态
      struct node*next;
 }node;


 node* makenode(char Nname,int Ncomet,char Nstate)//创建节点
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->name=Nname;
	newnode->comet=Ncomet;
	newnode->state=Nstate;
	newnode->next=NULL;
	return newnode;
 }


void addrlist(node *Lru,int i,node *Lr,int cal)//运行链表插入节点
{
    int j=0;
    cal=0;
    if(Lru->next==NULL)
    {
        Lru->next= Lr;
    }
    node* p=makenode(NULL,NULL,NULL);
     p=Lru;
     while(j<i-1)
     {
         p=p->next;
         ++j;
     }
     Lr->next=p->next;
     p->next=Lr;

     cal=cal+1;
}

int main()
{
    int cal;
  node *LR1=makenode("0","0","0");
  node *LR2=makenode("a","1","r");
  node *LR3=makenode("b","2","r");
  addrlist(LR1,"1",LR2,cal);
  addrlist(LR1,"2",LR3,cal);
  node *p=makenode(NULL,NULL,NULL);
     p=LR1->next;
   for(int k=0;k<cal;k++)
     {
       printf("%c",p->name);
       printf("\n");
        printf("%d",p->comet);
       printf("\n");
        printf("%c",p->state);
       printf("\n");

       p=p->next;
       }
       return 0;
  }
