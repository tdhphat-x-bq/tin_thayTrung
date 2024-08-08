#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int n,ans[35];
inr sum=0;

void in(int l){

    cout<<n<<"=";
    FOR(i,1,l-1)cout<<ans[i]<<"+";
    cout<<ans[l]<<"\n";
}

void sinh(int j){
    FOR(i,1,n){
        sum+=i;
        if(sum<=n and ans[j-1] <= i){
            ans[j]=i;
            if(sum==n){
                in(j);
            }else sinh(j+1);
        }
        sum-=i;
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("phantich.inp","r",stdin);
    //freopen("phantich.out","w",stdout);
    cin>>n;
    sinh(1);
}
