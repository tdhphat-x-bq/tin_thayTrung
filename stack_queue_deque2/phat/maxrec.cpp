#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e9
using namespace std;

int m,n,ans;
int a[M],l[M],r[M],h[M];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("maxrec.inp","r",stdin);
    freopen("maxrec.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[j];
            h[j]=a[j]==1 ? h[j]+1 : 0;
        }
        h[0]=h[n+1]=-1;
        stack<int>st;
        st.push(0);
        for(int j=1;j<=n;j++){
            while(h[j]<=h[st.top()]) st.pop();
            l[j]=st.top()+1;
            st.push(j);
        }
        while(!st.empty())st.pop();
        st.push(n+1);
        for(int j=n;j>0;j--){
            while(h[j]<=h[st.top()]) st.pop();
            r[j]=st.top()-1;
            st.push(j);
        }
        for(int j=1;j<=n;j++){
            ans=max(ans,h[j]*(r[j]-l[j]+1));
        }
    }
    cout<<ans;
}

