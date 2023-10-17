

// ARCHIVO TP REALIZADO POR:
// BENJAMIN DURAN
// MAXIMO TISCORNIA


#include<iostream>
#include<cstring>
#include<ctime>
#include "Jugador.h"
#include "Deporte.h"
#include "submenues.h"
#include "RegDeporte.h"

int main()
{
    int opc;
    while (true)
    {
        std::cout << "MENU PRINICIPAL\n";
        std::cout << " 1. SUBMENU JUGADORES \n 2. SUBMENU DEPORTES \n 3. REPORTES \n 4. CONFIGURACION \n 0. SALIR \n OPCION: ";
        std::cin >> opc;
        system("cls");
        switch (opc)
        {
        case 1:
            submenu::jugadores();
            break;
        case 2:
            submenu::deportes();
            break;
        case 3:
            submenu::reportes();
            break;
        case 4:
            submenu::configuracion();
            break;
        case 0:
            return 0;
        default:
            std::cout << "Opcion incorrecta" << std::endl;
            break;
        }
        system("cls");
    }
}

