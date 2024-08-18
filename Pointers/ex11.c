#include<stdio.h>
int main()
{
  int a[] = {2, 4, 5, 8, 1};
  int i;

  for(i = 0; i < 5; i++)
  {
    printf("%d\n", &a[i]); 
    printf("%d\n", a + i);
    printf("%d\n", a[i]);
    printf("%d\n", *(a+i));
  }
}

/* SAMPLE OUTPUT

978354800
978354800
2
2
978354804
978354804
4
4
978354808
978354808
5
5
978354812
978354812
8
8
978354816
978354816
1
1
*/