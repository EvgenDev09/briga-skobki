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

int main() {
    string s;
    cin >> s;

    vector< vector<bool> > a(s.length(), vector<bool>(s.length(), true));
    for (int i=1; i<=s.length(); i++) {
        for (int j=0; j<=s.length() - i; j++) {
            int l = j, r = j + i - 1;
            if (i == 1) a[l][r] = false; // Один символ
            else {
                a[l][r] = false;
                for (int k = 2; k <= i - 1; k++) {
                    // Конкатенация двух скобочных выражений
                    if (a[l][l + k - 1] && a[l + k][r]) {
                        a[l][r] = true;
                        break;
                    }
                }
                int t = get_brtype1(s[l]);
                if (s[l] == UNKN || s[r] == UNKN || (t != -1 && s[r] == BR2[t])) {
                    if (a[l + 1][r - 1]) {
                        // Без пары скобок по концам
                        a[l][r] = true;
                    }
                }
            }
        }
    }

    cout << (a[0][s.length() - 1] ? "YES" : "NO");

    return 0;
}
