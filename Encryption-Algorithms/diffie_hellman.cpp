#include<iostream>
#include<math.h>
using namespace std;
void bubbleSort(int arr[], int n)
{
   int i,t,j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           t=arr[j];
	   arr[j]=arr[j+1];
	   arr[j+1]=t;
           swapped = true;
        }
     }

     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}
int main()
{
	int n,flag=0;
	cout<<"\n Enter a Number: ";
	cin>>n;
	int a[n-1][n-1],i,j,k,b[n-1],g;
	for(i=0;i<n-1;++i)
		for(j=0;j<n-1;++j)
		{
			a[i][j]=(pow((i+1),(j+1)));
			a[i][j]=a[i][j]%n;
		}
        for(i=0;i<n-1;++i)
	{	for(j=0;j<n-1;++j)
	 		cout<<a[i][j]<<" ";
		       cout<<"\n" ;	
	}
	for(i=0;i<n-1;++i)
	{
//		cout<<"\n";
		flag=0;
		for(k=0;k<n-1;++k)
			b[k]=0;
		for(j=0;j<n-1;++j)
		{
			b[j]=a[i][j];
		}
		bubbleSort(b,n-1);
		for(j=0;j<n-1;++j)
			//cout<<b[j];
		for(k=0;k<n-1;++k)
		{
			if(b[k]!=k+1)
			{	flag=1;
				break;
			}
		}
		if(flag==0)
		{	g=i+1;
		    break;
		}
	}
	int a1,b1;
	cout<<"\n THE PRIMITIVE ROOT IS :";
	cout<<g;
	cout<<"\n Alice Choose a Private Key: ";
	cin>>a1;
	cout<<"\n Bob Choose a Private Key: ";
	cin>>b1;
	int pa,pb;
	pa=pow(g,a1);
	pa=pa%n;
	pb=pow(g,b1);
	pb=pb%n;
	cout<<"\n The Public key of Alice is :";
	cout<<pa;
	cout<<"\n The Public Key of Bob is :";
	cout<<pb;
	int sa,sb;
	sa=pow(pb,a1);
	sa=sa%n;
	sb=pow(pa,b1);
	sb=sb%n;
	cout<<"\n The secret key of Alice is:";
	cout<<sa;
	cout<<"\n The Secret key of Bob is: ";
	cout<<sb;
	cout<<"\n";
	return 0;
}

