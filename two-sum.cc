#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int);

int main(int argc, char *argv[]) {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(0);

    auto z = twoSum(nums, 0);
    for (auto &i : z) {
        cout << i << "\n";
    }

    return -1;
}

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> umap;
    vector<int> indices;

    for (int i = 0; i <= nums.size(); i++) {
        if ((nums[i] < target) &&
                (target != 0))  // For cases where target is not 0, this saves memory
        {
            umap[nums[i]] = i;
        } else {
            umap[nums[i]] = i;
        }
    }

    for (auto i : umap) {
        cout << i.first << " " << i.second << "\n";
    }

    for (int i = 0; i <= nums.size() - 1; i++) {
        if (umap.find(target - nums[i]) != umap.end()) {
            if (umap.at(target - nums[i]) != i) {
                indices.push_back(i);
                indices.push_back(umap.at(target - nums[i]));
                return indices;
            }
        }
    }

    return indices;
}