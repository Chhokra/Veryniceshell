#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[]){
	if (argc==2){
		DIR *lol;
		struct dirent *travel;
		lol = opendir(".");
		FILE *cp;
		cp = fopen(argv[1],"r");
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
	if(argc==9){
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

	if(argc==3){
		printf("hello1\n");
		if(strcmp(argv[1],"-n")==0){
			printf("hello2\n");
			DIR *lol;
			struct dirent *travel;
			lol = opendir(".");
			FILE *cp;
			cp = fopen(argv[2],"r");
			if(lol!=NULL){
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

		}
	}
	



}