// Newton Raphson

#include<iostream>
using namespace std;

class Raphson
{
	double x[10];	
	int n;

	public:
		
		double function1(double x1);
		double fd(double x1);
		void raphson();
};

double Raphson :: function1(double x1)
{
	double y;
//	y=x1*x1*x1-6*x1*x1+11*x1-6;	
	y=(x1-1.001)*(x1-1.002)*(x1-1.003);
	return y;
}

double Raphson :: fd(double x1)
{
	double y;
	y=2*x1;
	return y;
}

void Raphson :: raphson()
{
	double a,b,c,f1,f2,f3,ff,h,xg;
	double i;
	int j;
	a=-10;
	n=0;
	f1=function1(a);
		for(i=-9.999;i<=10;i=i+.001)
		{
		b=i;
		f2=function1(b);
			if(f1*f2<0)
			{
				xg=(a+b)/2;
				do
				{
				
				h=-function1(xg)/fd(xg);
				if(h<0)
				ff=-h;
				else
				ff=h;	
				xg=xg+h;
				if(h<1e-10)
					{
					x[n++]=xg;
					break;
					}
				}while(1);

			}
		a=i;
		f1=function1(a);
		}
	//display roots
		for(j=0;j<n;j++)
		cout<<"Root["<<j<<"]="<<x[j]<<endl;
}

int main()
{
	Raphson R;
	R.raphson();	
	return 0;
}
