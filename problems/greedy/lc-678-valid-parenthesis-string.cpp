/*
platform: lc
id: 678
name: valid parenthesis string
pattern: greedy
tags: greedy,stack,string
complexity:
- time = O(n)
- space = O(1)
notes:

stack solution is valid parentheses + wildcard consideration

greedy solution is balancing beam:
if the max possible opens (wildcards & true opens) goes less than zero:
then we have too many closes

*/

#include <map>
#include <set>
#include <stack>
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
  bool checkValidStringStack(string s) {
    stack<int> open, wild;

    for (int i{}; i < s.size(); ++i) {
      if (s[i] == '(')
        open.push(i);
      else if (s[i] == '*')
        wild.push(i);
      else {
        if (!open.empty())
          open.pop();
        else if (!wild.empty())
          wild.pop();
        else
          return false;
      }
    }

    while (!open.empty() && !wild.empty()) {
      if (open.top() > wild.top())
        return false;
      open.pop();
      wild.pop();
    }
    return open.empty();
  }

  bool checkValidStringGreedy(string s) {
    int mn{}, mx{};

    for (char c : s) {
      if (c == '(') {
        ++mn;
        ++mx;
      } else if (c == ')') {
        --mn;
        --mx;
      } else {
        --mn;
        ++mx;
      }

      if (mx < 0)
        return false;
      if (mn < 0)
        mn = 0;
    }

    return mn == 0;
  }
};
