
#include<iostream>
using namespace std;

class Matrix_Inversion
{
	float a[10][10],b[10],x[10],aug[10][20];
	int n;
	public:
	Matrix_Inversion( float x[10][10], float b1[10], int m);
	void matrix_inversion();
	void display();//display sol
	void display1();//display aug
};

Matrix_Inversion :: Matrix_Inversion(float x[10][10], float b1[10], int m)
{
	int i,j;
	n=m;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				a[i][j]=x[i][j];
		b[i]=b1[i];
		}
}

void Matrix_Inversion :: matrix_inversion()
{
	float am,s;
	float inverse[10][10];
	int i,j,k,n1;
	n1=2*n;
	//To form initial augmented matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			aug[i][j]=a[i][j];
				if(i==j)
				aug[i][j+n]=1;
				else
				aug[i][j+n]=0;
		}

	cout<<"\nThe co-efficients of the initial augmented matrix:\n";
	display1();	

	//Modify augmented matrix

	for(i=0;i<n;i++)
	{
		am=aug[i][i];
		for(j=0;j<n1;j++)
			aug[i][j]=aug[i][j]/am;
		for(j=0;j<n;j++)
			if(i!=j)
			{
				am=aug[j][i];
					for(k=0;k<n1;k++)
				aug[j][k]=aug[j][k]-aug[i][k]*am;
			}
	cout<<"\nElements in the modified augmented matrix: \n";
	display1();
	}

//To extract inverse matrix

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		inverse[i][j]=aug[i][j+n];

//To display elements of inverse matrix

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cout<<inverse[i][j]<<"\t";
	cout<<endl;
	}

//to get solutions of linear simultaneous equations

	for(i=0;i<n;i++)
	{
		s=0;
			for(j=0;j<n;j++)
			s=s+inverse[i][j]*b[j];
		x[i]=s;
	}
	display();
}

void Matrix_Inversion :: display()
{
	int i;
	cout<<"\nSolutins of given Equations:\n";
	for(i=0;i<n;i++)
		cout<<"x["<<(i+1)<<"]="<<x[i]<<endl;
}

void Matrix_Inversion :: display1()
{
	int i,j;
	int ch;
	cout<<"\nElements of augmented matrix are: \n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<2*n;j++)
				cout<<aug[i][j]<<"\t";
		cout<<endl;
		}
	cout<<"\nType any number and press enter--->";
	cin>>ch;
	system("clear");
}


int main()
{
	float a[10][10], b[10];
	int i,j,n;
	cout<<"\nEnter no. of eqns: ";
	cin>>n;
	cout<<"\nEnter co-efficients of all equations: ";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
			cout<<"a["<<i<<"]["<<j<<"]=";
			cin>>a[i][j];
			}
		cout<<"b["<<i<<"]=";
		cin>>b[i];
		}
	
	Matrix_Inversion MI(a,b,n);
	MI.matrix_inversion();
	
	return 0;
}

