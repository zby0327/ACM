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

//#define int long long
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
struct node{
    int to, dis;
    node(int a,int b){
        to=a,dis=b;
    }
};
int n;
vector<node> mp[maxn];
void sol(){
    for(int i=1;i<=n;++i){
        for(int j=0;j<mp[i].size();++j){
            for(int k=0;k<mp[i].size();++k){
                if(j==k)continue;
                int fl=0;
                int th=mp[i][j].to;
                int th2=mp[i][k].to;
                int th3=-1;
                int th4=-1;
                for(int p=0;p<mp[th].size();++p){
                    if(mp[th][p].to==th2){
                        th3=p;fl=1;break;
                    }
                }
                for(int p=0;p<mp[th2].size();++p){
                    if(mp[th2][p].to==th){
                        th4=p;fl=1;break;
                    }
                }
                int now=max(mp[i][j].dis,mp[i][k].dis);
                if(fl==0){
                    mp[th].pb(node(th2,now));
                    mp[th2].pb(node(th,now));
                }
                else{
                    if(mp[th][th3].dis>now)mp[th][th3].dis=now;
                    if(mp[th2][th4].dis>now)mp[th2][th4].dis=now;
                }

            }
        }
    }
}
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
int m,k;
cin>>n>>m>>k;
mem(mp,inf);
for(int i=1;i<=m;++i){
    int x,y,v;
    cin>>x>>y>>v;
    mp[x].pb(node(y,v));
    mp[y].pb(node(x,v));
}
sol();
int ans=0;
for(int i=1;i<=n;++i){
    for(int j=0;j<mp[i].size();++j){
        if(mp[i][j].dis==k)ans++;

    }
}

cout<<ans/2;









#ifdef use_t
}
#endif // use_t
return 0;
}
