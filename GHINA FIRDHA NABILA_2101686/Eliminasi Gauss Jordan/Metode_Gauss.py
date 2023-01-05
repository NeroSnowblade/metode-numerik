# Nama      : Ghina Firdha Nabila
# NIM       : 2101686
# Kelas     : PILKOM 3-A
# Metode Gauss

import numpy as np
import sys

n = int(input('Input jumlah variabel: '))
a = np.zeros((n,n+1))
x = np.zeros(n)

print('Input koefisien dan nilai kanan pada SPL:')

for i in range(n): 
    for j in range(n+1):
        a[i][j] = float(input( 'A['+str(i)+']['+ str(j)+']='))        
           
for i in range(n):
    if a[i][i] == 0.0: 
        sys.exit('Terdapat nilai 0 pada diagonal utama')  
          
        
    for j in range(i+1, n):
        ratio = a[j][i]/a[i][i]      
        for k in range(n+1):          
            a[j][k] = a[j][k] - ratio * a[i][k]
            
x[n-1] = a[n-1][n]/a[n-1][n-1]
for i in range(n-2,-1,-1):
    x[i] = a[i][n]   
    
    for j in range(i+1,n):
        x[i] = x[i] - a[i][j]*x[j]       
        
print('\nSolusi SPL adalah: ')
for i in range(n):
    print('X%d = %0.2f' %(i,x[i]), end = '\t')
