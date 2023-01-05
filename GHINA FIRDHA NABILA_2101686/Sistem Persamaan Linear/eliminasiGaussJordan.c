// Nama       : Ghina Firdha Nabila
// NIM        : 2101686
// Kelas      : PILKOM 3-A
// Eliminasi Gauss Jordan

#include <stdio.h>
#define size 5

// membuat variable global
int i, j, k;

// membuat fungsi eliminasi gauss jordan
void gaussJordan(double arr[size][size], int ordo){
    double pembagi, v[size];

    printf("\t[Matriks A | B]\n");
    printMatrix(arr, ordo);

    // melakukan perulangan seluruh matriks
    for(i = 0; i < ordo; i++){
        pembagi = arr[i][i];

        // melakukan perulangan tiap-tiap baris pada matriks
        for(k = i; k < ordo + 1; k++){
            arr[i][k] /= pembagi;
        }

        // melakukan perulangan tiap-tiap kolom pada matriks
        // untuk mengecek secara vertikal agar array selain x[i][i] bernilai 0
        for(j = i + 1; j < ordo + 1; j++){
            v[i] = arr[j][i];

            // melakukan perulangan tiap-tiap baris pada matriks kolom yang sama
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

// membuat fungsi untuk mencetak matriks
void printMatrix(double arr[size][size], int ordo){
    for (i = 0; i < ordo; i++){
        printf("|");
        for (j = 0; j < ordo; j++){
            printf("%.3f   ", arr[i][j]);

            // menuliskan vektor untuk matriks B
            if (j == ordo - 1){
                printf("\t|   %.3lf", arr[i][j + 1]);
            }
        }
        printf("|\n");
    }
}


// membuat fungsi utama
int main(){
    // mendeklarasi tipe data
    double arr[size][size];
    int ordo;


    printf("\n\n============= SOLUSI PERSAMAAN SISTEM LINEAR METODE GAUSS JORDAN ========================\n");
    printf("\nPress any key to continue.\n");
    getchar();

    printf("\nMasukkan Ordo Matriks : ");
    scanf("%d", &ordo);

    // fungsi saat inputan ordo kurang dari 2
    if(ordo < 2){
        printf("\nBentuk Matriks Minimal 2x2");
        return 0; // program akan berhenti
    }

    printf("\n[Terkonfirmasi Matriks Ordo %dx%d]\n\n", ordo, ordo);

    // fungsi mendeteksi input user
    // melakukan perulangan tiap baris matriks
    for(i = 0; i < ordo; i++) {
        printf("Input Matriks Baris ke-%d\n", (i + 1));

        // fungsi input tiap item kedalam matriks
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

    // fungsi menampilkan nilai x1, x2, x3
    for(i = 0; i < ordo; i++){
        printf("\nX%d = %.3lf", (i + 1), arr[i][ordo]);
    }
    return 0;
}
