#include<iostream>
using namespace std;
#include<string.h>
char k1[10]="\0",ch[27];
char key[6][6];
int uni=-1,uni_x,uni_y;
void alp1()
{
int i,j,z=0,flag=0;
    for(i=97;i<123;++i)
    {
        flag=0;
        for(j=0;j<strlen(k1);++j)
        {
           if(char(i)==k1[j])
           {
               flag=1;
               break;
           }
        }
        if(flag==0)
        {
            char h=char(i);
            if(char(i)=='j')
                i=i+1;
            ch[z++]=char(i);

        }

    }
    ch[z]='\0';

}
char alp()
{
uni=uni+1;
return ch[uni];
}
void dup(char k[10])
{
    int flag=0,m=0,i,j;

    for(i=0;i<strlen(k);++i)
    {
        flag=0;
        for(j=0;j<strlen(k1);++j)
        {
            if(k[i]==k1[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0 && k[i]=='j')
            k1[m++]='i';
        else if(flag==0)
            k1[m++]=k[i];

    }
    alp1();
    cout<<k1<<"\n";

    int v=0;
    for(i=0;i<5;++i)
    {
        for(j=0;j<5;++j)
        {
            if(v<strlen(k1))
            key[i][j]=k1[v++];
            else
                key[i][j]=alp();
        }
    }
    for(i=0;i<5;++i)
    {
        for(j=0;j<5;++j)
        {
            cout<<key[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void findc(char c)
{
int i,j;
    for(i=0;i<5;++i)
    {
        for(j=0;j<5;++j)
        {
            if(c==key[i][j])
            {
                uni_x=i;
                uni_y=j;
                break;
            }
        }
    }
}
void encrypt(char e[100])
{
    char e1[100];
    int i,j,z,x,flag=0,t1=0;
    for(i=0;i<strlen(e);++i)
    {
        if(e[i]==e[i+1])
        {

           e1[t1++]=e[i];
           e1[t1++]='x';

        }
        else
        e1[t1++]=e[i];

    }
    e1[t1]='\0';
    strcpy(e,e1);

    if(strlen(e)%2==1)
        strcat(e,"x");
        char temp='\0';
    for(i=0;i<strlen(e);i=i+2)
    {
       for(j=0;j<5;++j)
       {
           for(z=0;z<5;++z)
           {flag=0;
               if(e[i]==key[j][z])
               {
                   for(x=0;x<5;++x)
                   {
                       if(e[i+1]==key[j][x])
                       {cout<<key[j][(z+1)%5]<<key[j][(x+1)%5];flag=1;}
                       if(e[i+1]==key[x][z])
                        {cout<<key[(j+1)%5][z]<<key[(x+1)%5][z];flag=1;}

                   }
                   if(flag==0)
                   {
                       char t=e[i+1];
                       findc(t);
                        cout<<key[j][uni_y]<<key[uni_x][z];

                   }

               }
           }
       }
    }

}

    void decrypt(char e[100])
{
    int i,j,z,x,flag=0;
    if(strlen(e)%2==1)
        strcat(e,"x");
        char temp='\0';
    for(i=0;i<strlen(e);i=i+2)
    {
       for(j=0;j<5;++j)
       {
           for(z=0;z<5;++z)
           {flag=0;
               if(e[i]==key[j][z])
               {
                   /*if(e[i]==e[i+1])
                   {
                       temp=e[i];
                       e[i+1]='x';
                   }*/
                   for(x=0;x<5;++x)
                   {
                       if(e[i+1]==key[j][x])
                       {cout<<key[j][(z+4)%5]<<key[j][(x+4)%5];flag=1;}
                       if(e[i+1]==key[x][z])
                        {cout<<key[(j+4)%5][z]<<key[(x+4)%5][z];flag=1;}

                   }
                   if(flag==0)
                   {
                       char t=e[i+1];
                       findc(t);
                        cout<<key[j][uni_y]<<key[uni_x][z];

                   }
               }
           }
       }
    }


}
int main()
{
char e[100],k[10];
int choice;
cout<<"Enter the key value: ";
cin>>k;
dup(k);
cout<<"\n1.Encrypt \n2.Decrypt \n";
cin>>choice;
switch(choice)
{
case 1: cout<<"Enter the Plain text:";
cin>>e;
encrypt(e);
break;
case 2: cout<<"Enter the cipher text:";
cin>>e;
decrypt(e);
break;}
return 0;
}
