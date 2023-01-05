#include <stdio.h>

int main() {
    int input;
    printf("Masukan jumlah titik : ");
    scanf("%d", &input);
    float x[input];
    float y[input];

    int i, j;
    for ( i = 0; i < input; i++) {
        printf("\nx[%d] y[%d] : ", i, i);
        scanf("%f", &x[i]);
        scanf("%f", &y[i]);
    }
    
    float L[input];
    float Ly = 0;
    float Lx = 0;

    printf("\nMasukan titik interpolasi : ");
    scanf("%f", &Lx);

    for ( i = 0; i < Lx; i++) {
        L[i] = 1;
        for ( j = 0; j < Lx; j++) {
            if(i != j) { L[i] *= (Lx - x[j])/(x[i] - x[j]); }
        }
        Ly += L[i] * y[i];
    }
    
    printf("\np2(%.4f) : %.4f", Lx, Ly);
    return 0;
}