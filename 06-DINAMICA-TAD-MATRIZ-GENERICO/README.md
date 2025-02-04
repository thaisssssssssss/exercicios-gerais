
# Tipo Abstrato de Dados

  
**Objetivo**:  O objetivo desta aula é  apresentar modos de definir um tipo genérico utilizando diretivas de compilação e por meio de casting sobre um ponteiro void. Para isto, considere a representação de um tipo Matriz e suas operações.


**Códigos em Matriz_convencional**:

- matriz.h  - Cabeçalho contendo as funções
- matriz'.c - Implementação das funções de uma matriz de inteitors
- progmat - O programa cliente.

**Códigos em Matriz_generica_1_4**:

Contém os mesmos arquivos, contudo a matriz será definida por uma diretiva de compilação. Isto é, ao compilar será definido o tipo de cada elemento da matriz.

Outras diretivas vão sendo inseridas no código para facilitar a manipulação do tipo.

**Códigos em Matriz_void**:

Agora os elementos da matriz são implementados como `void*`, desta forma cada elemento da matriz pode ser genérico. É responsabilidade do desenvolvedor dar suporte para a implementação de cada tipo. 






