#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int arr[2];
void sigint_handler(int sig)
{
	close(arr[1]);
	close(arr[0]);
	_exit(0);
}

int main()
{
	int ret,err;
	char ch = 'A';
	struct sigaction sa;
	ret = pipe(arr);
	err = sigaction(SIGINT, &sa, NULL);
	if(err<0)
	{
		perror("sigaction() is failed");
	}
	int count = 0;
	while(1)
	{
		write(arr[1], &ch, 1);
		count ++;
		printf("Bytes written : %d\n", count);
	}
	return 0;
}
