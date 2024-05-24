#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

// step1: implement SIGINT handler
void sigint_handler(int sig)
{
	printf("SIGNINT : %d\n", sig);
}


int main()
{
	char cmd[512], *ptr, *args[32];
	int i, ret, err, s;

	signal(SIGINT, sigint_handler);

	while(1)
	{
		printf("cmd> ");
		gets(cmd);
		i=0;
		ptr = strtok(cmd, " ");
		args[i] = ptr;
		i++;
		//1	printf("first token: %s\n", ptr);
		do
		{
			ptr = strtok(NULL, " ");
			args[i] = ptr;
			i++;
			//1		printf("subseq token: %s\n", ptr);
		}while(ptr != NULL);

		//1	for(i=0; args[i]!=NULL; i++)
		//1		puts(args[i]);

		if(strcmp(args[0], "exit") == 0)
			break; // internal cmd 1 --exit

		else if(strcmp(args[0], "cd") == 0)
			chdir(args[1]); // internal cmd 2 -- cd


		else
		{
			// external cmd
			ret = fork();
			if(ret == 0)
			{
				err = execvp(args[0],args);
				if(err < 0)
				{
					perror("bad command");
					_exit(1);
				}
			}
			else
				wait(&s);
		}
	}
	printf("bye!\n");
	return 0;
}
