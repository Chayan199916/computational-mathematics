#include<iostream>
using namespace std;
class nwcm
{
    int req[3],cap[3],cost[3][3],allo[3][3];
    public:
    void set_data(int r[3],int c[3],int co[3][3])
    {
        int i,j;
        for(i=0;i<3;i++)
        {
            req[i]=r[i];
        }
        for(i=0;i<3;i++)
        {
            cap[i]=c[i];
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                cost[i][j]=co[i][j];
            }
        }
        for(i=0;i<3;i++)
        {
           for(j=0;j<3;j++)
            {
                allo[i][j]=0;
            }
        }
        cout<<"hye";
    }
    void calc()
    {
        int k=0,l=0,i,j=0,cp;
        i=0;
        cout<<"hello";
        while(j<3)
        {
                allo[i][j]=(req[k]>=cap[l])?cap[l]:req[k];
                cout<<allo[i][j]<<endl;
                if(allo[i][j]==req[k])
                {
                    cp=req[k];
                    req[k++]=0;
                    cap[l]=cap[l]-cp;
                    j++;
                    cout<<cap[l];
                    cout<<req[k]<<endl;
                }
                else
                {
                    if(req[k]==cap[l])
                    {
                        req[k]=cap[l]=0;
                        i++;
                        j++;
                        l++;
                        k++;
                   cout<<cap[l];
                   cout<<req[k]<<endl;
                    }
                    else
                    {
                        cp=cap[l];
                        cap[l++]=0;
                        req[k]=req[k]-cp;
                        i++;
                    cout<<cap[l];
                    cout<<req[k]<<endl;
                    }
                }
        }
        cout<<"tata";
    }
    void display()
    {
        int i,j;
        int s=0;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                s=s+allo[i][j]*cost[i][j];
            }
        }
        cout<<"the result is:"<<s<<endl;
      for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                cout<<allo[i][j]<<"\t";
            }
            cout<<endl;
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                cout<<cost[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
};
int main()
{
    int req[3]={4,7,2};
    int cap[3]={5,6,2};
    int cost[3][3]={2,1,4,3,6,2,1,4,6};
    nwcm ob1;
    ob1.set_data(req,cap,cost);
    ob1.calc();
    cout<<"bye";
    ob1.display();
    cout<<"..";
    return 0;
}
