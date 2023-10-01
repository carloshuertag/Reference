# Programación Dinámica (Dynamic Programming, DP)

> Carlos Huerta García

En ocasiones resolver subproblemas nos lleva a considerar subproblemas idénticos. Si se aprovecha la duplicación, resolviendo cada problema una sola vez, guardando la solución para su uso posterior entonces tendremos un algoritmo más eficiente. La idea de la programación dinámica es evitar repetición de cálculos. La base de la programación dinámica es el razonamiento inductivo: se resuelven primero los subproblemas más pequeños y por tanto más simples. Combinando las soluciones de ejemplares sucesivamente más grandes hasta llegar al ejemplar original.

La programación dinámica es un método para reducir el tiempo de ejecución de un algoritmo mediante la utilización de subproblemas superpuestos y subestructuras óptimas. La programación dinámica es un método ascendente: resuelve primero los problemas pequeños (guardando las soluciones) y después combinarlas para resolver problemas más grandes. La programación dinámica hace uso de subproblemas superpuestos, subestructuras óptimas y memoización.

La programación dinámica es un método ascendente, pues resuelve primero los problemas pequeños y después los combina para problemas más grandes, contrario a divide y vencerás que es descendente, pues empieza con el problema original y lo descompone en pasos sucesivos en problemas pequeños.

Una subestructura óptima significa que se pueden usar soluciones óptimas de subproblemas para encontrar la solución óptima del problema en su conjunto.

En general, se pueden resolver con subestructuras óptimas siguiendo tres pasos:

1. Dividir el problema en subproblemas más pequeños (a priori o durante el procesamiento).
2. Resolver estos problemas de manera óptima y almacenarlas (memorización).
3. Usar estas soluciones óptimas para construir una solución óptima al problema original (recursiva o iterativamente).

Los subproblemas se resuelven dividiéndolos en subproblemas más pequeños hasta que se alcance el caso fácil al cuál se le puede dar su respuesta óptima, la combinación de respuestas óptimas ira formando el óptimo global. Un problema tiene subproblemas superpuestos si se usa un mismo subproblema para resolver diferentes problemas mayores.

Richard Bellman en los años 1940s describió este proceso de resolución de problemas donde hace falta calcular la mejor solución consecutivamente, algunos lenguajes de programación funcionales usan la memorización automáticamente sobre funciones con un conjunto concreto de argumentos, para acelerar su evaluación, como Haskell.

## Elementos de la programación dinámica

Memoización. Los subproblemas superpuestos provocan resolver varias veces el mismo problema, ya que la solución de un subproblema requiere calcular soluciones que otro subproblema también tenga que calcular. Se evita calcular de nuevo la misma solución guardando las soluciones obtenidas en una lista de soluciones. Entonces, si se necesita resolver el mismo problema, se obtiene la solución de las ya calculadas para reutilizarla. En programación dinámica comúnmente se utilizan tablas de resultados conocidos que se va generando a meddia que se resuelven los subcasos.

Subestructuras óptimas. Donde se tiene la mayor aplicación de la programación dinámica es en la resolución de problemas de optimización. En este tipo de problemas se pueden presentar distintas soluciones, cada una con un valor, y lo que se desea es encontrar la solución de valor óptimo (máximo o mínimo). La solución de problemas mediante esta técnica se basa en el principio de optimalidad enunciado por Bellman en 1957

Principio de Optimalidad. En una secuencia de decisiones óptima toda subsecuencia ha de ser también óptima. Al optimizar se busca alguna de las mejores soluciones de entre muchas alternativas posibles. Dicho proceso de optimización puede ser visto como una secuencia decisiones que proporcionan la solución óptima. Se toman decisiones elementales, confiando en que la combinación de estas seguirá siendo óptima. La programación dinámica se aplica cuando la subdivisión de un problema conduce a: una enorme cantidad de subproblemas conduce a una gran cantidad de problemas, cuyas soluciones parciales se solapan y se cuenta con grupos de problemas de distinta complejidad.

## Enfoques de la programación dinámica

Top-down. El problema se divide en subproblemas, y estos se resuelven recordando las soluciones por si fueran necesarias nuevamente. Es una combinación de memorización y recursión.

Bottom-up. Todos los problemas que puedan ser necesarios se resuelven a priori y después se usan para resolver las soluciones a problemas mayores. Este enfoque es ligeramente mejor en consumo de espacio y llamadas a funciones, pero a veces resulta poco intuitivo encontrar todos los subproblemas necesarios para resolver un problema dado.

## Diseño de un algoritmo de programación dinámica

Para que un problema pueda ser abordar por esta técnica ha de cumplir dos condiciones:

1. La solución ha de ser alcanzada a través de una secuencia de decisiones, una en cada etapa.
2. Dicha secuencia de decisiones ha de cumplir el principio de optimalidad.

Consta de los siguientes pasos:

1. Planteamiento de la solución como una sucesión de decisiones y verificación de que ésta cumple el principio de optimalidad.
2. Definición recursiva o iterativa de la solución.
3. Cálculo de valor de la solución óptima mediante una estructura de datos en donde se almacenan soluciones a problemas parciales para reutilizar los cálculos.
4. Construcción de la solución óptima haciendo uso de la información contenida en la estructura de datos.

## Ejemplos

### Knapsack

El problema de la mochila es un problema de optimización combinatoria, es decir, que busca la mejor solución entre un conjunto finito de posibles soluciones a un problema. Modela una situación análoga al llenar una mochila, incapaz de soportar más de un peso determinado, con todo o parte de un conjunto de objetos, cada uno con un peso y valor específicos. Los objetos colocados en la mochila deben maximizar el valor total sin exceder el peso máximo.

https://www.spoj.com/problems/KNAPSACK/

[Iterativo](dpKnapsack.c)

[Recursivo](recursiveKnapsack.c)

### Longest Common Subsequence

El problema de la subsecuencia común más larga (LCS) es el problema de encontrar la subsecuencia común más larga entre dos (o más) secuencias. Es un caso especial del problema de subsecuencia más larga común (LCS), que difiere de este último en que no requiere que las subsecuencias comunes sean contiguas. El problema LCS tiene aplicaciones en la bioinformática y la recuperación de información.

https://omegaup.com/arena/problem/Longest-Common-Subsequence/#problems

[Solution](lcs.c)

https://www.spoj.com/problems/AIBOHP/

[Solution](aibophobia.c)

### Longest Increasing Subsequence

El problema de la subsecuencia creciente más larga (LIS) es el problema de encontrar la subsecuencia creciente más larga entre dos (o más) secuencias. Es un caso especial del problema de subsecuencia más larga común (LCS), que difiere de este último en que no requiere que las subsecuencias comunes sean contiguas. El problema LCS tiene aplicaciones en la bioinformática y la recuperación de información.

https://www.spoj.com/problems/ELIS/

[Solution](lis.c)
