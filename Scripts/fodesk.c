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

//failo atidarymas naudojant deksriptoriu

int deskriptorius(const char *failovardas);
int failouzdarymas(int failodesk);

//Gaunamas failo deskriptorius
int deskriptorius(const char *failovardas){
	int dsk;
	dsk = open(failovardas, O_RDONLY);
	if(dsk == -1 ){
		perror(failovardas);
		exit(1);
	}
	else{
		printf("failo deskriptorius: %d\n", dsk);
		return dsk;
	}
	
}
//failo uzdarymas naudojant deskriptoriu
int failouzdarymas(int failodesk){
	int rv;
	rv = close(failodesk);
	if(rv != 0){
		perror("uzdarymas nepavyko");
	}
	else{
		puts("failas uzdarytas");
	return rv;
	}
	
}
//atidarom faila skaitymui ir uzdarom
// failas paduodamas 1 argumentu
int main(int argc, char *argv[]){
	int d = deskriptorius(argv[1]);
	failouzdarymas(d);
	
	
	return 0;
}