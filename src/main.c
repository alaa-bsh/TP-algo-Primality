#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double calcule_temps(clock_t debut, clock_t fin) {
    return (double)(fin - debut) * 1000 / CLOCKS_PER_SEC;
}


int A1(int n){
    for(int i = 2; i<n; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int A2(int n){
    for(int i = 2; i <= n/2; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int A3(int n){
    for (int i = 2; i*i <= n ; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int A4(int n){
    if(n%2==0){
        return 0;
    }
    for(int i=3; i*i <= n; i+=2){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}


int main(){
    int x;
    printf("Entrez un nombre: \n");
    scanf("%d", &x);
    int premier = A1(x);
    if(premier == 1){
        printf("Le nombre %d est premier.\n", x);
    } else {
        printf("Le nombre %d n'est pas premier.\n", x);
    }
    return 0;
}

