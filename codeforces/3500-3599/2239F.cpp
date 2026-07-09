// Problem: F - Colorful Works
// Platform: codeforces
// Contest: Contest-2239
// Rating/Difficulty: 3500
// Language: C++23 (GCC 14-64, msys2)
// URL: https://codeforces.com/contest/2239/submission/381829522
// Solved on: 2026-07-09T09:37:12.971Z

// Problem Link: https://codeforces.com/contest/2239/problem/F
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//avneth
using namespace std;
using namespace __gnu_pbds;

// #pragma GCC optimize("O3")
// #pragma GCC target("sse4")
// #pragma GCC optimize("unroll-loops")

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ve vector<int>
#define vc vector<char>
#define PB push_back
#define PPB pop_back
#define mp make_pair
#define vll vector<long long>
#define ll long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define F first
#define S second
#define ld long double
#define vld vector<long double>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define GCD __gcd
#define INT __int128

#define ordered_set tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>

const ll mod=998244354;
const ll MOD=1e9+7;
const ll INF=1e18;
const int inf=1e9;

const int MAXN=2000005;
const int MAXM=200005;
const int MAXK=400005;
const int MAXW=MAXK/64+10;

int L[MAXN];
int R[MAXN];
int cnt[MAXM];
int F[MAXK];
ull dp[MAXW];
int pre0[MAXK+5];
int pre1[MAXK+5];

void solve(){

    int n; cin>>n;
    int m=0; ll A=0; int k=0;
    for(int i=1;i<=n;i++){
        cin>>L[i]>>R[i];
        m=max(m,R[i]);
        if(L[i]>0)
            k++;
    }
    int E=0;
    if(k>=2){
        E=0;
    }
    else if(k==1){

        int id=-1;
        for(int i=1;i<=n;i++)
            if(L[i]>0)
                id=i;
        if((L[id]&1)==(R[id]&1))
            E=1;
        else
            E=0;
    }
    else{
        ll sum=0;
        for(int i=1;i<=n;i++)
            sum+=R[i];

        if(sum&1)
            E=0;
        else
            E=1;
    }
    for(int i=0;i<=m;i++) cnt[i]=0;
for(int i=1;i<=n;i++){
        if(L[i]==0){
            A+=R[i];
        }
        else{
            A+=L[i]-1;
            int len=R[i]-L[i]+1;
            cnt[len]++;
        }
    }
    ll K=2LL*m-A;
    if(K<0){
        cout<<((E+2)%2)<<"\n";
        return;
    }
    if(K>2*m)
        K=2*m;
    for(int i=0;i<=K;i++)
        F[i]=0;

    for(int b=1;b<=m;b++){
        if(cnt[b]==0)
            continue;

        int c=cnt[b];
        for(int j=0;(1LL<<j)<=c;j++){
            if((c>>j)&1){
                ll v=1LL*b*(1LL<<j);
                if(v<=K)
                    F[v]++;
            }
        }
    }
    for(int i=1;i<=K;i++){
        if(F[i]>1){
            if(i*2<=K)
                F[i*2]+=F[i]/2;
            F[i]%=2;
        }
    }

    int lim=K/64;
    for(int i=0;i<=lim+1;i++)
        dp[i]=0;
    dp[0]=1;
    int mx=0;
    int word=0;
        for(int i=1;i<=K;i++){
        if(F[i]!=1)
            continue;
        int w=i/64;
        int b=i%64;
        if(b==0){
            for(int j=word;j>=0;j--){
                if(j+w<=lim)
                    dp[j+w]^=dp[j];
            }
        }

        else{
            int rem=64-b;
            for(int j=word;j>=0;j--){
                if(j+w+1<=lim)
                    dp[j+w+1]^=(dp[j]>>rem);
                if(j+w<=lim)
                    dp[j+w]^=(dp[j]<<b);
            }
        }
        mx=min((int)K,mx+i);
        word=mx/64;
    }
    int lim2=2*m+1;
    for(int i=0;i<=lim2+1;i++){
        pre0[i]=0;
        pre1[i]=0;
    }
    for(int i=0;i<=K;i++){
        int bit=(dp[i/64]>>(i%64))&1;
        if(!bit)
            continue;

        ll deg=1LL*i+A;
        if(deg>2*m)
            continue;

        if(deg&1)
            pre1[deg+1]=1;
        else
            pre0[deg+1]=1;
    }
    for(int i=1;i<=lim2;i++){
        pre0[i]+=pre0[i-1];
        pre1[i]+=pre1[i-1];
    }
        auto query=[&](int l,int r,int p){
        if(l>r || l>2*m)
            return 0;
        if(r>2*m)
            r=2*m;
        l=max(0,l);
        int res=0;
        if(p==0)
            res=pre0[r+1]-pre0[l];
        else
            res=pre1[r+1]-pre1[l];

        return res&1;
    };
    int bad=0;
    for(int i=1;i<=n;i++){
        int cur=0;
        if(L[i]==0){
            int l=R[i];
            int r=2*R[i]-1;
            cur=query(l,r,0);
        }
        else{
            int l=L[i]-1;
            int r=L[i]+R[i]-2;
            int p=(R[i]-L[i]+1)&1;
            cur=query(l,r,p);
        }
        bad=(bad+cur)&1;
    }
    int ans=(E-(bad&1)+2)&1;
    cout<<ans<<"\n";
}

signed main() {
    fastio

    int t; cin>>t;

    while(t--)
        solve();

    return 0;
}