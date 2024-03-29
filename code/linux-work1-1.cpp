#include <string.h>

#include <strings.h>

#include <stdio.h>

#include <stdlib.h>

#define BUFFER_SIZE 1024 

int main(int argc,char **argv) 

{ 

	FILE *from_fd;
	
	FILE *to_fd; 
	
	long file_len=0;
	
	char buffer[BUFFER_SIZE]; 
	
	char *ptr; 
	
	/*判断入参*/
	
	if(argc!=3) 
	{ 
	
		printf("Usage:%s fromfile tofile\n",argv[0]); 
		
		exit(1); 
	
	} 
/* 打开源文件 */ 

	if((from_fd=fopen(argv[1],"r"))==NULL) 	//from_fd,"r"
	{ 
	
		printf("Open %s Error\n",argv[1]); 
		
		exit(1); 		
	} 
/* 创建目的文件 */ 

	if((to_fd=fopen(argv[2],"wb"))==NULL) 	//to_fd,"w"
	{ 
	
		printf("Open %s Error\n",argv[2]); 
		
		exit(1); 	
	} 

/*测得文件大小*/

	fseek(from_fd,0L,SEEK_END);// from_fd ,0L ,SEEK_END
	
	file_len=ftell(from_fd);
	
	fseek(from_fd,0L,SEEK_SET);
	
	printf("from file size is=%d\n",file_len);

/*进行文件拷贝*/

	while(!feof(from_fd)) //from_fd
	{ 
		
		        /*从文件复制数据进入缓存*/
		
		fread(buffer,BUFFER_SIZE,1,from_fd);	//buffer,file_len,1,from_fd 
		if(BUFFER_SIZE>=file_len)		
		{
		   /*从缓存将数据写入文件*/		
			fwrite(buffer,BUFFER_SIZE,1,from_fd);	//buffer,file_len,1,to_fd
		}
		
		else 
		
		{
		
		fwrite(buffer,file_len,1,to_fd);// bufer,file_len,1,to_fd
		
		file_len=file_len-BUFFER_SIZE;
	}

//写入完成后清空缓冲区

	memset(buffer,0,BUFFER_SIZE);//buffer 0  BUFFER_SIZE

	} 

	fclose(from_fd); 
	
	fclose(to_fd); 
	
	exit(0); 

}
