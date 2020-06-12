#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <string.h>
#include <ftw.h>

//tikrinam ar failas paprastas - reguliarus
int tikrintifaila(char *failas);

int tikrintifaila(char *failas){
	struct stat buf;
	stat(failas, &buf);
	if(S_ISREG(buf.st_mode)){
	printf("Tai reguliarus failas!\n");
	}
else{
	printf("Iveskite reguliaru faila\n");
}	
	
	return 0;
}


int main(int argc, char *argv[]){
	tikrintifaila(argv[1]);
	
	return 0;
}