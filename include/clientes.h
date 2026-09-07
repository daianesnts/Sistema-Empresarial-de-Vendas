#ifndef CLIENTE_H
#define CLIENTE_H

#include "erros.h"
#include <cstdlib>

#define ARQUIVO_CLIENTES "clientes.txt"
#define TAMANHO_NOME 64 + 1
#define TAMANHO_CPF 14 + 1

#define CLIENTE_EXCLUIR 0

// Representa um cliente cadastrado no sistema.
struct Cliente {
  int id;
  char nome[TAMANHO_NOME];
  char cpf[TAMANHO_CPF];
};

// Tabela dinâmica de clientes carregados em memória.
struct TabelaCliente {
  int qtd;
  Cliente *dados;
};

bool encontrarIdCliente(TabelaCliente &tabela, int id);
int verificarCadastro(char *conteudo[], TabelaCliente &tabela);
void efetuarExclusao(TabelaCliente &tabela, int id);
void efetuarCadastro(TabelaCliente &tabela, char *conteudo[]);
void efetuarPesquisa(TabelaCliente &tabela, char *nomePesquisa);
void carregarClientes(TabelaCliente &tabela);
void corrigirTabelaInterface(TabelaCliente &tabela, int id);
void liberarMemoria(TabelaCliente &tabela);

#endif // CLIENTE_H
