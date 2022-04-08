#ifndef CUIDADORES_H
#define CUIDADORES_H


//struct que informa todas as informações necessárias sobre o cuidador
typedef struct cuidadores Cuidadores;

Cuidadores* iniciaCuidador(char* nome);

/**
 * @brief retorna o nome do cuidador
 * @param c - struct do cuidador
 * @return o nome do cuidador
 */
char* retornaNomeCuidador(Cuidadores* c);

/**
 * @brief retorna a latitude do cuidador 
 * @param cuid - struct do cuidador
 * @return o valor da latitude do cuidador
 */
double retornaLatiCuidador(Cuidadores* cuid);

/**
 * @brief retorna a longitude do cuidador 
 * @param cuid - struct do cuidador
 * @return o valor da longitude do cuidador
 */
double retornaLongiCuidador(Cuidadores* cuid);

/**
 * @brief destroi a lista de cuidadores e libera a memoria alocada
 * @param c - lista de cuidadores a ser destruida
 */
void destroiCuidador(Cuidadores* c);

#endif