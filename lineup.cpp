#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 123456789
#define inf 1e9
#define pii pair<int,int>
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int n;
int d,ans=inf;
unordered_map<int,int> used;
set<int>s;
pii a[N];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("lineup.inp","r",stdin);
    //freopen("lineup.out","w",stdout);
    cin>>n;
    FOR(i,1,n)cin>>a[i].first>>a[i].second,s.insert(a[i].second);
    sort(a+1,a+n+1);
    int l=1;
    FOR(r,1,n){
        if(used[a[r].second] == 0) d++;
        used[a[r].second]++;
        if(d == s.size()){
            d--;
            while(true){
                //cout<<"("<<a[l].first<<","<<a[r].first<<") ";
                ans = min(ans,a[r].first-a[l].first);
                used[a[l].second]--;
                if(used[a[l].second] == 0){
                    l++;
                    break;
                }
                l++;
            }
        }
    }
    cout<<ans;
}
