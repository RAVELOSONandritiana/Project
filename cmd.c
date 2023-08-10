#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	while(1){
		char *cmd;
			cmd = (char *)malloc(50);
		printf("\e[31mCMD\e[0m # ");
		scanf("%s",cmd);
		int nombre = strcmp(cmd,"exit");
		if(nombre != 0)
			system(cmd);
		else
			exit(1);
	}
	return 0;
}
