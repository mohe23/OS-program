#include<stdio.h>

typedef struct {
      char  name;   //���̱�ʶ��
      int comet;       //���̵���ʱ��
      char state;       //����״̬
      struct node*next;
 }node;


 node* makenode(char Nname,int Ncomet,char Nstate)//�����ڵ�
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->name=Nname;
	newnode->comet=Ncomet;
	newnode->state=Nstate;
	newnode->next=NULL;
	return newnode;
 }


void addrlist(node *Lru,int i,node *Lr,int cal)//�����������ڵ�
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
