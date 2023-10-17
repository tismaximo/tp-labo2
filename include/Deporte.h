#include<iostream>
#include<cstring>
#include<ctime>
#include "funcionesglobales.h"

#ifndef DEPORTE_H_INCLUDED
#define DEPORTE_H_INCLUDED

int nuevaID();

class Deporte
{
private:
    int id;
    char nombre[30];
    int tipo;
    int yearOrigen;
    bool estado=true;
public:
    Deporte(const char* nombre, int tipo, int yearOrigen, bool estado = true) {

        strcpy(this->nombre, nombre);
        this->tipo = tipo;
        this->yearOrigen = yearOrigen;
        this->estado = estado;
    }
    Deporte() {};
    void Cargar()
    {
        id = nuevaID();
        std::cout << "ID AUTOINCREMENTAL DEL DEPORTE: " << id << std::endl;
        std::cout<< "INGRESAR NOMBRE DEL DEPORTE: "<<std::endl;
        cargarCadena(nombre,29);
        std::cout << "INGRESAR TIPO: "<<std::endl;
        std::cin>>tipo;
        std::cout << "INGRESAR ANIO DE CREACION: "<<std::endl;
        std::cin>> yearOrigen;
        estado=true;
    }
    void Mostrar()
    {
        std::cout<< "ID: "<< id <<std::endl;
        std::cout << "NOMBRE: "<<nombre<<std::endl;
        std::cout << "TIPO: "<<tipo<<std::endl;
        std::cout << "ANIO DE ORIGEN: "<< yearOrigen<<std::endl<<std::endl;

    }
    void setID(int id_deporte)
    {
        id=id_deporte;
    }
    void setNombre(char *_nomDeporte)
    {
        strcpy(nombre, _nomDeporte);
    }
    void setTipo(int _tipoDeporte)
    {
        tipo=_tipoDeporte;
    }
    void setOrigen(int _yearDeporte)
    {
        yearOrigen=_yearDeporte;
    }

    void setEstado(bool _estado)
    {
        estado=_estado;
    }
    //getters
    int getID()
    {
        return id;
    }
    const char * getNombre()
    {
        return nombre;
    }
    int getTipo()
    {
        return tipo;
    }
    int getOrigen()
    {
        return yearOrigen;
    }
    bool Existe()
    {
        return estado;
    }

};


int nuevaID() {

    FILE * archivo = fopen("deportes.dat", "rb");
    if (archivo == NULL) {
        std::cout << "error";
        fclose(archivo);
        archivo = fopen("deportes.dat", "wb");
        fclose(archivo);
        archivo = fopen("deportes.dat", "rb");
    }
    int cont = 1;
    Deporte leer;
    while (fread(&leer, sizeof leer, 1, archivo)) {
        if (leer.Existe())    cont++;

    }
    fclose(archivo);
    return cont;
}

bool chequeoDeporte(Deporte registro)
{
    if (!registro.Existe())
    {
        std::cout << "EL DEPORTE NO EXISTE"<< std::endl;
        return false;
    }
    if (registro.getTipo() > 21 || registro.getTipo() < 1)
    {
        std::cout << "EL TIPO DE DEPORTE ESTA MAL"<< std::endl;
        return false;
    }
    time_t rawtime;
    tm * fechaActual;
    time ( &rawtime );
    fechaActual = localtime ( &rawtime );
    if (registro.getOrigen() < 1800 || registro.getOrigen() > fechaActual->tm_year + 1900 )
    {
        std::cout << "EL ANIO DEL DEPORTE ESTA MAL"<< std::endl;
        return false;
    }
    return true;
}

bool agregarDeporte()
{
    FILE * archivo = fopen("deportes.dat", "ab");
    if (archivo == NULL)
    {
        return false;
    }
    Deporte registro;
    registro.Cargar();
    bool exito = chequeoDeporte(registro);
    if (exito)
    {
        fwrite(&registro, sizeof registro, 1, archivo);
        std::cout << "REGISTRO ESCRITO CON EXITO"<< std::endl;
    }
    fclose(archivo);
    return true;
}

bool mostrarDeportes()
{
    FILE * archivo = fopen("deportes.dat", "rb");
    if (archivo == NULL)
    {
        std::cout << "ERROR ABRIENDO EL ARCHIVO \n";
        return false;
    }
    Deporte leer;
    while(fread(&leer, sizeof leer, 1, archivo))
    {
        if (leer.Existe()) leer.Mostrar();
    }
    fclose(archivo);
    return true;
}

int buscarDeporte (int id) {
    FILE * archivo = fopen("deportes.dat", "rb");
    if (archivo == NULL) {
        std::cout << "ERROR ABRIENDO EL ARCHIVO \n";
        return -1;
    }
    Deporte leer;
    int pos = 0;
    while (fread(&leer, sizeof leer, 1, archivo)) {
        if (leer.getID() == id && leer.Existe()) {
            leer.Mostrar();
            fclose(archivo);
            return pos;
        }
        pos++;
    }
    std::cout << "NO SE ENCONTRO EL DEPORTE CON EL ID INGRESADO \n";
    fclose(archivo);
    return -2;
}

bool modificarOrigen() {
    int id;
    std::cout << "INGRESAR ID DEL DEPORTE: ";
    std::cin >> id;
    int pos = buscarDeporte(id);
    if (pos > -1) {
        FILE * archivo = fopen("deportes.dat", "r+b");
        if (archivo == NULL) {
            std::cout << "ERROR ABRIENDO EL ARCHIVO \n";
            return false;
        }
        Deporte leer;
        fseek(archivo, sizeof leer * pos, SEEK_SET);
        fread(&leer, sizeof leer, 1, archivo);
        int anho;
        std::cout << "INGRESAR EL NUEVO ANHO: ";
        std::cin >> anho;
        leer.setOrigen(anho);
        fseek(archivo, sizeof leer * pos, SEEK_SET);
        if (fwrite(&leer, sizeof leer, 1, archivo)) {
            fclose(archivo);
            std::cout << "FECHA CAMBIADA CON EXITO \n";
            return true;
        }
        fclose(archivo);
        std::cout << "ERROR DE ARCHIVO AL CAMBIAR LA FECHA, INTENTA DE NUEVO\n";
        return false;
    }
    return false;
}

bool eliminarRegistroDep() {
    int id;
    std::cout << "INGRESAR ID DEL DEPORTE: ";
    std::cin >> id;
    int pos = buscarDeporte(id);
    if (pos > -1) {
        FILE * archivo = fopen("deportes.dat", "r+b");
        if (archivo == NULL) {
            std::cout << "ERROR ABRIENDO EL ARCHIVO \n";
            return false;
        }
        Deporte leer;
        fseek(archivo, sizeof leer * pos, SEEK_SET);
        fread(&leer, sizeof leer, 1, archivo);

        leer.setEstado(false);
        fseek(archivo, sizeof leer * pos, SEEK_SET);
        if (fwrite(&leer, sizeof leer, 1, archivo)) {
            fclose(archivo);
            std::cout << "REGISTRO ELIMINADO CON EXITO \n";
            return true;
        }
        fclose(archivo);
        std::cout << "ERROR DE ARCHIVO, INTENTA DE NUEVO\n";
        return false;
    }
    return false;
}


#endif // DEPORTE_H_INCLUDED
