#ifndef LISTAC_H
#define LISTAC_H
#include "../include/cuidadores.h"

typedef struct listaC ListaC;

/**
 * @brief inicia uma lista de cuidadores
 * @return uma nova lista de cuidadores
 */
ListaC* iniciaListaCuidadores();

/**
 * @brief insere um cuidador na lista de cuidadores
 * @param c - lista de cuidadores
 * @param cuidador - struct de um cuidador
 * @return uma lista de cuidadores atualizada com os cuidadores inseridos
 */
ListaC* insereListaCuidador(ListaC* c, Cuidadores* cuidador);

/**
 * @brief calcula a distancia dos cuidadores de um paciente e aciona o mais proximo
 * @param pac - struct do paciente 
 * @param c - lista de cuidadores
 * @param linha - contador para saber qual linha está sendo lida
 * @return o nome do cuidador mais proximo
 */
char* acionaMaisProximo(ListaC* c, void* pac, int linha);

/**
 * @brief procura um cuidador na lista  
 * @param c - lista de cuidadores
 * @param nome - nome do cuidador a ser procurado na lista
 * @return retorna a struct do cuidador procurado na lista
 */
Cuidadores* procuraCuidadorLista(ListaC* c, char* nome);

/**
 * @brief Libera a memoria da lista de cuidadores
 * @param c - lista de cuidadores
 **/
void destroiListaCuid(ListaC* lista);

#endif