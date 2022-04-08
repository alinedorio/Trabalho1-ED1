//TAD criada com o objetivo de usarmos uma lista duplamente encadeada sem sentinela, para facilitar a organização e o entendimento do programa.
#ifndef LISTAP_H
#define LISTAP_H

#include "../include/pacientes.h"

typedef struct listaP ListaP;

/**
 * @brief inicia uma lista de pacientes
 * @return uma nova lista de pacientes
 */
ListaP* iniciaListaPacientes();

/**
 * @brief insere um paciente na lista de pacientes
 * @param p - lista de pacientes
 * @param paciente - struct de um paciente
 * @return uma lista de pacientes atualizada com os pacientes inseridos
 */
ListaP* insereListaPaciente(ListaP* p, Paciente* paciente);

/**
 * @brief Libera a memoria da lista de pacientes
 * @param lista - lista de pacientes
 **/
void destroiListaPaciente(ListaP* lista);

/**
 * @brief procura um paciente na lista  
 * @param p - lista de pacientes
 * @param nome - nome do paciente a ser procurado na lista
 * @return retorna a struct do paciente procurado na lista
 */
Paciente* procuraPacienteLista(ListaP* p, char* nome);

#endif