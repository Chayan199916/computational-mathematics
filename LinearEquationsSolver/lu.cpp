#include<iostream>
using namespace std;
class matrix_factor
{
    float arr[10][10],b[10],x[10],l[10][10],u[10][10],y[10];
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
                u[i][j]=arr[i][j];
                if(i==j)
                    l[i][j]=1;
                else
                    l[i][j]=0;
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
            for(j=0;j<size;j++)
            {
                cout<<l[i][j]<<"\t";
            }
            cout<<endl;
        }
                for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                cout<<u[i][j]<<"\t";
            }
            cout<<endl;
        }

        for(i=0;i<size;i++)
        {
            for(j=i;j<size;j++)
            {
                if(i!=j)
                {
                    am=u[j][i]/u[i][i];
                    l[j][i]=am;
                    for(k=0;k<size;k++)
                    {
                        u[j][k]=u[j][k]-am*u[i][k];
                    }
                }
            }
        }
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                cout<<l[i][j]<<"\t";
            }
            cout<<endl;
        }
                for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                cout<<u[i][j]<<"\t";
            }
            cout<<endl;
        }
        y[0]=b[0];
        i=1;
        while(i<size)
        {
            s=0;
            for(j=0;j<size;j++)
            {
                if(i!=j)
                    s+=y[j]*l[i][j];
            }
            y[i]=(b[i]-s)/l[i][i];
            i++;
        }
        x[size-1]=y[size-1]/u[size-1][size-1];
        i=size-2;
        while(i>=0)
        {
            s=0;
            for(j=(i+1);j<size;j++)
            {
                s+=x[j]*u[i][j];
            }
            x[i]=(y[i]-s)/u[i][i];
            i--;
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
        cout<<"The result is:\n";
        for(i=0;i<size;i++)
            cout<<x[i]<<endl;
    }
};
int main()
{
    int i,j,size;
    float arr[10][10],b[10];
    cout<<"Enter the number of linear equations:\t";
    cin>>size;
    cout<<"enter the coefficients:"<<endl;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"enter the constant terms:"<<endl;
    for(i=0;i<size;i++)
    {
        cin>>b[i];
    }
    matrix_factor ob1;
    ob1.set_data(arr,size,b);
    ob1.elimination();
    ob1.display();
    return 0;
}