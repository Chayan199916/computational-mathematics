#include<iostream>
using namespace std;
class least_square
{
    float *x,*y,*xy,*x_sq;
    float equ1[3],equ2[3],ans[2];
    int size;
    public:
    least_square(int);
    ~least_square();
    void calc();
    void display();
    void gauss_elimination();
};
least_square::least_square(int size)
{
    int i;
    x=new float[least_square::size=size];
    y=new float[size];
    xy=new float[size];
    x_sq=new float[size];
    cout<<"enter the values of x[i]s and y[i]s:"<<endl;
    for(i=0;i<size;i++)
    {
        cin>>x[i];
        cin>>y[i];
    }
}
least_square::~least_square()
{
    delete[] x;
    delete[] y;
    delete[] xy;
    delete[] x_sq;
}
void least_square::calc()
{
    int i;
    float sx=0,sy=0,sxy=0,sx_sq=0;
    for(i=0;i<size;i++)
    {
        xy[i]=x[i]*y[i];
        x_sq[i]=x[i]*x[i];
    }
    for(i=0;i<size;i++)
    {
        sx=sx+x[i];
        sy=sy+y[i];
        sxy+=xy[i];
        sx_sq+=x_sq[i];
    }
    equ1[0]=size;
    equ1[1]=sx;
    equ1[2]=sy;
    equ2[0]=sx;
    equ2[1]=sx_sq;
    equ2[2]=sxy;
    gauss_elimination();
}
void least_square::gauss_elimination()
{
    int i;
    float am;
    am=equ2[0]/equ1[0];
    for(i=0;i<3;i++)
    {
        equ2[i]=equ2[i]-am*equ1[i];
    }
    ans[1]=equ2[2]/equ2[1];
    ans[0]=(equ1[2]-ans[1]*equ1[1])/equ1[0];
    display();
}
void least_square::display()
{
    cout<<"the equation is:"<<endl;
    cout<<"y="<<ans[0]<<"+"<<ans[1]<<"*x"<<endl;
}
int main()
{
    int size;
    cout<<"enter the number of x[i]s:"<<endl;
    cin>>size;
    least_square ob1(size);
    ob1.calc();
    return 0;
}