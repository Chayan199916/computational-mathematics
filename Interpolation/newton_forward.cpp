#include<iostream>
using namespace std;
class newton_forward
{
	float **arr;
	int size;
	public:
	newton_forward(int);
	~newton_forward();
	int fact(int);
	void interpolation();
};
newton_forward::newton_forward(int size)
{
	int i;
	arr=new float*[newton_forward::size=size];
	for(i=0;i<size;i++)
	{
		arr[i]=new float[size+1];
	}
}
newton_forward::~newton_forward()
{
	int i;
	for(i=0;i<size;i++)
	{
		delete[] arr[i];
	}
}
int newton_forward::fact(int a)
{
	int fact=1;
	int i=1;
	while(i<=a)
	{
		fact=fact*i;
		i++;
	}
	//cout<<endl<<"factorial is:\t"<<fact<<endl;
	return fact;
}
void newton_forward::interpolation()
{
	int i,j,k;
	float x,min,x0,h,s,ans=0,v;
	for(i=0;i<size;i++)
	{
		for(j=0;j<=size;j++)
		{
			arr[i][j]=0;
		}
	}
	cout<<"enter the values of x[i]s:"<<endl;
	for(i=0;i<size;i++)
	{
		j=0;
		cout<<"x["<<i<<"]:"<<"\t";
		cin>>arr[i][j++];
		cout<<endl<<"y["<<i<<"]:"<<"\t";
		cin>>arr[i][j];
		cout<<endl;
	}
	h=arr[1][0]-arr[0][0];
	j=2;
	k=1;
	while(k<size)
	{
		i=0;
		while(i<=size-j)
		{
			arr[i][j]=arr[i+1][j-1]-arr[i][j-1];
			i++;
		}
		k++;
		j++;
	}
	for(i=0;i<size;i++)
	{
		for(j=0;j<=size;j++)
		{
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"Enter the value for which you want to find:"<<endl;
	cin>>x;
	i=0;
	j=0;
	while(i<size)
	{
		if((x<arr[i][j])&&(i==0))
		{
			min=arr[i][j];
			k=i;
		}
		else if((x>arr[i][j])&&(i==size-1))
		{
			min=arr[i][j];
			k=i;
		}
		else
		{
			if((x>arr[i][j])&&(x<arr[i+1][j]))
			{
				if((arr[i+1][j]-x)<(x-arr[i][j]))
				{
					min=arr[i+1][j];
					k=i+1;
				}
				else
				{
					min=arr[i][j];
					k=i;
				}
			}
		}
		i++;
	}
	x0=min;
	s=(x-x0)/h;
	//cout<<x0<<"\t"<<s<<"\t"<<k<<endl;
	ans=ans+arr[k][1]+s*arr[k][2];
	//cout<<ans<<endl;
	i=2;
	while(i<size)
	{
		j=i-1;
		v=s;
		while(j>0)
		{
			v=v*(s-j);
			j--;
		}
		//cout<<v<<endl;
		v=(v/fact(i))*arr[k][i+1];
		//cout<<v<<endl;
		i++;
		ans=ans+v;
		//cout<<ans<<endl;
	}
	cout<<"The result is:"<<endl;
	cout<<ans<<endl;
}
int main()
{
	int size;
	char ch;
	do
	{
		cout<<"Enter the number of x[i]s:"<<endl;
		cin>>size;
		newton_forward obj1(size);
		obj1.interpolation();
		cout<<"Do you want to continue:(Y/y)"<<endl;
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	return 0;
}
