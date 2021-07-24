/**
 * @file remove-duplicates-in-place.cc
 * @brief
 *
 */
#include <iostream>
#include <vector>
using namespace std;
void removeDuplicates(vector<int> &);

int main(int argc, char *argv[]) {
  vector<int> nums = {1, 1, 2, 2, 3, 4, 5, 7, 7, 7};
  removeDuplicates(nums);
  for (auto &a : nums) {
    cout << a << "\n";
  }
  return 0;
}

// O(n^2) solution
void removeDuplicates(vector<int> &nums) {
  for (auto i = 0; i < nums.size(); i++) {
    if ((i + 1) <= nums.size()) {
      if (nums[i] == nums[i + 1]) {
        nums.erase(nums.begin() + i);
      }
    }
  }
  return;
}