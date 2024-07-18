#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
using namespace std;

inr n,t,ans;
inr a[N];
deque<inr>dmax,dmin;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("fgarden.inp","r",stdin);
    freopen("fgarden.out","w",stdout);
    cin>>n>>t;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1,j=1;i<=n;i++){
        while(!dmax.empty() and a[dmax.back()] <= a[i]) dmax.pop_back();
        while(!dmin.empty() and a[dmin.back()] >= a[i]) dmin.pop_back();
        dmax.push_back(i); dmin.push_back(i);
        while(!dmax.empty() and !dmin.empty() and a[dmax.front()] - a[dmin.front()] > t){
            if(dmax.front() == j) dmax.pop_front();
            else if(dmin.front() == j) dmin.pop_front();
            j++;
        }
        ans=max(ans,(inr)i-j+1);
    }
    cout<<ans;
}
