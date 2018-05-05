//Primer Parcial Laboratorio I
//Francisco L. Franco (com. 4)

#include "pila.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxDim = 50;

//Inciso 1
int cargarArreglo(int a[], int dim){
  char control = 's';
  int i = 0;
  while(control == 's' && i< dim){
    printf("Ingrese un elemento: \n");
    fflush(stdin);
    scanf("%i", &a[i]);
    printf("Desea ingresar otro elemento? s/n\n");
    fflush(stdin);
    scanf(" %c", &control);
    i++;
  }
  return i;
}
//Fin Inciso 1

//Inciso 2
void copiarPila(Pila *p, int a[], int val){
  for(int i = 0;i<val;i++){
    if(a[i]>96&&a[i]<123){
      apilar(p,a[i]);
    }
  }
}
//Fin Inciso 2

//Inciso 3
int menorPila(Pila *p){
  int menor = tope(p);
  Pila aux;
  inicpila(&aux);
  while(!pilavacia(p)){
    if(tope(p)<menor){
      menor = tope(p);
    }
    apilar(&aux,desapilar(p));
  }
  while(!pilavacia(&aux)){
    apilar(p,desapilar(&aux));
  }
  return menor;
}
//Fin Inciso 3

//Inciso 4
int sumar(Pila *p){
  int suma=0;
  Pila aux;
  inicpila(&aux);
  while(!pilavacia(p)){
    if(tope(p)>100){
      suma = suma + tope(p);
      apilar(&aux,desapilar(p));
    }else{
      apilar(&aux,desapilar(p));
    }
  }
  while(!pilavacia(&aux)){
    apilar(p,desapilar(&aux));
  }
  return suma;
}

int contar(Pila *p){
  int cont=0;
  Pila aux;
  inicpila(&aux);
  while(!pilavacia(p)){
    if(tope(p)>100){
      cont++;
      apilar(&aux,desapilar(p));
    }else{
      apilar(&aux,desapilar(p));
    }
  }
  while(!pilavacia(&aux)){
    apilar(p,desapilar(&aux));
  }
  return cont;
}

int promedio(Pila *p){
  int suma, cont, ver;
  int prom = 0;
  ver = verificar(p);
  if(verificar == 1){
    suma = sumar(p);
    cont = contar(p);
    prom = suma / cont;
  }
  return prom;
}

int verificar(Pila *p){
  int cont = 0;
  Pila aux;
  inicpila(&aux);

  while(!pilavacia(p)){
    if(tope(p)>100){
      cont = 1;
      apilar(&aux,desapilar(p));
    }else{
      apilar(&aux,desapilar(p));
    }
  }
  while(!pilavacia(&aux)){
    apilar(p,desapilar(&aux));
  }
}
//Fin Inciso 4

//Inciso 5
int pilaToChar(Pila *p, char a[], int dim){
  int i=0;
  Pila aux;
  inicpila(&aux);
  while(!pilavacia(p)&&i<dim){
    a[i] = tope(p);
    apilar(&aux, desapilar(p));
    i++;
  }
  while(!pilavacia(&aux)){
    apilar(p,desapilar(&aux));
  }
  printf(" %c\n",a[i]);
  return i;
}
//Fin Inciso 5

void mostrarArregloChar(char a[], int val){
  for(int i=0;i<val;i++){
    printf("%c - ",a[i]);
  }
}

//Inciso 6
int buscarChar(char a[], int val, char dato){
  int enco = 0;
  for(int i=0;i<val;i++){
    if(dato == a[i]){
      enco = 1;
    }
  }
  return enco;
}

void encontrado(char a[], int val){
  int enco;
  char dato;
  printf("\n\nIngrese un caracter:\n");
  fflush(stdin);
  scanf(" %c\n",&dato);
  enco = buscarChar(a,val,dato);
  if(enco == 1){
    printf("El caracter se encuentra en el arreglo\n");
  }else{
    printf("El caracter no se encuentra en el arreglo\n");
  }
}


int main() {
  int numeros[maxDim] = {0};
  char letras[maxDim];
  int validosN, menor, validosL, encont, prome;
  Pila pila1;
  inicpila(&pila1);
  //char prueba[maxDim] = {97};
  //printf(" %c\n",prueba[0]);


  validosN = cargarArreglo(numeros, maxDim);
  copiarPila(&pila1, numeros, validosN);
  menor = menorPila(&pila1);
  printf("El menor elemento de la pila es: %i\n",menor);
  prome = promedio(&pila1);
  validosL = pilaToChar(&pila1, letras, maxDim);
  mostrar(&pila1);
  mostrarArregloChar(letras, validosL);
  encontrado(letras,validosL);

  return 0;
}
