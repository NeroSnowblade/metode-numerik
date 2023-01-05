# Nama      : Ghina Firdha Nabila
# NIM       : 2101686
# Kelas     : PILKOM 3-A
# Metode Gauss jordan

import numpy as np 
import sys

n = int(input('Input jumlah variabel: ')) 
a = np.zeros((n,n+1))
x = np.zeros(n) 
print('Input koefisien dan nilai kanan pada SPL:')

for i in range(n):
    for j in range(n+1):
        a[i][j] = float(input( 'a['+str(i)+']['+ str(j)+']='))     
        
for i in range(n):
    if a[i][i] == 0.0: 
        sys.exit('Terdapat nilai 0 pada diagonal utama')
        
    for j in range(n):
        if i != j: 
            ratio = a[j][i]/a[i][i] 

            for k in range(n+1): #(3) : 0, 1, 2
                a[j][k] = a[j][k] - ratio * a[i][k] 
                
for i in range(n):
    x[i] = a[i][n]/a[i][i]
    
print('\nSolusi SPL adalah: ')
for i in range(n):
    print('X%d = %0.2f' %(i,x[i]), '\t')
