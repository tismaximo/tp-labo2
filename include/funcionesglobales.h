#include<iostream>
#include<cstring>

#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED


void cargarCadena(char *palabra, int tam)
{
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ )
    {
        palabra[i] = std::cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

int buscarMinPos(const int* vec, int tam) {
    int min;
    int posMin;
    for (int i = 0; i < tam; i++) {
        if (vec[i] < min || i == 0) {
            min = vec[i];
            posMin = i;
        }
    }
    return posMin;
}

void inicializarCero(int* vec, int tam) {
    for (int i = 0; i < tam; i++) {
        vec[i] = 0;
    }
}

#endif // FUNCIONESGLOBALES_H_INCLUDED
