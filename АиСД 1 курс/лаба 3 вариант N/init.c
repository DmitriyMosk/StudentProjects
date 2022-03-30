#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <math.h> 

///////////////////////////////////////////////////////////////////////////
int *GenRandIntArray(int size, int upper, int lower) { 
    
    int *arr = malloc(size * sizeof(int));     
    
    srand(time(0)); 
    
    for ( int i = 0; i < size; i++ ) 
        arr[i] = rand() % ( upper - lower + 1 ) + lower; 

    return arr;
}

void SortArray(int *arr, int size) 
{ 
    for ( int i = 0; i < size; i++ ) 
    { 
        for ( int j = 0; j < size - 1; j++ ) 
        { 
            if ( arr[j] > arr[j + 1] ) 
            { 
                int swipe = arr[j];
                arr[j] = arr[j + 1]; 
                arr[j + 1] = swipe; 
                
            } 
        } 
    } 
    
} 

void PrintArray(int *arr, int size) 
{ 
    for ( int i = 0; i < size; i++ ) printf("a[%i] = %i\n",i, arr[i]);

    printf("\n");
} 
///////////////////////////////////////////////////////////////////////////


int BinarySearch(int *arr, int size, int searchElement)
{ 
    int low, high, middle; 
    low = 0; high = size - 1; 
    
    while ( low <= high ) 
    { 
        middle = (low + high) / 2; 
        if ( searchElement < arr[middle] ) 
        { 
            high = middle - 1; 
        }
        else if ( searchElement > arr[middle] ) 
        { 
            low = middle + 1; 
        }
        else return middle; 
    }

    return -1;
} 

int PredictionSearch(int *arr, int size, int searchElement) 
{   
    int min = arr[0]; int max = arr[size-1]; 
    
    int predictIndex = (searchElement - min)*(size-1)/(max-min); 
    
    if ( arr[predictIndex] != searchElement ) 
    { 
        if ( arr[predictIndex - 1] == searchElement ) 
        { 
            predictIndex -= 1;
        }  
        else if ( arr[predictIndex + 1] == searchElement ) 
        { 
            predictIndex += 1;
        }
        else predictIndex = -1;
    } 

    return predictIndex; 
}



int main() 
{ 
    int N; 
    printf("Insert number N: "); scanf("%i",&N); 
    
    int *arr = GenRandIntArray(N, 100, 10); 
    //PrintArray(arr, N);
    SortArray(arr, N);
    PrintArray(arr, N); 
    //////////////////////////////////////
    
    int search; 
    printf("Insert search value: "); scanf("%i", &search); 

    char searchMethod; 
    printf("Insert b/p to select the search method(b - Binary, p - prediction): "); scanf(" %c", &searchMethod); 



    int idx = -1; 
    switch (searchMethod)
    {
    case 'b':
        idx = BinarySearch(arr, N, search); 
        break;
    case 'p':
        idx = PredictionSearch(arr, N, search);
        break;
    default:
        printf("\nUnknown search method.\n");
        break;
    }

    if ( idx != -1 ) 
        printf("Search output: element index %i", idx);
    else    
        printf("Search output: nil element");
} 
