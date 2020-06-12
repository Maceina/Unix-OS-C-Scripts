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

//failo nuskaitymas ir isvedimas i console 10 simbolio
// *fp yra pointeris i faila, o FILE tai duomenu 
// struktura apie faila

int skaitytifaila(char *failas);

int skaitytifaila(char *failas){
	FILE *fp;
	char str[10];
	if((fp = fopen(failas, "r")) == NULL){
		printf("error!");
		abort();
	}
	else{
		fscanf(fp, "%s", str );
		printf("Nuskaitytas tekstas: %s\n", str);
		fclose(fp);
	}
	
	return 0;
}


int main(int argc, char *argv[]){
	skaitytifaila(argv[1]);
	
	return 0;
}