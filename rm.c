#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
int main(int argc,char *argv[]){
	if(argc==2){
		struct stat lol;
		stat(argv[1],&lol);
		if(S_ISDIR(lol.st_mode)){
			printf("Error: Cannot delete Directory %s\n",argv[1] );
		}
		else{
			remove(argv[1]);
		}
	}
	if(argc==3){
		if(strcmp(argv[1],"-i")==0){
			struct stat lol;
			stat(argv[2],&lol);
			if(S_ISDIR(lol.st_mode)){
				printf("Error: Cannot delete Directory %s\n",argv[2] );
			}
			else{
				printf("Remove regular file %s?\n",argv[2] );
				char option = getchar();
				if(option=='y'){
					remove(argv[2]);
				}
				

			}
		}
		else if(strcmp(argv[1],"-d")==0){
			int alpha;
			alpha = rmdir(argv[2]);
			if(alpha==0){
				printf("%s deleted \n",argv[2] );
			}
			else{
				printf("Error: Directory not empty\n");
			}
		}
	}
}

