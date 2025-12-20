#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main() {
    vvi grid = {{1,1,1},{1,1,1},{1,1,1}};
    int x;
    for (int m=0;m<3;m++) {
        for (int n=0;n<3;n++) {
            cin >> x;
            for (int i=0;i<x;i++) {
                grid[m][n] ^= 1;
                if (m>0) grid[m-1][n] ^= 1;
                if (m<2) grid[m+1][n] ^= 1;
                if (n>0) grid[m][n-1] ^= 1;
                if (n<2) grid[m][n+1] ^= 1;
            }
        }
    }
    for (vi r : grid) {
        for (int i : r) cout << i;
        cout << '\n';
    }
    return 0;
}
