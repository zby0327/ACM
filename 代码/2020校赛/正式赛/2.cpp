#include<bits/stdc++.h>
//#include<ext/rope>
//using namespace __gnu_cxx;
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define int long long
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define pb push_back
#define fi first
#define se second
#define use_t 1
const double pi=acos(-1.0);
const double eps=1e-8;
const ll inf = 0x3f3f3f3f;
const ll maxn=1e5+7;
const ll mod=1e9+7;
ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)ans=ans*a%mod;
        a=a*a%mod;
        b/=2LL;
    }
    return ans;
}
int mp[4][4];

bool check(int now){
    int fl;
    for(int i=1;i<=3;++i){
        fl=1;
        for(int j=1;j<=3;++j){
            if(mp[i][j]!=now) fl=0;
        }
        if(fl){
            return 1;
        }
    }
    for(int j=1;j<=3;++j){
        fl=1;
        for(int i=1;i<=3;++i){
            if(mp[i][j]!=now) fl=0;
        }
        if(fl){
            return 1;
        }
    }
    fl=1;
    for(int i=1;i<=3;++i){
        if(mp[i][i]!=now) fl=0;
    }
    if(fl) return 1;
    fl=1;
    for(int i=1;i<=3;++i){
        if(mp[i][4-i]!=now) fl=0;
    }
    return fl;
}

int dfs(int x,int y,int now){
    if(mp[x][y]!=0)return 0;
    mp[x][y]=now;
    int ans=-1;
    if(ans==-1 &&check(now))   ans=1;
    if(ans==-1 &&check(3-now)) ans=0;

    int cnt=0;
    int fl=0,tr=0;
    if(ans==-1)
        for(int i=1;i<=3;++i){
            for(int j=1;j<=3;++j){
                if(ans!=-1) break;
                if(mp[i][j]==0){
                    cnt++;
                    if(dfs(i,j,3-now) )tr++;
                    else fl++;
                }
            }
        }

    if(ans==-1 &&cnt==0){
        if(now==1) ans=0;
        else ans=1;
    }
    else if(ans==-1){
        if(tr)ans=0;
        else ans=1;
    }

    mp[x][y]=0;
    return ans;
}
signed main ()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
//#ifdef yyhaos
//freopen("in.txt","r",stdin);
////freopen("out.txt","w",stdout);
//#endif



#ifdef use_t
ll t;
ll tt=1;
cin>>t;
for(tt=1;tt<=t;tt++)
{
#endif // use_t

    int x,y;
    memset(mp,0,sizeof(mp));
    cin>>x>>y;
    mp[x][y]=1;

    while(1){

        int sum=0;
        int fl=0;
        for(int i=1;i<=3;i++){
            if(fl)  break;
            for(int j=1;j<=3;j++){
                if(fl)  break;
                if(mp[i][j]==0 && dfs(i,j,2)){
                    fl=1;
                    cout<<i<<" "<<j<<endl;
                    mp[i][j]=2;
                }
            }
        }
        sum++;
        string ans;
        cin>>ans;
        if(ans[0]>='1' && ans[0]<='3'){
            x=ans[0]-'0';
            cin>>y;sum++;
            mp[x][y]=1;
        }
        else break;
        if(sum==9){
            cin>>ans;
            break;
        }
        mp[x][y]=1;
    }














#ifdef use_t
}
#endif // use_t
return 0;
}
