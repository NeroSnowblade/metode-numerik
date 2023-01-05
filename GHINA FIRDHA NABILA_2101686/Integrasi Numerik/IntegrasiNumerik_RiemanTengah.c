// Nama     : Ghina Firdha Nabila
// NIM      : 2101686
// Kelas    : PILKOM 3-A
// Integrasi Numerik Rieman-Tengah

#include<stdio.h> 
#include<conio.h>
#include<math.h>

// mendeklarasikan fungsi
#define f(x) 2*x + 3
//x/(1+pow(x,2)) 

int main(){
	// fungsi deklarasi variabel
	float a, b, integrasi=0.0, pias,x;
	int i, nInterval;
	
	// fungsi inputan user
	printf("Masukan batas bawah integral : ");
	scanf("%f", &a);
	printf("Masukan batas atas integral : ");
	scanf("%f", &b);
	printf("Masukkan jumlah subinterval: ");
	scanf("%d", &nInterval);

	// fungsi perhitiungan
	// fungsi menghitung panjang satu pias
	pias = (b - a)/nInterval;

	// fungsi mencari titik tengah dari pias pertama
	x =  a + pias / 2;

	// fungsi menghitung fungsi x dari setiap titik tengah pias
	integrasi = f(x);
	for(i=1; i<= nInterval-1; i++){
		x += pias;
		integrasi += f(x);
	}

	// fungsi Menghitung total nilai hampiran integrasi
	integrasi = integrasi * pias;
    // fungsi Mencetak hasil akhir integrasi
	printf("\nNilai hampiran dari integrasi adalah : %.3f", integrasi);
	// getch();

	return 0;
}
