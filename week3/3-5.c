#include"ch03.h"
int main()
{
	FILE *fp;
	char buf[80];
	int ret;
	memset(buf,0,sizeof(buf));
	if( (fp=fopen("test1.txt","w"))==NULL )
		perror("open failed\n");
	printf("Please input strings you want to store in file:\n");
	
	fgets(buf,sizeof(buf),stdin);
	printf("Content is %s.The size of stream is %ld bytes.\n",buf ,sizeof(buf));
	ret=fwrite(buf,4,sizeof(buf)/4,fp);
	printf("Actual writing number of item is %d\n",ret);
	fclose(fp);
	return 0;
}
	
