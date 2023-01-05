import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import make_interp_spline

# Input Jumlah Titik
n = int(input('Masukan jumlah titik: '))
ix = [0] * n
iy = [0] * n

# Input titik x[i], y[i]
for i in range(n):
    ix[i] = float(input( 'x['+str(i)+']= '))
    iy[i] = float(input( 'y['+str(i)+']= '))
    print()

# Konversi Array
x = np.array(ix)
y = np.array(iy)

# Input Titik Interpolasi
L = [1] * n
Ly = 0
Lx = float(input('Masukan titik interpolasi: '))

if Lx < x.max() and Lx > x.min() :
    i = 0
    j = 0
    for i in range(n):
        for j in range(n):
            if i != j:
                L[i] *= (Lx - x[j])/(x[i] - x[j])
        Ly += L[i] * y[i]

    # Output Terminal
    print("p2(" + str(Lx) + ") = " + str(Ly))
    
    # Output Grafik
    xnew = np.linspace(x.min(), x.max(), 300)
    spl = make_interp_spline(x, y, k=2)
    smooth = spl(xnew)
    plt.plot(x, y, 'bo', xnew, smooth, 'b-') # Jalur Titik
    plt.plot(Lx, Ly, 'ro', label="p2(" + str(Lx) + ") = " + str(Ly)) # Titik yang Dicari
    plt.ylabel('Y')
    plt.xlabel('X')
    plt.legend()
    plt.show()
else:
    print("Titik Berada diluar rentang data..")