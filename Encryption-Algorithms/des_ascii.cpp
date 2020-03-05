#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int bina[70],index=0,binary[64],round3=1,round1=16;
int p[64];
int xor2[60],xor1[40];
int keyi[70],key[70],roun[60],rou[16][60];
char key_1[70];
char so[64];
int sod=0;
int per[67];
int sbox[40];
int permute[40];
int stp[]={16,7,20,21,29,12,28,17,
           1,15,23,26,5,18,31,10,
           2,8,24,14,32,27,3,9,
           19,13,30,6,22,11,4,25};
int s1[4][16]={14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
            0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
            4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
            15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13};
int s2[4][16]={15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
            3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
            0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
            13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9};
int s3[4][16]={10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
            13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
            13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
            1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12};
int s4[4][16]={7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
               13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
               10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
               3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14};
int s5[4][16]={2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
               14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
               4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
               11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3};
int s6[4][16]={12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
               10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
               9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
               4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13};
int s7[4][16]={4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
               13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
               1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
               6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12};
int s8[4][16]={13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
               1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
               7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
               2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11};
int comp_p[]={14,17,11,24,1,5,3,28,
              15,6,21,10,23,19,12,4,
              26,8,16,7,27,20,13,2,
              41,52,31,37,47,55,30,40,
              51,45,33,48,44,49,39,56,
              34,53,46,42,50,36,29,32};
