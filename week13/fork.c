#include <stdio.h>
#include <unistd.h>

int gval=10;

int main(int argc, char *argv[])
{
	pid_t pid;
	int lval=20;
	gval++, lval+=5;
	
// 현재 부모 프로세스에서 자식 프로세스 생성 똑같은 구조를 생성하지만 자식 프로/// 세스는 return 값이 0이고 부모 프로세스는 return 값이 0이 아님
	pid=fork();
	if(pid == 0) // if child process
		gval+=2, lval+=2;
	else
		gval-=2, lval-=2;

	if(pid==0)
		printf("child proc: [%d, %d] \n", gval, lval);
	else
		printf("Parent Proc: [%d, %d] \n", gval, lval);

	sleep(10);

	return 0;
}

