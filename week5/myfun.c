#include"my.h"

void MyInput(void)
{
    struct USER user;
    printf("input user as "001 Jerry 87695 19970499263"\n");
    scanf("%d%s%s%s",&user.id,user.name,user.htel,user.tel);
    MyRanddat(user);
    MySave(user);

}

void MySave(struct USER user)
{
    FILE *stream;
    stream=fopen("user.dat","a");
    char str[40]="";
    sprintf(str,"%d",user.id);
    strcat(str,"\t");
    strcat(str,user.name);
    strcat(str,"\t");
    strcat(str,user.htel);
    strcat(str,"\t");
    strcat(str,user.tel);
    strcat(str,"\n");
    
    fputs(str,stream);
    fclose(stream);
    
    MyOutput(user);

}


int MyCmp(const void *a,const void *b)
{
    int i=0;
    char *stra=((struct USER*)a)->name;
    char *strb=((struct USER*)b)->name;
    while(stra[i]!='\0'&&strb[i]!='\0')
    {
        if(stra[i]>strb[i])
        {
            return 1;
        }
        if(stra[i]<strb[i])
        {
            return -1;
        }
        i++;
    }
    if(stra[i]=='\0'&&strb[i]=='\0') 
	return 0;
    if(stra[i]=='\0'&&strb[i]!='\0') 
	return -1;
    if(stra[i]!='\0'&&strb[i]=='\0') 
	return 1;
}

void MySort(int num)
{
    FILE *stream=fopen("user.dat","r");
    //测有多少条数据
    int sum=0;
    char c=fgetc(stream);
    while(!feof(stream))
    {
        if(c=='\n') sum++;
        c=fgetc(stream);
    }
    
    rewind(stream);
    
    //将数据读到数组中
    struct USER users[sum];
    int i=0;
    for(i=0;i<sum;i++)
    {
        char *str;
        size_t n=40;
        str=(char*)malloc(40);
        getline(&str,&n,stream); 
        sscanf(str,"%d %s %s %s",&users[i].id,users[i].name,users[i].htel,users[i].tel);
    }
    qsort(users,sum,sizeof(struct USER),MyCmp);
    if(num>0)
    {
        for(i=sum-1;i>=0;i--) MyOutput(users[i]);
    }else{
        for(i=0;i<sum;i++) MyOutput(users[i]);
    }
}

void MyRanddat(struct USER user)
{
    if(user.name[0]>'Z'||user.name[0]<'A')
        err_exit("The name must begin with a capital letter.");
    int i=0;
    while(user.name[i]!='\0')
    {
        i++;
        if(i>8) err_exit("The maximum number of names is 8.");
    }
}

void MyOutput(struct USER user)
{
    printf("%d\t%s\t%s\t%s\n",user.id,user.name,user.htel,user.tel);

}
