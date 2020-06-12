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

//KD3 Pavyzdine uzduotis;





//Tikrinam ar priima reikalingus argumentus

int main(int argc, char * argv[] ){
	int skaicius;
	
	if(argc >= 4){
		printf("per daug argumentu, turetu buti tik 2\n");
	}
	//tikrina ar direktorija, jei ne tai failas
	else if(argc <= 3){
		struct stat argstat;
		stat(argv[1],&argstat);
		if(S_ISDIR(argstat.st_mode)){
			skaicius = atoi(argv[2]);
			if(skaicius != 0)
			printf("Tai derektorija ir skaicius %d\n", skaicius);
			
		}
		else{
			skaicius = atoi(argv[2]);
		printf("tai failas ir skaicius: %d\n", skaicius);
		}	
	}
	
	
	
	return 0;
}