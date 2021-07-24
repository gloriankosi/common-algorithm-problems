/**
 * @file longest-substring-no-repeating.cc
 * @brief
 * Find the longest non repeating substring
 *
 */

#include <iostream>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string);

int main(int argc, char *argv[]) {
  string s = "ohomm";
  cout << lengthOfLongestSubstring(s) << "\n";
  return -1;
}

int lengthOfLongestSubstring(string s) {
  int largestSubstringLen = 0;
  int x = -1;
  vector<int> trackVector(
      128, -1);  // s consists of English letters, digits, symbols and spaces.
  for (int i = 0; i != s.length(); i++) {
    if (trackVector[s[i]] > x) {
      x = trackVector[s[i]];
    }
    trackVector[s[i]] = i;
    largestSubstringLen = max(largestSubstringLen, i - x);
  }
  return largestSubstringLen;
}
