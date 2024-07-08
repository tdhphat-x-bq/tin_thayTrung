#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

int n,x[N],d;
stack<int>a;
queue<int>b;
vector<string>ans;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("train1.inp","r",stdin);
    //freopen("train1.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=n;i>0;i--)a.push(i);
    for(int i=1;!a.empty() or !b.empty();i++){

        //else{
            while((!a.empty() and a.top() != x[i]) and (b.empty() or b.front() != x[i])){
                //cout<<"A->B\n";
                ans.push_back("A->B");
                b.push(a.top());
                a.pop();
            }
        //}
        if(!a.empty() and a.top() == x[i]){
            //cout<<"A->C\n";
            ans.push_back("A->C");
            a.pop();
        }else if(!b.empty() and b.front() == x[i]){
            //cout<<"B->C\n";
            ans.push_back("B->C");
            b.pop();
        }else{
            d=1;
            break;
        }
    }
    if(d == 1)cout<<"NO";
    else {
        cout<<"YES\n";
        string t=ans.back();
        ans.pop_back();
        for(string s:ans)cout<<s<<endl;
        cout<<t;
    }
}
