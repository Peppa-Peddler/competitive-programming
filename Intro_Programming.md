# Clase de fundamentos de programación (en c++)

## Para Windows:
- Visual Studio Code (VSCODE): [Link](https://code.visualstudio.com/Download)
- Configurar y compilar C++ en VSCODE: [Link](https://code.visualstudio.com/docs/languages/cpp)

## Clases:

### Clase 26 de octubre:

Mapa de Computer Science: https://www.flickr.com/photos/95869671@N08/36231833334

- ¿Qué es programar?
- Output: Función cout (Impresión)
- operadores 
- tipos de datos básicos (string / int)
- Input: Función cin (Lectura)

#### Hola Mundo

```c++
#include <iostream>
using namespace std;
int main()
{
    cout << "Hello World" << endl;
}
```

#### Función cout y operadores

```c++
cout << 3 + 4 + 10 << endl;
cout << 3 * 4 + 10 << endl;
cout << 3 * ( 4 + 10 ) << endl;
cout << 3 / 4 + 10 << endl;
cout << 3.0 / 4 + 10 << endl;
cout << 3. / 4 + 10 << endl;
cout << 3 / 4. + 10 << endl;
cout << 3. / (4 + 10) << endl;
```
#### Ejercicios:

1. Pasar de minutos a horas:
```
Ingresar: Cantidad de minutos que han pasado desde las 00:00. (entero)
Retornar: La hora en formato 24h. (entero)
```
```
Ejemplo:
Input: 71
Output: 1h 11m
```

2. Ángulo del reloj:
```
Ingresar: Hora, minutos y segundos. (enteros)
Retornar: Angulo en grados sexagesimales que ha recorrido
la manecilla horaria desde las 00:00. (flotante)
```
```
Ejemplo:
Input: 1 2 6
Output: 31.05
```
## Operador Módulo (%):
El operador ` % ` se usa para obtener el residuo de la división entera entre 2 números:
`a%b = r` donde r es el residuo, el valor de r va entre 0 y b - 1:
```c++
cout<< ( 0 % 5) <<endl; // = 0
cout<< ( 1 % 5) <<endl; // = 1
cout<< ( 2 % 5) <<endl; // = 2
cout<< ( 3 % 5) <<endl; // = 3
cout<< ( 4 % 5) <<endl; // = 4

cout<< ( 5 % 5) <<endl; // = 0
cout<< ( 6 % 5) <<endl; // = 1
cout<< ( 7 % 5) <<endl; // = 2
cout<< ( 8 % 5) <<endl; // = 3
cout<< ( 9 % 5) <<endl; // = 4

cout<< (10 % 5) <<endl; // = 0
cout<< (11 % 5) <<endl; // = 1
//etc, el resultado del residuo es cíclico
```

### Propiedades de %:

```
(a + c)%c = a%c (el residuo es cíclico)
(a + b)%c = (a%c + b%c)%c (distributiva en suma)
(a*b)%c = ((a%c)*(b%c))%c (distributiva en multiplicación)
a%10 = última cifra de a
```

### Ejercicios:
1. Resolver los ejercicios de reloj usando el operador (%)
2. Obtener el último dígito de un número entero elevado a la 7ma potencia
```
Input: Un número (entero)
Output: La última cifra del número elevado a la 7ma potencia (entero)
```
```
Ejemplo 1:
Input: 2
Output: 8
```
```
Ejemplo 2:
Input: 7
Output: 3
```

### Problemas con if / else

1. Leer coordenadas (fila y columna) de dos lugares en el tablero y ver si tienen el mismo color.
```
Ejemplo 1:
Input: 2 2 3 3
Output: si
```
```
Ejemplo 2:
Input: 2 3 3 3
Output: no
```
2. Leer coordenadas (fila y columna) de dos alfiles y ver si se atacan
3. Leer coordenadas (fila y columna) de dos reinas y ver si se atacan

