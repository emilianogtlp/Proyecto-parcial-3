#include "Fecha.h"

Fecha::Fecha()
{
	dd = 0;
	mm = 0;
	aa = 0;
}

Fecha::Fecha(int d, int m, int a)
{
	dd = d;
	mm = m;
	aa = a;
}

void Fecha::setFecha(int d, int m, int a)
{
	dd = d;
	mm = m;
	aa = a;
}

int Fecha::getDia()
{
	return dd;
}

int Fecha::getMes()
{
	return mm;
}

int Fecha::getAnio()
{
	return aa;
}

Fecha Fecha::operator+(int f1)
{
	int dia = 0, mes= 0, anio = 0;
	dia = dd + f1;
	if (mm == 2) {
		if (dia > 28) {
			dia = dia - 28;
			mes = 3;
			anio = aa;
		}
	}
	if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) {
		if (dia > 31) {
			dia = dia - 31;
			mes = mm + 1;
			anio = aa;
			if (mes > 12) {
				mes = 1;
				anio = aa + 1;
			}
		}
		else
		{
			mes = mm;
			anio = aa;
		}
	}
	if(mm == 4 || mm == 6 || mm == 9 || mm == 11)
	{
		if (dia > 30) {
			dia = dia-30;
			mes = mm + 1;
			anio = aa;
		}
		else
		{
			mes = mm;
			anio = aa;
		}
	}
	Fecha f2(dia, mes, anio);
	return f2;
}

bool Fecha::operator>=(Fecha f1)
{
	if (aa > f1.aa) {
		return true;
	}
	if (aa == f1.aa) {
		if (mm > f1.mm) {
			return true;
		}
		if (mm == f1.mm) {
			if (dd >= f1.mm) {
				return true;
			}
			if (dd < f1.dd) {
				return false;
			}
		}
		if (mm < f1.mm) {
			return false;
		}
	}
	if (aa < f1.aa) {
		return false;
	}
}

bool Fecha::operator<=(Fecha f1)
{
	if (aa < f1.aa) {
		return true;
	}
	if (aa == f1.aa) {
		if (mm < f1.mm) {
			return true;
		}
		if (mm == f1.mm) {
			if (dd <= f1.mm) {
				return true;
			}
			if (dd > f1.dd) {
				return false;
			}
		}
		if (mm > f1.mm) {
			return false;
		}
	}
	if (aa > f1.aa) {
		return false;
	}
}

bool Fecha::operator>(Fecha f1)
{
	if (aa > f1.aa) {
		return true;
	}
	if (aa == f1.aa) {
		if (mm > f1.mm) {
			return true;
		}
		if (mm == f1.mm) {
			if (dd > f1.mm) {
				return true;
			}
			if (dd <= f1.dd ) {
				return false;
			}
		}
		if (mm < f1.mm) {
			return false;
		}
	}
	if (aa < f1.aa) {
		return false;
	}
}

bool Fecha::operator<(Fecha f1)
{
	if (aa < f1.aa) {
		return true;
	}
	if (aa == f1.aa) {
		if (mm < f1.mm) {
			return true;
		}
		if (mm == f1.mm) {
			if (dd < f1.mm) {
				return true;
			}
			if (dd >= f1.dd) {
				return false;
			}
		}
		if (mm > f1.mm) {
			return false;
		}
	}
	if (aa > f1.aa) {
		return false;
	}
}

bool Fecha::operator==(Fecha f1)
{
	if ((aa == f1.aa) && (mm = f1.mm) && (dd = f1.dd)) {
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& os, Fecha f1)
{
	os << f1.dd;
	os << " / ";
	switch (f1.mm)
	{
	case 1:
		os << "Ene";
		break;
	case 2:
		os << "Feb";
		break;
	case 3:
		os << "Mar";
		break;
	case 4:
		os << "Abr";
		break;
	case 5:
		os << "May";
		break;
	case 6:
		os << "Jun";
		break;
	case 7:
		os << "Jul";
		break;
	case 8:
		os << "Ago";
		break;
	case 9:
		os << "Sep";
		break;
	case 10:
		os << "Oct";
		break;
	case 11:
		os << "Nov";
		break;
	case 12:
		os << "Dic";
		break;
	default:
		os << "Error";
		break;
	}
	os << " / " << f1.aa << endl;
	return os;
}

istream& operator>>(istream& os, Fecha& f1)
{
	cout << "Anio: " << endl;
	os >> f1.aa;
	cout << "Mes: " << endl;
	os >> f1.mm;
	//verificador de mes existente
	while (f1.mm > 12 || f1.mm < 1) 
	{
		cout << "Mes invalido, ingrese otro porfavor: " << endl;
		os >> f1.mm;
	}
	cout << "Dia: "<<endl;
	os >> f1.dd;
	// verifican que el dia sea real en el mes que se eligio
	while ((f1.mm == 1 || f1.mm == 3 || f1.mm == 5 || f1.mm == 7 || f1.mm == 8 || f1.mm == 10 || f1.mm == 12) && (f1.dd > 31 || f1.dd < 0))
	{
		cout << "Dia invalido para el mes elegido, intentelo de nuevo: " << endl;
		os >> f1.dd;
	}
	while ((f1.mm == 4 || f1.mm == 6 || f1.mm == 9 || f1.mm == 11)&&(f1.dd > 30 || f1.dd < 0))
	{
		cout << "Dia invalido para el mes elegido, intentelo de nuevo: " << endl;
		os >> f1.dd;
	}
	while ((f1.mm == 2) && (f1.dd < 0 || f1.dd>28)) {
		cout << "Dia invalido para el mes elegido, intentelo de nuevo: " << endl;
		os >> f1.dd;
	}
	return os;
}
