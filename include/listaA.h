#ifndef LISTAA_H
#define LISTAA_H

typedef struct listaA ListaA;

#include "listaP.h"
#include "amizades.h"

/**
 * @brief Inicia uma lista de amizades
 * @return Lista de amizades já iniciada
 */
ListaA* iniciaListaAmizades();

/**
 * @brief insere uma struct amizade na lista de amizades
 * @param l - Lista a qual vai ser adicionada a struct
 * @param amizade - struct a ser adicionada
 */
ListaA* insereListaAmizade(ListaA* l, Amizade* amizade);

/**
 * @brief calcula e aciona o amigo mais próximo
 * @param l - lista de amigos a ser analisada
 * @param pac - struct do paciente
 * @param linha - um inteiro linha para verificar a linha que esta sendo lida
 * @return um nome do amigo mais proximo
 */
char* acionaAmigoMaisProximo(ListaA* l, Paciente* pac, int linha);

/**
 * @brief destroi a lista de amizade armazenada
 * @param l - Lista a ser destruida
 * @return memoria liberada da lista de amizade
 */
void destroiListaAmizade(ListaA* l);

#endif