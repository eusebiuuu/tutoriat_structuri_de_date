#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;

struct Volume {
    string category;
    int count;
    Volume() : category(""), count(-1) {} 
    Volume(string c, int x) {
        this->category = c;
        this->count = x;
    }
};

unordered_map<string, Volume> volume_info;
unordered_map<string, int> books;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            string s, curr_categ;
            int cnt;
            cin >> s >> curr_categ >> cnt;
            if (volume_info.find(s) == volume_info.end()) {
                Volume curr_volume(curr_categ, cnt);
                volume_info[s] = curr_volume;
                books[volume_info[s].category] = cnt;
            } else if (volume_info[s].category == curr_categ) {
                volume_info[s].count += cnt;
                books[volume_info[s].category] += cnt;
            } else {
                cout << "INVALID\n";
            }
        } else if (t == 2) {
            string s;
            int cnt;
            cin >> s >> cnt;
            if (volume_info.find(s) != volume_info.end()) {
                volume_info[s].count -= cnt;
                books[volume_info[s].category] -= cnt;
                if (volume_info[s].count <= 0) {
                    volume_info.erase(s);
                    books.erase(volume_info[s].category);
                }
            }
        } else if (t == 3) {
            string s;
            if (volume_info.find(s) == volume_info.end()) {
                cout << "NU\n";
            } else {
                cout << volume_info[s].category << '\n';
            }
        } else {
            string curr_categ;
            cout << books[curr_categ] << '\n';
        }
    }
    return 0;
}