#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 123456789
#define inf 1e9
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int n;
int a[15][15],cot[15],d1[60],d2[60];
int ans=inf,tmp;

void xay(int i){
    FOR(j,1,n){
        if(cot[j]==0 and d1[n-j+i] == 0 and d2[j+i-1]==0){
            cot[j]=d1[n-j+i]=d2[j+i-1]=1;
            tmp+=a[i][j];
            if(i == n) ans=min(ans,tmp);
            else if(tmp <= ans)xay(i+1);
            cot[j]=d1[n-j+i]=d2[j+i-1]=0;
            tmp-=a[i][j];
        }
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("cungdien.inp","r",stdin);
    freopen("cungdien.out","w",stdout);
    cin>>n;
    FOR(i,1,n){
        FOR(j,1,n)cin>>a[i][j];
    }
    xay(1);
    cout<<ans;
}
