const fs = require('node:fs');
const path = require('node:path');

let data = '';

try {
  const inputFilePath = path.resolve(__dirname, 'in2.txt');
  data = fs.readFileSync(inputFilePath, 'utf8');
} catch (err) {
  console.error(err);
  process.exit(1);
}

const lista = [];
const freqb = {};

data.split(/\r?\n/).forEach((line) => {
  const [a, b] = line.split(/\s+/).map((numStr) => Number.parseInt(numStr));
  lista.push(a);
  if (!freqb[b]) {
    freqb[b] = 0;
  }
  freqb[b]++;
});

let similarityScore = 0;

lista.forEach((num) => {
  if (freqb[num] !== undefined) {
    similarityScore += num * freqb[num];
  }
});

console.log('Similarity score: %d', similarityScore);
