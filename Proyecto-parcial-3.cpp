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
    Reserva *arregloReservacion[60];
    // declaracion de tipo de info
    int IDMaterial, numPag, duracion, version;
    char clave;
    string nombre, autor, genero,so;
    //contadores
    int i = 0;
    int l = 0;
    int d = 0;
    int s = 0;
    //variables temporales
    Libro templ[30];
    Disco tempd[30];
    Software temps[30];
   
    // Se cargan los datos en los arreglos
    while (archivoMaterial >> IDMaterial) {
        archivoMaterial >> nombre;
        archivoMaterial >> clave;
        switch (clave)
        {
        case 'L':
            archivoMaterial >> numPag;
            archivoMaterial >> autor;
            templ[l].setIdMaterial(IDMaterial);
            templ[l].setTitulo(nombre);
            templ[l].setNumPag(numPag);
            templ[l].setAutor(autor);
            arregloMaterial[i] = &templ[l];
            l++;
            break;
        case 'D':
            archivoMaterial >> duracion;
            archivoMaterial >> genero;
            tempd[d].setIdMaterial(IDMaterial);
            tempd[d].setTitulo(nombre);
            tempd[d].setDuracion(duracion);
            tempd[d].setGenero(genero);
            arregloMaterial[i] = &tempd[d];
            d++;
            break;
        case 'S':
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
    for (int cont = 0; cont < 20; cont++) {
        arregloMaterial[cont]->muestraDatos();
    }
    return 0;
}
