// Problem: The FizzBuzz Program | Practice
// Platform: geeksforgeeks
// Language: unknown
// Verdict: Accepted
// URL: https://www.geeksforgeeks.org/problems/the-fizzbuzz-program/1?page=1&category=CPP&sortBy=submissions
// Solved on: 2026-07-25T07:55:09.944Z

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

   if(n%3==0 && n%5==0) cout << "FizzBuzz" <<endl;
   else if (n%5==0) cout << "Buzz" <<endl;
   else if (n%3==0) cout << "Fizz" <<endl;
   else cout << n <<endl;
    

    return 0;
}