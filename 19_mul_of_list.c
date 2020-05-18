#include <stdio.h>
#include <math.h>

int main()
{
  int n, i; int mul=1;
  (void) scanf ("%d", &n);
  for (i=0; i<n; i++)
	{
	  int x;
	 (void) scanf ("\n");
	 (void) scanf ("%d", &x);
	 mul *=x;
	}
  printf("%d\n", mul);
  return 0;
}
