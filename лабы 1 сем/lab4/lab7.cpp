#include <iostream> 
 
int main() 
{ 
    int input; 
    int asize = 0; 
    int* a = new int[asize]; 
    int indMax = 0; 
    int indMin = 0; 
    int max = a[0]; 
    int min = a[0]; 
    int nulls= 0; 
 
 
    while (std::cin >> input) 
    { 
        a[asize] = input; 
        asize++; 
    } 
    for (int i = 0; i < asize; i++) 
    { 
        if (a[i] >= max) 
        { 
            max = a[i]; 
            indMax = i; 
        } 
 
        if (a[i] <= min)  
        { 
            min = a[i]; 
            indMin = i; 
        } 
    } 
 
 
    for (int i = 0; i < asize; i++) 
    { 
        if ((i > indMax && i < indMin) || (i > indMin && i < indMax)) 
            a[i] = 0; 
    } 
 
    for (int i = 0; i < asize; i++) 
    { 
        if (a[i] == 0) 
            nulls++; 
    } 
 
    int asize2 = asize - nulls; 
    int* a2 = new int[asize2]; 
    int c = 0; 
 
    if (nulls> asize/2) 
    { 
        for (int i = 0; i < asize; ++i) 
        { 
            if (a[i] != 0) 
            { 
                a2[c] = a[i]; 
                c++; 
            } 
        } 
 
        for (int i = 0; i < c; i++) 
        { 
            std::cout << a2[i] << ' '; 
        } 
    } 
 
    else 
    { 
        for (int i = 0; i < asize; i++) 
            std::cout << a[i] << ' '; 
    } 
 
    return 0; 
}