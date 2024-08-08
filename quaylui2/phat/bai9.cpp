#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 102
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int m,n,cnt,id,smax,tmp;
int a[M][M],used[M][M],dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

bool check(int x,int y){
    return (x > 0 and y>0 and x<=m and y<=n and used[x][y]==0 and a[x][y] != 0);
}

void tim(int x,int y){
    used[x][y]=1;
    FOR(i,0,3){
        int nx=dx[i]+x,ny=dy[i]+y;
        if(a[nx][ny] < a[x][y]) tmp += a[x][y]-a[nx][ny];
    }
    FOR(i,0,3){
        int nx=dx[i]+x,ny=dy[i]+y;
        if(check(nx,ny)) tim(nx,ny);
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("qv.inp","r",stdin);
    freopen("qv.out","w",stdout);
    cin>>m>>n;
    FOR(i,1,m){
        FOR(j,1,n)cin>>a[i][j];
    }
    FOR(i,1,m){
        FOR(j,1,n){
            if(check(i,j)){
                tim(i,j);
                cnt++;
                if(smax < tmp){
                    smax=tmp;
                    id=cnt;
                }
                tmp=0;
            }
        }
    }
    cout<<cnt<<"\n"<<id<<" "<<smax;
}
