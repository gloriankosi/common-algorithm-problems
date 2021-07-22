/**
 *
 * @file list-transform.cc
 * @author Glorian Kosi
 * @brief
 * Given an integer array, keep the order while reassinging minimizes values
 * Example:
 * vec = {1 , 5 , 6 , 7, 1}
 * Should turn into:
 * {1 , 2 , 3 , 4 , 1}
 *
 */
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> reassignPriorities(vector<int>);

int main(int argc, char* argv[]) {
  vector<int> priorities = {1, 3, 4, 1, 9};
  auto v = reassignPriorities(priorities);
  for (auto& a : v) {
    cout << a << "\n";
  }
  return 0;
}

vector<int> reassignPriorities(vector<int> priorities) {
  unordered_map<int, int> priorityMap;
  set<int> prioritySet;  // gets rid of duplicates and orders the vector
  for (auto& a : priorities) {
    prioritySet.insert(a);
    priorityMap[a] = 0;
  }

  auto priorityMapSize =
      priorityMap
          .size();  // starting size, this is also the new value of the max int

  while (!prioritySet.empty()) {
    auto max = (prioritySet.end());  // get max element
    --max;                           // end() - 1
    priorityMap[*(max)] =
        priorityMapSize;  // add new value to the map with the original as key
    priorityMapSize = priorityMapSize - 1;  // decrement size
    auto i = prioritySet.end();
    --i;  // end() -1
    prioritySet.erase(
        i);  // delete last element in set, i.e, largest (automatically ordered)
  }

  for (auto& a : priorities) {
    a = priorityMap[a];  // assign new values to original unsorted vector
  }

  return priorities;
}