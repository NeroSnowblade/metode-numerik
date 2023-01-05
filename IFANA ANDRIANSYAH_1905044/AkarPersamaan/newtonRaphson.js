// Nama     : Ifana Andriansyah
// NIM      : 1905044
// Kelas    : PILKOM 3-A
// Program  : Akar Persamaan Metode Newton Raphson

const readline = require('readline');

function findRoot() {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });

  rl.question("Enter the initial guess: ", (x0) => {
    rl.question("Enter the tolerance: ", (tol) => {
      x0 = parseFloat(x0);
      tol = parseFloat(tol);

      function f(x) {
        return x * x - 4 * x + 4;
      }

      function df(x) {
        return 2 * x - 4;
      }

      var x1 = x0 - f(x0) / df(x0);
      while (Math.abs(x1 - x0) > tol) {
        x0 = x1;
        x1 = x0 - f(x0) / df(x0);
      }
      console.log("Root: " + x1);
      rl.close();
    });
  });
}

findRoot();
