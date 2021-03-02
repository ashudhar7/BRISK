#include <stdio.h>
#include<math.h>
#include<stdlib.h>

int sbox[16] = {0x5, 0xC, 0xB, 0x6, 0x9, 0x0, 0xD, 0xA, 0xE, 0x3, 0x8, 0xF, 0x4, 0x1, 0x7, 0x2};
int table[16][16];

 //main function   
int main()
{
   FILE *fp;
   fp=fopen("d:\\DTable.txt", "w");	
   printf("\nCreating differential table:\n");
    
    int i,j;
    
    
	for(i = 0; i < 16; i++)
        for(j = 0; j < 16; j++)
            table[i ^ j][sbox[i] ^ sbox[j]]++;        
 
    for(i = 0; i < 16; i++)
    {
        for(j = 0; j < 16; j++)
            fprintf(fp,"%d, ", table[i][j]);
        fprintf(fp,"\n");
    }
    
}        