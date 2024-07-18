#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

inr n,l,r;
inr a[N],t[4*N];
inr ans;

void build(inr id,inr l,inr r){
    if(l==r){
        t[id]=a[l];
        return;
    }
    inr m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=min(t[id*2],t[id*2+1]);
}

inr get(inr id,inr l,inr r,inr u,inr v){
    if(l>v or r<u)return inf;
    if(l>=u and r<=v)return t[id];
    inr m=(l+r)/2;
    return min(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("sumlr.inp","r",stdin);
    freopen("sumlr.out","w",stdout);
    cin>>n>>l>>r;
    FOR(i,1,n){
        int x;cin>>x;
        a[i]=a[i-1]+x;
    }
    build(1,0,n-1);
    ans=-inf;
    FOR(i,l,n){
        inr tmp=get(1,0,n-1,max((inr)0,i-r),i-l);
        //cout<<tmp<<" ";
        ans=max(ans,a[i]-tmp);
    }
    cout<<ans;
}
