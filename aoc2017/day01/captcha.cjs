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

function getCaptchaSumForStep(step = 1) {
  let captcha = 0;

  for (let i = 0; i < data.length; i++) {
    const currentDigit = data[i];
    const nextDigit = data[(i + step) % data.length];

    if (currentDigit === nextDigit) {
      captcha += Number.parseInt(currentDigit);
    }
  }

  return captcha;
}

console.log('Solution to the captcha: %d', getCaptchaSumForStep());

console.log(
  'Solution to the captcha with halfway step: %d',
  getCaptchaSumForStep(data.length / 2)
);
