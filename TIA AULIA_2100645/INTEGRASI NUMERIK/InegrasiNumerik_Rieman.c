// Nama		: Tia Aulia
// NIM		: 2100645
// Integras Numerik Rieman

#include<stdio.h>
#include<conio.h>
#include<math.h>

/* Tentukan fungsi di sini */
#define f(x) 2*x + 3
//x/(1+pow(x,2)) 

int main()
{
	// deklarasi variabel
	float lower, upper, integration=0.0, stepSize, k;
	int i, subInterval,x;
	// clrscr();
	
	/* Input User */
	printf("Masukkan batas bawah integrasi: ");
	scanf("%f", &lower);
	printf("Masukkan batas atas integrasi: ");
	scanf("%f", &upper);
	printf("Masukkan jumlah sub interval: ");
	scanf("%d", &subInterval);

	// Perhitungan 
	// Menemukan ukuran langkah
	stepSize = (upper - lower)/subInterval;
	x =  lower + stepSize / 2;
	
	// Menemukan Nilai Integrasi 
	integration = f(x);
	for(i=1; i<= subInterval-1; i++)
	{
 	x += stepSize;
 	integration += ((i-1)*f(x));
	}
	integration = integration * stepSize;
	printf("\nNilai integrasi yang dibutuhkan adalah: %.3f", integration);
	getch();
	return 0;
}
