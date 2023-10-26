#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "kmbint.h"

#define LENGTH 10000

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <n>\n", argv[0]);
		return 1;
	}

	int64_t i, n = atoi(argv[1]);

	// initialize first and second terms
	char t1[LENGTH] = "0";
	char t2[LENGTH] = "1";

	// initialize the next term (3rd term)
	char nextTerm[LENGTH] = "0";

	// nextTerm = t1 + t2
	kmbint_add(nextTerm, t1);
	kmbint_add(nextTerm, t2);

	// print 3rd to nth terms
	for (i = 3; i <= n; ++i)
	{
		strcpy(t1, t2);		  // t1 = t2
		strcpy(t2, nextTerm); // t2 = nextTerm

		// nextTerm = t1 + t2
		strcpy(nextTerm, t1);
		kmbint_add(nextTerm, t2);
	}

	printf("The %dth fibonacci number is:\n%s\n", n, nextTerm);

	return 0;
}