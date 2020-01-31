#include <stdio.h>

int main()
{
    int i;
    int j;
    int w = 20;
    for (i=0; i<20; i++)
    {
        for (j=0; j<40; j++)
        {
            if(i * j == w)
            {
                printf("%d * %d = %d\n", i, j, w);
            }
            
        }
    }
    return 0;
}