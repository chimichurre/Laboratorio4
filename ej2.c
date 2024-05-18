#include <stdio.h>

//Función a fin de hallar el valor mínimo(min) en el arreglo
int hallarMinimo(int set[], int length) {
    int min = set[0];
    for (int i = 1; i < length; i++) {
        if (set[i] < min) {
            min = set[i];
        }
    }
    return min;
}

//Función para buscar el valor máximo(max) en el arreglo
int hallarMaximo(int set[], int length) {
    int max = set[0];
    for (int i = 1; i < length; i++) {
        if (set[i] > max) {
            max = set[i];
        }
    }
    return max;
}

//Localización del valor mínimo y máximo utilizando punteros
void hallarMinMax(int *set, int *min, int *max, int length) {
    *min = *max = set[0];
    for (int i = 1; i < length; i++) {
        if (set[i] < *min) {
            *min = set[i];
        }
        if (set[i] > *max) {
            *max= set[i];
        }
    }
}

int main() {
    int set[] = {21, 24, 65, 3, 56, 12, 35, 15};
    int length = sizeof(set) / sizeof(set[0]);
    
    //Invocación de las funciones para obtener el mínimo y máximo
    int min = hallarMinimo(set, length);
    int max = hallarMaximo(set, length);
    
    //Exhibir el mínimo y máximo encontrados sin punteros
    printf("El valor mínimo es: %d\n", min);
    printf("El valor máximo es: %d\n", max);
    
    //Invocación de la función para CONSTATAR el mínimo y máximo utilizando punteros
    int min_ptr, max_ptr;
    hallarMinMax(set, &min_ptr, &max_ptr, length);
    
    //Imprimir el mínimo y máximo encontrados con punteros
    printf("El valor mínimo empleando punteros es: %d\n", min_ptr);
    printf("El valor máximo empleando punteros es: %d\n", max_ptr);
    
    return 0;
}