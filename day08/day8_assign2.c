//2. From a parent process (A) create a child process (B). The child (B) in turn creates new child process (C) and it (C) in turn create new child (D). All these
//processes should run concurrently for 5 seconds and cleaned up properly upon termination.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int ret, s;
	char i;

	for(i='B'; i<'E'; i++)
	{
		ret = fork();
		if(ret == 0)
		{
			for(int j =1; j<=5; j++)
			{
				//child
				printf("child_%c : %d\n",i,j);
				sleep(1);
			}
			_exit(0);
		}
	}


	//parent
	for(int j=1; j<=5; j++)
	{
		printf("Parent A: %d\n ",j);
		sleep(1);
	}

	for(i=0; i<3; i++)
	{
		waitpid(-1,&s,0);
		printf("child exit: %d\n",WEXITSTATUS(s));
	}
	return 0;
}
