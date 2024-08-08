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
inr x[15],used[15];

bool nt(int c){
    if(c<2)return false;
    FOR(i,2,sqrt(c)){
        if(c%i==0)return false;
    }
    return true;
}

void prime(int i){
    FOR(j,1,n){
        if(used[j] == 0 and nt(x[i-1]+j)){
            x[i]=j;
            used[j]=1;
            if(i==n and nt(x[i]+x[1])){
                FOR(k,1,n) cout<<x[k]<<" ";
                cout<<"\n";
            }else prime(i+1);
            used[j]=0;
        }
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("primering.inp","r",stdin);
    freopen("primering.out","w",stdout);
    while(cin>>n){
        fill(used,used+25,0);
        x[1]=1;
        used[1]=1;
        prime(2);
        cout<<"\n";
    }
}
