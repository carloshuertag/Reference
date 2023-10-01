# Bits

> Carlos Huerta García

Bit se deriva de binary digit, de forma que es un bit es un dígito binario.

Los bits son la base del cómputo actual. Son muy utilizados para optimizar el uso de memoria y representar información eficientemente. Algunos ejemplos de su uso son: máscaras de bits (bitmasks), exponenciación binaria, árbol binario indexado o ábrol de Fenwick (BIT), cojuntos de bits (bitset).

## Representaciones

### Sistemas de numeración

Un sistema de numeración es un conjunto de símbolos y reglas que permiten representar números válidos.
Sólo existe una representación para un número entero en un sistema de numeración posicional.
Se representa un número entero con una combinación lineal de potencias de la base del sistema de numeración.
A la cardinalidad del conjunto de símbolos se le conoce como la base del sistema de numeración.

En el sistema de numeración decimal, el conjunto de símbolos es {0, 1, 2, 3, ..., 9}, cuya cardinalidad es 10 (su base). Por lo tanto, un número entero se representa como una combinación lineal de potencias de 10.

En el sistema de numeración binario, el conjunto de símbolos es {0, 1}, cuya cardinalidad es 2 (su base). Por lo tanto, un número entero se representa como una combinación lineal de potencias de 2.

En el sistema de numeración hexadecimal, el conjunto de símbolos es {0, 1, 2, 3, ..., 9, A, B, C, D, E, F}, cuya cardinalidad es 16 (su base). Por lo tanto, un número entero se representa como una combinación lineal de potencias de 16.

En el sistemas de numeración se utilizan para representar ideas como una abstracción de la realidad. Se dice que el el sistema decimal se representan los 10 dedos de las manos empleados históricamente para contar. Por otro lado, en el sistema binario se representan dos estados físicos (0 o 5V) o lógicos (verdadero o falso).

### Representación de números binarios

Todo en el cómputo clásico es representado con bits, incluidas las variables. Por ejemplo, con número sin signo de n bits {bbb...bbb} existen 2^n posibles representaciones. Por lo tanto, el rango de representación es [0, 2^n - 1]. Una convención para los números con signo de n bits es tomar un bit para representar el signo y los n - 1 bits restantes para representar el valor absoluto {sbbb...bbb}. Por lo tanto, el rango de representación es [-2^(n-1), 2^(n-1) - 1]. Se representan en complemento a dos, que suma un bit al complemento a uno, que es la negación lógica de los bits. Así, es posible cumplir con la propiedad del inverso aditivo.

[Ejemplo de desbordamiento](vars.cpp)

[Ejemplo de números negativos](negatives.cpp)

## Operaciones y Aplicaciones

### Operaciones con representaciones binarias

Se pueden realizar las operaciones del álgebra de boole, lógicas y de teoría de conjuntos. En los números con signo, las operaciones binarias afectan únicamente a los bits que representan el número y no al de signo. Las operaciones lógicas son la negación (~), conjunción (&), disyunción (|) (inclusiva) y disyunción exclusiva (^).

Algunas operaciones útiles son:

x ^ 0 = 0, x ^ 1...1 = ~x, x ^ x = 0;

x & x = 0, x & 1...1 = x, x & x = x, x & ~x = 0;

x | 0 = x, x | 1...1 = 1...1, x | x = x, x | ~x = 1...1.

Corrimientos o desplazamientos (shifts):

Lógicos (<<<,>>>). Se introducen k cantidad de ceros en el lado de la operación a la representación en bits.

Aritméticos (<<,>>). Se introducen k cantidad de ceros en el lado de la operación a la representación en bits después del bit de signo.

Corrimientos útiles: a << k = a \* 2^k, a >> k = a / 2^k.

Least Significant Bit (LSB) es el bit menos significativo, el primer bit encontrado de derecha a izquierda.

Most Significant Bit (MSB) es el bit más significativo, el primer bit encontrado de izquierda a derecha.

Operaciones de bits útiles:

x - 1: Se niegan los bits de x desde el LSB hasta el primer bit encendido de derecha a izquierda.

x & 1: Se obtiene el LSB de x, y como este es el único que puede no ser divisible por dos, equivale a x % 2.

x >> 1: Se obtiene x / 2, pero si x es impar, se obtiene el resultado truncado hacia abajo.

[Ejemplo de operaciones](ops.cpp)

### Aplicaciones

Dado x, ¿x es potencia de 2?

```C++
return x & (x - 1) == 0
```

Dado x, ¿x es par?

```C++
x & 1 == 0
```

Contar la cantidad de bits encendidos en x:

```C++
int bitsCount(int x) {
    int ans = 0;
    while (x) {
        if(x & 1) ans++;
        x >>= 1;
    }
    return ans;
}
```

```C++
int bitsCount(int x) {
    int ans = 0;
    while (x) {
        ans += x & 1;
        x >>= 1;
    }
    return ans;
}
```

```C++
int bitsCount(int x) {
    int ans = 0;
    int index = 1;
    while (index != INT_MIN) {
        if (index & x) ans++;
        index <<= 1;
    }
    return ans;
}
```

```C++
int bitsCount(int x) {
    if(x == 0) return 0;
    return x & 1 + bitsCount(x >> 1);
}
```

```C++
__builtin_popcount(x);
```

arr: todos los números se repiten una vez (se presentan por pares) menos uno, ¿Cuál es el número que no se presenta en pares?

Por ejemplo: arr = [1,2,4,3,1,3,2…], r = 4, n = arr.len, n<10^8
Posibles soluciones:

cubetas (buckets) -> O(n), O(n)

map/set -> O(n), O(n)

xor -> O(n), O(1)

```C++
int findUnique(int arr[], int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans ^= arr[i];
    }
    return ans;
}
```

https://codeforces.com/problemset/problem/579/A

[Solution](raisingBacteria.cpp)

https://codeforces.com/problemset/gymProblem/102697/035

[Solution](distinctNumbers.cpp)

## Bitmasks

Se usa un número como un arreglo de bits para representar estados. Algunas operaciones útiles para el manejo de máscaras de bits son:
testBit(x, i)

```C++
(x >> i) & 1
```

```C++
x & (1 << i)
```

clearBit(x, i)

```C++
x & ~(1 << i)
```

setBit(x, i)

```C++
x | (1 << i)
```

toggleBit(x, i)

```C++
x ^ (1 << i)
```

updateBit(x, i, v)

```C++
x & ~(1 << i) | (v << i)
```

```C++
clearBit(x, i) | (v << i)
```

setBitRange(l, r)

```C++
(((1 << (l + 1)) - 1) ^ ((1 << (r)) - 1))
```

testBitRange(x, l, r)

```C++
(x & setBitRange(l, r)) >> r
```

## Bitset

Conjunto de bits. Asigna un bit para cada elemeto (bit). https://en.cppreference.com/w/cpp/utility/bitset

```C++
bitset<size> mtBitset;
```

https://codeforces.com/problemset/problem/579/A

```C++
constexpr bitset<64> bs{x};
cout << bs.count();
```

https://codeforces.com/problemset/gymProblem/102697/035

bitset como cubeta

```C++
bs.count()
```
