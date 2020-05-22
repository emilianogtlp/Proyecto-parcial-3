#include "Material.h"

Material::Material()
{
	titulo = "default";
	idMaterial = 0;
}

Material::Material(int id, std::string titu)
{
	titulo = titu;
	idMaterial = id;
}

void Material::setTitulo(std::string titu)
{
	titulo = titu;
}

void Material::setIdMaterial(int idmat)
{
	idMaterial = idmat;
}

std::string Material::getTitulo()
{
	return titulo;
}

int Material::getIdMaterial()
{
	return idMaterial;
}
