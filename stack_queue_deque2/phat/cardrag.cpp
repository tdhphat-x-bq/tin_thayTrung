#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

void solve(int n, int m, int& ans,int cnt, vector<string>& a, vector<vector<int>>& used,vector<int>& lunXuong
,vector<int>& lunTrai,vector<int>& lunLen,vector<int>& lunPhai){
    stack<int>st;
        FOR(i,0,m-1){
            if(a[0][i] == '.' or a[0][i] == 'N' or a[0][i] == 'W' or used[0][i] == 1){
                int check=0;
                if(a[0][i] == 'W'){
                    if(used[0][i] == 1)check=1;
                    else if(st.empty()){
                        ans++;
                        used[0][i]=1;
                        check=1;
                    }
                }
                if(a[0][i] == 'N' and used[0][i]==0){
                    ans++;
                    used[0][i]=1;
                }
                if(a[0][i] == '.')used[0][i]=1;
                if(a[0][i] == '.' or a[0][i] == 'N' or check==1 or used[0][i] == 1){
                    FOR(j,lunXuong[i],n-1){
                        //cout<<"("<<j<<","<<i<<")"<<" ";
                        if(a[j][i] == '.' or a[j][i] == 'N' or used[j][i] == 1){
                            lunXuong[i]=j+1;
                            if(a[j][i] == 'N' and used[j][i] == 0){
                                ans++;
                                used[j][i] =1;

                            }
                        }else break;
                    }
                }
            }else{
                st.push(i);
            }
        }// duyet hang dau tien
        //cout<<ans<<endl;
        if(ans==cnt)return;
        while(!st.empty()) st.pop();
        FOR(i,0,n-1){
            if(a[i][m-1] == '.' or a[i][m-1] == 'E' or a[i][m-1] == 'N' or used[i][m-1] == 1){
                int check=0;
                if(a[i][m-1] == 'N'){
                    if(used[i][m-1] == 1) check=1;
                    else{
                        if(st.empty()){
                            ans++;
                            check=1;
                            used[i][m-1]=1;
                           // cout<<"("<<i<<","<<m-1<<")"<<" ";
                        }
                    }
                }if(a[i][m-1] == 'E' and used[i][m-1] == 0){
                    ans++;
                    used[i][m-1]=1;
                    //cout<<"("<<i<<","<<m-1<<")"<<" ";
                }
                if(a[i][m-1] == '.' or a[i][m-1] == 'E' or check==1 or used[i][m-1] == 1){
                    FOD(j,lunTrai[i],0){
                        if(a[i][j] == '.' or a[i][j] == 'E' or used[i][j] == 1){
                            lunTrai[i]=j-1;
                            if(a[i][j] == 'E' and used[i][j]==0){
                                ans++;
                                used[i][j] = 1;

                                //cout<<"("<<i<<","<<j<<")"<<" ";
                            }
                        }else break;
                    }
                }
            }else st.push(i);
        }//duyet cot ben phai
        //cout<<ans<<endl;
        if(ans==cnt)return;
        while(!st.empty()) st.pop();
        FOD(i,m-1,0){
            if(a[n-1][i] == '.' or a[n-1][i] == 'S' or a[n-1][i] == 'E' or used[n-1][i] == 1){
                int check=0;
                if(a[n-1][i] == 'E'){
                    if(used[n-1][i] == 1)check=1;
                    else{
                        if(st.empty()){
                            ans++;
                            check=1;
                            used[n-1][i]=1;
                        }
                    }
                }if(a[n-1][i] == 'S' and used[n-1][i]==0){
                    ans++;
                    used[n-1][i]=1;
                }
                if(a[n-1][i] == '.' or a[n-1][i] == 'S' or check==1 or used[n-1][i] == 1){
                    FOD(j,lunLen[i],0){
                        if(a[j][i] == '.' or a[j][i] == 'S' or used[j][i]==1){
                            lunLen[i]=j-1;
                            if(a[j][i]=='S' and used[j][i]==0){
                                ans++;
                                used[j][i]=1;

                            }
                        }else break;
                    }
                }
            }else st.push(i);
        }//duyet hang ben duoi
        //cout<<ans<<endl;
        if(ans==cnt)return;
        while(!st.empty()) st.pop();
        FOD(i,n-1,0){
            if(a[i][0] == '.' or a[i][0] == 'W' or a[i][0] == 'S' or used[i][0]==1){
                int check=0;
                if(a[i][0] == 'S'){
                    if(used[i][0] == 1)check=1;
                    else{
                        if(st.empty()){
                            ans++;
                            check=1;
                            used[i][0]=1;
                            //cout<<"("<<i<<","<<0<<")"<<" ";
                        }
                    }
                }if(a[i][0] == 'W' and used[i][0] == 0){
                    ans++;
                    used[i][0]=1;
                    //cout<<"("<<i<<","<<0<<")"<<" ";
                }
                if(a[i][0] == 'W' or a[i][0] == '.' or check==1 or used[i][0]==1){
                    FOR(j,lunPhai[i],m-1){
                        if(a[i][j] == 'W' or used[i][j] == 1 or a[i][j] == '.'){
                            lunPhai[i]=j+1;
                            if(a[i][j] == 'W' and used[i][j] == 0){
                                ans++;
                                used[i][j] = 1;

                                //cout<<"("<<i<<","<<j<<")"<<" ";
                            }
                        }else break;
                    }
                }
            }else st.push(i);
        }//duyet cot ben trai
        //cout<<ans<<endl;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("cardrag.inp","r",stdin);
    freopen("cardrag.out","w",stdout);
    while(true){
        int n,m,ans=0,tmp=0,cnt=0;cin>>n>>m;
        if(n==0 and m==0) break;
        vector<string> a(n);
        FOR(i,0,n-1)cin >> a[i];
        FOR(i,0,n-1){
            for(char c:a[i]){
                if(c!='.')cnt++;
            }
        }
        vector<vector<int>> used(n, vector<int>(m, 0));
        vector<int>lunXuong(m,1),lunTrai(n,m-2),lunLen(m,n-2),lunPhai(n,1);
        int dem=1;
        for(;;){
            tmp=ans;
            solve(n,m,ans,cnt,a,used,lunXuong,lunTrai,lunLen,lunPhai);
            if(tmp==ans){
                cout<<ans<<endl;
                break;
            }
        }
    }
}

