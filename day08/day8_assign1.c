//1. From one parent create 5 child processes. Each child should run for 5 seconds and print count along with its pid. Parent should wait for all child processes
//   to complete and clean all of them. Hint: use loop to fork() multiple child processes.


#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int ret1, ret2, ret3, ret4, ret5, i, s;

	ret1 = fork();
	if(ret1 == 0)
	{
		//child 1
		for(i=1; i<=5; i++)
		{
			printf("child_1: %d\n", i);
			printf("pid : %d\n",getpid());
			sleep(1);
		}
		_exit(0);
	}

	ret2 = fork();
	if(ret2 == 0)
	{
		// child 2
		for(i=1; i<=5; i++)
		{
			printf("child_2: %d\n", i);
			printf("pid : %d\n",getpid());
			sleep(1);
		}
		_exit(0);
	}

	ret3 = fork();
	if(ret3 == 0)
	{
		// child 3
		for(i=1; i<=5; i++)
		{
			printf("child_3: %d\n", i);
			printf("pid : %d\n",getpid());
			sleep(1);
		}
		_exit(0);
	}


	ret4 = fork();
	if(ret4 == 0)
	{
		//child 4
		for(i=1; i<=5; i++)
		{
			printf("child_4: %d\n", i);
			printf("pid : %d\n",getpid());
			sleep(1);
		}
			sleep(1);
		}
		_exit(0);
	}

	ret5 = fork();
	if(ret5 == 0)
	{
		//child 5
		for(i=1; i<=5; i++)
		{
			printf("child_5: %d\n", i);
			printf("pid : %d\n",getpid());
			sleep(1);
		}
		_exit(0);
	}
	// parent
//	else
//	{	for(i=1; i<=10; i++)
//		{
//			printf("parent: %d\n", i);
//			sleep(1);
//		}
//	}

		for(int j=1; j<=3; j++)
		{	
			int child_pid;
			child_pid = wait(&s);
			printf("chid_%d exit: %d\n",j,WEXITSTATUS(s));
		}
	return 0;
}

