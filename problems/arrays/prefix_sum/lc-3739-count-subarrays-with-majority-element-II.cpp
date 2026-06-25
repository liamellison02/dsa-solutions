/*
platform: lc
id: 3739
name: count subarrays with majority element II
difficulty: hard
url: https://leetcode.com/problems/count-subarrays-with-majority-element-ii/
pattern: arrays/prefix_sum
tags: prefix-sum,hashing,counting,array
complexity:
- time = O(n)
- space = O(n)
notes: 
map nums to +1/-1:
+1 -> arr[i] == target
-1 -> arr[i] != target

goal: find all subarrs where range is positive
subarray is valid iff its prefix sum is positive (prefix[r] > prefix[l]);
maintain intervals = # valid left endpoints seen so far
increment intervals by count of left endpoints from curr equilibrium val (when balance rises)
decrement when it falls by cnt of new equilibrium val (cant be 50-50, i.e. equilibrium val == 0) 

sum[i] = equilibrium val of i (prefix sum)

we want to find all (l, r) where:
- sum[r] - sum[l] > 0
OR
- sum[r] > sum[l]

cnt[x] = cnt of equilibrium val x in arr[0...curr_idx]

valid intervals is bounded by curr equilibrium val
when equilibrium val increases -> add cnt[new val] to curr num of valid intervals
at end of each step, add the num of valid intervals to res

constraints on sum arr:
-n <= sum[i] <= n
len(sum) = n

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

#define rep(i, n) for (int i{0}; i < (n); ++i)

using ll = long long;
using vi = vector<int>;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        rep(i, n) nums[i] = (nums[i] == target) ? 1 : -1;

        int intervals{0}, curr{0};
        ll res{0};
        vi cnt(n*2 + 1, 0);
        cnt[n] = 1;

        rep(i, n) {
            // cnt idx = val + n
            if (nums[i] == 1) {
                intervals += cnt[curr+n];
                ++curr;
            }
            else {
                --curr;
                intervals -= cnt[curr+n];
            }
            ++cnt[curr+n];
            res += intervals;
        }

        return res;
    }
};
