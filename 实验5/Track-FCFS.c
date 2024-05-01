
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int num;//�ŵ���
    int order;//�ŵ��������˳������ԽС�������Խ�硣
    int len;//�ƶ����ôŵ��ľ��롣
    int length;//�洢��ǰ�ŵ����������ŵ������ľ���,��ֵΪ0���������ȷ�������㷨��û���ô���
    struct Track*next;
    }Track;

Track*CreateTrack(Track*a)//����һ��Track��㡣
{
    int i;
   printf("�����Ľڵ��ǿսڵ㻹�����ݽڵ�(��-i=0),i=");
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

Track*CreateTrackList(Track*a,int k)//����һ������Ϊk��Track����
{
    int i;
    Track*r=(Track*)malloc(sizeof(Track));
    r=a;//ָ��rʼ��ָ������a��ĩβ�ڵ㡣
    printf("��������\n");
    for(i=0;i<k;i++)
    {
      Track*b=(Track*)malloc(sizeof(Track));
      b=CreateTrack(b);
      r->next=b;
      r=b;
    }

  return a;
}


Track*Getmint(Track*a)//��������a������ʱ������Ĵŵ��Žڵ㡣��ͷ���a->num�������ʱ������Ĵŵ��Žڵ�����������(��ȥͷ���)��
{
  Track*t=(Track*)malloc(sizeof(Track));//Ҫ���صĽڵ㡣
  Track*h1=(Track*)malloc(sizeof(Track));
  Track*h2=(Track*)malloc(sizeof(Track));
  Track*h3=(Track*)malloc(sizeof(Track));
  int j,i=1;
  int x=999;//��ŵ�ǰ����ʱ������Ľڵ��order,��ֵ�õúܴ�������һ��ѭ����x�д�ŵ�������a�ĵ�һ���ڵ��orderֵ
  int m=0;//����a������ʱ������Ľڵ��������е���š�
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
    h1=h1->next;//��һ��Ҫ����Ľڵ㡣
    i=i+1;//��һ���ڵ�������a��λ�ã��ڼ������ݽڵ㣩��
  }

  h3=a->next;


  for(j=1;j<m;j++)
  {
    h3=h3->next;//��õ�ǰ����a����������Ĵŵ��Žڵ㡣

  }


  h2->num=h3->num;
  h2->order=h3->order;
  h2->len=h3->len;
  h2->length=h3->length;
  h2->next=NULL;
  a->num=m;

  return h2;
}

int Tlength(Track*a)//��������a����ͷ���֮��Ľڵ�����
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

Track* AddLast(Track*a,Track*b)//���ŵ��Žڵ�b���뵽����a��β��������Ϊ����a��ͷ��㡣
{
   Track*h=(Track*)malloc(sizeof(Track));
   Track*h1=(Track*)malloc(sizeof(Track));
   Track*h2=(Track*)malloc(sizeof(Track));
   int i,lengtht;
   lengtht=Tlength(a);//����a�����ݽڵ���
  // printf("length: %d\n",lengtht);
    h=a;
   if(lengtht==0)
      a->next=b;
   else
   {
       for(i=0;i<lengtht;i++)
          h=h->next;//ָ�����ڵ�ǰ����a�����һ����㡣
       //printf("����ǰ����a�����һ�����: %d\n",h->num);

       h->next=b;

   }

    return a;
}

Track*DeleteTrack(Track*a,int t)//ɾ���ŵ�������a��ָ��λ�ôŵ��Žڵ㣬���ص�������a��ͷ��㡣
{
  int i;
  Track*h1=(Track*)malloc(sizeof(Track));
  Track*h2=(Track*)malloc(sizeof(Track));

  h1=a;
  for(i=1;i<t;i++)
    h1=h1->next;//��ɾ���ŵ��Žڵ��ǰһ���ڵ㡣
    h2=h1->next;//��ɾ���ŵ��Žڵ㡣
    h1->next=h2->next;
    free(h2);

  return a;
}

Track*Getminl(Track*a,Track*b)//��������a�дŵ�����b�ڵ�ŵ��ž�����С�Ĵŵ��Žڵ㡣
{
  Track*h=(Track*)malloc(sizeof(Track));
  Track*h1=(Track*)malloc(sizeof(Track));
  Track*h2=(Track*)malloc(sizeof(Track));
  Track*h3=(Track*)malloc(sizeof(Track));
  h=a->next;
  h1=a->next;
  while(h!=NULL)
  {
    h->len=abs(h->num-b->num);//���������е����нڵ�Ĵŵ�����ڵ�b�ŵ��ŵľ��롣
    h=h->next;
  }

  int i=1,j;//i�Ǵ���ĵ�ǰ�ڵ���a�����е����
  int m;//��ž���ڵ�b�ŵ�������Ĵŵ��š�

  while(h1!=NULL)
  {
    if(1==i)
       {
         m=h1->len;
         j=1;
       }
    else
    {
        if(m>h1->len)//mֵ�����ڽ���lenֵ�����ǽ�m����Ϊ�˽ڵ��lenֵ,jҲ���£�Ϊ��ǰ�ڵ��������е���ţ�
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

       a->num=j;//Ҳ��������a��ͷ����numֵ��ű�ѡ�еĽڵ���ţ��Ա���ɾ����
      return h3;

}

float Compute(Track*a)//����ƽ��Ѱ�����ȡ�
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
   //printf("Ѱ���ܳ���: %f\n",sum);
    cd=sum/i;
    return cd;
}


void Print(Track*a)
{
    Track*h=(Track*)malloc(sizeof(Track));
    h=a->next;
    printf("�ŵ���            ����ʱ��            �ƶ�����             ����2\n");
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
  printf("�������ݽڵ㣺\n");
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

  printf("�����������: \n");
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
        ds=d->num;//��Ÿմ����Ľڵ�Ĵŵ��š�
       a0=DeleteTrack(a0,a0->num);
       c=AddLast(c,d);
       l1=Tlength(a0);

    }


  xw=Compute(c);
  printf("FCFS�㷨��\n");
  Print(c);
  printf("FCFS�㷨��ƽ��Ѱ�����ȣ�");
  printf("%f\n",xw);
  printf("\n");

   e=a4;

 Track*c1=(Track*)malloc(sizeof(Track));
 Track*d1=(Track*)malloc(sizeof(Track));
 Track*e1=(Track*)malloc(sizeof(Track));
 e1=a4;
  while(l2!=0)
  {
    d1=Getminl(f,e1);//�ҵ�����a�дŵ�����ڵ�e�ŵ�����С�Ľڵ㡣

    c1=AddLast(c1,d1);

    f=DeleteTrack(f,f->num);//ɾ������a���ҵ��Ľڵ㡣
    e1=d1;

    l2=Tlength(f);


  }

  printf("���Ѱ��ʱ�������㷨:\n");
  Print(c1);
  xz=Compute(c1);
  printf("���Ѱ��ʱ�������㷨��ƽ��Ѱ�����ȣ�");
  printf("%f\n",xz);

  return 0;
}
