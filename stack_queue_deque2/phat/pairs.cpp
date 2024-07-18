#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int n;
inr a[N],ans;
stack<int>st;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("pairs.inp","r",stdin);
    freopen("pairs.out","w",stdout);
    cin>>n;
    FOR(i,1,n)cin>>a[i];
    a[0]=inf;st.push(0);
    FOR(i,1,n){
        if(a[st.top()] > a[i]) ans++;
        else if(a[st.top()] == a[i]){
            ans++;
            st.pop();
        }else{
            while(a[st.top()] < a[i]){
                ans++;
                st.pop();
            }
            ans++;
            if(st.top() == 0)ans--;
            if(a[st.top()] == a[i]) st.pop();
        }

        st.push(i);
    }
    cout<<ans-1;
}
