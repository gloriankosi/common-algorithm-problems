#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> reassignPriorities(vector<int>);

int main(int argc, char* argv[]) {
    vector<int> priorities = {5, 3, 4, 1, 9};
    auto v = reassignPriorities(priorities);
    for (auto& a : v) {
        cout << a << "\n";
    }
    return 0;
}

vector<int> reassignPriorities(vector<int> priorities) {
    unordered_map<int, int> priorityMap;
    set<int> prioritySet;
    auto prioritiesCopy = priorities;
    sort(prioritiesCopy.begin(), prioritiesCopy.end());
    for (auto& a : prioritiesCopy) {
        prioritySet.insert(a);
        priorityMap[a] = 0;
    }

    auto priorityMapSize = priorityMap.size();

    while (!prioritySet.empty()) {
        auto max = (prioritySet.end());
        --max;
        priorityMap[*(max)] = priorityMapSize;
        priorityMapSize = priorityMapSize - 1;
        auto i = prioritySet.end();
        --i;
        prioritySet.erase(i);
    }
    for (auto& a : priorities) {
        a = priorityMap[a];
    }
    return priorities;
}