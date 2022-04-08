#include "../include/listaP.h"
#include "../include/pacientes.h"
#include "../include/listaA.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listaP{
  Paciente* pac;
  ListaP* ant;
  ListaP* prox;
};

ListaP* iniciaListaPacientes()
{
    return NULL;
}

ListaP* insereListaPaciente(ListaP* p, Paciente* paciente){

    ListaP* nova = (ListaP*)malloc(sizeof(ListaP));
    nova->pac = paciente;
    nova->ant = NULL;
    nova->prox = p;

    if(p != NULL)
    {
        p->ant = nova;
    }

    return nova;
}


void destroiListaPaciente(ListaP* lista){

    ListaP* p = lista;
    ListaP* t;

    while (p!= NULL){
        t = p->prox;
        destroiPaciente(p->pac);
        free(p);
        p = t;
    }

}

Paciente* procuraPacienteLista(ListaP* lista, char* nome){

    for(ListaP* p = lista; p != NULL; p = p->prox){
    if(strcmp(nome,recuperaNome(p->pac)) == 0)
    {
        return p->pac;

    }       
  }
        return NULL;
}

