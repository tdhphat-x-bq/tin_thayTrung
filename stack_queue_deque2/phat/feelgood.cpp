#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
using namespace std;

inr n,ans;
inr a[N],p[N],l[N],r[N];
stack<inr>sl,sr;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("feelgood.inp","r",stdin);
    freopen("feelgood.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[i]=p[i-1]+a[i];
    }
    a[0]=a[n+1]=-1;
    sl.push(0);sr.push(n+1);
    for(int i=1;i<=n;i++){
        while(a[i]<=a[sl.top()]) sl.pop();
        l[i]=sl.top()+1;
        sl.push(i);
    }
    for(int i=n;i>0;i--){
        while(a[i]<=a[sr.top()]) sr.pop();
        r[i]=sr.top()-1;
        sr.push(i);
    }
    for(int i=1;i<=n;i++){
        //cout<<l[i]<<" "<<r[i]<<endl;
        ans=max(ans,a[i]*(p[r[i]]-p[l[i]-1]));
    }
    cout<<ans;
}
