#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
using namespace std;

int m,n,dem0=0,vangmax;
int a[N],vang[N],xanh[N],t[N];

void update(int id,int val){
    while(id<N){
        t[id]+=val;
        id+=id&(-id);
    }
}

inr get(int id,int lim){
    inr res=0;
    while(id<=lim){
        res+=t[id];
        id+=id&(-id);
    }
    return res;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("rect.inp","r",stdin);
    //freopen("rect.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vang[i]=a[i];
        xanh[i]=m-a[i];
        if(a[i]==0)dem0++;
        update(vang[i],1);
        vangmax=max(vangmax,vang[i]);
    }
    for(int i=1;i<=vangmax;i++){
        inr tmp=get(i,vangmax);
        cout<<tmp<<" ";
    }
}
