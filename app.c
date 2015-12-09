// size 文件名
// 程序使用的内存 未初始化数据段
// 		已初始化数据段 全局区
// 		文本段 代码段
// 		堆
// 		栈
// 普通变量 main
// 只读普通变量 main const
// 静态普通变量 main static
// 自动分配内存 malloc 分配的是堆里面的内存

// 局部变量
// 只读局部变量
// 静态局部变量

// 全局变量
// 只读全局变量
// 静态全局变量

// ／proc／ 目录 pid getpid

// mem（物理内存，地址显示在这个文件） maps（虚拟内存，地址显示在这个文件）

// BSS			未初始化数据段        未初始化静态变量
// 代码区		只读全局变量          函数
// 全局区      全局变量              已初始化静态变量
// 堆          malloc
// 栈          普通变量              只读普通变量   局部变量

// 栈        从大地址开始分配        下 --->  上
// 堆        从小地址开始分配        上 --->  下


// C  中 手动分配
// 	malloc free
// 	free之后只是解除了内存分配的关系，地址里面存储的还是那个值。。。
// linux 里面的内存分配

// brk  sbrk
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int *p = (int*)sbrk(1024);
	int i;
	if((void*)-1 == (void*)p)
	
	{
	printf("sbrk error:m\n" );
	exit(-1);

	}
	printf("sbrk ok!!!\n");
	for(i = 10;i < 20 ;i++)
	{
		*p++ = i;
	}

	for(i = 0;i < 10;i++)
	{
		printf("%d\n",*p-- );
		printf("\n");
	}

	return 0;
}
/*
NAME
       brk, sbrk - change data segment size

SYNOPSIS
       #include <unistd.h>

       int brk(void *end_data_segment);

       void *sbrk(intptr_t increment);
       //linux建议内存按页分配 一页是 4K字节 为了方便
       //四个字节 四个字节 直接给4K   

   Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

       brk(), sbrk(): _BSD_SOURCE || _SVID_SOURCE || _XOPEN_SOURCE >= 500
DESCRIPTION
       brk() sets the end of the data segment to the value specified by end_data_seg-
       ment, when that value is reasonable, the system does have  enough  memory  and
       the process does not exceed its max data size (see setrlimit(2)).

       sbrk() increments the program’s data space by increment bytes.  sbrk() isn’t a
       system call, it is just a C library wrapper.  Calling sbrk() with an increment
       of 0 can be used to find the current location of the program break.

RETURN VALUE
       On success, brk() returns zero.  On error, -1 is returned, and errno is set to
       ENOMEM.  (But see Linux Notes below.)

       On success, sbrk() returns a pointer to the start of the new area.  On  error,
       -1 is returned, and errno is set to ENOMEM.

*/

















	
