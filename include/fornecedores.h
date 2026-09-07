#ifndef FORNECEDORES_H
#define FORNECEDORES_H

#include "erros.h"

#define NOME1_TAM 42
#define NOME2_TAM 42
#define CONTATO_TAM 15

#define FORNECEDOR_EDITAR 0
#define FORNECEDOR_EXCLUIR 1

// Representa um fornecedor cadastrado no sistema.
struct Fornecedor {
  int codigo;
  char empresaNome[NOME1_TAM + 1];
  char responsavel[NOME2_TAM + 1];
  char contato[CONTATO_TAM + 1];
};

// Tabela dinamica de fornecedores carregados em memoria.
struct TabelaFornecedor {
  int qtd;
  Fornecedor *dados;
};

void InicializarTabela(TabelaFornecedor &tabela);
void carregarFornecedores(TabelaFornecedor &tabela);
void ArmazenarDados(TabelaFornecedor &tabela, Fornecedor &f);
bool verificarIdExistente(TabelaFornecedor &tabela, int codigo);
void formataContato(char contato[]);
void efetuarCadastro(char **dados,
                     TabelaFornecedor &tabela); // Chamado pelo modulo Interface
void efetuarExclusao(TabelaFornecedor &tabela,
                     int codigo); // Chamado pelo modulo Interface
void efetuarPesquisa(TabelaFornecedor &tabela,
                     char *filtro); // Chamado pelo modulo Interface
void efetuarEdicao(TabelaFornecedor &tabela, Fornecedor &f,
                   int indice);               // Chamado pelo modulo Interface
void efetuarEdicao(TabelaFornecedor &tabela); // Chamado pelo modulo Interface
int verificarCad(char **dados,
                 TabelaFornecedor &tabela); // Chamado pelo modulo Interface
int verificarEdicao(Fornecedor &f);         // Chamado pelo modulo Interface
int verificarEdicao(char **f);              // Chamado pelo modulo Interface
void corrigirTabelaInterface(TabelaFornecedor &tabela,
                             int codigo); // Chamado pelo modulo Interface
void LiberarMemoria(TabelaFornecedor &tabela);

#endif // FORNECEDORES_H
