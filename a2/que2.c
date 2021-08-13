#include <stdio.h>

int main (void)
{

	int i, total, num;

	total = 0;

	for (i = 0; i < 10; i++)
		total += i;
        
	if (total != 45)
	    	printf ("Failure\n");
        else
	        printf ("Success\n");

	num = 0;	
	switch(num) {
	case 1: printf("1");
		break;

	case 2: printf("2");
		break;
	
	case 3: printf("3");
		break;
	
	case 4: printf("4");
		break;

	default: printf("0");
		break;
				
	}
	return 0;
}
