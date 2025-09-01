#ifndef CLIENTE_H
#define CLIENTE_H

// registro das funcoes de clientes
void menu_Clientes();


typedef struct {
    int id;
    char nome[100];
    char cpf[15];       // Novo campo (formato: 000.000.000-00)
    char telefone[20];
    char email[100];
} Cliente;


void cadastrarCliente();
void listarClientes();

#endif