#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
	int pid;
	printf("Before calling Fork: \n");
	pid = fork();
	
	if(pid > 0)
	{
		sleep(3);
		printf("\nParent Process Id is: %d \nParent's Parent Process Id is: %d \nChild Process Id is: %d\n",getpid(),getppid(),pid);
	}
	else if(pid == 0)
	{
		printf("Child Process Id is: %d\nParent Process Id is: %d",getpid(),getppid());
	}
	else
	{
		printf("An Error Occured while calling fork().");
		exit(1);
	}
	printf("\nBoth processes continues here\n ");
	exit(0);
}
