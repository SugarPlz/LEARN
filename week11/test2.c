#include"ch10.h"
int main()
{
	char *arg="ps -ef";
	system((const char *)arg);
	return 0;
}
