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
inr ans[N],a[N],b[N],t[4*N],a1[N];
stack<inr>st;
pair<inr,inr>p1[N],p2[N];
map<inr,inr>pos,pos1,ms;

void build(int id,int l,int r){
    if(l==r){
        t[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=max(t[id*2],t[id*2+1]);
}

void update(int id,int l,int r,int u,int k){
    if(l>u or r<u) return;
    if(l>=u and r<=u){
        t[id]=k;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,u,k);
    update(id*2+1,mid+1,r,u,k);
    t[id]=max(t[id*2],t[id*2+1]);
}

inr get(int id,int l,int r,int u,int v){
    if(l>v or r<u) return -inf;
    if(l>=u and r<=v)return t[id];
    int mid=(l+r)/2;
    inr t1=get(id*2,l,mid,u,v);
    inr t2=get(id*2+1,mid+1,r,u,v);
    return max(t1,t2);
}

inr tim_r(inr x){
    int res=-1,l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid] >= x){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    return res;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("overload.inp","r",stdin);
    freopen("overload.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n){
        cin>>a[i];
        pos[a[i]]=i;
    }
    FOR(i,1,m){
        cin>>b[i];
        pos1[b[i]]=i;
    }
    sort(a+1,a+n);
    sort(b+1,b+m);
    FOR(i,1,n)ms[a[i]]=i;
    build(1,1,n);
    fill(ans,ans+N,-1);
    FOR(i,1,m){
        inr r=tim_r(b[i]);
        if(r==-1)r=n;
        else if(a[r]>b[i])r--;
        //cout<<r<<" ";
        int p=pos[get(1,1,n,1,r)];
        //cout<<p<<endl;
        ans[p]=pos1[b[i]];
        //cout<<pos<<endl;
        update(1,1,n,ms[get(1,1,n,1,r)],-1);
    }
    FOR(i,1,n)cout<<ans[i]<<endl;
}
