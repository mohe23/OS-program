#include<stdio.h>
#include<stdlib.h>

typedef struct {
      char  name;   //������
      float runt;    //����ÿһ��ռ��CPU�ĵ���ʱ��
      float comet;       //����ԭʼ����ʱ��
    struct node*next;
 }node;


node* CreateNode(node *nenode)
 {
   char a;
   int c,i;
    float b;
   printf("�����ڵ�,����i:");//i=0�������սڵ㣻���򴴽������ݵĽڵ�
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
