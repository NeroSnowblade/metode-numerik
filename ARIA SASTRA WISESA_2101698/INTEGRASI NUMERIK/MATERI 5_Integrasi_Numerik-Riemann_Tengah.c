// Deklarsi library yang akan digunakan
#include<stdio.h> 
#include<conio.h>
#include<math.h>

// Deklarasikan fungsi disini
#define f(x) 2*x + 3
//x/(1+pow(x,2)) 

int main(){
	// Mendeklarasikan variabel
	float a, b, integrasi=0.0, pias,x;
	int i, nInterval;
	
	// Mengambil inputan user, kemudian disimpan dalam variabel
	printf("Masukan batas bawah integral : ");
	scanf("%f", &a);
	printf("Masukan batas atas integral : ");
	scanf("%f", &b);
	printf("Enter number of sub intervals: ");
	scanf("%d", &nInterval);

	// Proses kalkulasi

	// Menghitung panjang satu pias
	pias = (b - a)/nInterval;

	//Mencari titik tengah dari pias pertama
	x =  a + pias / 2;

	// Menghitung fungsi x dari setiap titik tengah pias
	integrasi = f(x);
	for(i=1; i<= nInterval-1; i++){
		x += pias;
		integrasi += f(x);
	}

	// Menghitung total nilai hampiran integrasi
	integrasi = integrasi * pias;
    // Mencetak hasil akhir integrasi
	printf("\nNilai hampiran dari integrasi adalah : %.3f", integrasi);
	// getch();

	return 0;
}