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
