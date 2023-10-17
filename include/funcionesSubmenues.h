#include<iostream>
#include<cstring>
#include "Deporte.h"
#include "Jugador.h"
#include "RegDeporte.h"
#ifndef FUNCIONESSUBMENUES_H_INCLUDED
#define FUNCIONESSUBMENUES_H_INCLUDED

const char* wb = "wb";
const char* rb = "rb";
const char* ab= "ab";

void crearBackupJugador(const char * archivo, Jugador obj) {
    char nomArchivo[50];
    strcpy(nomArchivo, archivo);
    strcat(nomArchivo, ".dat");
    FILE * puntero = fopen(nomArchivo, rb);
    char backup[50];
    strcpy(backup, archivo);
    strcat(backup, ".bkp");
    FILE * pBack = fopen(backup, wb);
    if (puntero == NULL) {
        puntero = fopen(nomArchivo, wb);
        fclose(puntero);
        puntero = fopen(nomArchivo, rb);
    }
    while (fread(&obj, sizeof obj, 1, puntero)) {
        if (!fwrite(&obj, sizeof obj, 1, pBack)) {
            std::cout << "ERROR AL REALIZAR EL BACKUP" << std::endl;
        }
    }
    std::cout << "COPIA DE SEGURIDAD REALIZADA CON EXITO" << std::endl;
    fclose(puntero);
    fclose(pBack);
}
void crearBackupDeporte(const char * archivo, Deporte obj) {
    char nomArchivo[50];
    strcpy(nomArchivo, archivo);
    strcat(nomArchivo, ".dat");
    FILE * puntero = fopen(nomArchivo, rb);
    char backup[50];
    strcpy(backup, archivo);
    strcat(backup, ".bkp");
    FILE * pBack = fopen(backup, wb);
    if (puntero == NULL) {
        puntero = fopen(nomArchivo, wb);
        fclose(puntero);
        puntero = fopen(nomArchivo, rb);
    }
    while (fread(&obj, sizeof obj, 1, puntero)) {
        if (!fwrite(&obj, sizeof obj, 1, pBack)) {
            std::cout << "ERROR AL REALIZAR EL BACKUP" << std::endl;
        }
    }
    std::cout << "COPIA DE SEGURIDAD REALIZADA CON EXITO" << std::endl;
    fclose(puntero);
    fclose(pBack);
}

void restaurarArchivoJugador(const char * archivo, Jugador obj) {
    char nomArchivo[50];
    strcpy(nomArchivo, archivo);
    strcat(nomArchivo, ".dat");
    FILE * puntero = fopen(nomArchivo, wb);
    char backup[50];
    strcpy(backup, archivo);
    strcat(backup, ".bkp");
    FILE * pBack = fopen(backup, rb);
    if (pBack == NULL) {
        std::cout << "NO HAY UN BACKUP DEL ARCHIVO" << std::endl;
        return;
    }
    while (fread(&obj, sizeof obj, 1, pBack)) {
        if (!fwrite(&obj, sizeof obj, 1, puntero)) {
            std::cout << "ERROR AL RESTAURAR EL ARCHIVO" << std::endl;
        }
    }
    std::cout << "ARCHIVO RESTAURADO EXITOSAMENTE" << std::endl;
    fclose(puntero);
    fclose(pBack);
}
void restaurarArchivoDeporte(const char * archivo, Deporte obj) {
    char nomArchivo[50];
    strcpy(nomArchivo, archivo);
    strcat(nomArchivo, ".dat");
    FILE * puntero = fopen(nomArchivo, wb);
    char backup[50];
    strcpy(backup, archivo);
    strcat(backup, ".bkp");
    FILE * pBack = fopen(backup, rb);
    if (pBack == NULL) {
        std::cout << "NO HAY UN BACKUP DEL ARCHIVO" << std::endl;
        return;
    }
    while (fread(&obj, sizeof obj, 1, pBack)) {
        if (!fwrite(&obj, sizeof obj, 1, puntero)) {
            std::cout << "ERROR AL RESTAURAR EL ARCHIVO" << std::endl;
        }
    }
    std::cout << "ARCHIVO RESTAURADO EXITOSAMENTE" << std::endl;
    fclose(puntero);
    fclose(pBack);
}

