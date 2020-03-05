#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int bina[70],index=0;
int binary[64];
int initial[]={58,50,42,34,26,18,10,2,
             60,52,44,36,28,20,12,4,
             62,54,46,38,30,22,14,6,
             64,56,48,40,32,24,16,8,
             57,49,41,33,25,17,9,1,
             59,51,43,35,27,19,11,3,
             61,53,45,37,29,21,13,5,
             63,55,47,39,31,23,15,7};

 int fin[]={40,8,48,16,56,24,64,32,
         39,7,47,15,55,23,63,31,
         38,6,46,14,54,22,62,30,
         37,5,45,13,53,21,61,29,
         36,4,44,12,52,20,60,28,
         35,3,43,11,51,19,59,27,
         34,2,42,10,50,18,58,26,
         33,1,41,9,49,17,57,25};
void binar(int a)
{
   int ch[10];
   int i=0,j;
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
void bin(char p[10])
{
    int b,i;
    for(i=0;i<strlen(p);++i)
    {

        binar(int(p[i]));

    }
}
void hex()
{
    int i,j;
    for(i=0;i<64;i=i+8)
    {
        int k=0,sum=0;
         for(j=i+7;j>=i;--j)
         {
             if(binary[j]==1)
            {
               // cout<<sum<<j<<" ";
                sum= sum+pow(2,k);}
            ++k;
         }
         //cout<<sum;
         cout<<char(sum);
    }
}

void encrypt()
{

    int i,j;
    for(i=0;i<index;++i)
    {
        if(bina[i]==1)
        {
            for(j=0;j<64;++j)
            {
                if(initial[j]==i+1)
                    {
                        binary[j]=1;
                    }
            }
        }
    }
}
void decrypt()
{

    int i,j;
    for(i=0;i<index;++i)
    {
        if(bina[i]==1)
        {
            for(j=0;j<64;++j)
            {
                if(fin[j]==i+1)
                    {
                        binary[j]=1;
                    }
            }
        }
    }
}
int main()
{

    int choice,i,j;
    char p[100];
    cout<<"\n1.Initial Permutation \n2.Final Permutation";
    cin>>choice;
    switch(choice)
    {
        case 1:{cout<<"\n Enter the text for initial Permutation: ";
        cin>>p;
        int l=strlen(p);
        for(i=0;i<8-(strlen(p)%8);++i)
            strcat(p,"0");
        for(j=0;j<l;j=j+8)
        {
            index=0;
            for(i=0;i<64;++i)
                {bina[i]=0;
                binary[i]=0;}
            char ch[10];
            int k=0;
            for(i=j;i<(j+8);++i)
                ch[k++]=p[i];
            ch[k]='\0';
            bin(ch);

        for(i=0;i<64;++i)
            cout<<bina[i];
            cout<<"\n";
        encrypt();
        for(i=0;i<64;++i)
            cout<<binary[i];
            cout<<"\n";
        hex();
        cout<<"\n";
        }
        break;}
        case 2:{cout<<"\n Enter the text for final Permutation: ";
        cin>>p;
        int l=strlen(p);
        for(i=0;i<8-(strlen(p)%8);++i)
            strcat(p,"0");
        for(j=0;j<l;j=j+8)
        {
            index=0;
            for(i=0;i<64;++i)
                {bina[i]=0;
                binary[i]=0;}
            char ch[10];
            int k=0;
            for(i=j;i<(j+8);++i)
                ch[k++]=p[i];
            ch[k]='\0';
            bin(ch);

        for(i=0;i<64;++i)
            cout<<bina[i];
            cout<<"\n";
        decrypt();
        for(i=0;i<64;++i)
            cout<<binary[i];
            cout<<"\n";
        hex();
        cout<<"\n";
        }
        break;}
    }
    return 0;
}
