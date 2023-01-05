// Nama     : Ifana Andriansyah
// NIM      : 1905044
// Kelas    : PILKOM 3-A
// Program  : Trapezoid Integrasi Numerik


// Fungsi untuk diintegrasikan
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
  for (let i = 1; i < n; i++) {
    // Tambahkan area trapezoid ke hasil
    result += h * (f(a + (i - 1) * h) + f(a + i * h)) / 2;
  }
  
  console.log(result);
  