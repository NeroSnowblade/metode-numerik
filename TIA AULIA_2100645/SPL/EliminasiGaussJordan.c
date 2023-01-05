// Nama		: Tia Aulia
// NIM		: 2100645
// Eliminasi Gauss Jordan

#include <stdio.h>

main()
{
	int i, j,d,e,f,g,h,k,l,m,n,o,p,q,a[4][4], x1,x2,x3;
	printf ("----Program Eliminasi Gauss Jordan----\n");

	for (i=0;i<3;i++)
	{
		for (j=0;j<4;j++)
		{	printf ("Masukkan nilai matriks A[%d][%d] : ",i+1,j+1);
			scanf ("%i", &a[i][j]);
		}
	}
	printf ("\n");

    printf("Ini merupakan bentuk aljabarnya\n");
    printf("----------------------------------------\n");
    printf("%ix1 (+) %ix2 (+) %ix3 = %i \n",a[0][0],a[0][1],a[0][2],a[0][3]);
    printf("%ix1 (+) %ix2 (+) %ix3 = %i \n",a[1][0],a[1][1],a[1][2],a[1][3]);
    printf("%ix1 (+) %ix2 (+) %ix3 = %i \n\n",a[2][0],a[2][1],a[2][2],a[2][3]);

	printf ("---Ini merupakan bentuk Matrik A-nya---  \n\n");
	for (i=0;i<3;i++)
	{
		for (j=0;j<4;j++)
		{	printf ("%i   ",a[i][j]);	}
	printf ("\n\n");
	}

	printf("     ---Bagian ini merupakan---\n");
	printf("Matrik pengganti dari A atau matrik A1 \n");
	printf("--------------------------------------\n\n");

	printf("%i ", a[0][0]);
	printf("%i ", a[0][1]);
	printf("%i ", a[0][2]);
	printf("%i ", a[0][3]); printf ("\n\n");


    d=((a[0][0]*a[1][0]) - (a[1][0]*a[0][0]))  ;  printf("%i ",d);
    e=((a[0][0]*a[1][1]) - (a[1][0]*a[0][1]))  ;  printf("%i ",e);
    f=((a[0][0]*a[1][2]) - (a[1][0]*a[0][2]))  ;  printf("%i ",f);
    g=((a[0][0]*a[1][3]) - (a[1][0]*a[0][3]))  ;  printf("%i ",g);printf ("\n\n");

    h=((a[0][0]*a[2][0]) - (a[2][0]*a[0][0]))  ;  printf("%i ",h);
    k=((a[0][0]*a[2][1]) - (a[2][0]*a[0][1]))  ;  printf("%i ",k);
    l=((a[0][0]*a[2][2]) - (a[2][0]*a[0][2]))  ;  printf("%i ",l);
    m=((a[0][0]*a[2][3]) - (a[2][0]*a[0][3]))  ;  printf("%i ",m);printf ("\n\n");


	printf("     ---Bagian ini merupakan---\n");
	printf("Matrik pengganti dari A1 atau matrik A2\n\n");
	printf("--------------------------------------\n");
	printf("%i ", a[0][0]);
	printf("%i ", a[0][1]);
	printf("%i ", a[0][2]);
	printf("%i ", a[0][3]); printf ("\n\n");
	
	printf("%i ", d);
	printf("%i ", e);
	printf("%i ", f);
	printf("%i ", g); printf ("\n\n");

    printf("%i ",h);
    n=((k*e) - (e*k))  ;  printf("%i ",n);
    o=((l*e) - (f*k))  ;  printf("%i ",o);
    p=((m*e) - (g*k))  ;  printf("%i ",p); printf ("\n\n");

    printf("Hasil X1, X2, dan X3-nya\n\n");
    x3=p/o;
    printf("X3 = %d ", x3); printf ("\n");
    x2=(g-(f*x3))/e;
    printf("X2 = %d ", x2); printf ("\n");
    x1=(a[0][3]-a[0][1]*x2- a[0][2]*x3)/a[0][0];
    printf("X1 = %d ", x1); printf ("\n");

}
