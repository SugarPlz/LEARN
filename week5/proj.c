#include "myfun.c"
int main()
{

        printf("Do you want to add user? y/n\n");
        int c,ans;
        c=tolower(fgetc(stdin));
        ans=c;
        while(c !='\n' && c!=EOF)
            c=fgetc(stdin);
        if(ans=='y')
        {
            MyInput();
            do
            {
                getchar();
                fputs("continue? y/n\n",stdout);
                c=tolower(fgetc(stdin));
                ans=c;
                while(c !='\n' && c!=EOF)
                    c=fgetc(stdin);
                if(ans=='y')
			MyInput();

            }while(ans=='y');
        }

        //判断是否输出数据
        fputs("Show all users?y/n\n",stdout);
        c=tolower(fgetc(stdin));
        ans=c;
        while(c !='\n' && c!=EOF)
            c=fgetc(stdin);
        if(ans=='y')
        {
            fputs("Sort by letter from a to z? y/n\n",stdout);
            c=tolower(fgetc(stdin));
            ans=c;
            while(c !='\n' && c!=EOF)
                c=fgetc(stdin);
            if(ans=='y'){
                MySort(0);  
            }else{
                MySort(1);
            }
        }
        
    
    return 0;
}
