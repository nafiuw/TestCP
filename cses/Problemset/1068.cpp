// Problem: Task
// Platform: cses
// Language: unknown
// Verdict: ACCEPTED
// URL: https://cses.fi/problemset/result/18087314/
// Solved on: 2026-07-25T10:50:34.355Z

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    while (true) {
        cout << n;
        if (n == 1) break;
        cout << " ";
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
    }

    return 0;
}