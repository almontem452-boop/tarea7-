#include <stdio.h>
#include <stdlib.h>

// 1. Definición de la estructura del nodo del árbol
typedef struct Nodo {
    int dato;
    struct Nodo *izq;
    struct Nodo *der;
} Nodo;

// Función auxiliar para crear un nuevo nodo utilizando memoria dinámica (malloc)
Nodo* crearNodo(int valor) {
    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error: No hay memoria suficiente.\n");
        exit(1);
    }
    nuevo->dato = valor;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

// 2. Función para insertar un número respetando las reglas del ABB (sin duplicados)
Nodo* insertar(Nodo *raiz, int valor) {
    if (raiz == NULL) {
        return crearNodo(valor);
    }
    
    if (valor < raiz->dato) {
        raiz->izq = insertar(raiz->izq, valor);
    } else if (valor > raiz->dato) {
        raiz->der = insertar(raiz->der, valor);
    } else {
        printf("El número %d ya existe en el árbol. No se permiten duplicados.\n", valor);
    }
    
    return raiz;
}

// 3. Recorridos del árbol
// Recorrido Preorden: Raíz, Izquierda, Derecha
void preorden(Nodo *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dato);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

// Recorrido Inorden: Izquierda, Raíz, Derecha
void inorden(Nodo *raiz) {
    if (raiz != NULL) {
        inorden(raiz->izq);
        printf("%d ", raiz->dato);
        inorden(raiz->der);
    }
}

// Recorrido Postorden: Izquierda, Derecha, Raíz
void postorden(Nodo *raiz) {
    if (raiz != NULL) {
        postorden(raiz->izq);
        postorden(raiz->der);
        printf("%d ", raiz->dato);
    }
}

// 4. Función para buscar un número en el árbol
int buscar(Nodo *raiz, int valor) {
    if (raiz == NULL) {
        return 0; // No encontrado
    }
    if (raiz->dato == valor) {
        return 1; // Encontrado
    }
    if (valor < raiz->dato) {
        return buscar(raiz->izq, valor);
    } else {
        return buscar(raiz->der, valor);
    }
}

// 5. Función principal con el menú de opciones
int main() {
    Nodo *raiz = NULL;
    int opcion, valor;

    do {
        // Menú de opciones exacto solicitado
        printf("\n===== ARBOL BINARIO DE BUSQUEDA =====\n\n");
        printf("1. Insertar un numero\n");
        printf("2. Mostrar recorrido en preorden\n");
        printf("3. Mostrar recorrido en inorden\n");
        printf("4. Mostrar recorrido en postorden\n");
        printf("5. Buscar un numero\n");
        printf("6. Salir\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el numero entero a insertar: ");
                scanf("%d", &valor);
                raiz = insertar(raiz, valor);
                break;
                
            case 2:
                printf("Recorrido Preorden: ");
                preorden(raiz);
                printf("\n");
                break;
                
            case 3:
                printf("Recorrido Inorden: ");
                inorden(raiz);
                printf("\n");
                break;
                
            case 4:
                printf("Recorrido Postorden: ");
                postorden(raiz);
                printf("\n");
                break;
                
            case 5:
                printf("Ingrese el numero que desea buscar: ");
                scanf("%d", &valor);
                if (buscar(raiz, valor)) {
                    printf("El numero %d existe en el arbol.\n", valor);
                } else {
                    printf("El numero %d no existe en el arbol.\n", valor);
                }
                break;
                
            case 6:
                printf("Saliendo del programa...\n");
                break;
                
            default:
                printf("Opcion invalida. Por favor, intente de nuevo.\n");
        }
    } while (opcion != 6);

    return 0;
}