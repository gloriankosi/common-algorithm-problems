#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<int>&, int);
int main(int argc, char* argv[]) {
  vector<int> nums = {5, 10, 15, 22, 30, 45};
  rotate(nums, 1);
  for (auto& a : nums) {
    cout << a << "\n";
  }
  return 0;
}
void rotate(vector<int>& nums, int k) {
  k = k % nums.size();
  int count = 0;
  for (int i = 0; count < (int)nums.size(); i++) {
    int current = i;
    int prev = nums[i];
    do {
      int next = (current + k) % nums.size();
      int temp = nums[next];
      nums[next] = prev;
      prev = temp;
      current = next;
      count++;
    } while (i != current);
  }
}