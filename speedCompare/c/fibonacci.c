#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <kmbint.h>

#define LENGTH 1000

int main()
{

  int16_t i, n;

  // initialize first and second terms
  char t1[LENGTH] = "0";
  char t2[LENGTH] = "1";

  // initialize the next term (3rd term)
  char nextTerm[LENGTH] = "0";

  // nextTerm = t1 + t2
  kmbint_add(nextTerm, t1);
  kmbint_add(nextTerm, t2);

  // get no. of terms from user
  printf("Enter a number: ");
  scanf("%d", &n);

  // print 3rd to nth terms
  for (i = 3; i <= n; ++i)
  {
    strcpy(t1, t2);       // t1 = t2
    strcpy(t2, nextTerm); // t2 = nextTerm

    // nextTerm = t1 + t2
    strcpy(nextTerm, t1);
    kmbint_add(nextTerm, t2);
  }

  printf("The %dth fibonacci number is: %s", n, nextTerm);

  return 0;
}