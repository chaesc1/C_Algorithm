#include <stdio.h>

int main(void)
{
    int n;
    int num[100];
    scanf("%d",&n);

   for (int i = 0; i < n; i++)
   {
        scanf("%d",&num[i]);
   }
   
    int theMin;
    int theSecond;

    if (num[0] <= num[1])
    {
        theMin = num[0];
        theSecond = num[1];
    }
    else
    {
        theMin = num[1];
        theSecond = num[0];
    }
    
    for (int i = 2; i < n; i++)
    {
        if (num[i] <= theMin)
        {
            theSecond = theMin;
            theMin = num[i];//최소값 찾기 알고리즘.
        }
        else if (num[i] < theSecond)
        {
            theSecond = num[i];
        }
        
    }
    
    printf("%d %d",theMin,theSecond);

    
    return 0;
}