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
int ni(int n){
    return ksm(n,mod-2);
}
int c(int n,int m){
    int ans=1;
    for(int i=1;i<=m;++i){
        ans*=n-i+1;
        ans*=ni(i);
        ans%=mod;
    }
    return ans;
}

int ans[1000005]={0};
signed main ()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
#ifdef yyhaos
freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
ans[0]=1;
for(int i=1;i<=1000003;++i){
    ans[i]=ans[i-1]*((27*i*i-27*i+6)%mod)%mod*ni(i)%mod*ni(i);
    ans[i]%=mod;
//    cout<<ans[i]<<endl;
}

#ifdef use_t
ll t;
ll tt=1;
cin>>t;
for(tt=1;tt<=t;tt++)
{
#endif // use_t
int n;
cin>>n;

if(n%2){
    cout<<0<<endl;
}

else {
    int res=ans[n/2];
    if((n/2)%2==1)res=-res;
    if(res<0)res+=mod;
    if(res>=mod)res-=mod;
    cout<<res<<endl;
}









#ifdef use_t
}
#endif // use_t
return 0;
}
