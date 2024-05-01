Page*ds=(Page*)malloc(sizeof(Page));
        ds=b->next;
        while(ds!=NULL)
        {
            printf("%d ",ds->num);
            ds=ds->next;
        }
        printf("\n");




        Page*bd=(Page*)malloc(sizeof(Page));
Page*be=(Page*)malloc(sizeof(Page));
Page*bf=(Page*)malloc(sizeof(Page));

bd=b->next;
be=a->next;
bf=b->next;
while(be!=NULL)
{
    printf("%d ",be->num);
    be=be->next;
}
printf("\n");


while(bf!=NULL)
{
    printf("%d ",bf->num);
    bf=bf->next;
}

printf("\n");

while(bd!=NULL)
{

    bd=lengths(a,f1,bd);
    printf("%d ",bd->length);
    bd=bd->next;
}

printf("\n");

int hg=Getnums(b);
printf("被替换的节点页号：");
printf("%d\n",hg);

b=Optfunc(a,f1,b,8,3);

bf=b->next;

while(bf!=NULL)
{
    printf("%d ",bf->num);
    bf=bf->next;
}


Page*b1=(Page*)malloc(sizeof(Page));
Page*b2=(Page*)malloc(sizeof(Page));
Page*b3=(Page*)malloc(sizeof(Page));

    b1->order=NULL;
    b1->num=2;
    b1->length=0;
    b1->next=b2;

    b2->order=NULL;
    b2->num=0;
    b2->length=0;
    b2->next=b3;

    b3->order=NULL;
    b3->num=3;
    b3->length=0;
    b3->next=NULL;


 a3=a->next;
while(a3!=NULL)
{
    printf("%d ",a3->num);
    a3=a3->next;
}
printf("\n");
a=AddNode(a,b,4);
a2=a->next;
while(a2!=NULL)
{
    printf("%d ",a2->num);
    a2=a2->next;
}



  Page*b1=(Page*)malloc(sizeof(Page));
Page*b2=(Page*)malloc(sizeof(Page));
Page*b3=(Page*)malloc(sizeof(Page));



    b->next=b1;

    b1->order=NULL;
    b1->num=2;
    b1->length=0;
    b1->next=b2;

    b2->order=NULL;
    b2->num=4;
    b2->length=0;
    b2->next=b3;

    b3->order=NULL;
    b3->num=3;
    b3->length=0;
    b3->next=NULL;


