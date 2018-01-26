#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
	char current;
	char command[1024];
	FILE *hp;
	hp = fopen("history.txt","a+");
	char currentdir[1024];
	char *dir;
	dir = getcwd(currentdir,1024);
	char previousdir[1024];
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
		if(strncmp(command,"history",7)==0){ // options handled -c 
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

		if(strncmp(command,"echo",4)==0){ // options handled -n
				
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

		if(strncmp(command,"cd",2)==0){
				if(strncmp(command,"cd -",4)==0){
						int check1;
						if(previousdir!=NULL){
							check1 = chdir(previousdir);
						}
						strcpy(previousdir,currentdir);
						dir = getcwd(currentdir,1024);
				}
				else if(strncmp(command,"cd ~",4)==0){
					char *home = getenv("HOME");
					int check2 = chdir(home);
					if(check2!=0){
						dir = getcwd(currentdir,1024);
					}
					strcpy(previousdir,currentdir);
					dir = getcwd(currentdir,1024);

				}
				else{
				char *travel;
				travel = strtok(command," ");
				int count = 1;
				int check;
				strcpy(previousdir,currentdir);
				while(travel!=NULL){
					if(count==2){
						check = chdir(travel);
						break;
					}
					travel = strtok(NULL," ");
					count++;
				}
				if(check!=0){
					printf("Invalid directory\n");
				}

				dir = getcwd(currentdir,1024);
				}
				

		}

		if(strncmp(command,"ls",2)==0){
			if(fork()==0){
				char *henlo = strtok(command," \n");
				char *henlo2[1024];
				int counter = 0;
				while(henlo!=NULL){
					henlo2[counter] = henlo;
					henlo = strtok(NULL," \n");
					counter++;
				}
				henlo2[counter] = NULL;
				execv("/home/chhokra/Desktop/OSAssignment1/xls",henlo2);
			}
			else{
				wait(NULL);
			}

		}
		if(strncmp(command,"cat",3)==0){
			if(fork()==0){
				char *henlo = strtok(command," \n");
				char *henlo2[1024];
				int counter = 0;
				while(henlo!=NULL){
					henlo2[counter] = henlo;
					henlo = strtok(NULL," \n");
					counter++;
				}
				henlo2[counter] = NULL;
				execv("/home/chhokra/Desktop/OSAssignment1/xcat",henlo2);
			}
			else{
				wait(NULL);
			}

		}

		if(strncmp(command,"date",4)==0){
			if(fork()==0){
				char *henlo = strtok(command," \n");
				char *henlo2[1024];
				int counter = 0;
				while(henlo!=NULL){
					henlo2[counter] = henlo;
					henlo = strtok(NULL," \n");
					counter++;
				}
				henlo2[counter] = NULL;
				execv("/home/chhokra/Desktop/OSAssignment1/xdate",henlo2);
			}
			else{
				wait(NULL);
			}

		}

		if(strncmp(command,"rm",2)==0){
			if(fork()==0){
				char *henlo = strtok(command," \n");
				char *henlo2[1024];
				int counter = 0;
				while(henlo!=NULL){
					henlo2[counter] = henlo;
					henlo = strtok(NULL," \n");
					counter++;
				}
				henlo2[counter] = NULL;
				execv("/home/chhokra/Desktop/OSAssignment1/xrm",henlo2);
			}
			else{
				wait(NULL);
			}

		}

		if(strncmp(command,"mkdir",5)==0){
			if(fork()==0){
				char *henlo = strtok(command," \n");
				char *henlo2[1024];
				int counter = 0;
				while(henlo!=NULL){
					henlo2[counter] = henlo;
					henlo = strtok(NULL," \n");
					counter++;
				}
				henlo2[counter] = NULL;
				execv("/home/chhokra/Desktop/OSAssignment1/xmkdir",henlo2);
			}
			else{
				wait(NULL);
			}
		}

		

		



	}
	fclose(hp);
}

	

