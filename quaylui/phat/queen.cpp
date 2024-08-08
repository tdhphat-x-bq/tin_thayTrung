#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int n,ans[13],cot[13],cheo1[100],cheo2[100];

void in(){
    FOR(i,1,n)cout<<ans[i]<<" ";
    cout<<"\n";
}

void sinh(int j){
    FOR(i,1,n){
        if(cot[i]==0 and cheo1[n+i-j] == 0 and cheo2[j+i-1] == 0){
            cot[i]=cheo1[n+i-j]=cheo2[j+i-1]=1;
            ans[j]=i;
            if(j==n)in();
            else sinh(j+1);
            cot[i]=cheo1[n+i-j]=cheo2[j+i-1]=0;
        }
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("queen.inp","r",stdin);
    //freopen("queen.out","w",stdout);
    cin>>n;
    sinh(1);
}
