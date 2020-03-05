#include<iostream>
using namespace std;
long long int mul(long long int a,long long int m)
{
    long long int i;
    for(i=1;i<m; ++i)
    {
    	if(i==m)
    	cout<<i;
        if((a*i) % m == 1)
            return i;
    }
    
}
int main()
{
long long int a,m,c;
cout<<"ax = 1(mod m) \nEnter the values of a and m: ";
cin>>a>>m;
//cout<<m;
c=mul(a,m);
cout<<"\n The multiplicative inverse of "<<a<<" in Z"<<m<<"\n";
cout<<c;
//cout<<(-60%26);
}
