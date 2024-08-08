#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int n;
int a[13][13],used[13];
inr ans=-inf,tmp;

void game(int i){
    FOR(j,1,n){
        if(used[j] == 0){
            used[j]=1;
            tmp+=a[i][j];
            if(i == n) ans=max(ans,tmp);
            else game(i+1);
            used[j]=0;
            tmp-=a[i][j];
        }
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("games.inp","r",stdin);
    freopen("games.out","w",stdout);
    cin>>n;
    FOR(i,1,n){
        FOR(j,1,n)cin>>a[i][j];
    }
    game(1);
    cout<<ans;
}
