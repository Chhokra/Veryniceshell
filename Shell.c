#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	int check = 1;
	char current;
	char command[1024];
	while(check){
		int size = 0;
		for(int i = 0;i<1024;i++){
			current = getchar();
			if(current=='\n'){
				command[size] = '\0';
				break;
			}
			else{
				command[size] = current;
				size++;
			}
		}
		if(strncmp(command,"cd",2) || strncmp(command,"echo",4) || strncmp(command,"history",7) || strncmp(command,"pwd",3) || strncmp(command,"exit",4)){
			system(command);
		}
		
		
	}

	
}