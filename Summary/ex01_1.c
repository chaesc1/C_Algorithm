#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d",&n);
    //printf("%d\n",n);

    while (n>0)
    {
        n/=2;
        printf("%d ",n);
    }
    
    return 0;
}