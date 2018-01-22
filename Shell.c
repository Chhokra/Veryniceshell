#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	char current;
	char command[1024];
	FILE *hp;
	hp = fopen("history.txt","a+");
	char currentdir[1024];
	char *dir;
	dir = getcwd(currentdir,1024);
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
			if(strncmp(command,"history -c",10)==0){
				hp = freopen("history.txt","w",hp);
				hp = freopen("history.txt","a+",hp);
			}
			else{
			int post = SEEK_CUR;
			fseek(hp,0,SEEK_SET);
		 	int travel;
		 	travel = fgetc(hp);
		 	while(travel!=-1){
		 		printf("%c", travel);
		 		travel = fgetc(hp);
		 	}

		 	fseek(hp,0,post);
			}
			

		}

		if(strncmp(command,"echo",4)==0){
				if(strncmp(command,"echo -e",7)==0){
					
				}
				int var = 1;
				if(strncmp(command,"echo -n",7)==0){
					var = 2;
				}
				char *p;
				p = strtok(command," ");
				int count = 1;
				while(p!=NULL){
					if(count>var){
						printf("%s ",p );

					}
					count++;
					p = strtok(NULL," ");

				}
				if(var!=2){
					printf("\n");
				}
				
			

		}
		if(strncmp(command,"pwd",3)==0){
			if(dir!=NULL){
				printf("%s\n", currentdir);
			}
		}

		



	}
	fclose(hp);
}

	

