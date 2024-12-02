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
  for (let skip = 0; skip < report.length; skip++) {
    if (skip === 0) {
      isIncreasing = report[1] < report[2];
    } else if (skip === 1) {
      isIncreasing = report[0] < report[2];
    } else {
      isIncreasing = report[0] < report[1];
    }

    let isSafe = true;

    let i = 0;
    while (i < report.length) {
      if (i === skip) {
        i++;
        continue;
      }

      let nextIdx = i + 1;
      if (skip === i + 1) {
        nextIdx = i + 2;
      }

      if (nextIdx >= report.length) {
        break;
      }

      const difference = report[nextIdx] - report[i];
      if (isIncreasing) {
        isSafe = isSafe && difference >= 1 && difference <= 3;
      } else {
        isSafe = isSafe && difference >= -3 && difference <= -1;
      }

      i++;
    }

    if (isSafe) {
      safeReportCount++;
      break;
    }
  }
});

console.log(
  'Number of safe reports after problem dampening: %d',
  safeReportCount
);
