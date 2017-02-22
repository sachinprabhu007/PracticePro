#include<stdio.h>
#include<sys/types.h>

#define MAX_COUNT 5

void ChildProcess();
void ParentProcess();

void main()
{
	pid_t pid;
	
	pid = fork();
	if(pid == 0)
		ChildProcess();
	else
		ParentProcess();
}


void ChildProcess()
{
	int i;
	
	for(i=1;i<=MAX_COUNT;i++)
		printf("This line is from the child,value = %d\n",i);
	printf("**** Child process is done ***\n");
}

void ParentProcess()
{
	int i;
		
	for(i=1;i<=MAX_COUNT;i++)
		printf("This line is from parent,value = %d\n",i);
	printf("****Parent is done****\n");
}

/*

http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html

*/
