// Deklarsi library yang akan digunakan
#include<stdio.h>
#include<conio.h>

void main(){

    // Mendeklarasikan beberapa variabel yang akan digunakan
    float x[100], y[100];
    float xp, yp=0, p;
	int i,j,totalSampel;

    // Mengambil inputan user untuk total sampel yang akan digunakan
    printf("Masukan jumlah sampel : ");
    scanf("%d", &totalSampel);

    // Mengambil inputan user untuk setiap data x dan y nya
    // Input akan dieksekusi berulang kali sesuai jumlah sampel yang sebelumnya dimasukan
    printf("Masukan jumlah data  :\n");
    for(i=1;i<=totalSampel;i++){
        // Menginput x ke-n sesuai perulangan
        printf("x ke-%d = ", i-1);
        scanf("%f", &x[i]);
        // Menginput y ke-n sesuai perulangan
        printf("yke-%d = ", i-1);
        scanf("%f", &y[i]);
    }

    // Menginput nilai x baru atau nilai yang akan dicari hampiran y nya
    printf("Enter interpolation point: ");
    scanf("%f", &xp);

    // Proses kalkulasi

    // Perulangan pertama untuk mengulang penjumlahan satu nilai interpolasi
    // yang kemudian nilainya akan di tampung di variabel yp
    for(i=1;i<=totalSampel;i++){

        // Variabel p digunakan untuk menampung total kalkulasi per sampel 
        // Memberi nilai p = 1 agar setiap pengulangan, nilai p kembali menjadi 1
        p=1;

        // Perulangan kedua dalam perulangan pertama 
        // Perulangan kedua untuk kalkulasi setiap berdasarkan derajatnya
        for(j=1;j<=totalSampel;j++){
            if(i!=j){
                // Menampung nilai perhitungan di p
                p = p* (xp - x[j])/(x[i] - x[j]);
            }
        }
        // variabel yp digunakan untuk menampung total kalkulasi dari setiap perulangan
        yp = yp + p * y[i];
    }
    // mencetak nilai akhir interpolasi
    printf("Nilai interpolasi dar %.3f adalah %.3f", xp, yp);
    getch();
}