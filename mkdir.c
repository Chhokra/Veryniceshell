#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
int main(int argc, char *argv[]){
	if(argc==2){
		int check;
		check = mkdir(argv[1],755);
		if(check==0){
			printf("%s directory created succesfully \n",argv[1] );
		}
		else if(errno==EEXIST){
			printf("ERROR %s directory already exists!\n",argv[1] );
		}

	}
}