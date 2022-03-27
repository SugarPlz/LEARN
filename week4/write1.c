#include"ch03.h"
#include<time.h>
int main()
{
	int n,i,fd;
	char buf;
	fd=open("./test.dat",O_CREAT|O_WRONLY,0644);
	for(i=0;i<2;i++)
	{
		srand(time(0));
		n=rand()%26;
		buf=(char)('a'+n);
		printf("Write2 :%c\n",buf);
		write(fd,&buf,1);
		sleep(30);
		
	}

	close(fd);
	
	
}
	
