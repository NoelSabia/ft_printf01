#include <stdio.h>

int main() {
    int zahl = 42;
    int *zeiger = &zahl;

    printf("Die Adresse des Zeigers: %p\n", (void*)zeiger);

    return 0;
}
