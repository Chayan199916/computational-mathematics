#include<iostream>
using namespace std;
class gauss_elimination
{
    float arr[10][10],b[10],x[10];
    int size;
    public:
    void set_data(float a[10][10],int s,float x[10])
    {
        int i,j;
        size=s;
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                arr[i][j]=a[i][j];
            }
            b[i]=x[i];
        }
    }
    void elimination()
    {
        int i,j,k;
        float am,s=0;
        for(i=0;i<size;i++)
        {
            for(j=i;j<size;j++)
            {
                if(i!=j)
                {
                    am=arr[j][i]/arr[i][i];
                    for(k=0;k<size;k++)
                        arr[j][k]=arr[j][k]-am*arr[i][k];
                    b[j]=b[j]-am*b[i];
                }
            }
        }
        x[size-1]=b[size-1]/arr[size-1][size-1];
        for(i=(size-2);i>=0;i--)
        {
            s=0;
            for(j=(i+1);j<size;j++)
            {
                s+=x[j]*arr[i][j];
            }
            x[i]=(b[i]-s)/arr[i][i];
        }
    }
    void display()
    {
        int i,j;
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                cout<<arr[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<"the result is:\t";
        for(i=0;i<size;i++)
            cout<<x[i]<<endl;
    }
};
int main()
{
    int i,j,size;
    float arr[10][10],b[10];
    cout<<"enter the size of the matrix:\t";
    cin>>size;
    cout<<"enter the values:"<<endl;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(i=0;i<size;i++)
    {
        cin>>b[i];
    }
    gauss_elimination ob1;
    ob1.set_data(arr,size,b);
    ob1.elimination();
    ob1.display();
    return 0;
}