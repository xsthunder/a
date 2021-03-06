#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("qpMatrix.in","r",stdin);
#endif
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)inp();
	return 0;
}
namespace qpMatrix{
	const int D = 3;
	typedef ll M[D][D];
	ll mod = 1000000007;
#define MCP(x,y) memcpy(x,y,sizeof(M)) //x=y
	void pM(M m){
		for(int i =0;i<D;i++){
			for(int j=0;j<D;j++){
				printf("%lld ",m[i][j]);
			}
			putchar('\n');
		}
	}
	void MtM(M m,M a,M b){//m=a*b
		M ans={0};
		for(int i=0;i<D;i++){
			for(int j =0;j<D;j++){
				for(int k=0;k<D;k++){
					ans[i][j]+=a[i][k]*b[k][j]%mod;
				}
				while(ans[i][j]<0)ans[i][j]+=mod;//如果矩阵出现负数
			}
		}
		MCP(m,ans);
	}
	void qp(M m,ll p){
		M b={0};for(int i = 0;i<D;i++)b[i][i]=1;
		while(p){
			if(p&1)MtM(b,b,m);
			p>>=1;
			MtM(m,m,m);
		}
		MCP(m,b);
	}
}
void inp(){
	using namespace qpMatrix;
	ll n;if(scanf("%lld",&n)==EOF)exit(0);
	mod=1024;
	M A0={
		0,0,9,
		0,0,97,
		0,0,969
	};
	if(n<=3){ printf("%lld\n",A0[n-1][2]);return; }
	n-=3;
	M A={
		0,1,0,
		0,0,1,
		1,-11,11
	};
	qp(A,n);
	MtM(A,A,A0);
	printf("%lld\n",(A[2][2])%mod);
}
//qpMatrix.cc by xsthunder at Wed Aug 23 16:21:51 2017

