#include <stdio.h> 
#include <string.h>
#define N_ARRAY 255
void MT_ADD_STATE() 
{

}
void MT_ADD_RULE() 
{ 

}

char storage[N_ARRAY]; int idx_lenta; int state; 
char cache_input[80];
//Turing 
    void MT_Init() 
    {   
        printf("Generating storage.. size %i \n", N_ARRAY);

        for ( int i = 0; i < N_ARRAY; i++ ) storage[i] = '#';

        printf("\n[OK]\n");
    }
    void MT_Right() 
    {
        idx_lenta++;
    }
    void MT_Left() 
    {
        idx_lenta--;
    }
    char MT_CurData() 
    { 
        return storage[idx_lenta];
    }
    void MT_WriteWord() 
    { 
        idx_lenta = 5; // Пусть так будет
        gets(cache_input);
        
        printf("Input Len: %i\n",strlen(cache_input));
        for(int i = 0; i < strlen(cache_input); i++) 
        { 
            storage[idx_lenta] = cache_input[i]; 
            MT_Right(); 
        }

        MT_Left();

        for (int i = 0; i<N_ARRAY; i++) 
        {
            if ( idx_lenta == i )
            {
                printf("[%c]",storage[i], idx_lenta);
            }
            else 
            { 
                printf("%c",storage[i]);
            }
            
        }
        printf("\n");
    }

    void MT_Handler() 
    {

    }

    

// 
int main() 
{
    MT_Init();
    MT_WriteWord(); 


    return 0;
}