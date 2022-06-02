
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int a; cin >> a;
    int x[a], y[a];
    for (int q = 0; q < a; q++) {
        cin >> x[q] >> y[q];
    }
    vector<int> ans(a);
    iota(ans.begin(), ans.end(), 0);
    for (int q = 1; q < a; q++) {
        double mn = 1e18;
        int ps = -1;
        for (int w = q; w < a; w++) {
            double dst = hypot(x[ans[q - 1]] - x[ans[w]], y[ans[q - 1]] - y[ans[w]]);
            if (dst < mn) {
                mn = dst;
                ps = w;
            }
        }
        swap(ans[q], ans[ps]);
    }
    for (int i : ans) cout << i + 1 << " ";
}