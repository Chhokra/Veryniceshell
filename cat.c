#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
int main(int argc,char *argv[]){

	if (argc==2){
		DIR *lol;
		struct dirent *travel;
		lol = opendir(".");
		if(strcmp(argv[1],"*")==0){
		 	

		 DIR *lol;
			struct dirent *travel;
			lol = opendir(".");
			if(lol!=NULL){
				travel = readdir(lol);
				while(travel!=NULL){
					FILE *cp;
					cp = fopen((*travel).d_name,"r");
					int num;
					num = fgetc(cp);
					while(num!=-1){
						printf("%c",num);
						num = fgetc(cp);
					}

					travel = readdir(lol);
				}
			}


		}

		else{

			FILE *cp;
		 	cp = fopen(argv[1],"r");
		 	struct stat lol1;
			int existence = stat(argv[1],&lol1);
			if(S_ISREG(lol1.st_mode)){
				if(existence==0){
					printf("hello\n");
				if(lol!=NULL){
			travel = readdir(lol);
		 	while(travel!=NULL){
		 		if(strcmp((*travel).d_name,argv[1])==0){
		 			int num;
		 			num = fgetc(cp);
		 			while(num!=-1){
		 				printf("%c",num);
		 				num = fgetc(cp);
		 			}

		 			break;
		 		}

		 		travel = readdir(lol);
		 	}
		 }
			}
			else{
				printf("File %s doesn't exist \n",argv[1] );
			}

			}
			else{
				printf("Cannot cat directory %s\n",argv[1] );
			}
			



		}
		


		
		
	}


	if(argc==3){

		if(strcmp(argv[1],"-n")==0){
			DIR *lol;
			struct dirent *travel;
			lol = opendir(".");
			FILE *cp;
			cp = fopen(argv[2],"r");
			struct stat lol1;
			int existence = stat(argv[2],&lol1);
			if(S_ISREG(lol1.st_mode)){
				if(lol!=NULL){
				if(existence==0){
					travel = readdir(lol);
				while(travel!=NULL){
					if(strcmp((*travel).d_name,argv[2])==0){
						int num;
						num = fgetc(cp);
						int count = 1;
						printf("%d     ",count);
						while(num!=-1){
							if(num=='\n'){
								printf("\n");
								count++;
								printf("%d     ",count);
							}
							else{
								printf("%c",num);

							}
							
							num = fgetc(cp);
						}

						break;
					}

					travel = readdir(lol);
				}
			}
			else{
				printf("File %s doesn't exist\n", argv[2]);
			}

				}
				

			}
			else{
				printf("Cannot cat directory  %s\n",argv[2] );

			}
			

		}
	}
	



}