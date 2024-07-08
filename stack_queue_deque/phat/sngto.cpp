#include <bits/stdc++.h>
#define inr long long
#define N 1000006
using namespace std;

inr t;
int ghep[4]={1,3,7,9},bandau[4]={2,3,5,7};

bool nt(inr n){
    if(n<2)return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("sngto.inp","r",stdin);
    freopen("sngto.out","w",stdout);
    cin>>t;
    while(t--){
        int k,ans=0;cin>>k;
        queue<pair<int,int>>q;
        for(int i=0;i<4;i++){
            q.push({bandau[i],1});
        }
        while(!q.empty()){
            int x=q.front().first,len=q.front().second;
            q.pop();
            if(len == k)ans++;
            else {
                for(int i=0;i<4;i++){
                    if(nt(x*10+ghep[i]))q.push({x*10+ghep[i],len+1});
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
