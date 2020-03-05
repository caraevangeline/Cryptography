#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
   char e[30],key[30];
   int choice,i,c;
   cout<<"\n Enter the key: ";
   cin>>key;
   cout<<"\n1.Encrypt \n2.Decrypt";
   cin>>choice;
   switch(choice)
   {
       case 1:cout<<"\n Enter the plain text: ";
       cin>>e;
       for(i=0;i<strlen(e);++i)
       {

            c=(int(key[i%strlen(key)])-97+int(e[i])-97)%26;
           c=c+97;
           cout<<char(c);
       }
       break;
       case 2:cout<<"\n Enter the cipher text: ";
       cin>>e;
       for(i=0;i<strlen(e);++i)
       {
           c=(26 - int(key[i%strlen(key)])+int(e[i]))%26;
           c=c+97;
           cout<<char(c);
       }
   }
   return 0;
}
