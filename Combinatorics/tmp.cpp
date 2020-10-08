#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn=100000+1000;
const int maxm=100+10;
const int mod=1000000007;
ll C[maxn][maxm],ans[maxn][maxm];
int a[maxn];
void init()
{
    C[0][0]=1;
    for(int i=1;i<maxn;++i)
    {
        C[i][0]=1;
        for(int j=1;j<=i&&j<maxm;++j)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    int l,r,k;
    while(m--)
    {
        scanf("%d%d%d",&l,&r,&k);
        for(int i=0;i<=k;++i) ans[l][i]=(ans[l][i]+C[k][k-i])%mod;
        for(int i=0;i<=k;++i) ans[r+1][i]=(ans[r+1][i]-C[k+r-l+1][k-i])%mod;

        for(int i = 0 ; i <= k ; i ++) {
            for(int j = 0 ; j <= k ; j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
    for(int i=1;i<n;++i)
        for(int j=101;j>=1;--j)
            ans[i+1][j-1]=(ans[i+1][j-1]+ans[i][j]+ans[i][j-1])%mod;
    for(int i=1;i<=n;++i)
        printf("%lld ",((ans[i][0]+a[i])%mod+mod)%mod);
    printf("\n");
    return 0;
}