#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int n,cnt;
vector<string>a(35);
int dx[]={-1,1,0,0,-1,1,-1,1},dy[]={0,0,-1,1,-1,1,1,-1};

bool check(int x,int y){
    return (x >= 0 and y>=0 and x<n and y<n and a[x][y] == '1');
}

void tim(int x,int y){
    //cout<<"("<<x<<","<<y<<") ";
    a[x][y]='0';
    FOR(i,0,7){
        int nx=dx[i]+x,ny=dy[i]+y;
        if(check(nx,ny)) tim(nx,ny);
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("images.inp","r",stdin);
    freopen("images.out","w",stdout);
    int test=1;
    while(true){
        cin>>n;
        if(n==0)break;
        FOR(i,0,n-1)cin>>a[i];
        FOR(i,0,n-1){
            FOR(j,0,n-1){
                if(check(i,j)){
                    cnt++;
                    tim(i,j);
                }
            }
        }
        cout<<test<<" "<<cnt<<"\n";
        test++;cnt=0;
    }
}
