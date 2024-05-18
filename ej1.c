#include <stdio.h>

//Función para realizar una búsqueda lineal
int rastreoLineal(int array[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (array[i] == x) {
            return i;
        }
    }
    return -1;
}

//Función para la ejecución de la búsqueda binaria
int rastreoBinario(int array[], int izquierda, int derecha, int x) {
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (array[medio] == x) {
            return medio;
        }
        if (array[medio] < x) {
            izquierda = medio + 1;
        } else {
           derecha = medio - 1;
        }
    }
    return -1;
}

//Función para efectuar la búsqueda binaria recursiva
int rastreoBinarioRecursivo(int array[], int izquierda, int derecha, int x) {
    if (derecha >= izquierda) {
        int medio = izquierda + (derecha- izquierda) / 2;
        if (array[medio] == x) {
            return medio;
        }
        if (array[medio] > x) {
            return rastreoBinarioRecursivo(array,izquierda, medio - 1, x);
        }
        return rastreoBinarioRecursivo(array, medio + 1, derecha, x);
    }
    return -1;
}

int main() {
    int arreglo[] = {2, 4, 6, 23, 56, 79};
    int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);

    //Pedirle al usuario un número a buscar
    int valor;
    printf("Ingrese un número entero a buscar: ");
    scanf("%d", &valor);

    //Búsqueda lineal
    int posicion = rastreoLineal(arreglo, tamaño, valor);
    if (posicion != -1) {
        printf("El valor %d fue encontrado en la posición %d a través de una búsqueda lineal.\n", valor, posicion);
    } else {
        printf("El valor %d no fue encontrado a través de la búsqueda lineal.\n", valor);
    }

    //Exploración binaria
    posicion = rastreoBinario(arreglo, 0, tamaño - 1, valor);
    if (posicion != -1) {
        printf("El valor %d fue encontrado en la posición %d a través de una búsqueda binaria.\n", valor, posicion);
    } else {
        printf("El valor %d no fue encontrado a través de la búsqueda binaria.\n", valor);
    }

    //Búsqueda binaria recursiva
    posicion = rastreoBinarioRecursivo(arreglo, 0, tamaño - 1, valor);
    if (posicion != -1) {
        printf("El valor %d fue encontrado en la posición %d a través de una búsqueda binaria recursiva.\n", valor, posicion);
    } else {
        printf("El valor %d no fue encontrado a través de la búsqueda binaria recursiva.\n", valor);
    }

    return 0;
}