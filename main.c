/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: yuris
 *
 * Created on 30 de noviembre de 2020, 11:31 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int Nuevo_evento(int nm);

struct Fecha{
    int dia;
    int mes;
    int anio;
};

struct Hora{
    int hr;
    int min;
};

struct Duracion{
    int hr;
    int min;
};

struct Evento{
    char Nombre[20];
    char Lugar[20];
    char Tema[20];
    
    struct Hora Hr;
    struct Fecha Fech;
    struct Duracion Dr;
};
int main() {
    int nm=0;
    int control=0;
    
    while(control!=8){
        opcion:
        printf("Menú\n");
        printf("1. Registrar evento\n");
        printf("2. Modificar evento (N\n");
        printf("3. Modificar horario\n");
        printf("4. Eliminar eventos\n");
        printf("5. Lista de eventos\n");
        printf("6. Lista de eventos por dia\n");
        printf("7. Buscar eventos\n");
        printf("8. Salir\n");
        scanf("%d",&control);
        if ((control<1) || (control>8)){
            printf("\nEsa no es una opción valida\n\n");
            goto opcion;
        }
        switch(control){
            case 1:
                Nuevo_evento(nm);
                nm++;
                break;
            case 2:
                Modifica_evento(nm);
                break;
            case 3:
                //Modifica_hora(nm);
                break;
            case 4:
                //Eliminar_eventos(nm);
                break;
            case 5:
                printf("\n");
                Lista(nm);
                break;
            case 6:
                printf("\n");
                Lista_por_eventos(nm);
                break;
            case 7:
                Buscar(nm);
                break;
        }
        
    }
    
    return 0;
}

    struct Evento nombre[100];
int Nuevo_evento(int nm){
    FILE*datos=fopen("miagenda.dat","ad");

    printf("\nIngrese el nombre del evento\n");
    scanf("%s",&nombre[nm].Nombre);
    printf("\nIngrese el lugar del evento\n");
    scanf("%s",&nombre[nm].Lugar);
    printf("\nIngrese el tema del evento\n");
    scanf("%s",&nombre[nm].Tema);
    printf("\nIngresa la fecha del evento\n");
    printf("Día: ");
    scanf("%d",&nombre[nm].Fech.dia);
    printf("\nMes: ");
    scanf("%d",&nombre[nm].Fech.mes);
    printf("\nAño: ");
    scanf("%d",&nombre[nm].Fech.anio);
    printf("\nIngresa la hora del evento\n");
    printf("Hora: ");
    scanf("%d",&nombre[nm].Hr.hr);
    printf("\nMinutos: ");
    scanf("%d",&nombre[nm].Hr.min);
    printf("\nIngresa la duracion del evento\n");
    printf("Hora: ");
    scanf("%d",&nombre[nm].Dr.hr);
    printf("\nMinutos: ");
    scanf("%d",&nombre[nm].Dr.min);

    
    fwrite(&nombre[nm],sizeof(struct Evento),1,datos);
    fclose(datos);
    return 0;
}


int Modifica_evento(int nm){
    int nm2 = 0;
    int control=0;
    char VN[20], NN[20];
    FILE*datos=fopen("miagenda.dat","a+");
    while(control!=4){
        opcion:
        printf("Modifica evento\n");
        printf("1. Cambiar nombre del evento\n");
        printf("2. Modificar lugar del evento (N\n");
        printf("3. Modificar tema del evento\n");
        printf("4. Salir\n");
        scanf("%d",&control);
        if ((control<1) || (control>4)){
            printf("\nEsa no es una opción valida\n\n");
            goto opcion;
        }
        switch(control){
            case 1:
                printf("Viejo nombre");
                scanf("%s",&VN);
                while(feof(datos)==0){
                fread(&nombre[nm2],sizeof(nombre[nm2]),1,datos);
                if (strcmp(VN, nombre[nm2].Nombre)==0){
                    printf("Ingresa el nuevo nombre");
                    scanf("%s",&NN);
                    fprintf(datos,"%s",NN);
                    }
                   nm2++;
                }
                fclose(datos);
                printf("si funcion");
                break;
            case 2:
                printf("Si sirve modificar");
                
                break;
            case 3:
                printf("Si sirve modificar hr");
                //Modifica_tema(nm);
                break;  
        }
        
    }
    //fwrite(&nombre[nm],sizeof(struct Evento),1,datos);
    
    
    
    return 0;
}

