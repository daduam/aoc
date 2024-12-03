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

const re = /mul\(([1-9]|[1-9]\d|[1-9]\d{2}),([1-9]|[1-9]\d|[1-9]\d{2})\)/gm;

let sumOfMultiplications = 0;

let m;
while ((m = re.exec(data)) !== null) {
  if (m.index === re.lastIndex) {
    re.lastIndex++;
  }

  const leftOp = Number.parseInt(m[1]);
  const rightOp = Number.parseInt(m[2]);

  sumOfMultiplications += leftOp * rightOp;
}

console.log('Sum of multiplications: %d', sumOfMultiplications);
