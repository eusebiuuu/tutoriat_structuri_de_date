#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    set<int> planted_trees;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            planted_trees.insert(x);
        } else if (t == 2) {
            int x;
            cin >> x;
            if (planted_trees.find(x) == planted_trees.end()) {
                cout << "NU\n";
            } else {
                cout << "DA\n";
            }
        } else {
            auto it = planted_trees.begin();
            while (it != planted_trees.end()) {
                cout << *it << ' ';
                it++;
            }
            cout << '\n';
        }
    }
    return 0;
}
