#include"ch10.h"
int main()
{
	pid_t pid;
	pid=vfork();
	//pid=fork();
	if(pid<0)
	{
		perror("fork failed\n");
		exit(-1);
	}
	else if(pid==0)
	{
		printf("10-6:pid=%d,ppid=%d\n",getpid(),getppid());
		execl("./test","./test","hello","world",NULL);
		printf("10-6 child ends!\n");
		exit(1);
		
	}
	else
	{	
		int r,s;
		r=wait(&s);
		printf("10-6: r=%d,status=%d\n",r,WEXITSTATUS(s));
		return 0;
	}

}
