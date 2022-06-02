#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ll n, w;
    cin >> n >> w;
    vector <pair<ll, ll>> a;
    for (int i = 0; i < n; i++) {
        int pi, wi;
        cin >> wi >> pi;
        a.push_back({wi, pi});
    }
    vector <int> ans;
    ll p = 0;
    for (int i = 0; i < (1 << n); i++) {
        ll nw = 0, np = 0;
        vector <int> nans;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                nw += a[j].first;
                np += a[j].second;
                nans.push_back(j + 1);
            }
        }
        if (nw > w) continue;
        if (np == p && ans.size() == nans.size()) {
            int it = 0;
            while (it < ans.size() && ans[it] == nans[it]) {
                it++;
            }
            if (it < ans.size() && ans[it] > nans[it]) {
                p = np;
                ans = nans;
            }
        }
        if (np > p || (np == p && ans.size() > nans.size())) {
            p = np;
            ans = nans;
        }
    }
    cout << ans.size() << ' ' << p << '\n';
    for (auto e : ans) {
        cout << e << ' ';
    }
    cout << '\n';
}
