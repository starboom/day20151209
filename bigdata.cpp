#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAX_NUM 1024
#define _raise 1
long int my_atoi(char const *s)
{
	char  const *tmp = NULL;
	char c;
	long int i = 0;
	int n = 0;
	tmp = s;
	int len=strlen(tmp);
	for(n = 0;n <= len ;n++)
	{
		c = *tmp;
		if(c >= '0' && c <= '9')
		{
			i = (i * 10) + (c - '0');
		}
		else
			continue; //continue 遇到小数点。。。	
		tmp++; 
	}
	return i;
}
int main(int argc, char const *argv[])
{
	// int a;
	// int b;
	// scanf("%d",&a);
	// scanf("%d",&b);
	// printf("%d\n",a );
//	printf("%d\n",a + b );

// 	char *num1;

// 	gets(num1);
// 	int i;
// 	int num_convert;
// 	num_convert = atoi(num1);
// //12312132132132132132132

// 	printf("%d\n",num_convert );

	// num1 = NULL;

	char num1[MAX_NUM] = {0};
	char num2[MAX_NUM] = {0};
	int sum[MAX_NUM];
	gets(num1);
	int i;
	int len = strlen(num1) - 1;
//	cout << num1[1] << endl;

	// cout << len << endl;
	gets(num2);
//	cout << num2 << endl;
	sum[len] = ((num1[len] - '0') + (num2[len] - '0'));
	for(;len > 0;len--)
	{
		if(sum[len] < 10)
		{
			sum[len] = ((num1[len] - '0') + (num2[len] - '0'));			
		}
		// sum[len] = ((num1[len] - '0') + (num2[len] - '0'));
		if(sum[len] >= 10)
		{

			sum[len] = sum[len] - 10;
			sum[len-1] = ((num1[len-1] - '0') + (num2[len-1] - '0') + _raise );
		}
		else
		{
			sum[len] = ((num1[len] - '0') + (num2[len] - '0'));
			sum[len-1] = ((num1[len-1] - '0') + (num2[len-1] - '0'));
		}
	}
	// sum[1] = ((num1[1] - '0') + (num2[1] - '0'));

//	printf("%d\n",sum[1] );
	// if(sum[1] >= 10)
	// {
	// 	_raise = 1;
	// 	sum[1] = sum[1] - 10;
	// 	sum[0] = ((num1[0] - '0') + (num2[0] - '0') + _raise );

	// }

	// int m[5] = {1,2,3,4,5};
	// for(i = 0;i < 5;i++)
	// {
	// 	printf("%d",m[i] );
	// }
	for(i = 0;i < strlen(num1);i++)
	{
		 // printf("************\n");
		printf("%d",sum[i]);
	}
//	printf("%d%d%d",sum[0],sum[1],sum[2]);
	// cout << sum[1] << endl;
	// int len1;
	// len1 = strlen(num1);

	// int len2;
	// len2 = strlen(num2);

	
	// cout << len1 << endl;
	// cout << len2 << endl;
	return 0;
}