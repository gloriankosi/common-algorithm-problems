/**
 * @file two-sorted-arr-median.cc
 *
 */
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Solved with help from: https://www.youtube.com/watch?v=LPFhl65R7ww
// NOTE: Not an easy problem, go watch the link posted above to understand what
// is going on Comments with explanations coming soon.

double findMedianSortedArrays(vector<int> &, vector<int> &);

int main(int argc, char *argv[]) {
    // Sampe input
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {2, 4, 5, 6};
    cout << findMedianSortedArrays(nums1, nums2) << "\n";
    return 0;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size())  // swap to keep nums2 larger
    {
        return findMedianSortedArrays(nums2, nums1);
    }

    int n1Size = nums1.size();
    int n2Size = nums2.size();

    double median = 0.0;

    int start = 0;
    int endIndexOfX = n1Size;

    while (start <= endIndexOfX) {
        int positionX = (endIndexOfX + start) / 2;
        int positionY = (n1Size + n2Size + 1) / 2 - positionX;

        auto maxLeftX = (positionX == 0) ? INT_MIN : nums1[positionX - 1];
        auto maxLeftY = (positionY == 0) ? INT_MIN : nums2[positionY - 1];

        auto minRightX = (positionX == n1Size) ? INT_MAX : nums1[positionX];
        auto minRightY = (positionY == n2Size) ? INT_MAX : nums2[positionY];

        if ((maxLeftX <= minRightY) and (maxLeftY <= minRightX)) {
            int totalSizeOfVecs = (n1Size + n2Size);
            if (totalSizeOfVecs % 2 == 1) {
                median = max(maxLeftX, maxLeftY);
                return median;
            } else {
                median = max(maxLeftX, maxLeftY) + min(minRightX, minRightY);
                median = median / 2;
                return median;
            }
        } else if (maxLeftX > minRightY) {
            endIndexOfX = positionX - 1;
        } else {
            start = positionX + 1;
        }
    }

    return median;
}