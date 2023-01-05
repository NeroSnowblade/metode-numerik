// Nama		: Tia Aulia
// NIM		: 2100645
// Integras Numerik Trapepsium


#include<stdio.h>
#include<conio.h>
#include<math.h>

// Deklarasi fungsi 
#define f(x) 2*x+3
//x/(1+pow(x,2))

int main(){
	// deklarasi variabel
	float a, b, integrasi=0.0, pias, k,s;
	int i, nInterval;
	
	// inputan user
	printf("Masukan batas bawah integral : ");
	scanf("%f", &a);
	printf("Masukan batas atas integral : ");
	scanf("%f", &b);
	printf("Masukkan jumlah subinterval: ");
	scanf("%d", &nInterval);

	// Perhitungan
	// Menghitung panjang satu pias
	pias = (b - a)/nInterval;

	// Menghitung nilai fungsi dari bagian awal dan akhir integral 
	integrasi = f(a) + f(b);
	
	// Comment dibawah digunakan jika ingin mencetak hasil perhitungan jumlah integrasi dari fungsi awal dan akhir 
	// printf("\n %.3f", integrasi);
	
	// Pengulangan untuk menghitung setiap jumlah fungsi setiap pias
	for(i=1; i<= nInterval-1; i++){
		k = a + i*pias;
		//mencetak nilai integrasi setiap pengulangan 	
		printf("\n %.3f , %.3f", k, f(k));
		
		// variabel s digunakan untuk menampung jumlah fungsi dari perhitungan sebelumnya
		s = f(k);
		integrasi +=  2 * s;	
	}
	
	// Menghitung nilai akhir dari total integrasi	
	integrasi = integrasi * pias/2;
    // Mencetak hasil akhir integrasi
	printf("\nNilai hampiran dari integrasi adalah : %.3f", integrasi);
	getch();
	return 0;
}
