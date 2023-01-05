// Nama		: Tia Aulia
// NIM		: 2100645
// Newton Raphson


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double newton(double guess, double sub_zero, int max, double epsilon);

main(){
    //deklarasi variabel
    double guess, sub_zero, epsilon;
    int max;
    
    //user input 
    printf("Masukan tebakan awal: ");
    scanf("%lf", &guess);
    printf("Masukan nilai dari C: ");
    scanf("%lf", &sub_zero);
    printf("Masukan Jumlah Iterasi maksimum: ");
    scanf("%d", &max);
    printf("Masukan eror maksimum: ");
    scanf("%lf", &epsilon);
    
    //memisahkan input dari solusi
    printf("\n\n                      Solusi \n");
    
    //panggil fungsi newton
    newton(guess, sub_zero, max, epsilon);
    
    //output
    printf("\n Iterasi maksimum yang anda masukan adalah: %d\n", max);
    printf("             Nilai tebakannya adalah: %0.3f\n", guess);
    printf("                 Nilai dari C adalah: %0.3f\n", sub_zero);
    printf("    Nilai eror yang dimasukan adalah: %0.3f\n\n", epsilon);
    

    system("pause");
    return 0;
}

double newton(double guess, double sub_zero, int max, double epsilon){
    //deklarasi variabel
    double y = guess, fx;
    int count = 0;
    
    //loop sampai hitungan kurang dari input pengguna "max"
    while(count < max){
        //keluar dari loop ketika |f(x)| lebih kecil dari epsilon
        if(fabs(fx) < epsilon){
                break;
        }
        //jika tidak, lakukan rumus newton dan f(x).
        else{
                fx = (pow(y,4)-sub_zero);
                y = y - (pow(y,4)-sub_zero)/(4*pow(y,3));
        
                ++count;
        }
    }
    
    //output hasil
    printf("\n                   Final root adalah: %f", y);
    printf("\n              Nilai dari f(x) adalah: %f", fx);
    printf("\n                Total iterasi adalah: %d", count);
    
    return y, fx, count;
}
