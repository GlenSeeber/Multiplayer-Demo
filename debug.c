#include <stdio.h>
#include <sys/time.h>


int main(){

	struct timeval currentTime;

	gettimeofday(&currentTime, NULL);
	
	long unsigned int ms;

	ms = (currentTime.tv_sec * 1000) + (currentTime.tv_usec / 1000);

	printf("seconds: %ld\nmicroseconds: %ld\n\n", currentTime.tv_sec, currentTime.tv_usec);

	printf("miliseconds since epoch: %lu\n", ms);


//	for (int i = 0; ; ++i){
//		
//	}
}
