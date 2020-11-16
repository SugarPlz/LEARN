#include"ch07.h"
static void set_env_string(void)
{	
	char test_env[]="Test_env=test";
	if(putenv(set_env)!=0)
	{	
		printf("putenv is failed!\n");

	}
	printf("1.The test_env=%s",getenv("set_env"));

}
static void show_env_string()
{	
	printf("2.The test_env=%s",getenv("set_env"));
}

int main()
{	

	static void set_env_string(void);
	static void show_env_string();
	return 0;
}
