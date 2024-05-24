#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void){
	int ret,err,s,fd;
	printf("Main process(Parent) started !!\n");

	ret = fork();
	if(ret == 0){
		fd = open("in.txt",O_RDONLY);
		close(0);
		dup(fd);
		close(fd);
		err = execlp("wc","wc",NULL);
		if(err < 0){
			perror("exec() failed");
			_exit(1);
		}
	}
	else
		waitpid(-1,&s,0);

	printf("Main process(Parent) completed !!\n");
	return 0;
}
