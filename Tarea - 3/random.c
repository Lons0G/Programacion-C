#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
srand (time(NULL));

int test;
float n;

test = rand();

printf("\nrandom %d\n",test);
printf("\nMAX %x",RAND_MAX);
printf("\nmin %x",-1*RAND_MAX);

int pos=0,neg=0,i;

for(i=0;i<1000;i++){
if(rand()%2==0){
	n=((float)test/RAND_MAX)*5.2;
	pos++;
	}
else{
	n=((float)test/RAND_MAX)*-5.2;
	neg++;
	}
}
printf("\nPos=%d Neg=%d \n",pos,neg);


}

