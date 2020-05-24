#include "Reserva.h"

Reserva::Reserva()
{
	idCliente = 0;
	idMaterial = 0;
	fechaReservacion = Fecha();
}

Reserva::Reserva(int idC, int idM, Fecha fechar)
{
	idCliente = idC;
	idMaterial = idM;
	fechaReservacion = fechar;
}

void Reserva::setReserva(int idc, int idm, Fecha fechar)
{
	idCliente = idc;
	idMaterial = idm;
	fechaReservacion = fechar;
}

void Reserva::setIdcliente(int id)
{
	idCliente = id;
}

void Reserva::setIdmaterial(int idm)
{
	idMaterial = idm;
}

void Reserva::setFecha(Fecha f1)
{
	fechaReservacion = f1;
}

int Reserva::getIdcliente()
{
	return idCliente;
}

int Reserva::getIdmaterial()
{
	return idMaterial;
}

Fecha Reserva::getFecha()
{
	return fechaReservacion;
}

Fecha Reserva::calculaFechaFinReserva(int m1)
{
	Fecha f2;
	f2 = fechaReservacion + m1;
	return f2;
}
