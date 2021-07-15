#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string);

int main(int argc, char *argv[]) {}

int lengthOfLongestSubstring(string s)
{
    int currentLen = 0;
    int largestSubstringLen = 0;
    unordered_map<char, bool> seenChars;
    while (!s.empty())
    {
        auto it = seenChars.find(s.back());
        if (it == seenChars.end())
        {
            currentLen++;
            seenChars.insert({s.back(), true});
            s.pop_back();
        }
        else
        {
            if (currentLen > largestSubstringLen)
            {
                largestSubstringLen = currentLen;
            }
            currentLen = 0;
            seenChars.clear();
            //may or may not need a s.pop_back() here
        }
    }
}
