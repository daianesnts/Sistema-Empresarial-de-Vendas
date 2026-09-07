#ifndef INTERFACE_H
#define INTERFACE_H

#include "gconio.h"
#include <cstring>
#include "fornecedores.h"
#include "gestao_estoque.h"
#include "vendas.h"
#include "clientes.h"

#define COLUNA_MAX 120
#define LINHA_MAX 30
#define BORDA_SUP_ESQUERDA 218
#define BORDA_SUP_DIREITA 191
#define BORDA_INF_ESQUERDA 192
#define BORDA_INF_DIREITA 217
#define LINHA_HORIZONTAL 196
#define LINHA_VERTICAL 179

#define ENTER '\r'
#define BACKSPACE 8
#define ESC 27
#define TECLA_ESCAPE 224
#define SETA_ESQ 75
#define SETA_DIR 77
#define SETA_CIMA 72
#define SETA_BAIXO 80

#define LINHAS_MAXIMAS_LISTA 18

#define DELAY 30
#define REMOVER_CURSOR() printf("\033[?25l")
#define RETORNAR_CURSOR() printf("\033[?25h")

#define FORNECEDORES_CONSULTA 0
#define FORNECEDORES_CADASTRO 1
#define FORNECEDORES_VOLTAR 2

#define MENU_PRINCIPAL_PRODUTO 0
#define MENU_PRINCIPAL_FORNECEDOR 1
#define MENU_PRINCIPAL_CLIENTE 2
#define MENU_PRINCIPAL_VENDA 3
#define MENU_PRINCIPAL_RELATORIO 4
#define MENU_PRINCIPAL_SAIR 5

// Estrutura que representa um elemento genérico da Interface de usuário

struct ElementoI {
    char *texto;                // Conteúdo textual do elemento
    int corFundo;               // Cor do fundo do elemento
    int corLetra;               // Cor do texto do elemento
    int col;                    // Coluna do elemento no terminal
    int lin;                    // Linha do elemento no terminal
};

struct CaixaFlutuante {
    int col;
    int lin;
    int largura;
    int altura;
    int cor;
};

struct CaixaTexto {
    ElementoI nome;
    CaixaFlutuante caixa;
    char *conteudo;
    bool cursorSobre;
};

// Estrutura que representa uma caixa de seleção
struct CheckBox {
    ElementoI elemento;         // Elemento da interface
    bool marcado;               // Informação se a caixa foi selecionada ou não
};

// Estrutura que representa um botão
struct Botao {
    ElementoI elemento;         // Elemento da interface
    bool cursorSobre;           // Informação se o cursor está sobre o botão
};

struct Menu {
    char **texto;                   // Conteúdo textual do elemento
    int corFundo;                   // Cor do fundo do elemento
    int corLetra;                   // Cor do texto do elemento
    int col;                        // Coluna do elemento no terminal
    int lin;
};

struct ListaFornecedor {
    int lin;
    int corFundo;
    int corLetra;
    bool cursorSobre;
    Fornecedor *fornecedor;
};

struct ListaProduto {
    int lin;
    int corFundo;
    int corLetra;
    bool cursorSobre;
    Produto *produto;
};

struct ListaVenda {
    int lin;
    int corFundo;
    int corLetra;
    bool cursorSobre;
    ItemVenda *item;
};

struct ListaCliente {
    int lin;
    int corFundo;
    int corLetra;
    bool cursorSobre;
    Cliente *cliente;
};



// Namespaces para leitura de dados 
namespace intr {
    bool lerDados(CaixaTexto &caixa, char *&conteudo, int n);
    void lerDados(CaixaTexto &caixa, char *&conteudo, int n, bool data);
}

namespace flt {
    void lerDados(CaixaTexto &caixa, char **conteudo, int n);
}

namespace strng {
    void lerDados(CaixaTexto &caixa, char *&conteudo, int n);
    void lerDados(CaixaTexto &caixa, char *&conteudo, int n, bool cpf);
}

// Declaracoes das funcoes globais da interface
bool tratarErroVenda(int cod);
bool tratarErroCad(int cod);
bool tratarErroCadP(int cod);
bool tratarErroEdicao(int cod);
bool tratarErroCadC(int cod);

