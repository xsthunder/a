#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<complex>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
namespace EPS{
	const double eps=1e-10;
	int dcmp(double x){ if(fabs(x)<eps)return 0;else return x<0?-1:1; }
	int dcmp(double x,double y){return dcmp(x-y);}
}
namespace ScalarBaseCplx{
	//complex,cmath,cstdio,EPS
	using namespace EPS;
	typedef complex<double > Point;
	typedef Point Vector;
	double Dot(Vector A,Vector B){return real(conj(A)*B);}
	double Cross(Vector A,Vector B){return imag(conj(A)*B);}
	Vector Rotate(Vector A,double rad){return A*exp(Point(0,rad));}
	Point read_point(){ double x,y; scanf("%lf%lf",&x,&y); return Point(x,y); }
	double get_x(Point A){return real(A);}
	double get_y(Point A){return imag(A);}
	//also can inject to std
	bool Cmp (const Point A,const Point B){//for sort unique
		bool ans;
		if(real(A)==real(B))ans=imag(A)<imag(B);else ans=real(A)<real(B);
		//pp(A),pp(B),printf("%d\n",ans);
		return ans;
	}
	bool Eq(const Point &A,const Point &B){//for unique
		using namespace EPS;
		bool a =dcmp(real(A),real(B)),b=dcmp(imag(A),imag(B));
		return a==0&&b==0;
	}
}
namespace Geo{
	using namespace ScalarBaseCplx;
	namespace Scalar{
		//dependencies Point Vector
		double Length(Vector A){return sqrt(Dot(A,A));}
		double Angle(Vector A,Vector B){return acos(Dot(A,B)/Length(A)/Length(B));}
	}
	namespace Line{
		//dependencies Point Vector EPS cmath
		using namespace Scalar;
		using namespace EPS;
		Point GetLineIntersection(Point P,Vector v,Point Q,Vector w){
			//make sure Cross(v,w)!=0
			//use with SegmentProperIntersection to find segment intersetion
			Vector u = P-Q;
			double t = Cross(w,u)/Cross(v,w);
			return P+v*t;
		}
		double DistanceToLine(Point P,Point A,Point B){
			Vector v1=B-A,v2=P-A; return fabs(Cross(v1,v2))/Length(v1);
		}
		double DistanceToSegment(Point P,Point A,Point B){
			if(Eq(A,B))return Length(P-A);
			Vector v1=B-A,v2=P-A,v3=P-B;
			if(dcmp(Dot(v1,v2))<0)return Length(v2);
			else if(dcmp(Dot(v1,v3)>0))return Length(v3);
			else return fabs(Cross(v1,v2))/Length(v1);
		}
		Point GetLineProjection(Point P,Point A,Point B){
			Vector v=B-A;
			return A+v*(Dot(v,P-A)/Dot(v,v));
		}
		bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2){
			double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),
						 c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
			return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
		}
		bool OnSegment(Point p,Point a1,Point a2){
			return dcmp(Cross(a1-p,a2-p))==0&&dcmp(Dot(a1-p,a2-p))<0;
		}
	}
	namespace Polygon{
		//dependencies Point Vector
		double PolygonArea(Point *p,int n){
			double area=0;
			for(int i = 1;i<n-1;i++){
				area+=Cross(p[i]-p[0],p[i+1]-p[0]);
			}
			return area/2;
		}
	}
}
int main(){
#ifdef XS
	freopen("uva11796.in","r",stdin);
#endif
	int n;scanf("%d",&n);for(int i =0;i<n;i++)inp();
	return 0;
}
using namespace Geo::Line;
using namespace ScalarBaseCplx;
void inp(){
}
//geo.cc by xsthunder at Wed Aug 16 19:59:38 2017
