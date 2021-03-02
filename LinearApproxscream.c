#include <stdio.h>
#include<stdlib.h>


int SBox[16] = {0x5, 0xC, 0xB, 0x6, 0x9, 0x0, 0xD, 0xA, 0xE, 0x3, 0x8, 0xF, 0x4, 0x1, 0x7, 0x2};

int LATable[16][16];

int Mask(int num, int mask)
{
    int value = num & mask;
    int t = 0;
    
    while(value > 0)
    {
        int var = value % 2;    
        value /= 2;
        
        if (var == 1) 
            t = t ^ 1;
    } 
    return t;   
}

void ApproxValue()
{
    int i, j, k;
    
    for(i = 0; i < 16; i++)                                         //output mask
        for(j = 0; j < 16; j++)                                     //input mask
            for(k = 0; k < 16; k++)                                 //input
                if (Mask(k, j) == Mask(SBox[k], i))
                    LATable[j][i]++;    
}




int main()
{
	FILE *fp;
    fp=fopen("d:\\L-Box.txt", "w");
    ApproxValue();
    int i, j;
    for(i = 0; i < 16; i++)
        {
		for(j = 0; j < 16; j++)
		{
		   fprintf( fp,"%d,  ", LATable[i][j]-8); 
		}
        fprintf(fp,"\n");    
        }     
    fclose(fp);
}
    