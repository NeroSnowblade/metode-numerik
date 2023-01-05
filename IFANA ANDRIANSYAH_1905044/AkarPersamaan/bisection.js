// Nama     : Ifana Andriansyah
// NIM      : 1905044
// Kelas    : PILKOM 3-A
// Program  : Akar Persamaan Metode Bisection

const readline = require('readline');

function findRoot() {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });

  rl.question("Enter the left bound of the interval: ", (a) => {
    rl.question("Enter the right bound of the interval: ", (b) => {
      rl.question("Enter the tolerance: ", (tol) => {
        a = parseFloat(a);
        b = parseFloat(b);
        tol = parseFloat(tol);

        function f(x) {
          return x * x - 4 * x + 4;
        }

        var midpoint = (a + b) / 2;
        while (Math.abs(f(midpoint)) > tol) {
          if (f(a) * f(midpoint) < 0) {
            b = midpoint;
          } else {
            a = midpoint;
          }
          midpoint = (a + b) / 2;
        }
        console.log("Root: " + midpoint);
        rl.close();
      });
    });
  });
}

findRoot();

