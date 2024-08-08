#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define pii pair<int,int>
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int m,n,u,v,lim=1000000000;
int a[200][200],used[200][200],dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
vector<pii>t,ans;

bool check(int x,int y){
    return (x > 0 and y>0 and x<=m and y<=n and used[x][y]==0 and a[x][y] == 0);
}

void tim(int x,int y){
    if(t.size()>lim) return;
    t.push_back({x,y});
    used[x][y]=1;
    if(x == 1 or y == 1 or x == m or y == n){
        if(t.size() < lim) {
            ans={t};
            lim=t.size();
        }
    }
        FOR(i,0,3){
            int nx=dx[i]+x,ny=dy[i]+y;
            if(check(nx,ny)) tim(nx,ny);
        }

    t.pop_back();
    used[x][y]=0;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("maze.inp","r",stdin);
    //freopen("maze.out","w",stdout);
    cin>>m>>n;
    FOR(i,1,m){
        FOR(j,1,n)cin>>a[i][j];
    }
    cin>>u>>v;
    ans.push_back({-1,-1});
    tim(u,v);
    if(lim==1000000000)cout<<-1;
    else{
        cout<<ans.size()-1<<endl;
        FOR(i,1,ans.size()-1)cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
}