int parity[]={57,49,41,33,25,17,9,01,
              58,50,42,34,26,18,10,02,
              59,51,43,35,27,19,11,03,
              60,52,44,36,63,55,47,39,
              31,23,15,07,62,54,46,38,
              30,22,14,06,61,53,45,37,
              29,21,13,05,28,20,12,04};
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
    if(a>0){
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
        else{
               int ch[10];
                /*int dup[10];
        char w[10];
        int in=0;*/
                a=a+256;
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

   /*while(a/2!=1)
    {
        ch[i++]=a%2;
        a=a/2;
    }
    ch[i++]=a%2;
    ch[i++]=a/2;
    for(j=i;j<=7;++j)
        ch[j]=0;
    for(j=7;j>=0;--j)
        dup[in++]=ch[j];
        for(i=0;i<in;++i)
        {
            if(dup[i]==1)
                w[i]='1';
            else
                w[i]='0';
        }
        w[i]='\0';
        printOneAndTwosComplement(w);*/        }



}
void bin(char p[10])
{
    int b,i;
    for(i=0;i<strlen(p);++i)
    {

    cout<<int(p[i])<<"\n";
        binar(int(p[i]));

    }
}
void expansion()
{
    int i,z,j,k;
    k=32;
    for(i=0;i<48;i=i+6)
    {
        z=i;
        for(j=k;j<k+4;++j)
        {
            p[++z]=binary[j];
        }
        if(i==0)
            p[i]=binary[63];
        else
            p[i]=binary[k-1];
        if(i==42)
            p[47]=binary[32];
        else
            p[++z]=binary[j];
        k=k+4;

    }
    cout<<"\n Expansion P-box: \n";
    for(i=0;i<48;++i)
        cout<<p[i];
}
void key_generation()
{
    int i=0,j,z=0,round2=1;
    for(z=0;z<16;++z){
    if(round2==1)
    {
        index=0;
    bin(key_1);
    for(i=0;i<64;++i)
    {
        if((i+1)%8==0){}
        else
        {
            if(bina[i]==1)
            {
                for(j=0;j<56;++j)
                {
                    if(parity[j]==i+1)
                    {
                        keyi[j]=1;
                    }
                }
            }
        }

    }}
    else{
            for(i=0;i<56;++i)
            keyi[i]=key[i];

    }

    if(round2==1 || round2==2 || round2==9 || round2==16 )
    {
        for(i=1;i<28;++i)
        {
            key[i-1]=keyi[i];
        }
        key[27]=keyi[0];
        for(i=29;i<56;++i)
        {
            key[i-1]=keyi[i];
        }
        key[55]=keyi[28];
    }
    else
    {
        for(i=2;i<28;++i)
        {
            key[i-2]=keyi[i];
        }
        key[27]=keyi[1];
        key[26]=keyi[0];
        for(i=30;i<56;++i)
        {
            key[i-2]=keyi[i];
        }
        key[55]=keyi[29];
        key[54]=keyi[28];
    }
    //for(i=0;i<48;++i)
      //  roun[i]=0;
    for(i=0;i<56;++i)
    {
        if(i==8 || i==17 || i==21 || i==24 || i==34 || i==37 || i==42 || i==53 ){}
        else
        {
            if(key[i]==1)
        {
            for(j=0;j<48;++j)
            {
                if(comp_p[j]==i+1)
                    {
                        rou[z][j]=1;
                    }
            }
        }
        }
    }
    round2=round2+1;}


}
void hex(int per[67])
{
    int i,j;
    for(i=0;i<64;i=i+8)
    {
        int k=0,sum=0;
         for(j=i+7;j>=i;--j)
         {
             if(per[j]==1)
            {
               // cout<<sum<<j<<" ";
                sum= sum+pow(2,k);}
            ++k;
         }
         //cout<<sum;
         cout<<char(sum);
         so[sod++]=char(sum);
    }
    so[sod]='\0';
}
void xorop()
{
    int i;
   for(i=0;i<48;++i)
   {
       if(p[i]==roun[i])
        xor2[i]=0;
       else
        xor2[i]=1;
   }
   cout<<"\nKey XOR Expansion:\n";
   for(i=0;i<48;++i)
    cout<<xor2[i];
}
void xorop1()
{
    int i;
   for(i=0;i<32;++i)
   {
       if(permute[i]==binary[i])
        xor1[i]=0;
       else
        xor1[i]=1;
   }
   cout<<"\n Left XOR Permute:\n";
   for(i=0;i<32;++i)
    cout<<xor1[i];
}
void next1()
{
    int b[70],i;
    if(round1!=1){
    for(i=0;i<32;++i)
        b[i]=binary[32+i];
    for(i=32;i<64;++i)
        b[i]=xor1[i-32];
    for(i=0;i<64;++i)
        binary[i]=b[i];
        cout<<"\n Round "<<round1<<" :\n";
        for(i=0;i<64;++i)
            cout<<binary[i];
            cout<<"\n\n\n";}
            else
            {
             for(i=0;i<32;++i)
        b[i]=xor1[i];
    for(i=32;i<64;++i)
        b[i]=binary[i];
    for(i=0;i<64;++i)
        binary[i]=b[i];
        cout<<"\n Round "<<round1<<" :\n";
        for(i=0;i<64;++i)
            cout<<binary[i];
            cout<<"\n\n\n";
            }
}
void next()
{
    int b[70],i;
    if(round3!=16){
    for(i=0;i<32;++i)
        b[i]=binary[32+i];
    for(i=32;i<64;++i)
        b[i]=xor1[i-32];
    for(i=0;i<64;++i)
        binary[i]=b[i];
        cout<<"\n Round "<<round3<<" :\n";
        for(i=0;i<64;++i)
            cout<<binary[i];
            cout<<"\n\n\n";}
            else
            {
             for(i=0;i<32;++i)
        b[i]=xor1[i];
    for(i=32;i<64;++i)
        b[i]=binary[i];
    for(i=0;i<64;++i)
        binary[i]=b[i];
        cout<<"\n Round "<<round3<<" :\n";
        for(i=0;i<64;++i)
            cout<<binary[i];
            cout<<"\n\n\n";
            }
}
int s_index=0;
void decimal(int value)
{
        switch(value)
        {
            case 0:sbox[s_index++]=0;
            sbox[s_index++]=0;
            sbox[s_index++]=0;
            sbox[s_index++]=0;
            break;
            case 1:sbox[s_index++]=0;
            sbox[s_index++]=0;
            sbox[s_index++]=0;
            sbox[s_index++]=1;
            break;
            case 2:sbox[s_index++]=0;
            sbox[s_index++]=0;
            sbox[s_index++]=1;
            sbox[s_index++]=0;
            break;
            case 3:sbox[s_index++]=0;
            sbox[s_index++]=0;
            sbox[s_index++]=1;
            sbox[s_index++]=1;
            break;
            case 4:sbox[s_index++]=0;
            sbox[s_index++]=1;
            sbox[s_index++]=0;
            sbox[s_index++]=0;
            break;
            case 5:sbox[s_index++]=0;
            sbox[s_index++]=1;
            sbox[s_index++]=0;
            sbox[s_index++]=1;
            break;
            case 6:sbox[s_index++]=0;
            sbox[s_index++]=1;
            sbox[s_index++]=1;
            sbox[s_index++]=0;
            break;
            case 7:sbox[s_index++]=0;
            sbox[s_index++]=1;
            sbox[s_index++]=1;
            sbox[s_index++]=1;
            break;
            case 8:sbox[s_index++]=1;
            sbox[s_index++]=0;
            sbox[s_index++]=0;
            sbox[s_index++]=0;
            break;
            case 9:sbox[s_index++]=1;
            sbox[s_index++]=0;
            sbox[s_index++]=0;
            sbox[s_index++]=1;
            break;
            case 10:sbox[s_index++]=1;
            sbox[s_index++]=0;
            sbox[s_index++]=1;
            sbox[s_index++]=0;
            break;
            case 11:sbox[s_index++]=1;
            sbox[s_index++]=0;
            sbox[s_index++]=1;
            sbox[s_index++]=1;
            break;
            case 12:sbox[s_index++]=1;
            sbox[s_index++]=1;
            sbox[s_index++]=0;
            sbox[s_index++]=0;
            break;
            case 13:sbox[s_index++]=1;
            sbox[s_index++]=1;
            sbox[s_index++]=0;
            sbox[s_index++]=1;
            break;
            case 14:sbox[s_index++]=1;
            sbox[s_index++]=1;
            sbox[s_index++]=1;
            sbox[s_index++]=0;
            break;
            case 15:sbox[s_index++]=1;
            sbox[s_index++]=1;
            sbox[s_index++]=1;
            sbox[s_index++]=1;
            break;

        }

}
void sboxes()
{
    int i,sum1,sum2,val;

i=0;
        sum1=(xor2[i]*2)+(xor2[i+5]*1);
        sum2=(xor2[i+1]*8)+(xor2[i+2]*4)+(xor2[i+3]*2)+(xor2[i+4]*1);
        val=s1[sum1][sum2];
        decimal(val);
i=6;
        sum1=(xor2[i]*2)+(xor2[i+5]*1);
        sum2=(xor2[i+1]*8)+(xor2[i+2]*4)+(xor2[i+3]*2)+(xor2[i+4]*1);
        val=s2[sum1][sum2];
        decimal(val);
i=12;
        sum1=(xor2[i]*2)+(xor2[i+5]*1);
        sum2=(xor2[i+1]*8)+(xor2[i+2]*4)+(xor2[i+3]*2)+(xor2[i+4]*1);
        val=s3[sum1][sum2];
        decimal(val);
i=18;
        sum1=(xor2[i]*2)+(xor2[i+5]*1);
        sum2=(xor2[i+1]*8)+(xor2[i+2]*4)+(xor2[i+3]*2)+(xor2[i+4]*1);
        val=s4[sum1][sum2];
        decimal(val);
i=24;
        sum1=(xor2[i]*2)+(xor2[i+5]*1);
        sum2=(xor2[i+1]*8)+(xor2[i+2]*4)+(xor2[i+3]*2)+(xor2[i+4]*1);
        val=s5[sum1][sum2];
        decimal(val);
i=30;
        sum1=(xor2[i]*2)+(xor2[i+5]*1);
        sum2=(xor2[i+1]*8)+(xor2[i+2]*4)+(xor2[i+3]*2)+(xor2[i+4]*1);
        val=s6[sum1][sum2];
        decimal(val);
i=36;
        sum1=(xor2[i]*2)+(xor2[i+5]*1);
        sum2=(xor2[i+1]*8)+(xor2[i+2]*4)+(xor2[i+3]*2)+(xor2[i+4]*1);
        val=s7[sum1][sum2];
        decimal(val);
i=42;
        sum1=(xor2[i]*2)+(xor2[i+5]*1);
        sum2=(xor2[i+1]*8)+(xor2[i+2]*4)+(xor2[i+3]*2)+(xor2[i+4]*1);
        val=s8[sum1][sum2];
        decimal(val);

    cout<<"\n Sbox:\n";
    for(i=0;i<32;++i)
        cout<<sbox[i];
    }
