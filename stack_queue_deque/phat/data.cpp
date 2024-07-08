#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("data.inp","r",stdin);
    freopen("data.out","w",stdout);
    int n;
    while(cin>>n){
        pair<int,int>a[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i].first>>a[i].second;
        }
        int dem=0,cnt=0,check[3];
        check[0]=check[1]=check[2]=0;
        priority_queue<int>p;
        queue<int>q;
        stack<int>st;
        for(int i=1;i<=n;i++){
            int k=a[i].first,x=a[i].second;
            if(k==1){
                p.push(x);
                q.push(x);
                st.push(x);
            }
            else{
                cnt++;
                if(!p.empty()){
                    if(p.top() == x)check[0]++;
                    p.pop();
                }if(!q.empty()){
                    if(q.front() == x)check[1]++;
                    q.pop();
                }if(!st.empty()){
                    if(st.top() == x)check[2]++;
                    st.pop();
                }
            }
        }
        for(int i=0;i<3;i++){
            if(check[i] == cnt)dem++;
        }
        if(dem>1)cout<<"no sure\n";
        else if(check[0] == cnt)cout<<"priority_queue\n";
        else if(check[1] == cnt)cout<<"queue\n";
        else if(check[2] == cnt)cout<<"stack\n";
        else cout<<"impossible\n";
    }
}
