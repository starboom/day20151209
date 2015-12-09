#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int a  = 3;
const int ca = 3;
static int sa = 3;

void func()
{
	int n2 = 100;
	const int cn2 = 200;

	static int sn2 = 300;

	printf("局部变量：%p\n",&n2 );

	printf("只读局部变量：%p\n",&cn2 );

	printf("静态局部变量：%p\n",&sn2 );

	// printf("局部变量：%p\n",&n2 );
}

int main(int argc, char const *argv[])
{
	int n1 = 10;
	const int cn1 = 20;
	static int sn1 = 30;

	int *p =(int*)malloc(sizeof(p));
	printf("普通变量：%p\n",&n1 );

	printf("只读普通变量：%p\n",&cn1 );

	printf("静态局部变量：%p\n",&sn1 );

	printf("动态分配内存：%p\n",p );

	func();

	printf("自定义函数:%p\n",func);

	printf("自定义函数:%p\n",main);	

	printf("当前静态程序的ID\n");

	while(1);
	return 0;
}