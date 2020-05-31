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
    ofstream archivoReserva_salida;
    archivoMaterial.open("Material.txt");
    archivoReserva.open("Reserva.txt");
    archivoReserva_salida.open("Reserva_actualizado.txt");
    
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
    Reserva reservasmaterial[60];
    int basura;
    int numero_reservas=0;
    int numero_reservas_conflicto = 0;
    // Varios
    int numErrores = 0;
    int respuesta;
    int idmaterialt;
    int numeromatenarr;
    Fecha fechat2;
    Fecha fecha_inicio;
    Fecha fecha_fin;
    Fecha fecha_h;
    Reserva reserva_h;
    //ejecutadores
    int ejecutador1 = 0;
    int ejecutador_menu = 1;
    int ejecutador_material = 0;
    int comprobante_material = 0;
    int comprobante_reserva = 0;
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
            cout << "Ingrese su ID de cliente:" << endl;
            cin >> IDcliente;
            cout << "Ingrese el ID del material:" << endl;
            cin >> idmaterialt;
            while (comprobante_material == 0) {
                for (int cont = 0; cont < i; cont++)
                {
                    if (arregloMaterial[cont]->getIdMaterial() == idmaterialt) {
                        numeromatenarr = cont;
                        comprobante_material = 1;
                    }
                }
                if (comprobante_material == 0) {
                    cout << "Ha ingresado un ID invalido, digite uno nuevo: " << endl;
                    cin >> idmaterialt;
                }
            }
            comprobante_material = 0;
            cout << "Ingrese una fecha para la reserva: " << endl;
            cin >> fechat;
            for (int cont2 = 0; cont2 < r; cont2++)
            {
                if (arregloReservacion[cont2].getIdmaterial() == idmaterialt)
                {
                    reservasmaterial[numero_reservas].setReserva(IDcliente, idmaterialt, arregloReservacion[cont2].getFecha());
                    numero_reservas++;
                    
                    /*fecha_inicio = arregloReservacion[cont2].getFecha();
                    fecha_fin = arregloReservacion[cont2].calculaFechaFinReserva(arregloMaterial[numeromatenarr]->cantidadDiasPrestamo());
                    reserva_h.setFecha(fechat);
                    fecha_h = reserva_h.calculaFechaFinReserva(arregloMaterial[numeromatenarr]->cantidadDiasPrestamo());
                    cout << "Fechas de reserva existente:" << endl;
                    cout << fecha_inicio << endl;
                    cout << fecha_fin << endl;
                    cout << "Fechas de reserva hipotetica:" << endl;
                    cout << fechat << endl;
                    cout << fecha_h << endl;
                    if (((fechat >= fecha_inicio && fechat < fecha_fin) || (fecha_h<fecha_fin && fecha_h>fecha_inicio))&&comprobante_reserva == 0)
                    {
                        cout << "El material que ha seleccionado ya se encuentra reservado en esa fecha" << endl;
                        comprobante_reserva = 1;
                    }
                    if ((fechat>=fecha_fin || fecha_h<=fecha_inicio) && comprobante_reserva == 0)
                    { 
                        arregloReservacion[r].setReserva(IDcliente, idmaterialt, fechat);
                        r++;
                        comprobante_reserva = 1;
                        cout << "Reserva efectuada" << endl;
                    }*/
                }
            }
            for (int cont3 = 0; cont3 < numero_reservas; cont3++)
            {
                fecha_inicio = reservasmaterial[cont3].getFecha();
                fecha_fin = reservasmaterial[cont3].calculaFechaFinReserva(arregloMaterial[numeromatenarr]->cantidadDiasPrestamo());
                reserva_h.setFecha(fechat);
                fecha_h = reserva_h.calculaFechaFinReserva(arregloMaterial[numeromatenarr]->cantidadDiasPrestamo());
                if (((fechat >= fecha_inicio && fechat < fecha_fin) || (fecha_h<fecha_fin && fecha_h>fecha_inicio)) && comprobante_reserva == 0)
                {
                    numero_reservas_conflicto++;
                    comprobante_reserva = 1;
                }
            }
            if (numero_reservas_conflicto == 0)
            {
                arregloReservacion[r].setReserva(IDcliente, idmaterialt, fechat);
                r++;
                comprobante_reserva = 1;
                cout << "Reserva efectuada" << endl;
            }
            if (numero_reservas_conflicto != 0)
            {
                cout << "El material que ha seleccionado tiene " << numero_reservas << " reservaciones de las cuales ";
                cout << numero_reservas_conflicto << " se empalman con la suya " << endl;
            }
            if (comprobante_reserva == 0) {
                cout << "Reserva efectuada" << endl;
                arregloReservacion[r].setReserva(IDcliente, idmaterialt, fechat);
                r++;
            }
            numero_reservas = 0;
            numero_reservas_conflicto = 0;
            comprobante_reserva = 0;
            break;
        case 6:
            cout << " Hasta pronto! ";
            for (int cont5 = 0; cont5 < r; cont5++)
            {
                archivoReserva_salida << arregloReservacion[cont5].getFecha().getDia() << " ";
                //cout << arregloReservacion[cont5].getFecha().getDia() << " ";
                archivoReserva_salida << arregloReservacion[cont5].getFecha().getMes() << " ";
                //cout << arregloReservacion[cont5].getFecha().getMes() << " ";
                archivoReserva_salida << arregloReservacion[cont5].getFecha().getAnio() << " ";
                //cout << arregloReservacion[cont5].getFecha().getAnio() << " ";
                archivoReserva_salida << arregloReservacion[cont5].getIdmaterial() << " ";
                //cout << arregloReservacion[cont5].getIdmaterial() << " ";
                archivoReserva_salida << arregloReservacion[cont5].getIdcliente() << endl;
                //cout << arregloReservacion[cont5].getIdcliente() << endl;
            }
            ejecutador_menu = 0;
            
            break;
        default:
            cout << "ERROR";
            ejecutador_menu = 0;
            break;
        }
    }
    //archivoReserva << "holaaaa" << endl;
    archivoReserva_salida.close();
    archivoMaterial.close();
    archivoReserva.close();
    return 0;
}

// Pruebas
//int main() {
//	Fecha fecha_inicio(20, 11, 2017);
//	Fecha fecha_fin(22, 11, 2017);
//	Fecha fechat(15, 11, 2017);
//	Fecha fechah(17, 11, 2017);
//	if (fechat<fecha_inicio) {
//		cout << "si";
//	}
//	else
//	{
//		cout << "no";
//	}
//
//	return 0;
//}

