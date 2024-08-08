#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

struct sub {
    inr ele,len;
};

bool cmp(sub a,sub b){
    if(a.len == b.len) return a.ele >= b.ele;
    return a.len < b.len;
}

int n;
inr a[N],minl[N],minr[N],b[N];
stack<int>st;
sub s[N];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("subseq.inp","r",stdin);
    //freopen("subseq.out","w",stdout);
    cin>>n;
    FOR(i,1,n)cin>>a[i],s[i].ele=a[i];
    a[0]=a[n+1]=-inf;
    st.push(0);
    FOR(i,1,n){
        while(a[st.top()] >= a[i])st.pop();
        minl[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    st.push(n+1);
    FOD(i,n,1){
        while(a[st.top()] >= a[i])st.pop();
        minr[i] = st.top();
        st.push(i);
    }
    FOR(i,1,n){
        //cout<<a[i]<<" "<<minl[i]<<" "<<minr[i]<<"\n";
        s[i].len = minr[i]-minl[i]-1;
    }
    sort(s+1,s+n+1,cmp);
    FOR(i,1,n){
        //cout<<s[i].ele<<" "<<s[i].len<<"\n";
        b[i] = s[i].len;
    }
    FOR(i,1,n){
        int tmp=lower_bound(b+1,b+n+1,i)-b;
        if(b[tmp] < i)tmp++;
        cout<<s[tmp].ele<<' ';
    }
}
