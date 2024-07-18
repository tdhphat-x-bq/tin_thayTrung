#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

struct tim{
    inr nhat, nhi, ba;
};

int n,k;
inr a[N],t[N*4];
deque<inr>d;
inr ans,sum=1;
tim ti[N];


void build(int id,int l,int r){
    if(l==r){
        t[id]=l;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=(a[t[id*2]] >= a[t[id*2+1]] ? t[id*2] : t[id*2+1]);
}

void update(int id,int l,int r,int u,int k){
    if(l>u or r<u) return;
    if(l>=u and r<=u){
        a[t[id]]=k;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,u,k);
    update(id*2+1,mid+1,r,u,k);
    t[id]=(a[t[id*2]] >= a[t[id*2+1]] ? t[id*2] : t[id*2+1]);
}

int get(int id,int l,int r,int u,int v){
    if(l>v or r<u) return -1;
    if(l>=u and r<=v)return t[id];
    int mid=(l+r)/2;
    int t1=get(id*2,l,mid,u,v);
    int t2=get(id*2+1,mid+1,r,u,v);
    if (t1 == -1) return t2;
    if (t2 == -1) return t1;
    return (a[t1] >= a[t2] ? t1 : t2);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("three.inp","r",stdin);
    freopen("three.out","w",stdout);
    cin>>n>>k;
    FOR(i,1,n)cin>>a[i];
    build(1,1,n);
    FOR(j,1,n-k){
        vector<pair<inr,inr>>b;
        FOR(i,1,3){
            int tmp=get(1,1,n,j,j+k);
            //cout<<tmp<<" ";
            b.push_back({a[tmp],tmp});
            if(i==1)ti[j].nhat=tmp;
            else if(i==2)ti[j].nhi=tmp;
            else ti[j].ba=tmp;
            update(1,1,n,tmp,0);
        }
        for(pair<inr,inr>cell:b) update(1,1,n,cell.second,cell.first);
    }


    FOR(i,1,n-k){
        //cout<<ti[i].nhat<<" "<<ti[i].nhi<<" "<<ti[i].ba<<endl;
        ans=max(ans,a[ti[i].nhat]*a[ti[i].nhi]*a[ti[i].ba]);
    }
    cout<<ans;
}
