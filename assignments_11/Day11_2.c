#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main(void){
	int par[2],s,chd[2],ret,num1,num2,res,n1,n2,r;
	ret = pipe(par);
	ret = pipe(chd);
	ret = fork();
	if(ret == 0){
		close(par[1]);
		close(chd[0]);
		printf("Enter two numbers : ");
		scanf("%d%d",&num1,&num2);
		write(chd[1],&num1,sizeof(num1));
		write(chd[1],&num2,sizeof(num2));
	
		read(par[0],&res,sizeof(res));
//		printf("Readed value is %d\n",res);
		printf("Addition of %d %d is %d\n",num1,num2,res);

		close(par[1]);
		close(chd[0]);
	}
	else{
		close(chd[1]);
		close(par[0]);
		read(chd[0],&n1,sizeof(int));
		read(chd[0],&n2,sizeof(int));
//		printf("Readed value is %d %d\n",n1,n2);
		r = n1 + n2;

		write(par[1],&r,sizeof(int));
		close(chd[0]);
		close(par[1]);
		waitpid(-1,&s,0);
	}
	close(chd[1]);
	close(chd[0]);
	close(par[1]);
	close(par[0]);
	return 0;

}
