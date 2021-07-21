#include <stdio.h>
#include <math.h>
#include <stdint.h>

int main()
{
	uint16_t T = 1024;
	uint16_t A = 5000;
	uint16_t C = 5000;
	uint64_t x = 0;
	int64_t sin_array[1024];
	
	for (x = 0; x < 1024; x++)
	{
		sin_array[x] = round(A*sin((2*M_PI)/T*x)+C);
	}
	uint8_t i= 0;
	FILE*  f = fopen("sin_array", "w+");
	if(NULL == f){
		printf("Error create file");
		return -1;
	}
	for (x = 0; x < 1024; x++)
	{
		fprintf(f, "%5ld,", sin_array[x]);
		i++;
		if(i == 8){
			fprintf(f, "\n");
			i=0;
		}
	}
	fprintf(f,"\n");
	fclose(f);
	return 0;
}
