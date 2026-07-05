// Problem: C - Registration System
// Platform: codeforces
// Contest: Contest-4
// Rating/Difficulty: 1300
// Language: C++23 (GCC 14-64, msys2)
// URL: https://codeforces.com/contest/4/submission/381322650
// Solved on: 2026-07-05T11:02:58.871Z

#include<bits/stdc++.h>
using namespace std;
int main()
{   //avneth
    int n; 
    cin>>n;
    unordered_map<string, int>db;
    while(n--)
    {
        string s;
        cin>>s;
        vector<string>v;
        if(db.count(s)==0){
            cout<<"OK"<<endl;
            db[s]=1;
        }else{
            cout<<s<<db[s]<<endl;
            db[s+ to_string(db[s])]=1;
            db[s]++;
        }
 
    }
    return 0;
}