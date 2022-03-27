#include<stdio.h>

int main()
{
	//unsigned char
	unsigned char uchar_max = ~(unsigned char)0;
	printf("unsigned char max = %u\n", uchar_max);
	
	//char
	char char_max = uchar_max >> 1;
	int char_min = ~(uchar_max >> 1);
	printf("char max = %d\n", char_max);
	printf("char min = %d\n", char_min);


	//unsigned short
	unsigned short ushort_max = ~(unsigned short)0;
	printf("unsigned short max = %u\n", ushort_max);
	
	//short
	short short_max = ushort_max >> 1;
	short short_min = ~(ushort_max >> 1);
	printf("short max = %d\n", short_max);
	printf("short min = %d\n", short_min);


	//unsigned int
	unsigned int uint_max = ~(unsigned int)0;
	printf("unsigned int max = %u\n", uint_max);
	
	//int
	int int_max = uint_max >> 1;
	int int_min = ~(uint_max >> 1);
	printf("int max = %d\n", int_max);
	printf("int min = %d\n", int_min);


	//unsigned long
	unsigned long ulong_max = ~(unsigned long)0;
	printf("unsigned long max = %lu\n", ulong_max);
	//long
	long long_max = ulong_max >> 1;
	long long_min = ~(ulong_max >> 1);
	printf("long max = %ld\n", long_max);
	printf("long min = %ld\n", long_min);

	
	//float
	printf("float: %ld\n", sizeof(float) * 8);
	
	//0 111 1111 1111 1111 1111 1111 1111 1111
	float float_max=-8.25;
	char *pf=(char*)&float_max;
 
	*pf=0xff;
	*(pf+1)=0xff;
	*(pf+2)=0x7f;
	*(pf+3)=0x7f;

	float  float_min = -float_max;
	printf("float max = %f\n", float_max);
	printf("float min = %f\n", float_min);

	//double
	printf("double: %ld\n", sizeof(double) * 8);
	//0 111 1111 1110 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 
    	double double_max = -6.25; 
    	char *pd = (char *)&double_max;
    	*pd = 0xff;
    	*(pd + 1) = 0xff;
    	*(pd + 2) = 0xff;
    	*(pd + 3) = 0xff;
    	*(pd + 4) = 0xff;
    	*(pd + 5) = 0xff;
    	*(pd + 6) = 0xef;
    	*(pd + 7) = 0x7f;

	double  double_min = -double_max;
	printf("double max = %lf\n", double_max);
	printf("double min = %lf\n", double_min);
	
}
