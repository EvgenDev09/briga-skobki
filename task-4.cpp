#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Скобки
const int BR = 3;
const char UNKN = '?';
const string BR1 = "([{", BR2 = ")]}";

// Получить тип открывающейся скобки
int get_brtype1(char c) {
    for (int i = 0; i < BR; i++) {
        if (c == BR1[i])
            return i;
    }
    return -1;
}

// Меньше ли вектор
bool vecmin(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

// Сложить вектора
vector<int> vecplus(vector<int> a, vector<int> b) {
    vector<int> c(a.size() + b.size());
    copy(a.begin(), a.end(), c.begin());
    copy(b.begin(), b.end(), c.begin() + a.size());
    return c;
}

int main() {
    string s;
    cin >> s;

    vector< vector< vector<int> > > a(s.length(), vector< vector<int> >(s.length()));
    for (int i=1; i<=s.length(); i++) {
        for (int j=0; j<=s.length() - i; j++) {
            int l = j, r = j + i - 1;
            if (i == 1) a[l][r].push_back(j); // Один символ
            else {
                vector<int> min_arr;
                a[l][r] = vecplus(a[l][l], a[l + 1][r]);
                for (int k = 2; k <= i - 1; k++) {
                    // Конкатенация двух скобочных выражений
                    min_arr = vecplus(a[l][l + k - 1], a[l + k][r]);
                    if (vecmin(min_arr, a[l][r])) {
                        a[l][r] = min_arr;
                    }
                }
                int t = get_brtype1(s[l]);
                if (s[l] == UNKN || s[r] == UNKN || (t != -1 && s[r] == BR2[t])) {
                    if (vecmin(a[l + 1][r - 1], a[l][r])) {
                        // Без пары скобок по концам
                        a[l][r] = a[l + 1][r - 1];
                    }
                }
            }
        }
    }

    vector<int> ans = a[0][s.length() - 1];
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i : ans) {
        cout << i << ' ';
    }
    cout << endl;
    for (int i = 0, j = 0; i < s.length(); i++) {
        if (j < ans.size() && i == ans[j])
            j++;
        else
            cout << s[i];
    }

    return 0;
}
