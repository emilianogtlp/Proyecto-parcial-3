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

Fecha Reserva::calculaFechaFinReserva(int m1)
{
	Fecha f2;
	f2 = fechaReservacion + m1;
	return f2;
}
