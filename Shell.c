#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	char current;
	char command[1024];
	FILE *hp;
	hp = fopen("history.txt","a+");
	while(1){ 
		printf("veryniceshell>");
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
		
		fprintf(hp, "%s\n",command);
		if(strncmp(command,"exit",4)==0){
			break;
		}
		if(strncmp(command,"history",7)==0){
			

		}

	}
	fclose(hp);
}

	

