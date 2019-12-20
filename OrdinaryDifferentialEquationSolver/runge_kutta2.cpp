#include<iostream>
using namespace std;
class runge_kutta
{
	float x0,y0,h,x;
	int n;
	public:
	runge_kutta(float,float,float,float,int);
	~runge_kutta();
	float func(float,float);
	void kutta();
};
runge_kutta::runge_kutta(float x0,float y0,float h,float x,int n)
{
	runge_kutta::x0=x0;
	runge_kutta::y0=y0;
	runge_kutta::h=h;
	runge_kutta::x=x;
	runge_kutta::n=n;
}
runge_kutta::~runge_kutta()
{}
float runge_kutta::func(float a,float b)
{
	return (b*b+(b*a));
}
void runge_kutta::kutta()
{
	float k1,k2;
	int i;
	for(i=0;i<n;i++)
	{
		k1=h*func(x0,y0);
		k2=h*func(x0+h,y0+k1);
		y0=y0+(0.5*(k1+k2));
		x0=x0+h;
	}
	cout<<"the result is:"<<endl;
	cout<<y0;
}
int main()
{
	float x0,y0,h,x;
	int n;
	cout<<"enter the value of x0,y0,h:"<<endl;
	cin>>x0>>y0>>h;
	cout<<"enter the value for which you want to calculate:"<<endl;
	cin>>x;
	cout<<"enter the number of iterations:"<<endl;
	cin>>n;
	runge_kutta obj1(x0,y0,h,x,n);
	obj1.kutta();
	return 0;
}
