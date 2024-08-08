#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int n,m;
int v[50],w[50],dp[50];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("caitui.inp","r",stdin);
    freopen("caitui.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n)cin>>w[i]>>v[i];
    FOR(i,1,n){
        FOD(j,m,w[i]){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[m];
}
