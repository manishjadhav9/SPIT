#include <stdio.h>
#include <sys/wait.h>  
#include<unistd.h>

void printTree(int pid,int level){
	for(int i=0;i<level;i++){
		printf("\t");
	}
	printf("PID:%d\n",pid);
}

int main()
{
	int process=16;
	int level=0;
	pid_t parentpid=getpid();
	
	for(int i=0;i<process;i++){
		pid_t childpid=fork();
		
		if(childpid==0){
			level++;
			printTree(getpid(),level);
		}
		else if(childpid>0){
			wait(NULL);
			break;
		}
		else{
			printf("Fork failed.\n");
			return 1;
		}
	}
	
	if(getpid()==parentpid){
		for(int i=0;i<process;i++){
			wait(NULL);
		}
		printf("All processses created.\n");
	}
			
	return 0;
}
