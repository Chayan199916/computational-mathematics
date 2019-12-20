#include<iostream>
using namespace std;
class matrix_min
{
    int req[3],cap[3],cost[3][3],allo[3][3];
    public:
   /* int min_calc()
    {
        int i,j,min=cost[0][0];
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(min>cost[i][j])
                {
                    min=cost[i][j];
                }
            }
        }
        return min;
    }*/
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
        int x,y,max=cost[0][0],min,i,j,l1=1,l2=1;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(max<=cost[i][j])
                {
                    max=cost[i][j];
                }
            }
        }
        while((l1==1)||(l2==1))
        {   
            l1=l2=0;
            min=max+1;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if((cap[i]==0)||(req[j]==0))
                    continue;
                if(min>=cost[i][j])
                {
                    min=cost[i][j];
                    x=i;
                    y=j;
                }
            }
        }
        cout<<min<<endl;
        allo[x][y]=(req[y]>=cap[x])?cap[x]:req[y];
        cout<<endl<<allo[x][y]<<" "<<x<<" "<<y<<endl;
        if(allo[x][y]==req[y])
        {
            cap[x]=cap[x]-req[y];
            req[y]=0;            
        }
        else if(allo[x][y]==cap[x])
        {
            if(req[y]==cap[x])
            {
                req[y]=0;
                cap[x]=0;
            }
            else
            {
                req[y]=req[y]-cap[x];
                cap[x]=0;
            }
        }
            for(i=0;i<3;i++)
            {
                if(req[i]!=0)
                    l1=1;
                if(cap[i]!=0)
                    l2=1;
            }
        }
        
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
    matrix_min ob1;
    ob1.set_data(req,cap,cost);
    ob1.calc();
    cout<<"bye";
    ob1.display();
    cout<<"..";
    return 0;
}
