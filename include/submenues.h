#include<iostream>
#include<cstring>
#include"Deporte.h"
#include"Jugador.h"
#include"funcionesSubmenues.h"

#ifndef SUBMENUES_H_INCLUDED
#define SUBMENUES_H_INCLUDED

namespace submenu
{
void jugadores()
{
    int opc;
    int dni;
    while (true)
    {
        std::cout << "SUBMENU JUGADORES\n";
        std::cout << " 1. AGREGAR JUGADOR \n 2. LISTAR JUGADOR POR DNI \n 3. LISTAR TODOS LOS JUGADORES \n 4. MODIFICAR FECHA DE INSCRIPCION \n 5. ELIMINAR REGISTRO DE JUGADOR \n 0. SALIR \n OPCION:";
        std::cin >> opc;
        system("cls");
        switch (opc)
        {
        case 1:
            agregarJugador();
            break;
        case 2:
            std::cout << "INGRESAR DNI DEL JUGADOR: ";
            std::cin >> dni;
            buscarJugador(dni);
            break;
        case 3:
            mostrarJugadores();
            break;
        case 4:
            modificarFecha();
            break;
        case 5:
            eliminarRegistro();
            break;
        case 0:
            return;
        }
        system("pause");
        system("cls");
    }
}
void deportes()
{
    int opc;
    int id;
    while (true)
    {
        std::cout << "SUBMENU DEPORTES\n";
        std::cout << " 1. AGREGAR DEPORTE \n 2. LISTAR DEPORTE POR ID \n 3. LISTAR TODOS LOS DEPORTES \n 4. MODIFICAR FECHA DE ORIGEN \n 5. ELIMINAR REGISTRO DE DEPORTE \n 0. SALIR \n OPCION:";
        std::cin >> opc;
        system("cls");
        switch (opc)
        {
        case 1:
            agregarDeporte();
            break;
        case 2:
            std::cout << "INGRESAR ID DEL DEPORTE: ";
            std::cin >> id;
            buscarDeporte(id);
            break;
        case 3:
            mostrarDeportes();
            break;
        case 4:
            modificarOrigen();
            break;
        case 5:
            eliminarRegistroDep();
            break;
        case 0:
            return;
        }
        system("pause");
        system("cls");
    }
}
void configuracion()
{
    int opc;
    const char * archivoDep = "deportes";
    const char * archivoJug = "jugadores";
    Deporte objDep;
    Jugador objJug;
    while (true)
    {
        std::cout << "SUBMENU CONFIGURACION\n";
        std::cout << " 1. BACKUP ARCHIVO JUGADRES\n 2. BACKUP ARCHIVO DEPORTES\n 3. RESTAURAR ARCHIVO JUGADORES\n 4. RESTAURAR ARCHIVO DEPORTES\n 5. ESTABLECER DATOS INICIO\n";
        std::cout << " 0. REGRESAR\n";
        std::cout << "OPCION: ";
        std::cin >> opc;
        system("cls");
        switch (opc)
        {
        case 1:
            crearBackupJugador(archivoJug, objJug);
            break;
        case 2:
            crearBackupDeporte (archivoDep, objDep);
            break;
        case 3:
            restaurarArchivoJugador (archivoJug, objJug);
            break;
        case 4:
            restaurarArchivoDeporte (archivoDep, objDep);
            break;
        case 5:
            establecerDatosInicio(archivoJug, archivoDep);
            break;
        case 0:
            return;
        }
        system("pause");
        system("cls");
    }

}
void reportes(){
    int opc;
        while (true)
        {
            std::cout << "MENU PRINICIPAL\n";
            std::cout << " 1. PUNTO 1 \n 2. PUNTO 2\n 0. SALIR \n OPCION: ";
            std::cin >> opc;
            system("cls");
            switch (opc)
            {
            case 1:
                punto1();
                break;
            case 2:
                punto2();
                break;
            case 0:
                return;
            default:
                std::cout << "Opcion incorrecta" << std::endl;
                break;
            }
            system("pause");
            system("cls");
        }
    }

}

#endif // SUBMENUES_H_INCLUDED
