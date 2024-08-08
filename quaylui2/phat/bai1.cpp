#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r,v) for(int i=l;i<=r;i+=v)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

unordered_map<char,vector<char>>mp;
unordered_map<char,int>dau;
int used[N],n;
string s,ans="";

void backtrack(){
    FOR(i,0,s.size()-1,2){
        if(used[i] == 0){
            used[i]++;
            for(char c:mp[s[i]]) used[dau[c]]++;
            ans+=s[i];
            if(ans.size() == n) cout<<ans<<"\n";
            else backtrack();
            used[i]--;
            for(char c:mp[s[i]]) used[dau[c]]--;
            ans.pop_back();
        }
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("rangbuoc.inp","r",stdin);
    freopen("rangbuoc.out","w",stdout);
    while(getline(cin,s)){
        string st;getline(cin,st);
        FOR(i,0,s.size()-1,2) dau[s[i]]=i;
        n = (s.size()+1)/2;
        mp.clear();
        fill(used,used+s.size()+1,0);
        FOR(i,0,st.size()-2,4) mp[st[i+2]].push_back(st[i]);
        backtrack();
    }
}
