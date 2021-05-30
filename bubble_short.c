#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIMITE 600000
void lee_datos(char nombre[], int *array, int n);
void muestra_datos(int *array, int n);
void burbuja(int *array, int n);

int main(){
    time_t t_1, t_2, t_programa1, t_programa2, t_3;
    int a_inv[LIMITE], a_ord[LIMITE],a_ale[LIMITE];
    int desde, hasta, incremento, N;
    float tiempo_actual, tiempo_restante, tr_minutos,tr_horas;
    int resul_inv, resul_ord, resul_ale;
    FILE *sal;
    FILE *t_final;
    sal = fopen("tiempos_bubblesort.csv", "wt");
    t_final = fopen("tiempo_programa_bubblesort.txt", "wt");
    fclose(sal);
    fclose(t_final);
    printf("Desde: ");
    scanf("%d", &desde);
    printf("Hasta: ");
    scanf("%d", &hasta);   
    printf("Incremento: ");
    scanf("%d", &incremento);
    t_programa1 = time(NULL);
    lee_datos("datos_invertidos.txt", a_inv, LIMITE);
    lee_datos("datos_ordenados.txt", a_ord, LIMITE);
    lee_datos("datos_aleatorios.txt", a_ale, LIMITE);
    //muestra_datos(a_ale, LIMITE);
    for (N = desde; N <= hasta; N = N + incremento){
        tiempo_actual = difftime(t_3,t_programa1);
        tiempo_restante = (N/tiempo_actual)*hasta-N;
        tr_minutos = tiempo_restante/60000;
        tr_horas = tr_minutos/60;
        printf("Procesando N = %d\nTiempo restante: %0.1f minutos o tambien %0.1f Horas", N, tr_minutos,tr_horas);
        t_1 = time(NULL);
        burbuja(a_inv, N);
        t_2 = time(NULL);
        resul_inv = (int)difftime(t_2,t_1);

        t_1 = time(NULL);
        burbuja(a_ord, N);
        t_2 = time(NULL);
        resul_ord = (int)difftime(t_2,t_1);

        t_1 = time(NULL);
        burbuja(a_ale, N);
        t_2 = time(NULL);
        resul_ale = (int)difftime(t_2,t_1);

        sal = fopen("tiempos_bubblesort.csv", "at");
        fprintf(sal,"%d,%d,%d,%d\n", N, resul_inv, resul_ord, resul_ale);
        fclose(sal);
        t_3 = time(NULL);
        system("cls");
     }
    t_programa2 = time(NULL);
    t_final = fopen("tiempo_programa_bubblesort.txt", "at");
    fprintf(t_final,"Tiempo Total del programa: %lf\n",difftime(t_programa2,t_programa1));
    fclose(t_final);
    return 0;
}

void lee_datos(char nombre[], int *array, int n){
    FILE *ent;
    int i;
    int dato;
    printf("Procesando: %s\n", nombre);
    ent = fopen(nombre,"r");
    for (i = 0; i < n; i++){
        fscanf(ent, "%d", &dato);
        array[i] = dato;
    }
    fclose(ent);
}

void muestra_datos(int *array, int n){
    int i;
    for (i= 0; i <n; i++){
        printf("%d\n", array[i]);
    }
}

void burbuja(int *array, int n){
    int i, j, aux;
    for(i = 0;i < n-1; i++){   
	    for(j = 0; j < n-i-1; j++){ 
	        if(array[j+1] < array[j]){       
		        aux = array[j+1];       
		        array[j+1] = array[j];  
		        array[j] = aux;
	        }   
	     } 
     } 
}