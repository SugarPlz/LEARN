#include"./ch10.h"
int main()
{
	int r1,r2,r3,r11;
	r1=fork();
	
	if(r1<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}

	else if (r1==0)
	{
		
		r11=fork();
		if(r11<0)
		{
			perror("r11 fork failed!\n");
			exit(-1);
		}else if (r11==0)
		{
			printf("child 11: pid=%d,ppid=%d\n",getpid(),getppid());
			exit(0);

		}else
		{
			wait(NULL);
			printf("parent :pid =%d,r11=%d\n",getpid(),r11);
			return 0;

		}
		printf("child 1: pid=%d,ppid=%d\n",getpid(),getppid());
		exit(0);
	}

	else
	{
		r2=fork();
		if(r2<0)
		{
			perror("fork failed!\n");
			exit(-1);
		}
		else if(r2==0)
		{	
			printf("child 2: pid=%d,ppid=%d\n",getpid(),getppid());
			exit(0);
		}
		else
		{
			
			r3=fork();
			if(r3<0)
			{
				perror("fork failed!\n");
				exit(-1);
			}
			else if(r3==0)
			{	
				printf("child 3: pid=%d,ppid=%d\n",getpid(),getppid());
				exit(0);
			}
			else
			{
				wait(NULL);
				wait(NULL);
				wait(NULL);
				printf("parent :pid =%d,r1=%d r2=%d r3=%d\n",getpid(),r1,r2,r3);
				return 0;
			}

		}
				
		
	}

	
}
