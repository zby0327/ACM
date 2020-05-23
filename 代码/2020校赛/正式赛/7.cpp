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
const ll mod=998244353;
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
int dp[505][505];
int a[1005];
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
    for(int i=1;i<=n;++i){
       cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=0;i<503;++i){
        for(int j=0;j<=503;++j){
            dp[i][j]=1;
        }
    }
    for(int si=0;si<=n;si++){
        for(int st=1;st<=n;st++){
            int ed= st+si-1;
            if(si<=1){
                dp[st][ed]=1;
                continue;
            }
            dp[st][ed]=0;
            for(int k=st;k<=ed;++k){
                if(k==st || a[k]>a[k-1]){
                    dp[st][ed]+=dp[st][k-1]*dp[k+1][ed]%mod;
                    dp[st][ed]%=mod;
                }
            }
        }
    }

    cout<<dp[1][n]<<endl;







#ifdef use_t
}
#endif // use_t
return 0;
}
