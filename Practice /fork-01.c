#include<stdio.h>
#include<string.h>
#include<sys/types.h>

#define MAX_COUNT 10
#define BUF_SIZE 100

void main()
{
	pid_t pid;
	int i;
	char buf[BUF_SIZE];

	//fork();
	//	pid = getpid();
	pid = fork();	
	for(i=1;i<=MAX_COUNT;i++)
	{
		sprintf(buf,"This line is from pid %d , value =%d\n",pid,i);
		write(1,buf,strlen(buf));
	}	
}

/*

http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html

*/
