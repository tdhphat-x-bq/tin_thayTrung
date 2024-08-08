#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int m,n,soi,cuu,ans1,ans2;
char a[300][300];
int used[300][300],dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

bool check(int x,int y){
    return (x > 0 and y>0 and x<=m and y<=n and used[x][y]==0 and a[x][y] != '#');
}

void tim(int x,int y){
    used[x][y]=1;
    if(a[x][y] == 'o')cuu++;
    if(a[x][y] == 'v')soi++;
    FOR(i,0,3){
        int nx=dx[i]+x,ny=dy[i]+y;
        if(check(nx,ny)) tim(nx,ny);
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("soicuu.inp","r",stdin);
    freopen("soicuu.out","w",stdout);
    cin>>m>>n;
    FOR(i,1,m){
        FOR(j,1,n)cin>>a[i][j];
    }
    FOR(i,1,m){
        FOR(j,1,n){
            if(check(i,j)){
                tim(i,j);
                soi >= cuu ? cuu=0 : soi=0;
                ans1+=cuu; ans2+=soi;
                soi=0;cuu=0;
            }
        }
    }
    cout<<ans1<<" "<<ans2;
}
