#include<iostream>
using namespace std;
int main()
{
	int i,j,size,rl=0,cl=0;
	int arr1[size*2];
	cout<<"ENTER NUMBER OF ELEMENTS OF RELATION:";
	cin>>size;
	cout<<"ENTER ELEMENTS OF RELATION:";
	for(i=0;i<size*2;i++)
	cin>>arr1[i];
	for(i=0;i<size*2;i=i+2)
	{
		if(rl<arr1[i])
		{
			rl=arr1[i];
		}
	}
	for(i=1;i<size*2;i=i+2)
	{
	
		if(cl<arr1[i])
		{
			cl=arr1[i];
		}
	}
	int arr2[rl][cl],a,b;
	for(i=0;i<size*2;i=i+2)
	{
		a=arr1[i];
		b=arr1[i+1];
		for(int p=0;p<rl;p++)
		{
			for(int k=0;k<cl;k++)
			{
				if(p==a-1 && k==b-1)      //please check
				{
					arr2[p][k]=1;
				}
				else 
				{
					arr2[p][k]=0;
				}
			}
		}
	}
	cout<<"\nRelation elements:";
	{
	
	for(i=0;i<size*2;i++)
	{
		if(i%2==0)
		{
			cout<<"("<<arr1[i]<<",";
		}
		else if(i%2!=0)
		{
			cout<<arr1[i]<<"),";
		}
		cout<<"/b";
	}

}
		
		
	//cout<<"\b";
	cout<<"\nMATRIX IS:\n";
	for(int p=0;p<rl;p++)
	{
		for(int k=0;k<cl;k++)
		{
			cout<<arr2[p][k]<<" ";
			
		}
		cout<<"\n";
	}
	return 0;
}
