/*
platform: lc
id: 25
name: reverse nodes in k group
pattern: linked_list
tags: linked-list,recurrsion,reversal
complexity:
- time = O(n)
- space = O(n/k) recursion depth = one frame per full group
notes:
recursive algo
walk k ahead first
- only reverse if full k-group actually exists
- recurse on rest b4 reversing so this group's tail points at the prev-reversed suffix
- then splice each of the k nodes onto front of curr (one at a time -> in-place reverse)
leftover tail shorter than k is left untouched (loop stops before hitting k)
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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    // curr scouts ahead from head to check the group; group counts how far it got
    ListNode *curr = head;
    int group = 0;

    // walk up to k nodes forward, stopping early if the list runs out
    while (curr != nullptr && group < k) {
      curr = curr->next; // advance the scout one node
      group++;         // tally another node confirmed in this group
    }

    // group == k means a full block of k nodes exists here -> reverse it
    // (if it's < k, we fall through and return head untouched: the short tail stays as-is)
    if (group == k) {
      // curr currently points at the (k+1)-th node = head of the remaining list.
      // recurrse FIRST so curr becomes the new head of the already-reversed suffix,
      // which is exactly what this group's tail must connect to.
      curr = reverseKGroup(curr, k);

      // splice this group's k nodes one-by-one onto the front of curr,
      // flipping their links so the block ends up reversed and attached to the suffix
      while (group-- > 0) {
        ListNode *tmp = head->next; // remember the next node before we overwrite the link
        head->next = curr;           // point current node back at the growing reversed list
        curr = head;                 // current node is now the front of the reversed list
        head = tmp;                 // advance head to the node we saved
      }

      // after the loop curr is the new head of this fully-reversed group
      head = curr;
    }

    // return the head of the reversed (or untouched) segment for the caller to stitch onto
    return head;
  }
};
