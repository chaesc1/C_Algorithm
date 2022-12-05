#include <stdio.h>

int main(void)
{

    int num;
    int arrnum = 0;
    FILE * file= fopen(".input.txt", "r");
    int arr[100][100];

    while (!feof(file))
    {
        fscanf(file,"%d",&arrnum);
         printf("%d\n",arrnum);
    }
    
    fclose(file);
    return 0;
}