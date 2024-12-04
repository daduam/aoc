const fs = require('node:fs');
const path = require('node:path');

let data = '';

try {
  const inputFilePath = path.resolve(__dirname, 'in.txt');
  data = fs.readFileSync(inputFilePath, 'utf8');
} catch (err) {
  console.error(err);
  process.exit(1);
}

const puzzles = data.split(/\s/);

let xmasCount = 0;

for (let i = 0; i < puzzles.length; i++) {
  for (let j = 0; j < puzzles[0].length; j++) {
    if (puzzles[i][j] !== 'A') {
      continue;
    }

    const rc = puzzles.length;
    const cc = puzzles[0].length;

    const isMidDiag = i - 1 >= 0 && i + 1 < rc && j - 1 >= 0 && j + 1 < cc;
    if (!isMidDiag) {
      continue;
    }

    const isLeadDiagMas =
      (puzzles[i - 1][j - 1] === 'M' && puzzles[i + 1][j + 1] === 'S') ||
      (puzzles[i - 1][j - 1] === 'S' && puzzles[i + 1][j + 1] === 'M');

    const isOtherDiagMas =
      (puzzles[i - 1][j + 1] === 'M' && puzzles[i + 1][j - 1] === 'S') ||
      (puzzles[i - 1][j + 1] === 'S' && puzzles[i + 1][j - 1] === 'M');

    if (isLeadDiagMas && isOtherDiagMas) {
      xmasCount++;
    }
  }
}

console.log('X-MASes appear %d times', xmasCount);
