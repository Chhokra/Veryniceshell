#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[]){
	if(argc==2){
		int check;
		check = mkdir(argv[1],0700);
		if(check==0){
			printf("%s directory created succesfully \n",argv[1] );
		}
		else if(errno==EEXIST){
			printf("ERROR %s directory already exists!\n",argv[1] );
		}
		else if(errno == ENOENT){
			printf("Cannot create %s. No such directory\n",argv[1]);
		}

	}
	else if(argc==3){
		char currentdir[1024];
		char *dir;
		dir = getcwd(currentdir,1024);
		if(strcmp(argv[1],"-p")==0){
			char *henlo = strtok(argv[2],"/\n");
			while(henlo!=NULL){
				mkdir(henlo,0700);
				chdir(henlo);
				henlo = strtok(NULL,"/\n");
			}
		}
		chdir(currentdir);

	}
}