bool establecerDatosInicio(const char* archivoJug, const char* archivoDep) {
    char nomArchivoDep[50];
    strcpy(nomArchivoDep, archivoDep);
    strcat(nomArchivoDep, ".dat");
    char nomArchivoJug[50];
    strcpy(nomArchivoJug, archivoJug);
    strcat(nomArchivoJug, ".dat");
    FILE * punteroJug = fopen(nomArchivoJug, wb);
    FILE * punteroDep = fopen(nomArchivoDep, wb);
    if (punteroJug == NULL || punteroDep == NULL) {
        std::cout << "ERROR ABRIENDO EL ARCHIVO" << std::endl;
        return false;
    }
    Jugador jugadoresInicio[10]{
        Jugador (1111, "Lalo", "Landa", "llanda@gmail.com", 11110101, 1, 1, 1, Fecha(20, 5, 2020), 0),
        Jugador(2222, "Martin", "Pescador", "mpescador@gmail.com", 22220202, 1, 2, 2, Fecha(2, 5, 2021), 212.75),
        Jugador(3333, "Susana", "Oria", "soria@gmail.com", 33330303, 1, 2, 2, Fecha(25, 12, 2021), 0),
        Jugador(4444, "Elena", "Nito", "enito@gmail.com", 44440404, 1, 4, 3, Fecha(14, 2, 2022), 55.75),
        Jugador(5555, "Esteban", "Quito", "equito@gmail.com", 55550505, 2, 5, 4, Fecha(10, 3, 2022), 173),
        Jugador(6666, "Maria", "Ada", "mada@gmail.com", 66660606, 2, 5, 4, Fecha(23, 4, 2022), 226.5),
        Jugador(7777, "Estela", "Guito", "eguito@gmail.com", 77770707, 3, 5, 6, Fecha(25, 5, 2022), 0),
        Jugador(8888, "Armando", "Lio", "alio@gmail.com", 88880808, 4, 6, 8, Fecha(30, 12, 2022), 215.25),
        Jugador(9999, "Olga", "Zan", "ozan@gmail.com", 99990909, 4, 6, 8, Fecha(10, 1, 2023), 79),
        Jugador(1234, "Elsa", "Pallito", "epallito@gmail.com", 12340102, 4, 8, 9, Fecha(10, 5, 2023), 75.25)
    };
    Deporte deportesInicio[10]{
        Deporte("Futbol", 1, 1860),
        Deporte("Basket", 1, 1890),
        Deporte("Voley", 2, 1952),
        Deporte("Hockey", 2, 1930),
        Deporte("Rugby", 2, 1895),
        Deporte("Tenis", 3, 2003),
        Deporte("Ciclismo", 4, 195),
        Deporte("Esgrima", 4, 1930),
        Deporte("Polo", 5, 2005),
        Deporte("Natacion", 5, 1972)
    };

    for (int i = 0; i < 10; i++) {
        fclose(punteroDep);
        deportesInicio[i].setID(nuevaID());
        punteroDep = fopen(nomArchivoDep, ab);
        if (!fwrite(&deportesInicio[i], sizeof deportesInicio[i], 1, punteroDep)) {
            std::cout << "ERROR ESCRIBIENDO EN EL ARCHIVO";
            fclose(punteroDep);
            fclose(punteroJug);
            return false;
        }
        if (!fwrite(&jugadoresInicio[i], sizeof jugadoresInicio[i], 1, punteroJug)) {
            std::cout << "ERROR ESCRIBIENDO EN EL ARCHIVO";
            fclose(punteroDep);
            fclose(punteroJug);
            return false;
        }
    }

    fclose(punteroDep);
    fclose(punteroJug);
    std::cout << "DATOS DE INICIO PUESTOS CON EXITO" << std::endl;
    return true;
}