int Lista(int nm){
    int nm2=0;
    int nm3=0;
 
    
    FILE*datos=fopen("miagenda.dat","rd");
    while(feof(datos)==0){
        fread(&nombre[nm2],sizeof(nombre[nm2]),1,datos);
        printf("%d",nombre[nm2].Hr.hr);
        printf("/%d",nombre[nm2].Hr.min);
        printf("\t%d",nombre[nm2].Dr.hr);
        printf("/%d",nombre[nm2].Dr.min);
        printf("\t\t%s\n",nombre[nm2].Nombre);
        printf("\t\t%d/",nombre[nm2].Fech.dia);
        printf("%d/",nombre[nm2].Fech.mes);
        printf("%d\n",nombre[nm2].Fech.anio);
        printf("\t\t%s\n",nombre[nm2].Lugar);
        printf("\t\t%s\n",nombre[nm2].Tema);
        nm2++;       
    }
    printf("\n");

    fclose(datos);
}

int Lista_por_eventos(int nm){
    int nm2=0;
    int A, D, M;
    
    FILE*datos=fopen("miagenda.dat","rd");
     
        printf("\nIngresa la fecha del evento\n");
        printf("Día: ");
        scanf("%s",D);
        printf("\nMes: ");
        scanf("%s",M);
        printf("\nAño: ");
        scanf("%s",A);
        while(feof(datos)==0){
            fread(&nombre[nm2],sizeof(nombre[nm2]),1,datos);
            if ((strcmp(A,nombre[nm2].Fech.anio)==0) && (strcmp(M,nombre[nm2].Fech.mes)==0) && (strcmp(D,nombre[nm2].Fech.dia)==0)){
            //if(strcmp(D, nombre[nm2].Fech.dia)==0){    
                printf("\nNombre: %s",nombre[nm2].Nombre);
                printf("\t\t\tLugar del evento\t%s",nombre[nm2].Lugar);
                printf("\t\t\tTema del evento\t%s",nombre[nm2].Tema);
                printf("\t\t\tHora del evento: %d/%d",nombre[nm2].Hr.hr,nombre[nm2].Hr.min);
                printf("\t\t\tDuracion del evento: %d/%d\n",nombre[nm2].Hr.hr,nombre[nm2].Hr.min);
            }
        }

return 0;
}

int Buscar(int nm){
    int nm2=0;
    char N[20];
    int ordenar;
    printf("\n1. Por nombre\n");
    printf("2. Por parte del nombre\n");
    scanf("%d",&ordenar);
    
    FILE*datos=fopen("miagenda.dat","rd");
     
    if(ordenar==1){
        printf("\nIngresa el nombre que busca\n");
        scanf("%s",&N);
        while(feof(datos)==0){
            fread(&nombre[nm2],sizeof(nombre[nm2]),1,datos);
            if (strcmp(N, nombre[nm2].Nombre)==0){
                printf("\nNombre: %s",nombre[nm2].Nombre);
                printf("\t\t\tLugar del evento\t%s",nombre[nm2].Lugar);
                printf("\t\t\tTema del evento\t%s",nombre[nm2].Tema);
                printf("\t\t\tFecha del evento: %d/%d/%d",nombre[nm2].Fech.dia,nombre[nm2].Fech.mes,nombre[nm2].Fech.anio);
                printf("\t\t\tHora del evento: %d/%d",nombre[nm2].Hr.hr,nombre[nm2].Hr.min);
                printf("\t\t\tDuracion del evento: %d/%d\n",nombre[nm2].Hr.hr,nombre[nm2].Hr.min);     
            }
            nm2++;
        }
    }
    
    if(ordenar==2){
        printf("\nIngresa parte del nombre\n");
        scanf("%s",&N);
        while(feof(datos)==0){
            fread(&nombre[nm2],sizeof(nombre[nm2]),1,datos);
            if (strstr(nombre[nm2].Nombre,N)!=NULL){
                printf("\n\t\t\tNombre: %s\n",nombre[nm2].Nombre);
                printf("\t\t\tLugar del evento\t%s",nombre[nm2].Lugar);
                printf("\t\t\tTema del evento\t%s",nombre[nm2].Tema);
                printf("\t\t\tFecha del evento: %d/%d/%d",nombre[nm2].Fech.dia,nombre[nm2].Fech.mes,nombre[nm2].Fech.anio);
                printf("\t\t\tHora del evento: %d/%d",nombre[nm2].Hr.hr,nombre[nm2].Hr.min);
                printf("\t\t\tDuracion del evento: %d/%d\n",nombre[nm2].Hr.hr,nombre[nm2].Hr.min);
            }
            nm2++;
        }
    }
    printf("\n\n");
    return 0;
}


