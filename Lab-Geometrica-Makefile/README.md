
# Tipo Abstrato de Dados

**Tipo Ponto**
  
Representação de um ponto e derivados de um ponto com suas operações. 
Você deve separar os códigos em cabeçalhos (*headers*) e código fonte.

Códigos em  TAD_PONTOS:
- pontos.c 
```
gcc -o main pontos.c -lm
```

### Tarefa

1. Separar o  código fonte do cabeçalho.
- tponto.h  - Cabeçalho contendo as funções
- tponto.c - Implementação das funções
- main.c - O programa cliente.

2. Além do tipo Ponto, este programa pode ser melhor modularizado de acordo com a forma que quer implementar.  Como tarefa, faça:
  - Uma biblioteca de pontos conter apenas as funções relativas ao ponto;
  - Uma biblioteca para círculo;
  - Uma biblioteca para triangulo;
  - Uma biblioteca chamada tGeometrica que une todas as bibliotecas;
