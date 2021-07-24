/**
 *
 * @file peak-element.cc
 * @brief
 *
 */
#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int> &, int, int);

int main(int argc, char *argv[]) {
  vector<int> A;
  for (char **i = argv; i != argv + argc; i++) {
    try {
      int val = stoi(*i);
      A.emplace_back(val);
    } catch (invalid_argument) {
      continue;
    }
  }
  cout << findPeak(A, 0, A.size() - 1) << "\n";
  return 0;
}

int findPeak(vector<int> &A, int left, int right) {
  if (left == right) return left;
  int mid = (left + right) / 2;
  if (A[mid] > A[mid + 1]) return findPeak(A, left, mid);
  return findPeak(A, mid + 1, right);
}