#ifndef VENDAS_H
#define VENDAS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstring>
#include "gestao_estoque.h"

#define ERRO_QTD_INVALIDA -4  // Quantidade informada menor ou igual a zero

// Representa um item dentro de uma venda. 
struct ItemVenda {
    int codigoProduto;
    char descricao[100];
    float precoUnitario;
    int quantidade;
    float subtotal;
};

// Representa uma venda completa com seus itens. 
struct Venda {
    int numeroVenda;
    char data[11];
    int codigoCliente;
    int qtdLista;
    ItemVenda *itens;
    float totalVenda;
};

void inicializarVenda(Venda &venda);
void salvarVenda(Venda* venda);
void adicionarItem(TabelaProduto &tabela, Venda &venda, int indice, int qtd);
bool carregarListaVenda(Venda &venda);
void armazenarListaVenda(ItemVenda &item);
void excluirListaVenda();
int efetuarPesquisa(int &indice, int &qtd, char **dados, TabelaProduto &tabela);
int efetuarRemocaoVenda(TabelaProduto &tabela, Venda &venda, int indice);
void resetarVenda(Venda &venda);

#endif // VENDAS_H
