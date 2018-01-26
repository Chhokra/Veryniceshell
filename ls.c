#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[]){
	DIR *lol;
	struct dirent  *travel;
	if(argc == 1 ){
		lol = opendir(".");
		if(lol!=NULL){
			travel = readdir(lol);
			while(travel!=NULL){
				
			
			
					
					
						if((*travel).d_name[0]!='.'){
						printf("%s\n",(*travel).d_name );
					

					}
					travel = readdir(lol);
			}
			
		}
	

	}
	else if(argc==2){
		if(strcmp(argv[1],"-i")==0){
			lol = opendir(".");
			if(lol!=NULL){
				travel = readdir(lol);
				while(travel!=NULL){
					if((*travel).d_name[0]!='.'){
						printf("%lu    %s\n",(*travel).d_ino,(*travel).d_name );
					}
					travel = readdir(lol);
				}
			}
		}
		if(strcmp(argv[1],"-a")==0){
			lol = opendir(".");
		if(lol!=NULL){
			travel = readdir(lol);
			while(travel!=NULL){
				
			
			
					
					
						printf("%s\n",(*travel).d_name );
					

					
					travel = readdir(lol);
			}
			
		}
	

		}
		else{
			lol = opendir(argv[1]);
		if(lol!=NULL){
			travel = readdir(lol);
			while(travel!=NULL){
				
			
			
					
					
						if((*travel).d_name[0]!='.'){
						printf("%s\n",(*travel).d_name );
					

					}
					travel = readdir(lol);
			}
			
		}
	

		}
	}
	else if(argc==3){
		
		lol = opendir(argv[2]);
		if(lol!=NULL){
			travel = readdir(lol);
			
			while(travel!=NULL){
						
						if(strcmp(argv[1],"-a")==0){
							
							printf("%s\n",(*travel).d_name );
						}
						else if(strcmp(argv[1],"-i")==0){
							
							printf("%lu   %s\n",(*travel).d_ino,(*travel).d_name );
						}
						
					
					
					travel = readdir(lol);
			}
			printf("\n");
		}
	}

}