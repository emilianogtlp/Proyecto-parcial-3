#include "Fecha.h"
#include "Reserva.h"
#include "Libro.h"
#include "Software.h"
#include "Disco.h"
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
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
    

    //ejecutadores
    int ejecutador1 = 0;
   
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
            archivoReserva >> basura;
        }
        ejecutador1 = 0;
    }
    for (int cont = 0; cont < 20; cont++) {
        arregloMaterial[cont]->muestraDatos();
    }
    for (int cont = 0; cont < r; cont++)
    {
        cout << arregloReservacion[cont].getFecha() << " | " << arregloReservacion[cont].getIdmaterial();
        cout << " | " << arregloReservacion[cont].getIdcliente() << endl;
    }
    return 0;
}
