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

cout<<fixed<<setprecision(10);

#ifdef use_t
ll t;
ll tt=1;
cin>>t;
for(tt=1;tt<=t;tt++)
{
#endif // use_t
double a,b,c,p,s,ans1,ans2;
cin>>a>>b>>c;
p=(a+b+c)/2;
s=sqrt(p*(p-a)*(p-b)*(p-c));
ans1=a*b*c/4/s;
ans2=2*s/(a+b+c);
cout<<ans1<<" "<<ans2<<endl;















#ifdef use_t
}
#endif // use_t
return 0;
}
