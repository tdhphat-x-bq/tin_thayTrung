#include<bits/stdc++.h>
#define inr long long
#define N 100006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("print.inp","r",stdin);
    freopen("print.out","w",stdout);
    int t;cin>>t;
    while(t--){
        deque<int>d;
        priority_queue<int>pq;
        int n,m;cin>>n>>m;
        int a[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i];
            d.push_back(i);
            pq.push(a[i]);
        }
        int phut=0,giay=0;
        while(true){
            int x = pq.top();
            while(x != a[d.front()]){
                giay++;
                d.push_back(d.front());
                d.pop_front();
            }
            phut++;
            if(d.front() == m+1)break;
            d.pop_front();
            pq.pop();
        }
        while(giay>=60){
            phut++;
            giay-=60;
        }
        cout<<phut<<" "<<giay<<endl;
    }
}
