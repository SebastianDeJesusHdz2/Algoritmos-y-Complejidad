#include <stdio.h>
#include <sys/time.h>

#define SIZE 100000

void fillArray(long long *);
long long seqSearch(long long *, long long);

int main(int argc, char *argv[]){
	struct timeval start, finish;
	long long array[SIZE];
	long long x = 50000;
	long long location;
	fillArray(array);
	gettimeofday(&start, NULL);
	printf("Value %lld was located in position %lld\n", x, seqSearch(array, x));
	gettimeofday(&finish, NULL);
	double execution_time = (double) (finish.tv_usec - start.tv_usec) / 1000000 +
							(double) (finish.tv_sec - start.tv_sec);
	printf("Execution time: %f\n", execution_time);
	return 0;
}
void fillArray(long long *S){
	for(long long i = 0; i < SIZE; i++){
		S[i] = i + 1;
	}
}
long long seqSearch(long long *S, long long x){
	long long location = 0;
	while(location < SIZE && S[location] != x)
		location++;
	if(location == SIZE)
		return -1;
	else
		return location;
}
