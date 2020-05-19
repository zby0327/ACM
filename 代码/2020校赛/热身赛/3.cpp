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
//#define use_t 1
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
vector<int> mp[10005];
int sz[100005];
int getsi(int x){
    sz[x]=-1;
   // cout<<"get:"<<x<<endl;
    int tmp=1;
    int ma=mp[x].size();
    for(int i=0;i<ma;i++){
        int nxt=mp[x][i];
        if(sz[nxt] ==0){
            tmp+=getsi(nxt);
        }
    }
    return sz[x]=tmp;
}

int pos[1010][20];
int ke[20];
int vis[10005];

void dfs(int x,int nowx,int nowy){
    int ma=mp[x].size();
    int maxnow=-1;
    int maxsi=-1;

    for(int i=0;i<ma;++i){
        int nxt=mp[x][i];
        if(nxt!=x && vis[nxt]==0){
            if(maxsi<sz[nxt]) {
                maxsi=sz[nxt];
                maxnow=nxt;
            }
        }
    }
    for(int i=0;i<ma;++i){
        int nxt=mp[x][i];
        if(nxt!=maxnow && nxt!=x && vis[nxt]==0){
            int ny=nowy+1;
            vis[nxt]=1;
            pos[++ke[ny]][ny]=nxt;
            dfs(nxt,ke[ny],ny);
        }
    }

    if(maxnow!=-1){
    vis[maxnow]=1;
        pos[++ke[nowy]][nowy]=maxnow;
        dfs(maxnow,ke[nowy],nowy);
    }

}
int ax[1005];
int ay[1005];

signed main ()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
#ifdef yyhaos
freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif



#ifdef use_t
ll t;
ll tt=1;
cin>>t;
for(tt=1;tt<=t;tt++)
{
#endif // use_t
    int n;
    cin>>n;
    mem(sz,0);
    for(int i=0;i<=n-2;++i){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    getsi(1);
    mem(pos,0);
    pos[0][0]=1;

    dfs(1,0,0);


    for(int i=0;i<1010;++i){
        for(int j=0;j<20;++j){
            if(pos[i][j]>0){
                ax[pos[i][j]]=i;
                ay[pos[i][j]]=j;
            }
        }
    }
    for(int i=1;i<=n;++i){
        cout<<ax[i]+10<<" "<<ay[i]+10<<endl;
    }















#ifdef use_t
}
#endif // use_t
return 0;
}
