#include<iostream>
#include<cstring>
#include<ctime>
#include "funcionesglobales.h"
#include "Fecha.h"
#include "Deporte.h"

#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

bool chequeoFecha(Fecha);
bool chequeoClaustro(int);
bool chequeoDni(int);
bool chequeoDeporte(int);
bool chequeoMatricula(int);

class Jugador
{
protected:
    int dni;
    char nombre[100];
    char apellido [100];
    char email[100];
    int telefono;
    int claustro;
    int deporte;
    int numEquipo;
    Fecha inscripcion;
    float matricula;
    bool estado = true;
public:
    Jugador(int dni, const char* nombre, const char* apellido, const char* email, int telefono, int claustro, int deporte, int numequipo, Fecha inscripcion, float matricula, bool estado = true) {
        this->dni = dni;
        strcpy(this->nombre, nombre);
        strcpy(this->apellido, apellido);
        strcpy(this->email, email);
        this->telefono = telefono;
        this->claustro = claustro;
        this->deporte = deporte;
        this->numEquipo = numequipo;
        this->inscripcion = inscripcion;
        this-> matricula = matricula;
        this->estado = estado;
    }
    Jugador() {}
    bool Cargar()
    {
        int dia, mes, agno;
        std::cout << "INGRESAR DNI ";
        std::cin >> dni;
        if (!chequeoDni(dni)) return false;
        std::cout << "INGRESAR NOMBRE ";
        cargarCadena(nombre, 100);
        std::cout << "INGRESAR APELLIDO ";
        cargarCadena(apellido, 100);
        std::cout << "INGRESAR EMAIL ";
        cargarCadena(email, 100);
        std::cout << "INGRESAR TELEFONO ";
        std::cin >> telefono;
        std::cout << "INGRESAR CLAUSTRO ";
        std::cin >> claustro;
        if (!chequeoClaustro(claustro)) return false;
        std::cout << "INGRESAR DEPORTE ";
        std::cin >> deporte;
        if (!chequeoDeporte(deporte) || buscarDeporte(deporte) < 0) return false;
        std::cout << "INGRESAR NUMERO DE EQUIPO ";
        std::cin >> numEquipo;
        std::cout << "INGRESAR FECHA DE INSCRIPCION ";
        std::cout << "DIA ";
        std::cin >> dia;
        if (dia < 0 || dia > 31)
        {
            std::cout << "DIA INVALIDO"<< std::endl;
            return false;
        }
        inscripcion.setDia(dia);
        std::cout << "MES ";
        std::cin >> mes;
        if (mes < 0 || mes > 12)
        {
            std::cout << "MES INVALIDO"<< std::endl;
            return false;
        }
        inscripcion.setMes(mes);
        std::cout << "ANHO ";
        std::cin >> agno;
        inscripcion.setAnio(agno);
        if (!chequeoFecha(inscripcion)) return false;
        std::cout << "MATRICULA ";
        std::cin >> matricula;
        if (!chequeoMatricula(matricula)) return false;
        return true;
    }
    void Mostrar()
    {
        std::cout << "DNI: " << dni << std::endl;
        std::cout << "NOMBRE: " << nombre << std::endl;
        std::cout << "APELLIDO: " << apellido << std::endl;
        std::cout << "EMAIL: " << email << std::endl;
        std::cout << "TELEFONO: " << telefono << std::endl;
        std::cout << "CLAUSTRO: " << claustro << std::endl;
        std::cout << "DEPORTE: " << deporte << std::endl;
        std::cout << "NUMERO DE EQUIPO: "<<numEquipo << std::endl;
        std::cout << "FECHA DE INSCRIPCION: ";
        inscripcion.Mostrar();
        std::cout << "MATRICULA: " << matricula << std::endl << std::endl;
    }
    int getDni()
    {
        return dni;
    }
    const char * getNombre()
    {
        return nombre;
    }
    int getClaustro()
    {
        return claustro;
    }

    int getDeporte()
    {
        return deporte;
    }
    Fecha getInscripcion()
    {
        return inscripcion;
    }
    bool Existe()
    {
        return estado;
    }
    float getMatricula()
    {
        return matricula;
    }
    void setDni(int num)
    {
        dni = num;
    }
    void setNombre(char * nom)
    {
        strcpy(nombre, nom);
    }
    void setApellido(char * ap)
    {
        strcpy(apellido, ap);
    }
    void setEmail(char * em)
    {
        strcpy(email, em);
    }
    void setClaustro(int cla)
    {
        if (cla > 0 && cla < 5)
        {
            claustro = cla;
        }
    }
    void setDeporte(int cla)
    {
        if (cla > 0 && cla < 11)
        {
            deporte = cla;
        }
    }
    void setNumEquipo(int num)
    {
        numEquipo = num;
    }
    void setInscripcion(Fecha insc)
    {
        inscripcion = insc;
    }
    void setEstado(bool est)
    {
        estado = est;
    }
    void setFecha(Fecha fecha) {
        inscripcion = fecha;
    }
};

