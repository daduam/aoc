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
    if (puzzles[i][j] !== 'X') {
      continue;
    }

    if (
      j + 3 < puzzles[i].length &&
      puzzles[i][j + 1] === 'M' &&
      puzzles[i][j + 2] === 'A' &&
      puzzles[i][j + 3] === 'S'
    ) {
      xmasCount++;
    }

    if (
      j - 3 >= 0 &&
      puzzles[i][j - 1] === 'M' &&
      puzzles[i][j - 2] === 'A' &&
      puzzles[i][j - 3] === 'S'
    ) {
      xmasCount++;
    }

    if (
      i + 3 < puzzles.length &&
      puzzles[i + 1][j] === 'M' &&
      puzzles[i + 2][j] === 'A' &&
      puzzles[i + 3][j] === 'S'
    ) {
      xmasCount++;
    }

    if (
      i - 3 >= 0 &&
      puzzles[i - 1][j] === 'M' &&
      puzzles[i - 2][j] === 'A' &&
      puzzles[i - 3][j] === 'S'
    ) {
      xmasCount++;
    }

    if (
      i + 3 < puzzles.length &&
      j + 3 < puzzles[i].length &&
      puzzles[i + 1][j + 1] === 'M' &&
      puzzles[i + 2][j + 2] === 'A' &&
      puzzles[i + 3][j + 3] === 'S'
    ) {
      xmasCount++;
    }

    if (
      i + 3 < puzzles.length &&
      j - 3 >= 0 &&
      puzzles[i + 1][j - 1] === 'M' &&
      puzzles[i + 2][j - 2] === 'A' &&
      puzzles[i + 3][j - 3] === 'S'
    ) {
      xmasCount++;
    }

    if (
      i - 3 >= 0 &&
      j + 3 < puzzles[i].length &&
      puzzles[i - 1][j + 1] === 'M' &&
      puzzles[i - 2][j + 2] === 'A' &&
      puzzles[i - 3][j + 3] === 'S'
    ) {
      xmasCount++;
    }

    if (
      i - 3 >= 0 &&
      j - 3 >= 0 &&
      puzzles[i - 1][j - 1] === 'M' &&
      puzzles[i - 2][j - 2] === 'A' &&
      puzzles[i - 3][j - 3] === 'S'
    ) {
      xmasCount++;
    }
  }
}

console.log('XMAS appears %d times', xmasCount);
