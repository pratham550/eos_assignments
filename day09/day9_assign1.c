#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int main()
{
	int pid, sig;

	printf("enter pid and signal number : ");
	scanf("%d %d",&pid, &sig);

	//kill(pid,sig);
	if(kill(pid,sig) == -1)
	{
		perror("kill");
		return 1;
	}

	return 0;
}
