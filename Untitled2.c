 while(s<4)
  {
      //printf("%d\n",a1->num);

    b=AddNode(b,a2,s);
     Prin(b);
    s=s+1;
    //printf("%d\n",s);
    a1=a1->next;//��Ȼ������a1��nextָ��������⡣
    a2=a1;
    a2->next=NULL;//printf("%c\n",a1->num);

    if(a1==NULL)
        printf("122334 \n");

  }
