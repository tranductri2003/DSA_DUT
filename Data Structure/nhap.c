#include <stdio.h>

void change(int *n)
{
    *n=10;
}
int main()
{
    int *n=0;
    change(&n);
    printf("%d",n);
}
