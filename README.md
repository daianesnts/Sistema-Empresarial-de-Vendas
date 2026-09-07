# Sistema Empresarial de Vendas

Projeto desenvolvido em **C++** para a disciplina **Programação II**, simulando um **sistema empresarial de vendas** com interface interativa em modo texto, construída com a biblioteca **gconio**.

## Sobre o Projeto

O objetivo foi desenvolver um sistema modular representando o funcionamento básico de uma empresa: desde o controle de estoque e fornecedores, passando pelo cadastro de clientes, até o registro de vendas e geração de relatórios.

Aplicamos na prática conceitos de:
- Programação estruturada e modular em C++
- Alocação dinâmica de memória (`new`/`delete`)
- Persistência de dados em arquivos (texto e binário)
- Organização de código em múltiplos arquivos (`.h` / `.cpp`)
- Trabalho em equipe com integração entre módulos

## Estrutura do Projeto

```
.
├── include/                    # Arquivos de cabeçalho (.h)
│   ├── clientes.h              # Protótipos e structs do módulo Clientes
│   ├── erros.h                 # Códigos de erro centralizados
│   ├── fornecedores.h          # Protótipos e structs do módulo Fornecedores
│   ├── gconio.h                # Biblioteca de interface gráfica em modo texto
│   ├── gestao_estoque.h        # Protótipos e structs do módulo Estoque
│   ├── interface.h             # Elementos gráficos, caixas e declarações visuais
│   ├── relatorio_estoque.h     # Protótipos dos relatórios de estoque
│   ├── relatorio_vendas.h      # Protótipos dos relatórios de vendas
│   ├── utilitarios_re.h        # Funções auxiliares para relatórios
│   └── vendas.h                # Protótipos e structs do módulo Vendas
│
├── src/                        # Implementações dos módulos (.cpp)
│   ├── clientes.cpp            # Lógica de cadastro/pesquisa de clientes
│   ├── fornecedores.cpp        # Lógica de cadastro/gestão de fornecedores
│   ├── gestao_estoque.cpp      # Lógica de controle de estoque
│   ├── interface.cpp           # Lógica visual de menus, janelas e inputs
│   ├── main.cpp                # Ponto de entrada e fluxo do sistema
│   ├── relatorio_estoque.cpp   # Geração de relatórios de estoque
│   ├── relatorio_vendas.cpp    # Geração de relatórios de vendas
│   ├── utilitarios_re.cpp      # Implementação dos utilitários de relatório
│   └── vendas.cpp              # Registro e baixa de vendas
│
├── .gitignore                  # Arquivos ignorados pelo Git
├── LICENSE                     # Licença de uso
└── README.md                   # Documentação do projeto
```

## Funcionalidades

### Estoque
- Cadastro, edição e exclusão de produtos
- Controle de quantidade disponível
- Atualização automática ao realizar vendas

### Fornecedores
- Cadastro completo com empresa, responsável e contato
- Pesquisa e edição de registros

### Clientes
- Cadastro com validação de CPF
- Pesquisa por nome

### Vendas
- Seleção de cliente e adição de itens ao carrinho
- Validação de estoque em tempo real
- Geração de arquivo de venda

### Relatórios
- Relatório completo de estoque com status de reabastecimento
- Relatório de vendas totais (quantidade, receita, produto mais/menos vendido)
- Relatório de vendas por intervalo de datas

## Como Compilar e Executar

### Pré-requisitos
- Compilador **g++** com suporte a C++11
- Ambiente **Windows** (a biblioteca gconio usa APIs do Windows Console)
- Recomendado: **Code::Blocks**, **Dev-C++** ou terminal com MinGW

### Compilação via terminal

```bash
g++ src/*.cpp -Iinclude -o sistema -std=c++11
```

### Execução

```bash
./sistema
```

> **Nota:** Na primeira execução, os arquivos de dados são criados automaticamente. O sistema funciona sem configuração prévia.

## Contexto Acadêmico

Este projeto foi desenvolvido no **2º período** do curso de Sistemas de Informação como um trabalho colaborativo entre múltiplos grupos. Cada equipe ficou responsável por um módulo de negócio específico (Estoque, Vendas, Clientes, Fornecedores e Relatórios), enquanto o meu grupo assumiu o papel central de **Interface Visual e Integração Geral**. 

Por estarmos à frente da integração, atuamos de forma transversal em **todos os módulos da aplicação**, ajustando pontos de contato, unificando estruturas de erro e corrigindo inconsistências para conectar as peças de cada grupo no fluxo principal (`main.cpp` e `interface.cpp/.h`).

## Aprendizados (perspectiva do 6º período)

Ao resgatar o código agora, no 6º período, passei algumas semanas fazendo uma análise crítica em cada módulo e em cada interação que o sistema tinha com o usuário. Fico feliz em dizer que consegui fazer uma boa melhoria geral, **sem perder a essência/lógica do projeto ou fazer grandes mudanças**. Claro que ainda existem pontos a serem melhorados, mas já foram mudanças significativas.

- **Reestruturação**: Organização em `include/` e `src/`, seguindo o padrão moderno de C++.
- **Correção de Acoplamentos**: Desvinculação de implementações que estavam indevidamente dentro de headers (`.h`) gerando erros de múltipla definição.
- **Nivelamento de Código e Limpeza**: Ajuste de erros latentes em módulos individuais, remoção de redundâncias e padronização do tratamento de erros.
- **Análise de Evolução**: Identificação de pontos de melhoria como substituição de alocação dinâmica manual por `std::vector` e uso de RAII.
- **Compilação Limpa**: Correção de conversões de ponteiros de texto (`const char*`), retornos ausentes de funções e resolução de conflitos de macros.


---
Desenvolvido de forma colaborativa no 2° período e aprimorado por **Daiane Santos** no 6º período de Sistemas de Informação.