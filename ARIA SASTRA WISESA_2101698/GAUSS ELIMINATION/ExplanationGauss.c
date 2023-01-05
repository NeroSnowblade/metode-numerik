#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define SIZE 10

int main(){
	float a[SIZE][SIZE], x[SIZE], ratio;
	int i, j, k, n;
	
	// Input jumlah variabel yang dicari
	printf("Input jumlah variabel: ");
	scanf("%d", &n);
	
	// Proses input persamaan linear 
	for(i=1; i<=n; i++){
		for(j=1; j<=n+1; j++){
			printf("a[%d][%d] = ", i, j);
			scanf("%f", &a[i][j]);
		}
	}
	
	// Menerapkan Gauss Elimination
	for(i=1; i<=n-1; i++){
		if(a[i][i] == 0.0){
			printf("Mathematical Error!");
			exit(0);
		}
		for(j=i+1; j<=n; j++){
			printf("\nratio = a[%d][%d]/a[%d][%d]\n", j, i, i, i);
			ratio = a[j][i]/a[i][i];
			printf("ratio = %.2f/%.2f\n", a[j][i], a[i][i]);
			printf("ratio = %.2f\n", ratio);

			for(k=1; k<=n+1; k++){
                printf("a[%d][%d] = a[%d][%d] - ratio*a[%d][%d]\n", j, k, j, k, i, k);
                printf("a[%d][%d] = %.2f - %.2f*%.2f\n", j, k, a[j][k], ratio, a[i][k]);
			  	a[j][k] = a[j][k] - ratio*a[i][k];
                printf("a[%d][%d] = %.2f\n", j, k, a[j][k]);
			}
		}
	}
	 
	// Mendapatkan solusi dengan substitusi balik
    printf("\nx[%d] = a[%d][%d+1]/a[%d][%d]\n", n, n, n, n , n);
	x[n] = a[n][n+1]/a[n][n];
    printf("x[%d] = %.2f/%.2f\n", n, a[n][n+1], a[n][n]);
    printf("x[%d] = %.2f\n", n, x[n]);
	
	for(i=n-1; i>=1; i--){
        printf("\nx[%d] = a[%d][%d+1]\n", i, i, n);
		x[i] = a[i][n+1];
        printf("x[%d] = %.2f\n", i, x[i]);

		for(j=i+1; j<=n; j++){
            printf("x[%d] = x[%d] - a[%d][%d]*x[%d]\n", i, i, i, j, j);
            printf("x[%d] = %.2f - %.2f*%.2f\n", i, x[i], a[i][j], x[j]);
		  	x[i] = x[i] - a[i][j]*x[j];
            printf("x[%d] = %.2f\n", i, x[i]);
		}
        printf("x[%d] = x[%d]/a[%d][%d]\n", i, i, i, i);
        printf("x[%d] = %.2f/%.2f\n", i, x[i], a[i][i]);
		x[i] = x[i]/a[i][i];
        printf("x[%d] = %.2f\n", i, x[i]);
	}
	
	// Menampilkan solusi
	printf("\nSolution:\n");
	for(i=1; i<=n; i++){
	  	printf("x[%d] = %0.3f\n", i, x[i]);
	}

	getch();
	return 0;
}