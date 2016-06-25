Algoritmos para Grafos em C++ 
==============

Neste projeto foi desenvolvido um console interativo onde o usuário tem a possibilidade de ler instâncias de um grafo e executar alguns algoritmos sobre ela.

Requisitos
-------------------------
É necessário ter conhecimento básico em manipulação de terminal pois essa aplicação foi desenvolvida para compilar e executar em ambiente Linux. 

Algoritmos Implementados
-------------------------

- Depth-First Search (DFS)
- Breadth-First Search  (BFS)
- Algoritmo PRIM (Árvore Geradora Mínima)
- Dijkstra (Caminho Mínimo)

Como executar?
---

O projeto não possui nenhum binário associado para execução. Para isso, você precisará compilar o código antes de executar a aplicação. Abra o terminal do linux, navegue até o diretório principal e execute o comando:

```shell
$ make
````

Após esse comando, o será gerado um arquivo executável com o nome "paa". Para rodar, execute o comando:

```shell
$ ./bin/paa
```

Precisa de ajuda?
---

A qualquer momento você pode digitar:

```shell
>> help
```

E todas as opções disponíveis da aplicação serão exibidas.

Opções disponíveis
---

* [<b>todot</b>] - Imprimir no arquivo texto o grafo lido no formato DOT
* [<b>help</b>] - Imprimir na tela os comandos disponíveis
* [<b>print</b>] - Imprimir na tela a matriz de adjacências
* [<b>exit</b>] - Sair da aplicação
* [<b>clear</b>] - Limpar da memória o ultimo grafo carregado
* [<b>read</b> < filename.(g|txt)\> ] - Ler um arquivo contendo um grafo
* [<b>dfs</b> < vertex>] - Executar algoritmo DFS iniciando no vertice <vertice>
* [<b>bfs</b> < vertex>] - Executar algoritmo BFS iniciando no vertice <vertice>
* [<b>mst</b> < fileName>] - Imprime no arquivo texto a árvore gerada mínima iniciando pelo vertice <vertice>
* [<b>sp</b> < startVertex> < endVertex>] - Imprime na tela o menor caminho de < startVertex> até < endVertex>

Formato da Instância
---

O arquivo deve possuir extensão ".g" ou ".txt" e deve está descrito da seguinte forma:

* Primeira linha do arquivo deve conter a quantidade de vértices do grafo
* Segunda linha em diante deve conter as arestas do grafo bem como seu peso.

Para ver um exemplo de como deve ser montada a instância do grafo, você pode olhar os exemplos contidos na pasta "in".

Contact
---

Se você encontrou algum problema, por favor use o [GitHub Issue Tracker](https://github.com/thiagodnf/algoritmos-para-grafos-em-c-plus-plus/issues) 

Se você gostou deste projeto, conte-me!
