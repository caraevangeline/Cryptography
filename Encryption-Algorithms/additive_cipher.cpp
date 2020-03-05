#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
void encrypt(char e[30],int k)
{
char d[30];
int i;
for(i=0;i<strlen(e);++i)
{
    int c=int(e[i])+k-96;
    c=c%26;
    //cout<<c;
d[i]=char(c+96);
}
d[i]='\0';
cout<<d;

}
void decrypt(char e[30],int k)
{
char d[30];
k=26-k;
int i;
for(i=0;i<strlen(e);++i)
{
    int c=int(e[i])+k-96;
    c=c%26;
d[i]=char(c+96);
}
d[i]='\0';
cout<<d;

}
int main()
{
char e[30];
int k,choice;
cout<<"Enter the key value: ";
cin>>k;
cout<<"\n1.Encrypt \n2.Decrypt \n";
cin>>choice;
switch(choice)
{
case 1: cout<<"Enter the Plain text:";
cin>>e;
encrypt(e,k);
break;
case 2: cout<<"Enter the cipher text:";
cin>>e;
decrypt(e,k);
break;}
return 0;
}
