#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include "data.h"
#include "uint128.h"
		
int main() {

	//The final item in the list.
	char *sought = "9dc7f07099b4b45f640d7f6baa7e2bc7";

	struct timeval start;
	gettimeofday(&start, (NULL));

	int i;

	//Do straight forward string comparisons to find the sought hash.
	for (i = 0; i < datanum; i++) {


		if (!strcmp(sought, data[i])) {

			struct timeval end;
			gettimeofday(&end, (NULL));
			printf("1 - Found! %lu\n", end.tv_usec - start.tv_usec);
			break;
		}
	}

	struct uint128 data2[datanum];
	gettimeofday(&start, (NULL));

	//Convert all the hash strings into uint128.
	for (i = 0; i < datanum; i++) {
		create_uint128(data[i], &data2[i]);
	}
	{
	struct timeval end;
	gettimeofday(&end, (NULL));
	printf("Conversion took %lu\n", end.tv_usec - start.tv_usec);
	}

	struct uint128 sought2;
	create_uint128(sought, &sought2);

	gettimeofday(&start, (NULL));

	//Do uint128 comparisons to find the sought hash.
	for (i = 0; i < datanum; i++) {
		if (cmp_uint128(&sought2, &data2[i])) {
			struct timeval end;
			gettimeofday(&end, (NULL));
			printf("2 - Found! %lu\n", end.tv_usec - start.tv_usec);
			break;
		}
	}
}

