#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

int n,k;
int a[N];
deque<int>q;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("minimum.inp","r",stdin);
    freopen("minimum.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=k;i++){
        while(!q.empty() and a[q.back()] >= a[i]) q.pop_back();
        q.push_back(i);
    }
    cout<<a[q.front()]<<endl;
    for(int i=k+1;i<=n;i++){
        while(!q.empty() and a[q.back()] >= a[i]) q.pop_back();
        q.push_back(i);
        if(q.front() == i-k)q.pop_front();
        cout<<a[q.front()]<<endl;
    }
}
