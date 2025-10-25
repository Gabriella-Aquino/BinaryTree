# Árvore Binária em C++

Este projeto implementa uma árvore binária de busca (BST) em C++, com funcionalidades para inserção, remoção, contagem de nós e folhas, cálculo de altura, percursos e verificação de similaridade e igualdade entre árvores.

## Estrutura do Projeto

`no.h` – Define a estrutura do nó (Node) da árvore, contendo o valor e ponteiros para filhos esquerdo e direito.

`binarytree.h` – Declara a classe BinaryTree com todos os métodos para manipulação da árvore e implementa os métodos da classe BinaryTree.

`main.cpp` – Contém o menu interativo para o usuário inserir, remover e visualizar elementos da árvore.

## Funcionalidades

- Inserir elementos na árvore (inserir)

- Remover elementos (remove)

- Imprimir árvore no console de forma estruturada (print)

- Contar o número de nós (countNodes)

- Contar o número de folhas (countLeaves)

- Calcular a altura da árvore (height)

- Obter o menor e o maior valor da árvore (getMinValue, getMaxValue)

- Percorrer a árvore em diferentes ordens:

  - In-order

  - Pre-order

  - Post-order

- Verificar se duas árvores são similares (isSimilar)

- Verificar se duas árvores são iguais (isEqual)

## Compilação

Para compilar o projeto, use o g++:

```
g++ main.cpp binarytree.cpp -o arvore
```


Depois, execute o programa:

```
./arvore
```

Observação: Certifique-se de que todos os arquivos (no.h, binarytree.h, binarytree.cpp, main.cpp) estejam no mesmo diretório.

## Uso

Ao executar, será exibido um menu interativo:

```
===== MENU ARVORE BINARIA =====
1. Inserir elemento
2. Remover elemento
3. Imprimir arvore
4. Contar nos
5. Contar folhas
6. Mostrar altura
7. Mostrar menor valor
8. Mostrar maior valor
9. Percorrer em ordem (in-order)
10. Percorrer em pre-ordem
11. Percorrer em pos-ordem
0. Sair
```


Basta digitar a opção desejada e seguir as instruções.

## Exemplo de Uso
```
Escolha uma opcao: 1
Digite o valor a ser inserido: 10

Escolha uma opcao: 1
Digite o valor a ser inserido: 5

Escolha uma opcao: 3
Arvore:
     10
5
```

Observações

- A implementação utiliza ponteiros e alocação dinâmica, portanto, a remoção de nós libera corretamente a memória.

- A impressão da árvore mostra o nó raiz no centro/topo e os filhos recuados à direita e à esquerda.

- O cálculo de altura considera a quantidade de níveis da árvore.
