#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int n,k,ans[22],used[22];
map<vector<int>,int>mp;

void in(){
    FOR(i,1,k)cout<<ans[i]<<" ";
    cout<<"\n";
}

void sinh(int j){
    FOR(i,ans[j-1]+1,n){
        ans[j]=i;
        if(j==k)in();
        else sinh(j+1);

    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("tohop.inp","r",stdin);
    freopen("tohop.out","w",stdout);
    cin>>n>>k;
    sinh(1);
}
