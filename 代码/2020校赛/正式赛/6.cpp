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
int n,m;
string str;
int ans[1005][1005];
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


    cin>>n>>m;
    cin>>str;
    if(n*m%2){
        cout<<"QAQ"<<endl;
        return 0;
    }
    cout<<"QQQ"<<endl;
    int p=0;
    ans[1][n]=p++;
    if(m%2==0) {
        for(int i=m;i>=2;i-=2){
            for(int j=2;j<=n;j++){
                ans[j][i]=p++;
            }
            for(int j=n;j>=2;j--){
                ans[j][i-1]=p++;
            }
        }
        for(int i=1;i<=m-1;i++)
            ans[1][i]=p++;
    }
    else {
        for(int i=2;i<=n;i++){
            ans[i][m]=p++;
        }
        for(int j=n;j>=2;j-=2){
            for(int i=m-1;i>=1;i--){
                ans[j][i]=p++;
            }
            for(int i=1;i<=m-1;i++){
                ans[j-1][i]=p++;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
          //  printf("%4d",ans[i][j]);
            printf("%c",str[ans[i][j]]);
        }
        printf("\n");
    }















#ifdef use_t
}
#endif // use_t
return 0;
}
