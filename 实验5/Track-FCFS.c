
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int num;//磁道号
    int order;//磁道号请求的顺序，数字越小，请求得越早。
    int len;//移动到该磁道的距离。
    int length;//存储当前磁道号与其他磁道号相差的距离,初值为0，在先来先服务这个算法，没有用处。
    struct Track*next;
    }Track;

Track*CreateTrack(Track*a)//创建一个Track结点。
{
    int i;
   printf("创建的节点是空节点还是数据节点(空-i=0),i=");
    scanf("%d",&i);
    if(0==i)
    {
        a->num=-1;
        a->order=-1;
        a->len=-1;
        a->length=-1;
    }

    else
    {
        printf("num: ");
        scanf("%d",&(a->num));
        printf("order: ");
        scanf("%d",&(a->order));
        a->len=0;
        printf("len: 0\n");
        a->length=0;
        printf("length: 0\n\n");
    }
    a->next=NULL;
    return a;
}

Track*CreateTrackList(Track*a,int k)//创建一个长度为k的Track链表。
{
    int i;
    Track*r=(Track*)malloc(sizeof(Track));
    r=a;//指针r始终指向链表a的末尾节点。
    printf("创建链表：\n");
    for(i=0;i<k;i++)
    {
      Track*b=(Track*)malloc(sizeof(Track));
      b=CreateTrack(b);
      r->next=b;
      r=b;
    }

  return a;
}


Track*Getmint(Track*a)//返回链表a中请求时间最早的磁道号节点。用头结点a->num存放请求时间最早的磁道号节点在链表的序号(除去头结点)。
{
  Track*t=(Track*)malloc(sizeof(Track));//要返回的节点。
  Track*h1=(Track*)malloc(sizeof(Track));
  Track*h2=(Track*)malloc(sizeof(Track));
  Track*h3=(Track*)malloc(sizeof(Track));
  int j,i=1;
  int x=999;//存放当前请求时间最早的节点的order,初值置得很大，这样第一次循环，x中存放的是链表a的第一个节点的order值
  int m=0;//链表a中请求时间最早的节点在链表中的序号。
  h1=a->next;

  while(h1!=NULL)
  {


    if(x>h1->order)
    {
        x=h1->order;
        m=i;
    }

    else
    {
        x=x;
        m=m;
    }
    h1=h1->next;//下一个要处理的节点。
    i=i+1;//下一个节点在链表a的位置（第几个数据节点）。
  }

  h3=a->next;


  for(j=1;j<m;j++)
  {
    h3=h3->next;//获得当前链表a的请求最早的磁道号节点。

  }


  h2->num=h3->num;
  h2->order=h3->order;
  h2->len=h3->len;
  h2->length=h3->length;
  h2->next=NULL;
  a->num=m;

  return h2;
}

int Tlength(Track*a)//返回链表a除了头结点之外的节点数。
{
    int le=0;
    Track*h=(Track*)malloc(sizeof(Track));
    h=a->next;
    if(a->next==NULL)
        le=0;

    while(h!=NULL)
    {
        le=le+1;
        h=h->next;
    }
   return le;
}

Track* AddLast(Track*a,Track*b)//将磁道号节点b插入到链表a的尾部，返回为链表a的头结点。
{
   Track*h=(Track*)malloc(sizeof(Track));
   Track*h1=(Track*)malloc(sizeof(Track));
   Track*h2=(Track*)malloc(sizeof(Track));
   int i,lengtht;
   lengtht=Tlength(a);//链表a中数据节点数
  // printf("length: %d\n",lengtht);
    h=a;
   if(lengtht==0)
      a->next=b;
   else
   {
       for(i=0;i<lengtht;i++)
          h=h->next;//指向插入节点前链表a的最后一个结点。
       //printf("插入前链表a的最后一个结点: %d\n",h->num);

       h->next=b;

   }

    return a;
}

Track*DeleteTrack(Track*a,int t)//删除磁道号链表a的指定位置磁道号节点，返回的是链表a的头结点。
{
  int i;
  Track*h1=(Track*)malloc(sizeof(Track));
  Track*h2=(Track*)malloc(sizeof(Track));

  h1=a;
  for(i=1;i<t;i++)
    h1=h1->next;//待删除磁道号节点的前一个节点。
    h2=h1->next;//待删除磁道号节点。
    h1->next=h2->next;
    free(h2);

  return a;
}

Track*Getminl(Track*a,Track*b)//返回链表a中磁道号与b节点磁道号距离最小的磁道号节点。
{
  Track*h=(Track*)malloc(sizeof(Track));
  Track*h1=(Track*)malloc(sizeof(Track));
  Track*h2=(Track*)malloc(sizeof(Track));
  Track*h3=(Track*)malloc(sizeof(Track));
  h=a->next;
  h1=a->next;
  while(h!=NULL)
  {
    h->len=abs(h->num-b->num);//计算链表中的所有节点的磁道号与节点b磁道号的距离。
    h=h->next;
  }

  int i=1,j;//i是处理的当前节点在a链表中的序号
  int m;//存放距离节点b磁道号最近的磁道号。

  while(h1!=NULL)
  {
    if(1==i)
       {
         m=h1->len;
         j=1;
       }
    else
    {
        if(m>h1->len)//m值大于于结点的len值，则是将m更新为此节点的len值,j也更新（为当前节点在链表中的序号）
           {
              m=h1->len;
              j=i;
           }
        else
           {
              m=m;
              j=j;
           }
    }
    h1=h1->next;
    i=i+1;
  }
  h2=a->next;
  for(i=1;i<j;i++)
    h2=h2->next;

    h3->num=h2->num;
    h3->order=h2->order;
    h3->len=h2->len;
    h3->length=h2->length;
    h3->next=NULL;

       a->num=j;//也是用链表a的头结点的num值存放被选中的节点序号，以便于删除。
      return h3;

}

