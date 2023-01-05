// Nama     : Ifana Andriansyah
// NIM      : 1905044
// Kelas    : PILKOM 3-A
// Program  : Integraso Numerik Metode Rieman

// Function to integrate
function f(x) {
    return x * x;
  }
  
  // Batas-batas integrasi
  const a = 0;
  const b = 1;
  
  // Jumlah interval
  const n = 1000;
  
  // Lebar setiap interval
  const h = (b - a) / n;
  
  // Inisialisasi hasil
  let result = 0;
  
   // Iterasi melalui interval
  for (let i = 0; i < n; i++) {
    // Add area of rectangle to result
    result += h * f(a + i * h);
  }
  
  console.log(result);
  