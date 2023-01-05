// Nama		: Tia Aulia
// NIM		: 2100645
// Bisection Method


#include<stdio.h>
#include<math.h>

float f(float x);
int main()
{
	// deklarasi variabel
    float a, b, x =0, f1, f2, f3, c, e=4;
    int i;
    
    for(i=0;i<10;i++){
        if(f((float)(i))*f((float)(i+1))<0)
        {
            a=i;
            b=i+1;
            break;
        }
    }
    do{
        c=x;
        x=(a+b)/2;
        if(f(x)*f(a)<0)
            b=x;
        else
            a=x;
    }
    while((int)(c*pow(10,4))-(int)(x*pow(10,4))!=0);
    printf("root=%.3f",x);
    return 0;

}

float f(float x)
{
    float y;
    y=x*x*x+5*x-1;
    return y;
}
