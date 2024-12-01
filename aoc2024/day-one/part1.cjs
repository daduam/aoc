const fs = require('node:fs');
const path = require('node:path');

let data = '';

try {
  const inputFilePath = path.resolve(__dirname, 'in1.txt');
  data = fs.readFileSync(inputFilePath, 'utf8');
} catch (err) {
  console.error(err);
  process.exit(1);
}

const lista = [];
const listb = [];

data.split(/\r?\n/).forEach((line) => {
  const [a, b] = line.split(/\s+/).map((numStr) => Number.parseInt(numStr));
  lista.push(a);
  listb.push(b);
});

lista.sort((a, b) => a - b);
listb.sort((a, b) => a - b);

let totalDifference = 0;

for (let i = 0; i < Math.min(lista.length, listb.length); i++) {
  totalDifference += Math.abs(lista[i] - listb[i]);
}

console.log('Total difference: %d', totalDifference);
