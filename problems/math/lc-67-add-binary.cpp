/*
platform: lc
id: 67
name: add binary
pattern: math
tags: binary,math,simulation,bit-manipulation,string,bitstring
complexity:
- time = O(n)
- space = O(n)
notes:
binary addition simulation... just do it lol
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define rep(i, n) for (int i{0}; i < (n); ++i)
#define rrep(i, n) for (int i{(n) - 1}; i >= 0; --i)
#define FOR(i, a, b) for (int i{(a)}; i < (b); ++i)

using ll = long long;
using ull = unsigned long long;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;
using VB = vector<bool>;
using VC = vector<char>;
using VI = vector<int>;
using Vll = vector<ll>;
using VS = vector<string>;
using VPI = vector<PI>;
using VTI = vector<TI>;
using VVC = vector<VC>;
using VVI = vector<VI>;
using VVll = vector<Vll>;
using VVS = vector<VS>;
using VVPI = vector<VPI>;
using SI = set<int>;
using USI = unordered_set<int>;
using MII = map<int, int>;
using UMII = unordered_map<int, int>;

template <typename T> using vec = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;

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
  string addBinary(string a, string b) {
    string res{};
    int i = a.size() - 1, j = b.size() - 1, carry{0};

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0 && a[i--] == '1')
        ++carry;
      if (j >= 0 && b[j--] == '1')
        ++carry;

      switch (carry) {
      case 2:
        --carry;
      case 0:
        res.push_back('0');
        break;
      case 3:
        --carry;
      case 1:
        --carry;
        res.push_back('1');
      }
    }

    return string(res.rbegin(), res.rend());
  }
};
