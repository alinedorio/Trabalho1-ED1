#include "../include/amizades.h"
#include "../include/listaA.h"
#include "../include/pacientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct amizade{
  Paciente* p;
};

Amizade* iniciaAmizade(Paciente* p){

    Amizade* amizade = (Amizade*)malloc(sizeof(Amizade));
    amizade->p = p;

      return amizade;


}
char* retornaNomeAmizade(Amizade* a){

  
  return recuperaNome(a->p);

}


double recuperaLatiAmigo(Amizade* amigo, Paciente* pac){

  pac = amigo->p;
  retornaLatitude(pac);
   

}

double recuperaLongiAmigo(Amizade* amigo, Paciente* pac){

  pac = amigo->p;
  retornaLongitude(pac);
   

}


void criaAmizade(ListaP* p, FILE* arquivoApoio){

   
  
  char linha[1000];
  ListaA* a = iniciaListaAmizades();
  char* aux;
  Paciente* paciente1, *paciente2;
  //fgets(linha, 1000, arquivoApoio);
  while(fgets(linha, 1000, arquivoApoio) != NULL)
  { 
    
    aux = strtok(linha, ";\n");
    paciente1 = procuraPacienteLista(p, aux);
    aux = strtok(NULL, ";\n");
    paciente2 = procuraPacienteLista(p, aux);
    Amizade* amizade1 = iniciaAmizade(paciente1);
    Amizade* amizade2 = iniciaAmizade(paciente2);
    insereListaAmizade((ListaA*)recuperaListaAmizade(paciente1), amizade2);
    insereListaAmizade((ListaA*)recuperaListaAmizade(paciente2), amizade1);
     
  }
    //destroiListaAmizade(a);
    //destroiPaciente(paciente1);
    //destroiPaciente(paciente2);
    
}


void destroiAmizade(Amizade* a)
{

  free(a);
}
