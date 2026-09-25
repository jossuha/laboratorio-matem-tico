/*
 * Laboratorio Matematico en C
 * Programacion en C - Proyecto individual
 *
 * Menu principal que integra geometria, evaluacion de funciones,
 * aproximacion de limites y calculo numerico de derivadas.
 */

#include <stdio.h>

#define PI 3.14159265

/* Variable global: cuenta cuantas operaciones ha hecho el usuario
   durante la ejecucion del programa */
int contadorOperaciones = 0;

/* ---------- Prototipos de funciones ---------- */
void mostrarMenu(void);
void moduloGeometria(void);
void calcularCirculo(float radio);
void calcularTriangulo(void);
float evaluarFuncion(float a, float b, float c, float x);
void moduloEvaluarFuncion(void);
float funcionLimite(float x);
void moduloAproximarLimite(void);
float aproximarDerivada(float a, float b, float c, float x, float h);
void moduloDerivada(void);

/* ---------- Funcion principal ---------- */
int main() {
    int opcion = 0;

    while (opcion != 5) {
        mostrarMenu();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                moduloGeometria();
                break;
            case 2:
                moduloEvaluarFuncion();
                break;
            case 3:
                moduloAproximarLimite();
                break;
            case 4:
                moduloDerivada();
                break;
            case 5:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpcion invalida.\n");
        }
    }

    printf("Operaciones realizadas en total: %d\n", contadorOperaciones);
    return 0;
}

/* ---------- Menu ---------- */
void mostrarMenu(void) {
    printf("\n=================================\n");
    printf("      LABORATORIO MATEMATICO\n");
    printf("=================================\n");
    printf("1. Geometria\n");
    printf("2. Evaluar una funcion\n");
    printf("3. Aproximar un limite\n");
    printf("4. Calcular una derivada\n");
    printf("5. Salir\n");
}

/* ---------- Geometria ---------- */
void moduloGeometria(void) {
    int opcionGeo;
    float radio;

    printf("\n--- GEOMETRIA ---\n");
    printf("1. Circulo\n");
    printf("2. Triangulo\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcionGeo);

    if (opcionGeo == 1) {
        printf("Ingrese el radio del circulo: ");
        scanf("%f", &radio);
        calcularCirculo(radio);
    } else if (opcionGeo == 2) {
        calcularTriangulo();
    } else {
        printf("Opcion invalida.\n");
    }

    contadorOperaciones++;
}

void calcularCirculo(float radio) {
    float area, perimetro;

    if (radio <= 0) {
        printf("Radio invalido.\n");
        return;
    }

    area = PI * radio * radio;
    perimetro = 2 * PI * radio;

    printf("Area del circulo: %.2f\n", area);
    printf("Perimetro del circulo: %.2f\n", perimetro);
}

void calcularTriangulo(void) {
    float base, altura, lado1, lado2, lado3, area;

    printf("Ingrese la base del triangulo: ");
    scanf("%f", &base);
    printf("Ingrese la altura del triangulo: ");
    scanf("%f", &altura);

    if (base > 0 && altura > 0) {
        area = base * altura / 2;
        printf("Area del triangulo: %.2f\n", area);
    } else {
        printf("Datos invalidos.\n");
    }

    printf("Ingrese el lado 1: ");
    scanf("%f", &lado1);
    printf("Ingrese el lado 2: ");
    scanf("%f", &lado2);
    printf("Ingrese el lado 3: ");
    scanf("%f", &lado3);

    if (lado1 <= 0 || lado2 <= 0 || lado3 <= 0) {
        printf("Longitudes invalidas.\n");
        return;
    }

    if (lado1 == lado2 && lado2 == lado3) {
        printf("El triangulo es equilatero.\n");
    } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
        printf("El triangulo es isosceles.\n");
    } else {
        printf("El triangulo es escaleno.\n");
    }
}

/* ---------- Evaluacion de funcion cuadratica ---------- */
float evaluarFuncion(float a, float b, float c, float x) {
    return a * x * x + b * x + c;
}

void moduloEvaluarFuncion(void) {
    float a, b, c, x, resultado;

    printf("\n--- EVALUAR FUNCION f(x) = ax^2 + bx + c ---\n");
    printf("Ingrese a: ");
    scanf("%f", &a);
    printf("Ingrese b: ");
    scanf("%f", &b);
    printf("Ingrese c: ");
    scanf("%f", &c);
    printf("Ingrese x: ");
    scanf("%f", &x);

    resultado = evaluarFuncion(a, b, c, x);
    printf("f(%.2f) = %.2f\n", x, resultado);

    contadorOperaciones++;
}

/* ---------- Aproximacion de limite ---------- */
float funcionLimite(float x) {
    return (x * x - 4) / (x - 2);
}

void moduloAproximarLimite(void) {
    float punto = 2, distancia = 0.1;
    float x, resultado;
    int i;

    printf("\n--- APROXIMAR LIMITE cuando x -> 2 ---\n");

    printf("Aproximacion por la izquierda:\n");
    distancia = 0.1;
    for (i = 0; i < 4; i++) {
        x = punto - distancia;
        resultado = funcionLimite(x);
        printf("x = %.4f  ->  f(x) = %.4f\n", x, resultado);
        distancia = distancia / 10;
    }

    printf("Aproximacion por la derecha:\n");
    distancia = 0.1;
    for (i = 0; i < 4; i++) {
        x = punto + distancia;
        resultado = funcionLimite(x);
        printf("x = %.4f  ->  f(x) = %.4f\n", x, resultado);
        distancia = distancia / 10;
    }

    contadorOperaciones++;
}

/* ---------- Derivada numerica ---------- */
float aproximarDerivada(float a, float b, float c, float x, float h) {
    float valorDerecha = evaluarFuncion(a, b, c, x + h);
    float valorIzquierda = evaluarFuncion(a, b, c, x - h);
    return (valorDerecha - valorIzquierda) / (2 * h);
}

void moduloDerivada(void) {
    float a, b, c, x, h, derivada;

    printf("\n--- CALCULAR DERIVADA (aproximacion numerica) ---\n");
    printf("Ingrese a: ");
    scanf("%f", &a);
    printf("Ingrese b: ");
    scanf("%f", &b);
    printf("Ingrese c: ");
    scanf("%f", &c);
    printf("Ingrese el punto x: ");
    scanf("%f", &x);
    printf("Ingrese h (valor pequeno): ");
    scanf("%f", &h);

    if (h == 0) {
        printf("h no puede ser cero.\n");
        return;
    }

    derivada = aproximarDerivada(a, b, c, x, h);
    printf("f'(%.2f) aprox %.4f\n", x, derivada);

    contadorOperaciones++;
}