float Compute(Track*a)//计算平均寻道长度。
{
    Track*h=(Track*)malloc(sizeof(Track));
    float i=0;
    float sum=0,cd;
    h=a->next;
    while(h!=NULL)
    {
        sum=sum+(float)(h->len);
        i=i+1;
        h=h->next;
    }
   //printf("寻道总长度: %f\n",sum);
    cd=sum/i;
    return cd;
}


void Print(Track*a)
{
    Track*h=(Track*)malloc(sizeof(Track));
    h=a->next;
    printf("磁道号            请求时间            移动距离             距离2\n");
     while(h!=NULL)
     {
         if(h->num<10)
            printf("%-20d",h->num);
         else
            printf("%-20d",h->num);
         if(h->order<10)
            printf("%-20d",h->order);
         else
            printf("%-20d",h->order);
         printf("%-20d",h->len);
         printf("%-20d\n",h->length);
         h=h->next;
     }
     printf("\n");
}

int main()
{
  Track*a0=(Track*)malloc(sizeof(Track));
  Track*a1=(Track*)malloc(sizeof(Track));
  Track*a2=(Track*)malloc(sizeof(Track));
  Track*a3=(Track*)malloc(sizeof(Track));
  Track*a4=(Track*)malloc(sizeof(Track));
  Track*a5=(Track*)malloc(sizeof(Track));
  Track*a6=(Track*)malloc(sizeof(Track));
  Track*a7=(Track*)malloc(sizeof(Track));
  Track*a8=(Track*)malloc(sizeof(Track));
  Track*a9=(Track*)malloc(sizeof(Track));
  Track*a10=(Track*)malloc(sizeof(Track));
   Track*h=(Track*)malloc(sizeof(Track));
  Track*b=(Track*)malloc(sizeof(Track));
  Track*c=(Track*)malloc(sizeof(Track));
  Track*d=(Track*)malloc(sizeof(Track));
  Track*e=(Track*)malloc(sizeof(Track));
  Track*f=(Track*)malloc(sizeof(Track));
  c->num=0;
  c->order=0;
  c->length=0;
  c->next=NULL;



  a0->next=NULL;
  printf("输入数据节点：\n");
 a0=CreateTrackList(a0,10);

  a1->num=55;
  a1->order=12;
  a1->len=0;
  a1->length=0;
  a1->next=a2;

  a2->num=90;
  a2->order=32;
  a2->len=0;
  a2->length=0;
  a2->next=a3;

  a3->num=184;
  a3->order=89;
  a3->len=0;
  a3->length=0;
  a3->next=a5;

  a4->num=100;
  a4->order=8;
  a4->len=0;
  a4->length=0;
  a4->next=NULL;

  a5->num=160;
  a5->order=47;
  a5->len=0;
  a5->length=0;
  a5->next=a6;

  a6->num=18;
  a6->order=30;
  a6->len=0;
  a6->length=0;
  a6->next=a7;

  a7->num=38;
  a7->order=70;
  a7->len=0;
  a7->length=0;
  a7->next=a8;

  a8->num=58;
  a8->order=16;
  a8->len=0;
  a8->length=0;
  a8->next=a9;

  a9->num=150;
  a9->order=59;
  a9->len=0;
  a9->length=0;
  a9->next=a10;

  a10->num=39;
  a10->order=23;
  a10->len=0;
  a10->length=0;
  a10->next=NULL;

  printf("待处理的数据: \n");
  Print(a0);

   h=a0->next;
   Track*r=(Track*)malloc(sizeof(Track));
   f=r;
   while(h!=NULL)
   {
     Track*s=(Track*)malloc(sizeof(Track));
       s->num=h->num;
       s->order=h->order;
       s->len=h->len;
       s->length=h->length;
       s->next=NULL;
       r->next=s;
       r=s;
       h=h->next;
   }
int ds=100;
   float xz,xw;
    int l1=Tlength(a0);
    int l2=l1;

    while(l1!=0)
    {

       d=Getmint(a0);
       d->len=abs(ds - d->num);
        ds=d->num;//存放刚处理后的节点的磁道号。
       a0=DeleteTrack(a0,a0->num);
       c=AddLast(c,d);
       l1=Tlength(a0);

    }


  xw=Compute(c);
  printf("FCFS算法：\n");
  Print(c);
  printf("FCFS算法的平均寻道长度：");
  printf("%f\n",xw);
  printf("\n");

   e=a4;

 Track*c1=(Track*)malloc(sizeof(Track));
 Track*d1=(Track*)malloc(sizeof(Track));
 Track*e1=(Track*)malloc(sizeof(Track));
 e1=a4;
  while(l2!=0)
  {
    d1=Getminl(f,e1);//找到链表a中磁道号与节点e磁道号最小的节点。

    c1=AddLast(c1,d1);

    f=DeleteTrack(f,f->num);//删除链表a中找到的节点。
    e1=d1;

    l2=Tlength(f);


  }

  printf("最短寻道时间优先算法:\n");
  Print(c1);
  xz=Compute(c1);
  printf("最短寻道时间优先算法的平均寻道长度：");
  printf("%f\n",xz);

  return 0;
}
