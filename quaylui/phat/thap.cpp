#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int n;


void chuyen(int n,char a,char b,char c){
    if(n==1) cout<<a<<"->"<<c<<"\n";
    else{
        chuyen(n-1,a,c,b);
        cout<<a<<"->"<<c<<"\n";
        chuyen(n-1,b,a,c);
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("thap.inp","r",stdin);
    freopen("thap.out","w",stdout);
    int n;cin>>n;
    char a='A',b='B',c='C';
    chuyen(n,a,b,c);
}
