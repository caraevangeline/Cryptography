#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int bina[2500],index=0;
/*void ascii_to_bin(char p[300],int plain[2500])
{
    int i=0,a,j,ch[2500];
    for(i=0;i<(strlen(p));++i)
    {
        a=(int)p[i];
         while(a/2!=1)
    {
        ch[i++]=a%2;
        a=a/2;
    }
    ch[i++]=a%2;
    ch[i++]=a/2;
    for(j=i;j<=7;++j)
        ch[j]=0;
    for(j=7;j>=0;--j)
        bina[index++]=ch[j];
    }
    }

}*/
void encryption(char p[300],char kbyte[300],char out[2500])
{
  int i=0;
  //cout<<"\n"<<p;
  //int plain[2500],key[2500];
  //ascii_to_binary(p,plain);
  //ascii_to_binary(kbyte,key);
  for(i=0;i<(strlen(p));++i)
  {
      out[i]=p[i]^kbyte[i];
  }
  out[i]='\0';
  cout<<"\nEncrypted text:";
 cout<<out;
}
void decryption(char kbyte[300],char out[2500])
{
  int i=0;
  char d[2500];
  for(i=0;i<(strlen(kbyte));++i)
  {
      d[i]=out[i]^kbyte[i];
  }
  d[i]='\0';
cout<<"\nDecrypted text:";
 cout<<d;
}
int main()
{
    char key[260],p[300],kbyte[300];
    int i,j,s[260],ks[260];
    cout<<"\nEnter the key ";
    cin>>key;
    for(i=strlen(key);i<256;++i)
    {
        for(j=0;j<strlen(key);++j)
        {
            key[i]=key[j];
            ++i;
        }
    }
    j=0;
    int t;
    for(i=0;i<256;++i)
    {
      s[i]=i;
      ks[i]=(int)key[i];
    }
    for(i=0;i<256;++i)
    {
        j=(j+s[i]+ks[i])%256;
        t=s[i];
        s[i]=s[j];
        s[j]=t;
    }
    cout<<"\nEnter the plaintext ";
    cin>>p;
    i=0,j=0;
    int c=0,t1;
    //cout<<"\n"<<p;
    while(c<strlen(p))
    {
        i=(i+1)%256;
        j=(j+s[i])%256;
        t=s[i];
        s[i]=s[j];
        s[j]=t;
        t=(s[i]+s[j])%256;
        kbyte[c]=(char)s[t];
        c++;
    }
    kbyte[c]='\0';
    //cout<<"\n"<<p;
    //cout<<kbyte;
    char out[2500];
    encryption(p,kbyte,out);
    //cout<<"\n"<<p;
    decryption(kbyte,out);
    return 0;
}