void mostrarCopiaJugador(const char * archivo, Jugador obj) {
    char nomArchivo[50];
    strcpy(nomArchivo, archivo);
    strcat(nomArchivo, ".bkp");
    FILE * puntero = fopen(nomArchivo, rb);
    if (puntero == NULL) {
        std::cout << "NO HAY UN BACKUP DEL ARCHIVO" << std::endl;
        return;
    }
    while (fread(&obj, sizeof obj, 1, puntero)) {
        obj.Mostrar();
    }
    std::cout << "ARCHIVO RESTAURADO EXITOSAMENTE" << std::endl;
    fclose(puntero);
}
void mostrarCopiaDeporte(const char * archivo, Deporte obj) {
    char nomArchivo[50];
    strcpy(nomArchivo, archivo);
    strcat(nomArchivo, ".bkp");
    FILE * puntero = fopen(nomArchivo, rb);
    if (puntero == NULL) {
        std::cout << "NO HAY UN BACKUP DEL ARCHIVO" << std::endl;
        return;
    }
    while (fread(&obj, sizeof obj, 1, puntero)) {
        obj.Mostrar();
    }
    std::cout << "ARCHIVO RESTAURADO EXITOSAMENTE" << std::endl;
    fclose(puntero);
}

bool punto1() {
    FILE * pJug = fopen("jugadores.dat", "rb");
    FILE * pDep = fopen("deportes.dat", "rb");
    if (pJug == NULL || pDep == NULL) {
        std::cout << "ERROR DE ARCHIVO: EL ARCHIVO NO EXISTE O NO SE TIENEN PERMISOS\n";
        return false;
    }
    Jugador jug;
    Deporte dep;
    int contDeportes = 0;
    while (fread(&dep, sizeof dep, 1, pDep)) {
        contDeportes++;
    }
    const int tam = contDeportes;
    int* vectorDeportes = (int*)malloc(sizeof(int)*tam);
    inicializarCero(vectorDeportes, tam);
    while (fread(&jug, sizeof jug, 1, pJug)) {
        vectorDeportes[jug.getDeporte() - 1]++;
    }
    std::cout << "EL DEPORTE CON MENOS JUGADORES ES EL DEPORTE " << buscarMinPos(vectorDeportes, tam) + 1 << std::endl;
    fclose(pDep);
    fclose(pJug);

    return true;
}

bool punto2() {
    FILE * pJug = fopen("jugadores.dat", "rb");
    FILE * pDep = fopen("deportes.dat", "rb");
    FILE * pNuevo = fopen("deportes50alumnos.dat", "wb");
    if (pJug == NULL || pDep == NULL || pNuevo == NULL) {
        std::cout << "ERROR DE ARCHIVO: EL ARCHIVO NO EXISTE O NO SE TIENEN PERMISOS\n";
        return false;
    }
    Jugador jug;
    Deporte dep;
    int contDeportes = 0;
    while (fread(&dep, sizeof dep, 1, pDep)) {
        contDeportes++;
    }
    const int tam = contDeportes;
    int* vectorDeportes = (int*)malloc(sizeof(int)*tam);
    inicializarCero(vectorDeportes, tam);
    while (fread(&jug, sizeof jug, 1, pJug)) {
        vectorDeportes[jug.getDeporte() - 1]++;
    }
    fseek(pDep, 0, 0);
    while (fread(&dep, sizeof dep, 1, pDep)) {
        if (vectorDeportes[dep.getID() - 1] > 50 && dep.getTipo() == 1) {
            RegDeporte reg(
                           dep.getID(),
                           dep.getNombre(),
                           dep.getOrigen(),
                           vectorDeportes[dep.getID() - 1]
                           );
            if (!fwrite(&reg, sizeof reg, 1, pNuevo)) {
                std::cout << "ERROR ESCRIBIENDO EN EL ARCHIVO";
                fclose(pDep);
                fclose(pJug);
                fclose(pNuevo);
                return false;
            }
        }
    }
    std::cout << "ARCHIVO GENERADO CON EXITO\n";
    fclose(pDep);
    fclose(pJug);
    fclose(pNuevo);
    return true;
}

#endif // FUNCIONESSUBMENUES_H_INCLUDED
