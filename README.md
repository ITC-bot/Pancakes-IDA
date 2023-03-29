# Juegos-de-los-Pancakes-aplicando-IDA
Juego de los pancakes (pancake sorting) aplicando IDA

Hecho por Marcos Zacarias, ITC-TM, Universidad Autonoma de Baja California Sur

Pequeña explicacion de las funciones:

--"void voltear(string& pancakes, int k)" Esta función recibe una cadena de caracteres, en este caso, los pancakes, y un entero k, y voltea los primeros k caracteres de la cadena. Se utiliza para simular la acción de voltear un número determinado de pancakes en una pila.

--"bool esta_ordenada(string pancakes)" Esta función recibe una cadena de caracteres pancakes y devuelve true si la cadena está ordenada de forma ascendente, es decir, si cada caracter es mayor o igual al caracter que le precede en la cadena. Se llama para verificar si el parametro que recibe esta ordenado.

--"vector generar_sucesores(string pancakes)" Esta función recibe una cadena de caracteres pancakes y devuelve un vector de cadenas de caracteres, son las posibles opciones de voltear distintos numeros de pancakes del arreglo. Se usa para generas sucesores de la cadena actual que recibe y los agrega a la cola de busqueda.

--"string generar_caracteres_aleatorios(int n)" Esta función recibe un entero n y devuelve una cadena de caracteres de longitud n, se usa para generar caracteres aleatorios, asi ahorrando estar pidiendo al usuario que se ingrese caracter por caracter.

--"float h4(const string& pancakes, const string& target)" Esta función es la heurística utilizada por el algoritmo de búsqueda A*. Recibe dos cadenas de caracteres, pancakes y target, y devuelve un entero que representa el costo estimado desde pancakes hasta target. La heurística utilizada es la siguiente: para cada posición de pancakes, si el caracter en esa posición es diferente al caracter correspondiente en target, se suma 1 al costo. Además, si hay dos caracteres consecutivos en pancakes que están separados por más de una posición en target, se suma 1 al costo. Por ejemplo, si pancakes es "adcbe" y target es "abcde", el costo estimado será 2, ya que hay dos caracteres diferentes ("d" y "b") y un par de caracteres consecutivos separados por más de una posición ("c" y "e"). Se cambio a tipo float para devolver una estimacion un poco mas precisa.

--Por actualiza

--"int main()" Esta es la función principal del programa. Solicita al usuario el número de caracteres de la pila de pancakes, genera una configuración aleatoria de pancakes utilizando la función generar_caracteres_aleatorios y llama a la función ida_star para llevar a cabo la búsqueda por amplitud.
