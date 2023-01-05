// Deklarsi library yang akan digunakan
#include<stdio.h>
#include<conio.h>
#include<math.h>

// Deklarasikan fungsi disini
#define f(x) 2*x+3
//x/(1+pow(x,2))

int main(){
	// Mendeklarasikan variabel yang akan digunakan
	float a, b, integrasi=0.0, pias, k,s;
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