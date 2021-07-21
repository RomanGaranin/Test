#include <stdio.h>
#include <math.h>
#include <stdint.h>

int main()
{
	uint8_t time_str[10] = "00:00:00";
	uint16_t count=0;
	uint8_t h = 0, m = 0, s = 0;

	for(h=0;h<24;h++)
	{
		for(m=0; m<60; m++)
		{
			for(s=0; s<60; s++)
			{
				sprintf(time_str, "%02d:%02d:%02d\n",h,m,s);
				uint8_t h1,h2,m1,m2,s1,s2;
				sscanf(time_str,"%c%c:%c%c:%c%c",&h1,&h2,&m1,&m2,&s1,&s2);
				if((h2=='5') || (m1=='5') || (m2=='5') || (s1=='5') || (s2=='5'))
				{
					count++;
				}
			}
		}
	}
	printf("We will see digit \"5\" %d seconds \n", count);
	return 0;
}
