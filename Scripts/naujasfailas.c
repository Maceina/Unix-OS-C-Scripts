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

//tikrinam ar failas egzistuoja jei ne tai ji sukuriam
int failasegzistuoja(const char *failas);



int failasegzistuoja(const char *failas){
	int fd;
	fd = open(failas, O_RDONLY);
	if(fd >= 0 ){
		printf("failas: %s egzistuoja \n", failas);
	}
	else{
		//sukuriamas naujas failas
		//printf("failas %s nerastas\n", failas);
		fd = creat(failas, O_RDONLY);
		printf("Sukurtas naujas fialas: %d\n", fd);
	}
	
	return 0;
}








int main(int argc, char *argv[]){
	//jei deskriptorius grazina -1 tai naujas failas nesukurtas!!!
	failasegzistuoja(argv[1]);
	
	return 0;
}