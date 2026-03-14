#pragma once

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// usage: dbg(x), dbg(x, y, z), dbg(vec), dbg(map)
// prints variable name + value to stderr so it doesn't pollute stdout
// compile with -DLOCAL to enable; no-ops otherwise

#ifdef LOCAL

// --- base printers ---

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  for (int i = 0; i < (int)v.size(); ++i)
    os << (i ? ", " : "") << v[i];
  return os << "]";
}

template <typename T> ostream &operator<<(ostream &os, const set<T> &s) {
  os << "{";
  bool first = true;
  for (auto &x : s) {
    if (!first)
      os << ", ";
    os << x;
    first = false;
  }
  return os << "}";
}

template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &s) {
  os << "{";
  bool first = true;
  for (auto &x : s) {
    if (!first)
      os << ", ";
    os << x;
    first = false;
  }
  return os << "}";
}

template <typename K, typename V>
ostream &operator<<(ostream &os, const map<K, V> &m) {
  os << "{";
  bool first = true;
  for (auto &[k, v] : m) {
    if (!first)
      os << ", ";
    os << k << ": " << v;
    first = false;
  }
  return os << "}";
}

template <typename K, typename V>
ostream &operator<<(ostream &os, const unordered_map<K, V> &m) {
  os << "{";
  bool first = true;
  for (auto &[k, v] : m) {
    if (!first)
      os << ", ";
    os << k << ": " << v;
    first = false;
  }
  return os << "}";
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &grid) {
  os << "[\n";
  for (auto &row : grid)
    os << "  " << row << "\n";
  return os << "]";
}

// --- dbg macro ---

void _dbg_out() { cerr << endl; }

template <typename Head, typename... Tail>
void _dbg_out(Head H, Tail... T) {
  cerr << " " << H;
  if constexpr (sizeof...(T) > 0)
    cerr << ",";
  _dbg_out(T...);
}

#define dbg(...)                                                                \
  cerr << "[" << __FILE__ << ":" << __LINE__ << "] (" << #__VA_ARGS__          \
       << ") =", _dbg_out(__VA_ARGS__)

#else

#define dbg(...) ((void)0)

#endif
