#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int n,k,ans[12],used[12];

void in(){
    FOR(i,1,k)cout<<ans[i]<<" ";
    cout<<"\n";
}

void sinh(int j){
    FOR(i,1,n){
        if(used[i]==0){
            used[i]=1;
            ans[j]=i;
            if(j==k)in();
            else sinh(j+1);
            used[i]=0;
        }

    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("chinhhop.inp","r",stdin);
    freopen("chinhhop.out","w",stdout);
    cin>>n>>k;
    sinh(1);
}
