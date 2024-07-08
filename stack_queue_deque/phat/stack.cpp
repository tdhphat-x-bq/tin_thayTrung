#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

inr n;
inr a[N];
stack<int>st;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("stack.inp","r",stdin);
    freopen("stack.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    a[0]=-inf;
    stack<int>st;
    st.push(0);
    for(int i=1;i<=n;i++){
        while(!st.empty() and a[st.top()] >= a[i]) st.pop();
        cout<<st.top()+1<<" ";
        st.push(i);
    }
    cout<<endl;
    a[n+1]=-inf;
    while(!st.empty()) st.pop();
    st.push(n+1);
    vector<int>next;
    for(int i=n;i>0;i--){
        while(!st.empty() and a[st.top()] >= a[i]) st.pop();
        next.push_back(st.top()-1);
        st.push(i);
    }
    reverse(next.begin(),next.end());
    for(int x:next)cout<<x<<" ";
}