void logicaTelaFCP(int *opcao, bool *enter);
void logicaListaItens(int *opcao, int *desliza, int linhas, int total, bool *enter, bool *esc);
void logicaTelaVenda(int *opcao, bool *enter);
void logicaListaProduto(int *opcao, int *desliza, int linhas, int total, bool *enter, bool *esc);
void logicaConsultarProduto(int *opcao, bool *enter);
void logicaCadastroProduto(int *opcao, bool *enter);
void logicaCadastroFornecedor(int *opcao, bool *enter);
void logicaConsultarFornecedor(int *opcao, bool *enter);
void logicaListaFornecedor(int *opcao, int *desliza, int linhas, int total, bool *enter, bool *esc);
void logicaConsultarCliente(int *opcao, bool *enter);
void logicaCadastroCliente(int *opcao, bool *enter);
void logicaEditarProduto(int *opcao, bool *enter);
void logicaEditarFornecedor(int *opcao, bool *enter);
void logicaTelaEditarVoltar(int *opcao, bool *enter);
void logicaListaCliente(int *opcao, int *desliza, int linhas, int total, bool *enter, bool *esc);
void logicaTelaInicial(int *opcao, bool *enter);
bool logicaListaVendaRegistro(int &desliza, const int qnt);
void logicaTelaEstoqueRelatorio(int *opcao, bool *enter);
void logicaTelasRegistro(int *opcao, bool *enter);
void logicaTelaInicialRegistro(int *opcao, bool *enter);
void logicaTelaApagarRegistro(int *opcao, bool *enter);

void atualizarListaVenda(ListaVenda *lista, Venda &venda, int linhas);
void atualizarEstados(Botao *botoes, int opcao, int n);
void atualizarEstados(ListaFornecedor *elemento, int opcao, int n);
void atualizarEstados(ListaProduto *elemento, int opcao, int n);
void atualizarEstados(ListaVenda *elemento, int opcao, int n);
void atualizarEstados(ListaCliente *elemento, int opcao, int n);
void atualizarEstados(CaixaTexto *caixas, Botao *botoes, int opcao, int nC, int nB);

void deslizarLista(ListaFornecedor *lista, Fornecedor *fornecedores, int desliza, int nL);
void deslizarLista(ListaProduto *lista, Produto *produtos, int desliza, int nL);
void deslizarLista(ListaVenda *lista, Venda &venda, int desliza, int nL);
void deslizarLista(ListaCliente *lista, Cliente *clientes, int desliza, int nL);

void inicializarApagarRelatorio(Botao *botoes);
void inicializarTelaRE(CaixaTexto *caixas, Botao *botoes);
void inicializarTelasRegistro(CaixaTexto *caixas, Botao *botoes);
void inicializarTelaInicialRegistro(Botao *opcoes);
void inicializarConsultaCliente(CaixaTexto *caixa, Botao *botoes);
void inicializarListaClientes(ListaCliente **lista, Cliente *clientes, int &n);
void inicializarTelaIdCliente(CaixaTexto *caixas);
void inicializarTelaVenda(CaixaTexto *caixas, Botao *botoes, ListaVenda *lista);
void inicializarEditarProduto(CaixaTexto *caixas, Botao *botoes, const Produto &f);
void inicializarListaProduto(ListaProduto **lista, Produto *produtos, int &n);
void inicializarConsultaProduto(CaixaTexto *caixa, Botao *botoes);
void inicializarCadastroProduto(CaixaTexto *caixas, Botao *botoes);
void inicializarEditarFornecedor(CaixaTexto *caixas, Botao *botoes, const Fornecedor &f);
void inicializarCadastroFornecedor(CaixaTexto *caixas, Botao *botoes);
void inicializarCadastroCliente(CaixaTexto *caixas, Botao *botoes);
void inicializarListaFornecedor(ListaFornecedor **lista, Fornecedor *fornecedores, int &n);
void inicializarConsultaFornecedor(CaixaTexto *caixa, Botao *botoes);
void inicializarTelaFCP(Botao *opcoes);
void inicializarTelaEEV(Botao *opcoes);
void inicializarTelaEV(Botao *opcoes);
void inicializarMenuPrincipal(Botao *opcoes);

void desenharCaixasTexto(const CaixaTexto *caixas, int n);
void desenharBordaEsqTopo(int c, int l, int h, int w, int cor);
void desenharBordaDirBaixo(int c, int l, int h, int w, int cor);
void desenharCheckBox(const CheckBox *opcoes, int n);
void desenharBotao(const Botao *botoes, int n);
void desenharLista(const ListaFornecedor *lista, int n);
void desenharLista(const ListaProduto *lista, int n);
void desenharLista(const ListaVenda *lista, int n);
void desenharLista(const ListaCliente *lista, int n);
void desenharBorda();
void desenharBorda(int c, int l, int h, int w, int cor);
void desenharPrecoTotal(float preco);

void limparTela(int c, int l, int h, int w);
void limparTela(int c, int l, int h, int w, int cor);
void limparMemoria(Botao *elemento, int n);
void limparMemoria(CaixaTexto *elemento, int n);
void limparConteudoCaixa(CaixaTexto *elemento, int n);
void limparMemoria(char **elemento, int n);
void limparMemoria(ListaFornecedor *elemento);
void limparMemoria(ListaProduto *elemento);
void limparListaVenda(ListaVenda *lista, int &n);
void limparMemoria(ListaCliente *elemento);

#endif // INTERFACE_H
