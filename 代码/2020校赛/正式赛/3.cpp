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
cout<<"Case #"<<tt<<": ";
ll x1,y1,x2,y2,x3,y3;
cin>>x1>>y1>>x2>>y2>>x3>>y3;
ll ans;
ans =4000000000000000001.0;
//cout<<ans<<endl;
ll sx[3]={0,1,2};
while(1){

    for(ll i=0;i<8;++i){
        ll x[3],y[3];
        x[sx[0]]=x1;
        x[sx[1]]=x2;
        x[sx[2]]=x3;
        y[sx[0]]=y1;
        y[sx[1]]=y2;
        y[sx[2]]=y3;
        for(ll j=0;j<3;++j){
            for(ll k=0;k<3;++k){
                if(i&(1LL<<k)){
                    swap(x[k],y[k]);
                }
            }
        }
        ll maxx=max(x[2],x[0]+x[1]);
        ll maxy=max(y[1],y[0]+y[2]);
        if(y[1]<=y[0] || x[2]<=x[0]) {
            ans=min(ans,maxx*maxy);
        }
        else {
            ans=min(ans,(x[1]+x[2])*maxy);
            ans=min(ans, maxx*(y[1]+y[2]));
        }
        ans=min(ans,max(max(y[0],y[1]),y[2])*(x[0]+x[1]+x[2]));
        ans=min(ans,max(max(x[0],x[1]),x[2])*(y[0]+y[1]+y[2]));
    }
    if(next_permutation(sx,sx+3)) continue;
    else break;
}
cout<<ans<<endl;














#ifdef use_t
}
#endif // use_t
return 0;
}
