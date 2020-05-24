#include "Fecha.h"
#include "Reserva.h"
#include "Libro.h"
#include "Software.h"
#include "Disco.h"
#include <string.h>
#include <iostream>
#include <fstream>
int main()
{
    // Se declaran y abren los archvos de recursos
    ifstream archivoMaterial;
    ifstream archivoReserva;
    archivoMaterial.open("Material.txt");
    archivoReserva.open("Reserva.txt");
    
    // declaracion de matrices de distintos tipos donde se almacena la info
    Material *arregloMaterial[30];
    Reserva arregloReservacion[60];
    
    // declaracion de tipo de info
    int IDMaterial, IDcliente, numPag, duracion, version,dia,mes,anio;
    char clave;
    string nombre, autor, genero,so;
    
    //contadores
    int i = 0; // contador general para carga de materiales
    int l = 0; // contador especifico para carga de libros
    int d = 0; // contador especifico para carga de discos
    int s = 0; // contador especifico para carga de software 
    int r = 0; // contador general para carga de reserva
    int f = 0; // contador especifico para carga de fechas
    
    //variables temporales
    Libro templ[30];
    Disco tempd[30];
    Software temps[30];
    Fecha fechat;
    int basura;
    // Varios
    int numErrores = 0;
    int respuesta;
    int idmaterialt;
    Fecha fechat2;
    Fecha fecha_inicio;
    Fecha fecha_fin;
    //ejecutadores
    int ejecutador1 = 0;
    int ejecutador_menu = 1;
    int ejecutador_material = 0;
    int comprobante_material = 0;
    // Se cargan los datos en los arreglos
    while (archivoMaterial >> IDMaterial) {
        archivoMaterial >> nombre;
        archivoMaterial >> clave;
        switch (clave)
        {
        case 'L': // caso Libro
            archivoMaterial >> numPag;
            archivoMaterial >> autor;
            templ[l].setIdMaterial(IDMaterial);
            templ[l].setTitulo(nombre);
            templ[l].setNumPag(numPag);
            templ[l].setAutor(autor);
            arregloMaterial[i] = &templ[l];
            l++;
            break;
        case 'D': // caso Disco
            archivoMaterial >> duracion;
            archivoMaterial >> genero;
            tempd[d].setIdMaterial(IDMaterial);
            tempd[d].setTitulo(nombre);
            tempd[d].setDuracion(duracion);
            tempd[d].setGenero(genero);
            arregloMaterial[i] = &tempd[d];
            d++;
            break;
        case 'S': //Caso software
            archivoMaterial >> version;
            archivoMaterial >> so;
            temps[s].setIdMaterial(IDMaterial);
            temps[s].setTitulo(nombre);
            temps[s].setVersion(version);
            temps[s].setOS(so);
            arregloMaterial[i] = &temps[s];
            s++;
            break;
        default:
            cout << "error" << endl;
            break;
        }
        i++;
    }
    while (archivoReserva>>dia) {
        archivoReserva >> mes;
        archivoReserva >> anio;
        archivoReserva >> IDMaterial;
        //Verfica que IDmaterial exista
        for (int y = 0; y < i; y++) {
            if ((IDMaterial == arregloMaterial[y]->getIdMaterial())&&ejecutador1==0) {
                archivoReserva >> IDcliente;
                fechat.setFecha(dia, mes, anio);
                ejecutador1 = 1;
                arregloReservacion[r].setReserva(IDcliente, IDMaterial, fechat);
                r++;
            }
        }
        if (ejecutador1 == 0) {
            archivoReserva >> basura;
            numErrores++;
        }
        ejecutador1 = 0;
    }
    while (ejecutador_menu == 1)
    {
        cout << "               MENU" << endl;
        cout << "  1.- Consultar lista de Materiales" << endl;
        cout << "  2.- Consultar lista de reservaciones" << endl;
        cout << "  3.- Consultar las reservaciones de un material" << endl;
        cout << "  4.- Consultar las reservaciones de una fecha dada " << endl;
        cout << "  5.- Hacer una reservacion" << endl;
        cout << "  6.- Terminar" << endl;
        cin >> respuesta;
        while (respuesta < 1 || respuesta>6) {
            cout << "Respuesta invalida, intentelo de nuevo: " << endl;
            cin >> respuesta;
        }
        switch (respuesta)
        {
        case 1:
            for (int cont = 0; cont < i; cont++) {
                arregloMaterial[cont]->muestraDatos();
            }
            break;
        case 2:
            for (int cont = 0; cont < r; cont++)
            {
                cout << "Fecha inicio reservacion: " << arregloReservacion[cont].getFecha() << " | ";
                cout << "Fecha fin reservacion: ";
                for (int cont2 = 0; cont2 < i; cont2++)
                {
                    if (arregloReservacion[cont].getIdmaterial() == arregloMaterial[cont2]->getIdMaterial()) {
                        cout << arregloReservacion[cont].calculaFechaFinReserva(arregloMaterial[cont2]->cantidadDiasPrestamo());
                    }
                }
                cout << " |  ID Material: " << arregloReservacion[cont].getIdmaterial();
                cout << " |  ID cliente:" << arregloReservacion[cont].getIdcliente() << endl;
            }
            break;
        case 3:
            cout << "Escriba el ID del material: " << endl;
            cin >> idmaterialt;
            while (comprobante_material == 0) {
                for (int  cont = 0; cont < i; cont++)
                {
                    if (arregloMaterial[cont]->getIdMaterial() == idmaterialt) {
                        comprobante_material = 1;
                    }
                }
                if (comprobante_material == 0) {
                    cout << "Ha ingresado un ID invalido, digite uno nuevo: " << endl;
                    cin >> idmaterialt;
                }
            }
            comprobante_material = 0;
            for (int cont = 0; cont < i; cont++) {
                if (arregloMaterial[cont]->getIdMaterial() == idmaterialt)
                {
                    for (int cont2 = 0; cont2 < r; cont2++)
                    {
                        if (arregloMaterial[cont]->getIdMaterial() == arregloReservacion[cont2].getIdmaterial())
                        {
                            ejecutador_material = 1;
                            cout << "Nombre material: " << arregloMaterial[cont]->getTitulo() << " | ";
                            cout << "Fecha inicio reservacion: " << arregloReservacion[cont2].getFecha();
                            cout << " | Fecha fin reservacion: ";
                            cout << arregloReservacion[cont2].calculaFechaFinReserva(arregloMaterial[cont]->cantidadDiasPrestamo());
                            cout << endl;
                        }
                    }
                }
            }
            if (ejecutador_material == 0)
            {
                cout << "No se encontro ninguna reservacion para ese material" << endl;
            }
            ejecutador_material = 0;
            break;
        case 4:
            cin >> fechat2;
            for (int cont = 0; cont < r; cont++) {
                for (int cont2 = 0; cont2 < i; cont2++)
                {
                    if (arregloReservacion[cont].getIdmaterial() == arregloMaterial[cont2]->getIdMaterial()) {
                        fecha_inicio = arregloReservacion[cont].getFecha();
                        fecha_fin = arregloReservacion[cont].calculaFechaFinReserva(arregloMaterial[cont2]->cantidadDiasPrestamo());
                        if (fechat2 >= fecha_inicio&& fechat2 < fecha_fin) {
                            cout << "Nombre material: " << arregloMaterial[cont2]->getTitulo() << " | ";
                            cout << "Id cliente: " << arregloReservacion[cont].getIdcliente() << endl;
                        }
                    }
                }
            }
            break;
        case 5:

            break;
        case 6:
            cout << " Hasta pronto! ";
            ejecutador_menu = 0;
            break;
        default:
            cout << "ERROR";
            ejecutador_menu = 0;
            break;
        }
    }
    archivoMaterial.close();
    archivoReserva.close();
    return 0;
}


