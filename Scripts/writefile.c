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

//rasymas i faila
int rasytifaila(char *failas);

int rasytifaila(char *failas){
	FILE *fp;
	char str[] = "Man pavyko parasyti i faila\n";
	fp = fopen(failas, "w");
	fwrite(str, 1, sizeof(str), fp);
	fclose(fp);
	
	return 0;
}


int main(int argc, char *argv[]){
	rasytifaila(argv[1]);
	
	return 0;
}