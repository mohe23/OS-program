#include<stdio.h>

int*Tone(int*s,int*h,int*k,int p1,int p2)//���2�����Ϻϲ���Ĵ󼯺ϡ�
{
   int i,j,p,k1,k2;
   p=p1+p2;
   
   if(p1>=p2)//��Ԫ�ض�ļ��Ϸ��뵽Ԥ�ȹ���Ĵ󼯺��С�
   {
      for(i=0;i<p1;i++)
		  k[i]=s[i];

	  k1=p1;//��ʱ�ϲ������е�Ԫ����Ŀ��
	  k2=p2;
   }

   else
   {
      for(i=0;i<p2;i++)
		  k[i]=h[i];

	  k1=p2;//��ʱ�ϲ������е�Ԫ����Ŀ��
	  k2=p1;
   }


   for(i=k1,j=0;i<p,j<k2;i++,j++)//�������Ҫ�����������������Ҫ������ͬԪ�ػ�������
   {
     int key;
	 key=Pan()
   }
}

  int Pan(int*d,int l,int e)//�ж�����e�Ƿ��ڼ���d�У����ڣ�����0�����ڣ�����1��
  {
     int i,t=1;//t�Ƿ���ֵ�������жϽ����
	 for(i=0;i<l;i++)
	 {
	    if((d[i]-e)==0)//���d������һ��Ԫ��ֵ����e,����ѭ��������ֵΪ0��
		{
			t=0;
			break;
		}

	 }
    
	 return t;
  }


int main()
{
  int a[4],b[4],c[8];

}