void straightp()
{
    int i,j;
    for(i=0;i<32;++i)
        permute[i]=0;
    for(i=0;i<32;++i)
    {
        if(sbox[i]==1)
        {
            for(j=0;j<32;++j)
            {
                if(stp[j]==i+1)
                    {
                        permute[j]=1;
                    }
            }
        }
    }
    cout<<"\n Straight Permutation:\n";
    for(i=0;i<32;++i)
        cout<<permute[i];
}
void initpermute()
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
    cout<<"\nInitial Permutation :\n";
    for(i=0;i<64;++i)
        {
            if(i==32)
            cout<<"\n";
        cout<<binary[i];

        }
}
void encrypt()
{
    int j;
    if(round3==1)
    initpermute();
            expansion();
if(round3==1)
    key_generation();
cout<<"\n Generated key for round "<<round3<<":\n";

        for(j=0;j<48;++j)
            roun[j]=rou[round3-1][j];
        for(j=0;j<48;++j)
        cout<<roun[j];
            xorop();
            s_index=0;
            sboxes();
            straightp();
            xorop1();
            next();
}

void finalpermute()
{
    int i,j;
    for(i=0;i<64;++i)
    {
        if(binary[i]==1)
        {
            for(j=0;j<64;++j)
            {
                if(fin[j]==i+1)
                    {
                        per[j]=1;
                    }
            }
        }
    }
    cout<<"\n Final Permutation:\n";
    //for(i=0;i<64;++i)
      //  cout<<per[i];
    hex(per);
}
void decrypt()
{
    int j,i,b[70];
  if(round1==16)
    {
        initpermute();
    }
            expansion();
//if(round1==16)
//key_generation();
cout<<"\n Generated key for round "<<round1<<":\n";
        for(j=0;j<48;++j)
            roun[j]=rou[round1-1][j];
        for(j=0;j<48;++j)
        cout<<roun[j];
            xorop();
            s_index=0;
            sboxes();
            straightp();
            xorop1();
            next1();
}

