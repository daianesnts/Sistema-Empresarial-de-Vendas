#ifndef GESTAO_ESTOQUE_H
#define GESTAO_ESTOQUE_H

#include "erros.h"

#define TIPO_TAM 16
#define NOME_TAM 32

#define PRODUTO_EDITAR  0
#define Produto_EXCLUIR 1

#define ERRO_PRODUTO_NAO_EXISTE      -2  // ID de produto nao encontrado no estoque
#define ERRO_QUANTIDADE_INSUFICIENTE -3  // Quantidade solicitada maior que o estoque
#define PRODUTO_VALIDO                1  // Produto encontrado e quantidade suficiente

// Representa um produto no estoque.
struct Produto {
    int id;
    int Quantidade;
    char dia[3];
    char mes[3];
    char ano[5];
    float precoTotal;
    float preco;
    bool disponivel;
    char categoria[TIPO_TAM+1];
    char TipoUnidade[TIPO_TAM+1];
    char nome[NOME_TAM+1];
};

// Tabela dinamica de produtos carregados em memoria.
struct TabelaProduto {
    int qtd;
    Produto *dados;
};

void carregarProdutos(TabelaProduto &tabela);
void ArmazenarDados(TabelaProduto &tabela, Produto &f);
bool verificarIdExistente(TabelaProduto &tabela, int codigo);
int checarEstoque(int id, int quantidade, int &indice, TabelaProduto &tabela);
void removerEstoqueId(TabelaProduto &tabela, int id, int qtd);
void adicionarEstoqueId(TabelaProduto &tabela, int id, int qtd);
void efetuarCadastro(char **dados, TabelaProduto &tabela);              // Chamado pelo modulo Interface
void efetuarExclusao(TabelaProduto &tabela, int codigo);               // Chamado pelo modulo Interface
void efetuarPesquisa(TabelaProduto &tabela, char *filtro);             // Chamado pelo modulo Interface
void efetuarEdicao(TabelaProduto &tabela, Produto &f, int indice);    // Chamado pelo modulo Interface
void efetuarEdicao(TabelaProduto &tabela);                             // Chamado pelo modulo Interface
int verificarCad(char **dados, TabelaProduto &tabela);                 // Chamado pelo modulo Interface
int verificarEdicaoP(char **p);                                        // Chamado pelo modulo Interface
void corrigirTabelaInterface(TabelaProduto &tabela, int codigo);       // Chamado pelo modulo Interface
void LiberarMemoria(TabelaProduto &tabela);

#endif // GESTAO_ESTOQUE_H
