#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e9
using namespace std;

inr n;
inr h[N],maxl[N],maxr[N];
stack<inr>st;
inr ans;
map<pair<inr,inr>,inr>mp;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("water.inp","r",stdin);
    //freopen("water.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    h[0]=h[n+1]=inf;
    st.push(0);
    for(int i=1;i<=n;i++){
        while(!st.empty() and h[st.top()] <= h[i]) st.pop();
        maxl[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    st.push(n+1);
    for(int i=n;i>0;i--){
        while(!st.empty() and h[st.top()] <= h[i]) st.pop();
        maxr[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=1;i<=n;i++){
        //cout<<maxl[i]<<" "<<maxr[i]<<endl;
        pair<inr,inr>p;
        p.first=maxl[i];p.second=maxr[i];
        if(mp[p]==0){
            if(maxl[i]!=0 and maxr[i]!=n+1){
                ans+=((min(h[maxl[i]],h[maxr[i]]) - h[i]) * (maxr[i]-maxl[i]-1));
                mp[p]=1;
            }

        }
        //cout<<ans<<" ";
    }
    cout<<ans;
}
