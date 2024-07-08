#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
using namespace std;

int n,ans;
inr a[N];
stack<inr>st;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("pairs.inp","r",stdin);
    freopen("pairs.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    a[n]=1e18;
    st.push(n);
    for(int i=n-1;i>0;i--){
        while(!st.empty() and a[st.top()] < a[i]) st.pop();
        ans+=(st.top()-i);
        st.push(i);
    }
    cout<<ans;
}
