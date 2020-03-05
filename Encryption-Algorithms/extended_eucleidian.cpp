#include<iostream>
using namespace std;
int s,t;
int gcd(int a,int b,int s1,int s2,int t1,int t2)
{

   if(b==0)
   {
       s=s1;
    t=t1;
      return a;
   }


    s=s1-(s2*(a/b));
    t=t1-(t2*(a/b));
    if(b!=0)
       return gcd(b,a%b,s2,s,t2,t);


}
int main()
{
    int a,b,c;
    cout<<"\n Enter values of a and b:";
    cin>>a>>b;
    c=gcd(a,b,1,0,0,1);
    cout<<c;
    cout<<"\n"<<s<<" "<<t;
    return 0;
}
