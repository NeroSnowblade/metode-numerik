// Nama		: Tia Aulia
// NIM		: 2100645
// Gauss Elimination


#include<stdio.h>
int main()
{
	//deklarasi variabel
    int i,j,k,n;
    float A[20][20],c,x[10],sum=0.0;
    
    // inputan user
    printf("\nMasukkan ordo matriks: ");
    scanf("%d",&n);
    printf("\nMasukkan elemen baris matriks:\n\n");
    
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {
            printf("A[%d][%d] : ", i,j);
            scanf("%f",&A[i][j]);
        }
    }
    for(j=1; j<=n; j++) /* loop untuk membentuk matriks segitiga atas*/
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    x[n]=A[n][n+1]/A[n][n];
    /* loop ini untuk backward substitution*/
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+A[i][j]*x[j];
        }
        x[i]=(A[i][n+1]-sum)/A[i][i];
    }
    printf("\n Solusiny adalah: \n");
    for(i=1; i<=n; i++)
    {
        printf("\nx%d=%f\t",i,x[i]); /* x1, x2, x3 adalah solusi yang diperlukan*/
    }
    return(0);
}
