// Problem: Odd or Even | Practice
// Platform: geeksforgeeks
// Language: unknown
// Verdict: Accepted
// URL: https://www.geeksforgeeks.org/problems/odd-or-even3618/1?page=1&difficulty=Basic&sortBy=submissions
// Solved on: 2026-07-25T09:41:43.625Z

class GfG {

    public static boolean isEven(int n)
    {
        // finding remainder of n
        int rem = n % 2;
        if(rem == 0){
            return true;
        }
        else{
            return false;
        }
    }
    
    // Driver Code
    public static void main(String[] args)
    {
        int n = 15;
        if (isEven(n) == true)
            System.out.print("true");
        else
            System.out.print("false");
    }
}