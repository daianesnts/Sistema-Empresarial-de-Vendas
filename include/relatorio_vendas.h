#ifndef RELATORIO_VENDAS_H
#define RELATORIO_VENDAS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <locale.h>
#include <iomanip>
#include <ctime>
#include <climits>
#include <map>
#include <cstdio>
#include <string>

#define TAMANHO_NOME_ITEM 48
#define MAX_ITENS         100

// Nomes dos arquivos de sada dos relatorios
extern const char* vendasTotais;
extern const char* vendasLista;
extern const char* intervaloVendas;

// Cabecalho de uma venda (dados gerais). 
struct InfoVenda {
    int numeroVenda;
    char data[11];
    int codigoCliente;
    int qntId;
    float totalVenda;
};

// Representa um item vendido em um relatorio. 
struct InfoItens {
    int id;
    char nome[TAMANHO_NOME_ITEM+1];
    float preco;
    int qnt;
    float subtotal;
};

// Dados agregados de todas as vendas (para relatorio de totais). 
struct DadosRelatorio {
    int quantidadeTotal = 0;
    float receitaTotal = 0;
    std::string maisVendido = " ";
    int maisUnidades = 0;
    std::string menosVendido = " ";
    int menosUnidades = INT_MAX;
};

// Linha de registro de venda para o relatorio de intervalo. 
struct produtosListados {
    std::string data;
    int id_produto;
    std::string nome_produto;
    float preco_unitario;
    int quantidade;
    float subtotal;
};

// Array global de vendas carregadas para o relatorio de intervalo
extern produtosListados vendasListadas[MAX_ITENS];
extern int totalVendas;

// Declaracoes das funcoes 
void configurarLocalizacao();
void contLinhas(int &linhas);
void lerDadosVendas(int linhas, std::string vendasCadastradas[]);
void converteDados(std::string vendasCadastradas[], int linhas, InfoVenda &vendas, InfoItens itens[], int &numItens, DadosRelatorio &dado);
void carregarDadosRelatorio(DadosRelatorio &dado);
void vendasTotaisRel(DadosRelatorio &dado, InfoVenda &vendas, InfoItens itens[], int numItens);
void vendasListaRel(InfoVenda &vendas, InfoItens itens[], int numItens);
bool conversaoData(const std::string &dataStr, tm &dataTm);
int compararDatas(const tm& data1, const tm& data2);
void lerVendasLista();
bool gerarRelatorioIntervalo(std::string dataInicioStr, std::string dataFimStr);
void limpaArquivo(const char* arquivo);
void exibirTotal();
void exibirLista(const char* arquivo);
void exibirListaIntervalo(const char* arquivo);
void carregamentoVendas();

#endif // RELATORIO_VENDAS_H