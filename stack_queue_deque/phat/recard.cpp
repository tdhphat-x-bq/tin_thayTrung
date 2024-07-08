#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;


main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("recard.inp","r",stdin);
    //freopen("recard.out","w",stdout);
    inr n;
    while(cin>>n){
        deque<inr>d;
        for(int i=1;i<=n;i++){
            d.push_back(i);
        }
        while(d.size() != 0){
            cout<<d.front()<<" ";
            d.pop_front();
            if(d.size() == 1){
                cout<<endl<<d.front()<<endl;
                break;
            }
            inr x=d.front();
            d.push_back(x);
            d.pop_front();
        }
    }
}
