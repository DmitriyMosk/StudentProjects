# git ls-files --others --exclude-from=.git/info/exclude
# Lines that start with '#' are comments.
# For a project mostly in C, the following would be a good set of
# exclude patterns (uncomment them if you want to use them):
# *.[oa]
# *~
                                                                                                                                                                                                                                                                                rage[idx_lenta];
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
