#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
using namespace std;

inr n,ans;
inr a[N],maxl[N],maxr[N],minl[N],minr[N];
stack<inr>st;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("weight.inp","r",stdin);
    //freopen("weight.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    a[0]=a[n+1]=1e9;
    st.push(0);
    for(int i=1;i<=n;i++){
        while(!st.empty() and a[st.top()] < a[i]) st.pop();
        maxl[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    st.push(n+1);
    for(int i=n;i>0;i--){
        while(!st.empty() and a[st.top()] <= a[i]) st.pop();
        maxr[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    a[0]=a[n+1]=0;
    st.push(0);
    for(int i=1;i<=n;i++){
        while(!st.empty() and a[st.top()] > a[i]) st.pop();
        minl[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    st.push(n+1);
    for(int i=n;i>0;i--){
        while(!st.empty() and a[st.top()] >= a[i]) st.pop();
        minr[i]=st.top();
        st.push(i);
    }
    inr ans=0;
    for(int i=1;i<=n;i++){
        ans+=(i-maxl[i])*(maxr[i]-i)*a[i];
        ans-=(i-minl[i])*(minr[i]-i)*a[i];
    }
    cout<<ans;
}
