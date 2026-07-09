// Problem: Palindrome Number
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/palindrome-number/
// Solved on: 2026-07-09T07:37:59.030Z

class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        }

        int halfRev = 0;

        while(halfRev < x){

            halfRev = halfRev * 10 + (x % 10);
            x /= 10;
        }

        return halfRev == x || halfRev / 10 == x;
    }
};