bool chequeoMatricula(int matricula)
{
    if (matricula < 0)
    {
        std::cout << "LA MATRICULA ES INVALIDA"<< std::endl;
        return false;
    }
    return true;
}

bool chequeoDeporte(int deporte)
{
    if (deporte > 10 || deporte < 1)
    {
        std::cout << "EL DEPORTE ESTA MAL"<< std::endl;
        return false;
    }
    return true;
}

bool chequeoDni(int dni)
{
    FILE * archivo = fopen("jugadores.dat", "rb");
    Jugador leer;
    while (fread(&leer, sizeof leer, 1, archivo))
    {
        if (leer.getDni() == dni && leer.Existe())
        {
            std::cout << "EL DNI YA EXISTE"<< std::endl;
            return false;
        }
    }
    fclose(archivo);
    return true;
}

bool chequeoClaustro(int claustro)
{
    if (claustro > 4 || claustro < 1)
    {
        std::cout << "EL CLAUSTRO ESTA MAL"<< std::endl;
        return false;
    }
    return true;
}

bool chequeoFecha(Fecha fecha)
{
    time_t rawtime;
    struct tm * fechaActual;
    time ( &rawtime );
    fechaActual = localtime ( &rawtime );
    if (fecha.getAnio() > (fechaActual->tm_year + 1900))
    {
        std::cout << "LA FECHA ES INVALIDA"<< std::endl;
        std::cout << fechaActual->tm_year;
        return false;
    }
    if (fecha.getAnio() == fechaActual->tm_year + 1900)
    {
        if (fecha.getMes() > fechaActual->tm_mon + 1)
        {
            std::cout << "LA FECHA ES INVALIDA"<<std::endl;
            return false;
        }
        if (fecha.getMes() == fechaActual->tm_mon + 1 && fecha.getDia() > fechaActual->tm_mday)
        {
            std::cout << "LA FECHA ES INVALIDA"<< std::endl;
            return false;
        }
    }
    return true;
}

bool agregarJugador()
{
    FILE * archivo = fopen("jugadores.dat", "ab");
    if (archivo == NULL)
    {
        return false;
    }
    Jugador registro;
    bool exito = registro.Cargar();
    if (exito)
    {
        fwrite(&registro, sizeof registro, 1, archivo);
        std::cout << "REGISTRO ESCRITO CON EXITO"<< std::endl;
    }
    fclose(archivo);
    return true;
}

bool mostrarJugadores()
{
    FILE * archivo = fopen("jugadores.dat", "rb");
    if (archivo == NULL)
    {
        std::cout << "ERROR ABRIENDO EL ARCHIVO \n";
        return false;
    }
    Jugador leer;
    while(fread(&leer, sizeof leer, 1, archivo))
    {
        if (leer.Existe()) leer.Mostrar();
    }
    fclose(archivo);
    return true;
}

int buscarJugador (int dni) {
    FILE * archivo = fopen("jugadores.dat", "rb");
    if (archivo == NULL) {
        std::cout << "ERROR ABRIENDO EL ARCHIVO \n";
        return -1;
    }
    Jugador leer;
    int pos = 0;
    while (fread(&leer, sizeof leer, 1, archivo)) {
        if (leer.getDni() == dni && leer.Existe()) {
            leer.Mostrar();
            fclose(archivo);
            return pos;
        }
        pos++;
    }
    std::cout << "NO SE ENCONTRO EL JUGADOR CON EL DNI INGRESADO \n";
    fclose(archivo);
    return -2;
}

bool modificarFecha() {
    int dni;
    std::cout << "INGRESAR DNI DEL JUGADOR: ";
    std::cin >> dni;
    int pos = buscarJugador(dni);
    if (pos > -1) {
        FILE * archivo = fopen("jugadores.dat", "r+b");
        if (archivo == NULL) {
            std::cout << "ERROR ABRIENDO EL ARCHIVO \n";
            return false;
        }
        Jugador leer;
        fseek(archivo, sizeof leer * pos, SEEK_SET);
        fread(&leer, sizeof leer, 1, archivo);
        Fecha fecha;
        fecha.Cargar();
        leer.setFecha(fecha);
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

bool eliminarRegistro() {
    int dni;
    std::cout << "INGRESAR DNI DEL JUGADOR: ";
    std::cin >> dni;
    int pos = buscarJugador(dni);
    if (pos > -1) {
        FILE * archivo = fopen("jugadores.dat", "r+b");
        if (archivo == NULL) {
            std::cout << "ERROR ABRIENDO EL ARCHIVO \n";
            return false;
        }
        Jugador leer;
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


#endif // JUGADOR_H_INCLUDED
