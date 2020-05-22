#include "Software.h"

Software::Software():Material()
{
	Version = 0;
	SO = "default";
}

Software::Software(int id, std::string titu, int ver, std::string so):Material(id,titu)
{
	Version = ver;
	SO = so;
}

void Software::setVersion(int ver)
{
	Version = ver;
}

void Software::setOS(std::string os)
{
	SO = os;
}

int Software::getVersion()
{
	return Version;
}

std::string Software::getOS()
{
	return SO;
}

void Software::muestraDatos()
{
	std::cout << "ID: " << idMaterial << " | Titulo: " << titulo << " | SO: " << SO << " | Version: " << Version << std::endl;
}

int Software::cantidadDiasPrestamo()
{
	return 1;
}
