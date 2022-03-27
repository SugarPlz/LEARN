#include"ch11.h"
int main()
{
	pid_t pid1;
	pid1=fork();
	if(pid1<0)
	{
		perror("fork pid error!\n");
		exit(-1);
	}else if(pid1==0)
	{
		
		printf("child1=%d,ppid=%d\n",getpid(),getpid());
		exit(0);
	}else
	{
		int pid2;
		pid2=fork();
		if(pid2<0)
		{
			perror("pid2 fork failed!\n");
			exit(-1);
		}else if (pid2==0)
		{
			printf("child2:%d,ppid=%d\n",getpid(),getppid());
			exit(0);

		}else
		{
			
			int s1,r1,s2,r2;
			r1=wait(&s1);
			r2=wait(&s2);
			if(r1==pid1)		
			{
				printf("parent wait for child1 %d : exit code %d\n",r1,WEXITSTATUS(s1));
			}
			else
			{
				printf("parent wait for child2 %d : exit code %d\n",r1,WEXITSTATUS(s1));
			}

			if(r2==pid1)
			{		
				printf("parent wait for child1 %d : exit code %d\n",r2,WEXITSTATUS(s1));
			}
			else
			{
				printf("parent wait for child2 %d : exit code %d\n",r2,WEXITSTATUS(s2));
			}
			return 0;
		}
	}
}
