# Problemas iteradores, strings, arreglos

### 1. Hallar el segundo valor más grande
Dada una lista de `n` números. Hallar el segundo valor más grande. Osea, hallar el máximo valor `x` tal que sea estrictamente menor que el máximo valor de la lista.

```
input: 10 2 20 30 40
output: 30
```
```
input: 30 40 40
output: 30
```
### 2. Desigualdad de strings
Sea dos strings `A` y `B`. La siguiente proposición `A < B` es verdadera, si es que cumple lo siguiente:
- Es suficiente si `A[0] < B[0]`. (**a**sddsjdisjdsidjsidjs < **b**c)
- En caso `A[0] == B[0]`, entonces `A < B` si `A[1] < B[1]`. (ie. **ab**zzjdfigfdj < **ac**fdfdffd)
- En caso `A[1] == B[1]`, entonces `A < B` si `A[2] < B[2]`. (ie. **aaa**zzsddd < **aab**frgthygijirjhi)
- Y así con todos los demás elementos. 
- Si ningún elemento de `A` es menor que su correspondiente en `B`, y `A.size() < B.size()`, entonces `A < B`. (ie. aaaa < aaaab).

Dado dos strings `A` y `B`, responder `Si` si es que `A < B` caso contrario, responder `No`. Considerar solamente strings con letras minúsculas.
```
input: abcde accc
output: Si
```
```
input: aasdkoasdkoas b
output: si
```
```
input: a a
output: No
```
```
input: a ac
output: Si
```
```
input: c b
output: No
```
**Nota**: El problema sale usando comparación con strings, `string a = "hola", b = "holaas"; cout << (a < b) << endl;`. Pero usar `for` como ejercicio.

### 3. Triángulo
Dado un número entero positivo `n` dibujar un triángulo con base de tamaño `n`. Guiarse del ejemplo:
```
input: 10
output:
         #
        # #
       # # #
      # # # #
     # # # # #
    # # # # # #
   # # # # # # #
  # # # # # # # #
 # # # # # # # # #
# # # # # # # # # #
```
```
input: 4
output:
   #
  # #
 # # #
# # # #
```
### 3. Triángulo con dígitos:
Dado un número entero positivo `n` dibujar un triángulo con base de tamaño `n`. En lugar de `#, usar números de un dígito. Empezar con 1, 2, 3..... cuándo se llega a 9, reiniciar a 1. Guiarse del ejemplo:
```
input: 10
output:
         1
        2 3
       4 5 6
      7 8 9 1
     2 3 4 5 6
    7 8 9 1 2 3
   4 5 6 7 8 9 1
  2 3 4 5 6 7 8 9
 1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9 1
```
```
input: 5
output:
    1
   2 3
  4 5 6
 7 8 9 1
2 3 4 5 6
```
### 4. Suma de strings
Dado dos strings A y B. Crear una función que retorne la concatenación de A con el string reverso de B:
```
input: abc accd
output: abcdcca
```
```
input: abc 1234
output: abc4321
```
### 5. String en varias líneas
Sea un string A y un número c. Imprimir A en varias lineas de tamaño c.

```
input: abcdefghijklmno 5
output:
abcde
fghij
klmno
```
```
input: abcdefghijklmnopqr 8
output:
abcdefgh
ijklmnop
qr
```
### 6. Reinas
Dada la posición de 8 reinas (fila y columna) en un tablero de ajedrez. Determinar si alguna de esas reinas se pueden atacar, de ser el caso responder con `Si`, caso contrario responder con `No`.
```
input:
1 7
2 4
3 2
4 8
5 6
6 1
7 3
8 5
output:
NO
```
### 7.
Dada una lista de `n` números, buscar los dos valores más cercanos (osea que su diferencia sea la menor de todas entre cualquier otro par de números).
```
input:
700 200 100 450 300 600 400 
output:
450 400
```
**Nota:** en esta caso 400 y 450 su diferencia es la mínima entre cualquier otro par de elementos.

### 8.
Dada las coordenadas (`x` / `y`) de dos puntos, calcular la distancia euclidiana de esos puntos:
```
input:
1 1
2 1
output:
1.0
```
```
input:
10 10
20 20
output:
14.1421356237
```
### 9.
Dada las coordenadas (`x` / `y`) de `n` puntos. Buscar los dos puntos más cercanos entre sí.
```
input:
4
1000 1001
1000 1000
2023 20
1002 2329
output:
1000 1001
1000 1000
```
