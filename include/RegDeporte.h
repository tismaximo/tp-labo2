#include<cstring>
#ifndef REGDEPORTE_H_INCLUDED
#define REGDEPORTE_H_INCLUDED

class RegDeporte {
private:
    int id;
    char nombre[50];
    int anho;
    int cantAlumnos;
public:
    RegDeporte(int id = 1, const char* nombre = "NADA", int anho = 1800, int cantAlumnos = -1) {
        this->id = id;
        strcpy(this->nombre, nombre);
        this->anho = anho;
        this->cantAlumnos = cantAlumnos;
    }
    RegDeporte() {};
    void mostrar() {
        std::cout << id << std::endl;
        std::cout << nombre << std::endl;
        std::cout << anho << std::endl;
        std::cout << cantAlumnos << std::endl;
    }
};

#endif // REGDEPORTE_H_INCLUDED
