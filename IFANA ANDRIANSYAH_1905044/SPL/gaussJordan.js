// Nama     : Ifana Andriansyah
// NIM      : 1905044
// Kelas    : PILKOM 3-A
// Program  : Metode Gauss Jordan
const { NOTIMP } = require("dns");
const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// Sistem persamaan linear yang akan diselesaikan
let equations;


// Fungsi untuk mencari nilai pivot
function pivot(matrix, row) {
  let max = Math.abs(matrix[row][row]);
  let maxRow = row;
  for (let i = row + 1; i < matrix.length; i++) {
    if (Math.abs(matrix[i][row]) > max) {
      max = Math.abs(matrix[i][row]);
      maxRow = i;
    }
  }
  return maxRow;
}

// Fungsi untuk menyelesaikan sistem persamaan linear dengan metode Gauss-Jordan
function gaussJordan(matrix) {
  // Loop untuk setiap baris
  for (let i = 0; i < matrix.length; i++) {
    // Mencari nilai pivot untuk baris ini
    const pivotRow = pivot(matrix, i);
    // Menukar baris dengan baris pivot jika diperlukan
    if (i !== pivotRow) {
      [matrix[i], matrix[pivotRow]] = [matrix[pivotRow], matrix[i]];
    }
    // Menghitung faktor pembagian untuk menjadikan elemen pivot menjadi 1
    const pivotValue = matrix[i][i];
    if (pivotValue !== 1) {
      for (let j = 0; j < matrix[i].length; j++) {
        matrix[i][j] /= pivotValue;
      }
    }
    // Mengurangi baris lain dengan baris pivot untuk menjadikan elemen subdiagonal menjadi 0
    for (let k = 0; k < matrix.length; k++) {
      if (k !== i) {
        const factor = matrix[k][i];
        for (let l = 0; l < matrix[k].length; l++) {
          matrix[k][l] -= matrix[i][l] * factor;
        }
      }
    }
  }
  // Menghitung nilai variabel dari baris terakhir ke baris pertama
  const result = new Array(matrix.length);
  for (let i = matrix.length - 1; i >= 0; i--) {
    result[i] = Math.round(matrix[i][matrix[i].length - 1] * 1000000) / 1000000;
    for (let j = i - 1; j >= 0; j--) {
      matrix[j][matrix[j].length - 1] = Math.round((matrix[j][matrix[j].length - 1] - matrix[j][i] * result[i]) * 1000000) / 1000000;
    }
  }
  

  return result;
}

// Meminta input jumlah persamaan dari user
rl.question("Masukkan jumlah persamaan: ", numEquations => {
  rl.question("Masukkan jumlah variabel: ", numVariables => {
    // Membuat array kosong untuk menyimpan persamaan
    equations = new Array(+numEquations);

    // Meminta input persamaan dari user
    function askEquation(i) {
      if (i < numEquations) {
        rl.question(`Masukkan persamaan ke-${i + 1}: `, equation => {
          // Memecah string persamaan menjadi array of numbers
          equations[i] = equation.split(" ").map(Number);
          askEquation(i + 1);
        });
      } else {
        // Menyelesaikan sistem persamaan linear
        const result = gaussJordan(equations);
        console.log(`Hasilnya: [${result.join(", ")}]`);
        rl.close();
      }
    }
    askEquation(0);
  });
});


