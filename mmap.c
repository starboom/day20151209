#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

struct student
{
	char name[20];
	int age;
	char sex[10];
	double score;
	
};
 typedef struct student stu;
#define SIZE sizeof(stu)
int main(int argc, char const *argv[])
{
	int fd;

	fd = open("/mnt/hgfs/linux_share/day20151209/stu1.txt",O_CREAT|O_EXCL|O_RDWR,0777);
	if(fd == -1)
	{
		perror("open file  :");
		_exit(-1);
	}

	printf("open file  ok!!\n");

/*
	       int ftruncate(int fd, off_t length);
*/

	int m = ftruncate(fd,3 * SIZE);
	if (-1 == m)
	{
		perror("file truncate :");
		_exit(-2);
	}
	printf("truncate ok!!\n");

	stu *p;

	p = mmap(NULL,3*SIZE,PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
	if((void*)-1 == (void*)p)
	{
		perror("mmap   :");
		_exit(-3);
	}
	printf("mmap ok!!\n");

	stu *pos;
	pos = p;

	strcpy(p -> name,"方振华");
	p -> age = 17;
	strcpy(p -> sex,"男");
	p -> score = 65.66;

	p++;

	strcpy(p -> name,"李浩敏");
	p -> age = 17;
	strcpy(p -> sex,"男");
	p -> score = 88.55;

	p++;

	strcpy(p -> name,"郭晓霞");
	p -> age = 17;
	strcpy(p -> sex,"女");
	p -> score = 72.85;

	 // int munmap(void *start, size_t length);

	int del_map = munmap(pos,3*SIZE);
	if(-1 == del_map)
	{
		perror("del_map : ");
		_exit(-4);
	}

	printf("munmap ok!!\n");
	p = NULL;
	pos = NULL;




	return 0; 
}


