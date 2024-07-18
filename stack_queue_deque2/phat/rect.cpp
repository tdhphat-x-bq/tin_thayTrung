#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int n,m;
inr vang[N],xanh[N],ans,minl[N],minr[N],ansv,ansx;
stack<inr>sl,sr;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("rect.inp","r",stdin);
    freopen("rect.out","w",stdout);
    cin>>m>>n;
    FOR(i,1,n){
        cin>>vang[i];
        xanh[i]=m-vang[i];
    }
    vang[0]=vang[n+1]=xanh[0]=xanh[n+1]=-1;
    sl.push(0);sr.push(n+1);
    FOR(i,1,n){
        while(vang[sl.top()]>=vang[i]) sl.pop();
        minl[i]=sl.top();
        sl.push(i);
    }
    FOD(i,n,1){
        while(vang[sr.top()]>=vang[i]) sr.pop();
        minr[i]=sr.top();
        ansv=max(ansv,(minr[i]-minl[i]-1)*vang[i]);
        sr.push(i);
    }
    while(!sl.empty()) sl.pop();
    while(!sr.empty()) sr.pop();
    sl.push(0);sr.push(n+1);
    FOR(i,1,n){
        while(xanh[sl.top()]>=xanh[i]) sl.pop();
        minl[i]=sl.top();
        sl.push(i);
    }
    FOD(i,n,1){
        while(xanh[sr.top()]>=xanh[i]) sr.pop();
        minr[i]=sr.top();
        ansx=max(ansx,(minr[i]-minl[i]-1)*xanh[i]);
        sr.push(i);
    }
    cout<<max(ansx,ansv);
}
