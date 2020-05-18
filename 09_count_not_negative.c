#include <stdio.h>
#include <math.h>

int main()
{
  int n, i; int count=0;
  (void) scanf ("%d", &n);
  for (i=0; i<n; i++)
	{
	  int x;
	 (void) scanf ("\n");
	 (void) scanf ("%d", &x);
	  if (x>=0)
		count++;
	}
  printf("%d\n", count);
  return 0;
}
