// Problem: Basic Data Types
// Platform: hackerrank
// Language: cpp
// URL: https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem?isFullScreen=true
// Solved on: 2026-07-11T11:20:25.627Z

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    long long b;
    char c;
    float d;
    double e;

    cin >> a >> b >> c >> d >> e;

    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    cout << fixed << setprecision(3) << d << "\n";
    cout << fixed << setprecision(9) << e << "\n";

    return 0;
}
