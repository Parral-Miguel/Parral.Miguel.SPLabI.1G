#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "LinkedList.h"
#include "entidades.h"

int menu ();
void paises_listarUno(LinkedList* listaPaises,ePaises* pais, int index);
int listar_paises(LinkedList* listaPaises);
int mas_castigado(LinkedList* listaPaises);
int ordenarMasInfectados(LinkedList* listaPaises);

#endif // INFORMES_H_INCLUDED
