#include<bits/stdc++.h>
#define inr long long
#define N 200006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

int n,a[N],f[N][22],q;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("dqueue.inp","r",stdin);
    freopen("dqueue.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i],f[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j] =min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    vector<pair<int,int>>test;
    while(q--){
        int l,r;cin>>l>>r;
        test.push_back({l,r});

    }
    for(pair<int,int>cell:test){
        int l=cell.first,r=cell.second;
        int k=log2(cell.second-cell.first+1);
        cout<<min(f[l][k],f[r-(1<<k)+1][k]);
        cout<<endl;
    }
}
