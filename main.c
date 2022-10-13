#include <stdio.h>

int opt;
int optUser;
int optStudent;
int optSecondStudent;
#define limitStudents 3
#define limitQualities 3
float qualities[limitStudents][limitQualities];

void requestUser(){
    while (opt != 1 && opt != 2){
        printf("Ingrese el tipo de usuario:\n");
        printf("1) Profesor\n");
        printf("2) Estudiante\n");
        scanf("%d", &opt);
    }
    if( opt == 1 ){
        printf("Tu perfil es Profesor\n");
    } else if( opt == 2 ){
        printf("Tu perfil es Estudiante\n");
    }
}

void ingressQuality(){
    int students = 1;
    float quality = 0;
    printf("Ingresar notas para %d estudiantes:\n", limitStudents);
    while (students <= limitStudents){
        printf("Ingrese la nota para el estudiante (%d):\n", (students+1));
        int qualitiesCounter = 0;
        while (qualitiesCounter < limitQualities){
            printf("Ingrese la nota (%d) para el estudiante (%d):\n", (qualitiesCounter+1), (students+1));
            scanf("%f", &quality);
            qualities[students][qualitiesCounter] = quality;
            qualitiesCounter++;
        }
        printf("\n");
        students++;
    }
}

void getQuality(){
    printf("Sus notas son:\n");
    for (int i = 0; i < limitQualities; ++i) {
        printf("Nota #%d: %f\n", (i+1), (qualities[optUser][i]));
    }
}

void getAverage(){
    float average = 0;
    for (int i = 0; i < limitQualities; ++i) {
        average = average + qualities[optUser][i];
    }
    printf("Su promedio es: %f\n", average);
}

void getMax(){
    float max = 0;
    for (int i = 0; i < limitQualities; ++i) {
        if( max < qualities[optUser][i] ){
            max = qualities[optUser][i];
        }
    }
    printf("Su nota maxima es: %f\n", max);
}

void optsStudent(){
    while (optStudent != 1 && optStudent != 2 && optStudent != 3){
        printf("Ingrese una opcion:\n");
        printf("1) Consultar notas\n");
        printf("2) Promedio notas\n");
        printf("3) Valor más alto notas\n");
        scanf("%d", &optStudent);
    }
    if( optStudent == 1 ){
        getQuality();
    }
    if( optStudent == 2 ){
        getAverage();
    }
    if( optStudent == 3 ){
        getMax();
    }
    optSecondStudent = 0;
    while (optSecondStudent != 1 && optSecondStudent != 2){
        printf("\nIngrese una opcion:\n");
        printf("1) Volver al menu anterior\n");
        printf("2) Salir del programa\n");
        scanf("%d", &optSecondStudent);
    }
    if( optSecondStudent == 1 ){
        optSecondStudent = 0;
        optStudent = 0;
        optsStudent();
    }
}

void userOpts(){
    optUser = 0;
    if( opt == 1 ){
        while (optUser != 1 && optUser != 2){
            printf("Ingrese una opcion:\n");
            printf("1) Ingresar notas\n");
            printf("2) Cambiar a estudiante\n");
            scanf("%d", &optUser);
        }
        if( optUser == 1 ){
            ingressQuality();
            userOpts();
        }else if( optUser == 2 ){
            opt = 2;
            requestUser();
            userOpts();
        }
    } else if( opt == 2 ){
        while (optUser != 1 && optUser != 2 && optUser != 3){
            printf("Seleccione un estudiante:\n");
            printf("1) Estudiante 1\n");
            printf("2) Estudiante 2\n");
            printf("3) Estudiante 3\n");
            scanf("%d", &optUser);
        }
        optsStudent();
    }
}

int main() {
    printf("Hola Bienvenido al Colegio Casita Azul\n");
    requestUser();
    userOpts();
    return 0;
}
