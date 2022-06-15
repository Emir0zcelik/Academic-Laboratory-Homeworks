#include <stdio.h>

int values(int *x, int *y)
{
  int z, pa, pb;
  
  if(*x > *y)
  {
    z = *x - *y;
    *x -= z;
    *y += z;
  }
  
  else if(y > x)
  {
    z = *y - *x;
    *x += z;
    *y -= z;
  }
}
int addresses (int *x , int *y)
{
	int *storage;
	
	storage = x;
	x = y;
	y = storage;
	
	printf("pa address = %p\n", x);
    printf("pb address = %p\n", y);
}
int main()
{
  
  int a, b;
  int *pa = &a;
  int *pb = &b;
  
  printf("a = ");
  scanf("%d", &a);
  printf("b = ");
  scanf("%d", &b);
  printf("--------Swap1-------\n");
  values(&a, &b);
  
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("pa address = %p\n", pa);
  printf("pb address = %p\n", pb);
  printf("--------Swap2-------\n");
  addresses(pa, pb);
  return 0;
}
