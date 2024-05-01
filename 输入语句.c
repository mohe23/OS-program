#include<stdio.h>
#include<stdlib.h>

typedef struct {
      char  name;   //进程名
      float runt;    //进程每一次占用CPU的到来时间
      float comet;       //进程原始到来时间
    struct node*next;
 }node;


node* CreateNode(node *nenode)
 {
   char a;
   int c,i;
    float b;
   printf("创建节点,输入i:");//i=0，创建空节点；否则创建带数据的节点
   scanf("%d",&i);
    fflush(stdin);
   printf("\n");

   if(i==0)
   {
    nenode->name=NULL;
    nenode->comet=0;
   nenode->runt=0;

   }
   else{
        printf("name: ");
        scanf("%c",&(nenode->name));
        fflush(stdin);
        printf("\n");
        printf("comet: ");
        scanf("%f",&(nenode->comet));
        fflush(stdin);
        printf("\n");
        printf("runt: ");
        scanf("%f",&(nenode->runt));
        fflush(stdin);
          printf("\n");


      }
   nenode->next=NULL;
   return nenode;
 }

 int main()
 {
    node *l=(node*)malloc(sizeof(node));
    l=CreateNode(l);
    printf("%c\n",l->name);
     printf("%.2f\n",l->comet);
      printf("%.2f\n",l->runt);
      return 0;
 }
