/*
    PROGRAM SOLUSI PERMASALAHAN SISTEM PERSAMAAN LINEAR

    Kelompok : 6
    Aldianto Prabowo Adi
    Fiqal Hanif Al Daris
    Muhammad Fadhlurrahman Muzakki
    Reta Haura Zahra
    Sarah Aghnia Fauzia
    Mohammad Guntur Nugraha
*/

#include <stdio.h>
#define size 5

// VARIABEL GLOBAL
int i, j, k;

// FUNGSI ELIMINASI GAUSS JORDAN
void gaussJordan(double arr[size][size], int ordo){
    double pembagi, v[size];

    printf("\t[Matriks A | B]\n");
    printMatrix(arr, ordo);

    // perulangan seluruh matriks
    for(i = 0; i < ordo; i++){
        pembagi = arr[i][i];

        // perulangan tiap-tiap baris pada matriks
        for(k = i; k < ordo + 1; k++){
            arr[i][k] /= pembagi;
        }

        // perulangan tiap-tiap kolom pada matriks
        // cek secara vertikal agar array selain x[i][i] bernilai 0
        for(j = i + 1; j < ordo + 1; j++){
            v[i] = arr[j][i];

            // perulangan tiap-tiap baris pada matriks kolom yang sama
            for(k = i; k < ordo + 1; k++){
                arr[j][k] = arr[j][k] - v[i] * arr[i][k];
            }
        }
    }

    for(i = 1; i < ordo; i++){
        for(j = 1; j < i + 1; j++){
            v[j] = arr[j - 1][i];
            for(k = i; k < ordo + 1; k++){
                arr[j - 1][k] -= v[j] * arr[i][k];
            }
        }
    }

    printf("\n\t[Matriks Identitas]\n");
    printMatrix(arr, ordo);
}

// FUNGSI CETAK MATRIKS
void printMatrix(double arr[size][size], int ordo){
    for (i = 0; i < ordo; i++){
        printf("|");
        for (j = 0; j < ordo; j++){
            printf("%.3f   ", arr[i][j]);

            // menuliskan vektor matriks B
            if (j == ordo - 1){
                printf("\t|   %.3lf", arr[i][j + 1]);
            }
        }
        printf("|\n");
    }
}


// FUNGSI UTAMA
int main(){
    // deklarasi tipe data
    double arr[size][size];
    int ordo;


    printf("\n\n============= SOLUSI PERSAMAAN SISTEM LINEAR METODE GAUSS JORDAN ========================\n");
    printf("\nPress any key to continue.\n");
    getchar();

    printf("\nMasukkan Ordo Matriks : ");
    scanf("%d", &ordo);

    // ketika inputan ordo kurang dari 2
    if(ordo < 2){
        printf("\nBentuk Matriks Minimal 2x2");
        return 0; // program akan berhenti
    }

    printf("\n[Terkonfirmasi Matriks Ordo %dx%d]\n\n", ordo, ordo);

    // Deteksi Input User
    // Perulangan Tiap Baris Matriks
    for(i = 0; i < ordo; i++) {
        printf("Input Matriks Baris ke-%d\n", (i + 1));

        // input tiap item kedalam matriks
        printf("Matriks A\n");
        for(j = 0; j < ordo; j++){
            printf("[%d][%d] = ", (i+1), (j+1));
            scanf("%lf", &arr[i][j]);

            // vektor B disimpan ke dalam array dimensi kedua indeks terakhir
            // jika telah sampai pada ujung baris (ordo - 1), input vektor B ke array arr[i][j+1]
            if(j == ordo - 1){
                printf("Matriks B\n");
                printf("[%d][%d] = ", (i+1), (j+1));
                scanf("%lf", &arr[i][j + 1]);
            }
        }
        printf("\n");
    }

    // Operasi Gauss Jordan
    gaussJordan(arr, ordo);

    // menampilkan nilai x1, x2, x3
    for(i = 0; i < ordo; i++){
        printf("\nX%d = %.3lf", (i + 1), arr[i][ordo]);
    }
    return 0;
}
