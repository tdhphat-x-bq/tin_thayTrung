#include<bits/stdc++.h>
#define inr long long
#define N 400005
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int d,sum;
int a[6],used[6];
vector<int>x;
vector<vector<int>>func;

void kphan(){
    FOR(i,1,3){
        x.push_back(i);
        if(x.size() == 4) func.push_back(x);
        else kphan();
        x.pop_back();
    }
}

int handle(int f,int b,int c){
    if(f==1)return b+c;
    if(f==2)return b-c;
    return b*c;
}

void cal(){
    if(d==1)return;
    FOR(i,1,5){
        if(used[i]==0){
            used[i]=1;
            x.push_back(a[i]);
            if(x.size() == 5){
                int k=0;
                for(vector<int> f:func){
                    sum = handle(f[3],handle(f[2],handle(f[1],handle(f[0],x[0],x[1]),x[2]),x[3]),x[4]);
                    if(sum == 23){
                        d=1;
                        return;
                    }
                }
            }else cal();
            x.pop_back();
            used[i]=0;
        }
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("expression.inp","r",stdin);
    freopen("expression.out","w",stdout);
    kphan();
    x.clear();
    while(true){
        FOR(i,1,5)cin>>a[i];
        if(a[1]==0 and a[2]==0 and a[3]==0 and a[4]==0 and a[5]==0)break;
        d=0; sum=0; cal();
        d == 1 ? cout<<"Possible\n" : cout<<"Impossible\n";
    }
}
