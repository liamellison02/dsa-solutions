/*
platform: lc
id: 208
name: implement trie
pattern: strings/trie
tags: tries,prefix-trees,design,implementation
notes:
trie/prefix tree data structure implementation
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
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

constexpr int MOD = 1e9 + 7;

#define rep(i, n) for (int i{0}; i < (n); ++i)
#define rrep(i, n) for (int i{(n) - 1}; i >= 0; --i)
#define FOR(i, a, b) for (int i{(a)}; i < (b); ++i)

using str = string;

using ll = long long;
using ull = unsigned long long;
using ui8 = uint8_t;
using ui16 = uint16_t;
using ui32 = uint32_t;
using ui64 = uint64_t;

using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ti = tuple<int, int, int>;
using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vpi = vector<pi>;
using vti = vector<ti>;
using vvc = vector<vc>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvs = vector<vs>;
using vvpi = vector<vpi>;

using si = set<int>;
using usi = unordered_set<int>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;

template <typename T> using vec = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template <typename K, typename V> using umap = unordered_map<K, V>;

struct TrieNode {
  TrieNode *next[26];
  bool word;
  TrieNode() : word(false) {
    std::fill(std::begin(next), std::end(next), nullptr);
  }
};

class Trie {
  TrieNode *root;

public:
  Trie() : root(new TrieNode()) {}

  void insert(const string &w) {
    TrieNode *cur = root;
    for (char ch : w) {
      int i = ch - 'a';
      if (!cur->next[i])
        cur->next[i] = new TrieNode();
      cur = cur->next[i];
    }
    cur->word = true;
  }

  bool search(const string &w) {
    TrieNode *cur = root;
    for (char ch : w) {
      int i = ch - 'a';
      if (!cur->next[i])
        return false;
      cur = cur->next[i];
    }
    return cur->word;
  }

  bool startsWith(const string &p) {
    TrieNode *cur = root;
    for (char ch : p) {
      int i = ch - 'a';
      if (!cur->next[i])
        return false;
      cur = cur->next[i];
    }
    return true;
  }
};
