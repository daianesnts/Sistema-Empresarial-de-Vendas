#ifndef UTILITARIOS_RE_H
#define UTILITARIOS_RE_H

#include <cstdio>
#include <string>
#include <unordered_map>
#include <fstream>
#include "gestao_estoque.h"

// Armazena dados de uma mercadoria para fins de relatorio.
struct mercadorias
{
    int codigo;                    // Codigo do Produto
    char nome[33];                 // Nome do Produto
    char categoria[17];            // Categoria do Produto
    int qtd_anterior;              // Quantidade anterior ao periodo
    int qtd_atual;                 // Quantidade atual em estoque
    float preco_custo;             // Preco unitario de custo
    float valor_total;             // Valor total (preco x quantidade)
    std::string status_reabastecimento; // Status de reabastecimento
    std::string data_cadastro;          // Data de cadastro do produto
};

// Representa um relatorio de estoque com metadados e lista de produtos.
struct Relatorio
{
    std::string data;               // Data do relatorio
    std::string hora;               // Hora do relatorio
    std::string responsavel;        // Responsavel pelo relatorio
    std::string localizacao;        // Localizacao do estoque
    std::string fonte_dados;        // Fonte dos dados utilizados
    mercadorias *objetos;           // Array dinamico de produtos
    int total_produtos;             // Total de produtos armazenados
    int total_movimentacoes;        // Total de movimentacoes registradas
    float valor_total_estoque;      // Valor total do estoque

    // Construtor: inicializa ponteiros e variaveis numericas
    Relatorio()
        : objetos(NULL),
          total_produtos(0),
          total_movimentacoes(0),
          valor_total_estoque(0.0) {}

    // Destrutor: libera memoria do array dinamico de produtos
    ~Relatorio()
    {
        if (objetos)
        {
            delete[] objetos;
            objetos = NULL;
        }
    }
};

extern std::unordered_map<int, int> dados_anteriores;

// Calcula o valor total de um conjunto de produtos
float calcular_valor_total(const mercadorias *produtos, int total);

// Determina o status de reabastecimento baseado na quantidade atual
std::string determinar_status_reabastecimento(int qtd_atual, int estoque_minimo, int estoque_normal);

void carregarDadosAnteriores(const char *nomeArquivo);
void salvarDadosAnteriores(const char *nomeArquivo);
void verificarQtdAnterior(mercadorias &objeto);

#endif // UTILITARIOS_RE_H
