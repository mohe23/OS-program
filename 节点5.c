#include<stdio.h>
#include<stdlib.h>
 typedef struct {
      char  name;   //进程标识符
      int comet;       //进程到来时间
      char tate;       //进程状态
      struct node*next;
 }node;

 node* CreateNode(node *nenode,char a,int b,char c)
 {
   nenode=(node*)malloc(sizeof(node));
   nenode->name=a;
   nenode->comet=b;
   nenode->tate=c;
   return nenode;
    }

int main()
{
   node *D;
   char m='a';
   char n='r';
   int  q=1;
   D=CreateNode(D,m,q,n);
   printf("%c\n",D->name);
   printf("%d\n",D->comet);
   printf("%c\n",D->tate);
   return 0;
   }

