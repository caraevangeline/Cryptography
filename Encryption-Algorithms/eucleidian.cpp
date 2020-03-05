#include<iostream>
using namespace std;
int gcd(int a, int b)
{
    if(b!=0)
        return gcd(b,a%b);
    else
        return a;
}
int main()
{
int a,b,c;
cout<<"\n Enter the numbers: ";
cin>>a>>b;
if(a>b)
    c=gcd(a,b);
else
    c=gcd(b,a);

    cout<<c;
return 0;
}
