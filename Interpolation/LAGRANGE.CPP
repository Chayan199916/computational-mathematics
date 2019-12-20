#include<iostream>
using namespace std;
class lagrange
{
    float x[10],y[10];
    int size;
    public:
    void set_data(float a[10],float b[10],int s)
    {
        int i;
        size=s;
        for(i=0;i<size;i++)
        {
            x[i]=a[i];
            y[i]=b[i];
        }
    }
    void calc()
    {
        float val,s=0,p1=1,p2=1;
        int i,j;
        cout<<"enter the value for which you want to find:\t";
        cin>>val;
        for(i=0;i<size;i++)
        {
            p1=1;
            p2=1;
            for(j=0;j<size;j++)
            {
                if(i!=j)
                {
                    p1*=(val-x[j]);
                    p2*=(x[i]-x[j]);
                }
            }
            s+=(p1/p2)*y[i];
        }
        cout<<"The result is :\t"<<s;
    }
};
int main()
{
    int i,size;
    float x[10],y[10];
    cout<<"Enter the number of x[i]s:\t";
    cin>>size;
    cout<<"enter values of x[i]s :\n";
    for(i=0;i<size;i++)
    {
        cin>>x[i];
    }
    cout<<"enter values of y[i]s :\n";
    for(i=0;i<size;i++)
    {
        cin>>y[i];
    }
    lagrange ob1;
    ob1.set_data(x,y,size);
    ob1.calc();
    return 0;
}