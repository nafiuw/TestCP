// Problem: B- Chat Order
// Platform: codeforces
// Contest: 800
// Rating/Difficulty: 800
// Language: C++17
// URL: 
// Solved on: 2026-07-04T11:55:23.859Z



    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        int n;
        cin>>n;
        map<string,int>l;
        vector<string>nm(n);
       for(int i=0; i<n; i++){
        cin>>nm[i];
        l[nm[i]]=i;
       }
       vector<pair<int,string>>ord;
       for(const auto& p : l){
        ord.push_back({p.second,p.first});
       }
       sort(ord.rbegin(),ord.rend());
       for(auto& p : ord){
        cout<<p.second<<"\n";
       }
        
        return 0;
    }