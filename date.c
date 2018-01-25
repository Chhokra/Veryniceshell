#include <stdio.h>
#include <time.h>
int main(){
	struct tm *local;
	time_t hello;
	hello = time(&hello);
	local = localtime(&hello);
	printf("%s %s",tzname[0],asctime(local) );
}