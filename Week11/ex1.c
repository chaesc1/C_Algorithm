#include <stdio.h>

int main(void)
{
    double nominal = 1.0;
    double sum = 0.0;

    for (int i = 0; i < 10; i++)
    {
        sum += 0.1;
    }
    
    if (nominal == sum)
    {
        printf("same");
    }
    else
    {
        printf("diff");
    }
    
    return 0;
}
