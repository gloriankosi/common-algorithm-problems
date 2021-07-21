#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(vector<int> &);

int main(int argc, char *argv[]) {
  vector<int> v = {1, 2, 3, 5, 6, 7};
  cout << findMissingNumber(v) << "\n";
  return 0;
};

int findMissingNumber(vector<int> &v) {
  // 1 element is missing, use this to calculate the expected sum
  int vSize = v.size() + 1;
  int actualSum = 0;
  int expectedSum = 0;

  int minValue;
  int maxValue;

  for (auto &i : v) {
    (minValue > i) ? minValue = i : minValue;
    (maxValue < i) ? maxValue = i : maxValue;
    actualSum += i;
  }

  // Arithmetic sum formula
  expectedSum = vSize * (minValue + maxValue);
  expectedSum = expectedSum / 2;

  return abs(expectedSum - actualSum);
};