int main()
{

    int choice,i,dec,j,b[70],k1,l;
    char p[10];
    cout<<"\n1.Encryption \n2.Decryption";

        cout<<"\n Enter the text for Encryption: ";
        cin>>p;
        cout<<"\n Enter the key:";
            cin>>key_1;
       l=strlen(p);
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
            dec=0;


        for(k1=0;k1<16;++k1)
        {

            encrypt();
            round3++;
        }}
        finalpermute();
        cout<<so<<strlen(so);
        //hex();

        //for(i=0;i<16-strlen(p);++i)
          //  strcat(p,"0");
       l=strlen(so);
       // for(i=0;i<8-(strlen(so)%8);++i)
         //   strcat(so,"0");
        for(j=0;j<l;j=j+8)
        {
            index=0;
            for(i=0;i<64;++i)
                {bina[i]=0;
                binary[i]=0;
                //p[i]=0;
               }
               for(i=0;i<40;++i)
               {
                   xor1[i]=0;
                   sbox[i]=0;
                   permute[i]=0;
               }
               for(i=0;i<67;++i)
                per[i]=0;
               for(i=0;i<60;++i)
                xor2[i]=0;
            char ch[10];
            int k=0;
            for(i=j;i<(j+8);++i)
                ch[k++]=so[i];
            ch[k]='\0';
            cout<<ch;
            bin(ch);

        for(i=0;i<64;++i)
            cout<<bina[i];
            cout<<"\n";
            dec=1;


        for(k1=0;k1<16;++k1)
        {

            decrypt();
            round1--;
        }}

        finalpermute();

    return 0;
}
