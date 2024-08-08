#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int n,cnt,sum;
int pseudo[]={1,-1};
char x[22];

void ngoac(int j){
    //FOR(k,1,n)cout<<x[k];
    //cout<<"\n";
    FOR(i,0,1){
        if(sum+pseudo[i] > -1){
            sum+=pseudo[i];
            x[j] = pseudo[i] == -1 ? ')' : '(';
            if(j == n){
                if(sum==0){
                    cnt++;
                    FOR(k,1,j)cout<<x[k];
                    cout<<"\n";
                }
            }else ngoac(j+1);
            sum-=pseudo[i];
        }
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("ngoac.inp","r",stdin);
    freopen("ngoac.out","w",stdout);
    cin>>n;
    ngoac(1);
    cout<<cnt;
}
