/*
platform: lc
id: 1200
name: minimum absolute difference
pattern: arrays/sorting
tags: array,sorting,greedy
complexity:
- time = O(nlogn)
- space = O(1)
notes:
sort and use two ptr in place to check difference btwn i and i+1
*/

#include <algorithm>
#include <climits>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;
using VB = vector<bool>;
using VC = vector<char>;
using VI = vector<int>;
using VS = vector<string>;
using VPI = vector<PI>;
using VTI = vector<TI>;
using VVC = vector<VC>;
using VVI = vector<VI>;
using VVS = vector<VS>;
using VVPI = vector<VPI>;
using SI = set<int>;
using USI = unordered_set<int>;
using MII = map<int, int>;
using UMII = unordered_map<int, int>;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    sort(arr.begin(), arr.end());

    int md{INT_MAX};
    vector<vector<int>> r;

    for (int i{}; i < arr.size() - 1; ++i)
      if (arr[i + 1] - arr[i] < md)
        md = arr[i + 1] - arr[i];
    for (int i{}; i < arr.size() - 1; ++i)
      if (arr[i + 1] - arr[i] == md)
        r.push_back({arr[i], arr[i + 1]});

    return r;
  }
};
