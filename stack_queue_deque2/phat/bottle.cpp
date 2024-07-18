#include<bits/stdc++.h>
#define inr long long
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

const inr N = 5e5+5;

inr a[N],p[N],pr[N],luu[N],dau[N];
pair<inr,inr>t[N*4];

void update(int id,int l,int r,int u,inr k){
    if(l>u or r<u)return;
    if(l==r){
        t[id].first=k;
        t[id].second=u;
        return;
    }
    int m=(l+r)/2;
    update(id*2,l,m,u,k);
    update(id*2+1,m+1,r,u,k);
    if(t[id*2].first>=t[id*2+1].first)t[id]=t[id*2];
    else t[id]=t[id*2+1];
    //t[id] = max(t[id*2],t[id*2+1]);
}

pair<inr,inr> get(int id,int l,int r,int u,int v){
    if(l>v or r<u){
        pair<inr,inr>p;
        p.first = -inf;p.second=0;
        return p;
    }
    if(l>=u and r<=v)return t[id];
    int mid=(l+r)/2;
    pair<inr,inr> t1=get(id*2,l,mid,u,v);
    pair<inr,inr> t2=get(id*2+1,mid+1,r,u,v);
    if(t1.first>=t2.first)return t1;
    else return t2;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("bottles.inp","r",stdin);
    freopen("bottles.out","w",stdout);
    inr n,k;
    cin>>n>>k;
    FOR(i,1,n){
        cin>>a[i];
        pr[i]=pr[i-1]+a[i];
    }
    if(n<k){
        cout<<n<<" "<<pr[n]-pr[0]<<endl;
        FOR(i,1,n)cout<<i<<" ";
    }
    else{
        FOR(i,1,k-1) {
            update(1,1,n,i,pr[i]-pr[i+1]);
            //kq=max(kq,pr[i]-pr[i+1]);
        }
        //build(1,0,n);
        inr ans=0,tmp=-inf;
        FOR(i,k,n){
            //inr pos;
            if(i==k){
                //tmp=max(0ll-pr[1],get(1,1,n,i-k+1,i-1));
                if(0ll-pr[1] >= get(1,1,n,i-k+1,i-1).first){
                    tmp=0ll-pr[1];
                    luu[i]=1;
                }
                else {
                    tmp=get(1,1,n,i-k+1,i-1).first;
                    luu[i]=get(1,1,n,i-k+1,i-1).second+1;
                }
            }else {
                tmp=get(1,1,n,i-k,i-1).first;
                luu[i]=get(1,1,n,i-k,i-1).second+1;
            }
            //cout<<tmp<<" "<<pos<<endl;
            //cout<<luu[i]<<endl;
            ans=pr[i]+tmp;
            //kq=max(kq,ans);
            //cout<<ans<<" "<<pr[i+1]<<endl;
            update(1,1,n,i,ans-pr[i+1]);
        }
        //FOR(i,1,4*n)cout<<p[t[i]]<<" ";
        tmp=abs(tmp);
        int i=n;
        while(tmp>=0 and i>0){
            dau[luu[i]]=1;
            tmp-=a[luu[i]];
            i=luu[i]-1;
        }
        vector<int>res;
        FOR(i,1,n){
            if(dau[i]==0)res.push_back(i);
        }
        cout<<res.size()<<" "<<ans<<endl;
        for(int x:res)cout<<x<<" ";

    }
}
