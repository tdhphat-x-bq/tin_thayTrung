#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int n,v;
inr a[25],used[25],sum;
vector<inr>ans;
vector<vector<inr>>x;

void water(){
    FOR(j,ans.empty() ? 1 : ans.back()+1,n){
        if(used[j]==0){
            used[j]=1;
            ans.push_back(j);
            sum+=a[j];
            if(sum == v)x.push_back(ans);
            else if(sum<=v) water();
            used[j]=0;
            sum-=a[j];
            ans.pop_back();
        }
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("water.inp","r",stdin);
    freopen("water.out","w",stdout);
    cin>>n>>v;
    FOR(i,1,n)cin>>a[i];
    water();
    if(x.size() == 0) cout<<-1;
    else{
        cout<<x.size()<<"\n";
        for(vector<inr>v : x){
            for(inr i:v)cout<<i<<" ";
            cout<<"\n";
        }
    }

}
