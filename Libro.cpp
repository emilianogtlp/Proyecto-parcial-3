#include "Libro.h"

Libro::Libro():Material()
{
	numPag = 0;
	Autor = "Autor default";
}

Libro::Libro(int id, std::string titu, int num, std::string au): Material(id,titu)
{
	numPag = num;
	Autor = au;
}

void Libro::setNumPag(int num)
{
	numPag = num;
}

void Libro::setAutor(std::string au)
{
	Autor = au;
}

int Libro::getNumPag()
{
	return numPag;
}

std::string Libro::getAutor()
{
	return Autor;
}

void Libro::muestraDatos()
{
	std::cout << "ID: " << idMaterial << " | Titulo: " << titulo << " | Numero de paginas: " << numPag << " | Autor: " << Autor << std::endl;
}

int Libro::cantidadDiasPrestamo()
{
	return 7;
}
