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

const reports = [];

data.split(/\r?\n/).forEach((line) => {
  const report = line.split(/\s+/).map((numStr) => Number.parseInt(numStr));
  reports.push(report);
});

let safeReportCount = 0;

reports.forEach((report) => {
  let isSafe = true;
  let isIncreasing = report.length > 1 && report[0] < report[1];

  for (let i = 1; i < report.length; i++) {
    const difference = report[i] - report[i - 1];
    if (isIncreasing) {
      isSafe = isSafe && difference >= 1 && difference <= 3;
    } else {
      isSafe = isSafe && difference >= -3 && difference <= -1;
    }
  }

  if (isSafe) {
    safeReportCount++;
  }
});

console.log('Number of safe reports: %d', safeReportCount);
