#include<iostream>
using namespace std;
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#include <sstream>
#include <bitset>
int key[16][130],round1=0;
char hex1[40];
int h=0;
int cipher[10][130];
string mix2[4][4];
string rconst[10]={"00000001000000000000000000000000","00000010000000000000000000000000","00000100000000000000000000000000","00001000000000000000000000000000","00010000000000000000000000000000",
                   "00100000000000000000000000000000","01000000000000000000000000000000","10000000000000000000000000000000","00011011000000000000000000000000","00110110000000000000000000000000"};
string sbox[16][16]={"63","7c","77","7b","f2","6b","6f","c5","30","01","67","2b","fe","d7","ab","76",
                     "ca","82","c9","7d","fa","59","47","f0","ad","d4","a2","af","9c","a4","72","c0",
                     "b7","fd","93","26","36","3f","f7","cc","34","a5","e5","f1","71","d8","31","15",
                     "04","c7","23","c3","18","96","05","9a","07","12","80","e2","eb","27","b2","75",
                     "09","83","2c","1a","1b","6e","5a","a0","52","3b","d6","b3","29","e3","2f","84",
                     "53","d1","00","ed","20","fc","b1","5b","6a","cb","be","39","4a","4c","58","cf",
                     "d0","ef","aa","fb","43","4d","33","85","45","f9","02","7f","50","3c","9f","a8",
                     "51","a3","40","8f","92","9d","38","f5","bc","b6","da","21","10","ff","f3","d2",
                     "cd","0c","13","ec","5f","97","44","17","c4","a7","7e","3d","64","5d","19","73",
                     "60","81","4f","dc","22","2a","90","88","46","ee","b8","14","de","5e","ob","db",
                     "e0","32","3a","0a","49","06","24","5c","c2","d3","ac","62","91","95","e4","79",
                     "e7","c8","37","6d","8d","d5","4e","a9","6c","56","f4","ea","65","7a","ae","08",
                     "ba","78","25","2e","1c","a6","b4","c6","e8","dd","74","1f","4b","bd","8b","8a",
                     "70","3e","b5","66","48","03","f6","0e","61","35","57","b9","86","c1","1d","9e",
                     "e1","f8","98","11","69","d9","8e","94","9b","1e","87","e9","ce","55","28","df",
                     "8c","a1","89","0d","bf","e6","42","68","41","99","2d","0f","b0","54","bb","16"};
void ascii_to_bin(char c[20],int r)
{
    int temp[130],count1=0,i,x;
    for(i=0;i<16;++i)
    {
        int t[10],j=0;
        int a=(int)c[i];
        //a=a-97;

        while(a/2!=1 && a!=0)
        {
            t[j++]=a%2;
            a=a/2;
        }
        t[j++]=a%2;
        t[j++]=a/2;

        for(x=j;x<=7;++x)
            t[x]=0;
        for(x=7;x>=0;--x)
            temp[count1++]=t[x];
    }

    for(i=0;i<128;++i)
        {
            key[r][i]=temp[i];
        }
}
void bin_to_hex(int temp[130],int c)
{
    int i;
    h=0;
    for(i=0;i<10;++i)
        hex1[i]='\0';
for(i=0;i<c;i=i+4)
{
    if(temp[i]==0 && temp[i+1]==0 && temp[i+2]==0 && temp[i+3]==0)
        hex1[h++]='0';
    else if(temp[i]==0 && temp[i+1]==0 && temp[i+2]==0 && temp[i+3]==1)
        hex1[h++]='1';
    else if(temp[i]==0 && temp[i+1]==0 && temp[i+2]==1 && temp[i+3]==0)
        hex1[h++]='2';
    else if(temp[i]==0 && temp[i+1]==0 && temp[i+2]==1 && temp[i+3]==1)
        hex1[h++]='3';
    else if(temp[i]==0 && temp[i+1]==1 && temp[i+2]==0 && temp[i+3]==0)
        hex1[h++]='4';
    else if(temp[i]==0 && temp[i+1]==1 && temp[i+2]==0 && temp[i+3]==1)
        hex1[h++]='5';
    else if(temp[i]==0 && temp[i+1]==1 && temp[i+2]==1 && temp[i+3]==0)
        hex1[h++]='6';
    else if(temp[i]==0 && temp[i+1]==1 && temp[i+2]==1 && temp[i+3]==1)
        hex1[h++]='7';
    else if(temp[i]==1 && temp[i+1]==0 && temp[i+2]==0 && temp[i+3]==0)
        hex1[h++]='8';
    else if(temp[i]==1 && temp[i+1]==0 && temp[i+2]==0 && temp[i+3]==1)
        hex1[h++]='9';
    else if(temp[i]==1 && temp[i+1]==0 && temp[i+2]==1 && temp[i+3]==0)
        hex1[h++]='a';
    else if(temp[i]==1 && temp[i+1]==0 && temp[i+2]==1 && temp[i+3]==1)
        hex1[h++]='b';
    else if(temp[i]==1 && temp[i+1]==1 && temp[i+2]==0 && temp[i+3]==0)
        hex1[h++]='c';
    else if(temp[i]==1 && temp[i+1]==1 && temp[i+2]==0 && temp[i+3]==1)
        hex1[h++]='d';
    else if(temp[i]==1 && temp[i+1]==1 && temp[i+2]==1 && temp[i+3]==0)
        hex1[h++]='e';
      else
        hex1[h++]='f';

}
hex1[h]='\0';
}
int bin[40],c3=0;
void hex_to_bin(string s[10])
{
    int i,j;
    c3=0;
    for(i=0;i<40;++i)
        bin[i]=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<2;++j)
        {
            if(s[i][j]=='0')
            {
                bin[c3++]=0;
                bin[c3++]=0;
                bin[c3++]=0;
                bin[c3++]=0;
            }
            else if(s[i][j]=='1')
            {
                bin[c3++]=0;
                bin[c3++]=0;
                bin[c3++]=0;
                bin[c3++]=1;
            }
            else if(s[i][j]=='2')
            {
                bin[c3++]=0;
                bin[c3++]=0;
                bin[c3++]=1;
                bin[c3++]=0;
            }
            else if(s[i][j]=='3')
            {
                bin[c3++]=0;
                bin[c3++]=0;
                bin[c3++]=1;
                bin[c3++]=1;
            }
            else if(s[i][j]=='4')
            {
                bin[c3++]=0;
                bin[c3++]=1;
                bin[c3++]=0;
                bin[c3++]=0;
            }
            else if(s[i][j]=='5')
            {
                bin[c3++]=0;
                bin[c3++]=1;
                bin[c3++]=0;
                bin[c3++]=1;
            }
            else if(s[i][j]=='6')
            {
                bin[c3++]=0;
                bin[c3++]=1;
                bin[c3++]=1;
                bin[c3++]=0;
            }
            else if(s[i][j]=='7')
            {
                bin[c3++]=0;
                bin[c3++]=1;
                bin[c3++]=1;
                bin[c3++]=1;
            }
            else if(s[i][j]=='8')
            {
                bin[c3++]=1;
                bin[c3++]=0;
                bin[c3++]=0;
                bin[c3++]=0;
            }
            else if(s[i][j]=='9')
            {
                bin[c3++]=1;
                bin[c3++]=0;
                bin[c3++]=0;
                bin[c3++]=1;
            }
            else if(s[i][j]=='a')
            {
                bin[c3++]=1;
                bin[c3++]=0;
                bin[c3++]=1;
                bin[c3++]=0;
            }
            else if(s[i][j]=='b')
            {
                bin[c3++]=1;
                bin[c3++]=0;
                bin[c3++]=1;
                bin[c3++]=1;
            }
            else if(s[i][j]=='c')
            {
                bin[c3++]=1;
                bin[c3++]=1;
                bin[c3++]=0;
                bin[c3++]=0;
            }
            else if(s[i][j]=='d')
            {
                bin[c3++]=1;
                bin[c3++]=1;
                bin[c3++]=0;
                bin[c3++]=1;
            }
            else if(s[i][j]=='e')
            {
                bin[c3++]=1;
                bin[c3++]=1;
                bin[c3++]=1;
                bin[c3++]=0;
            }
            else
            {
                bin[c3++]=1;
                bin[c3++]=1;
                bin[c3++]=1;
                bin[c3++]=1;
            }

        }
    }

}
int mult[40],cm=0;
void multiply(int b[40],int v)
{
    int temp[40],ci=0,i;
    cm=0;
    for(i=0;i<32;++i)
        mult[i]=0;
    for(i=0;i<32;++i)
    {
        if(rconst[v-1][i]=='0')
            temp[ci++]=0;
        else
            temp[ci++]=1;
    }
    for(i=0;i<32;++i)
    {
        if(temp[i]==b[i])
            mult[cm++]=0;
        else
            mult[cm++]=1;
    }

}
void key_generation(char c[20])
{
    ascii_to_bin(c,0);
    int i,j;
    cout<<"Pre Round Key: ";
    for(i=0;i<128;++i)
    {
        cout<<key[0][i];
        if(i%8==7)
            cout<<"  ";
    }
    int temp[130],co=0,c1=0,t1,t2;
    string sub[10];
   for(i=1;i<11;++i)
    {
        cout<<"\n\n Round "<<i<<"\n";
        co=0;
        h=0;
        /*for(j=0;j<128;++j)
        {
            temp[j]=0;
            hex[j]='\0';
        }*/
        for(j=96;j<=127;++j)
            temp[co++]=key[i-1][j];
        int temp1[40],c2=0;
        for(j=8;j<32;++j)
            temp1[c2++]=temp[j];
        for(j=0;j<8;++j)
            temp1[c2++]=temp[j];
        cout<<"\n Shift :\n";
        for(j=0;j<32;++j)
            cout<<temp1[j];
        cout<<"\n";
        bin_to_hex(temp1,32);
        //for(j=0;j<8;++j)
            //cout<<hex1[j];
c1=0;
        for(j=0;j<8;j=j+2)
        {
            if(isdigit(hex1[j]))
                t1=(int)hex1[j]-48;
            else
                t1=(int)hex1[j]-87;
            if(isdigit(hex1[j+1]))
                t2=(int)hex1[j+1]-48;
            else
                t2=(int)hex1[j+1]-87;
            //cout<<"\n"<<t1<<"\n"<<t2;
            sub[c1++]=sbox[t1][t2];
            //cout<<sub[c1-1]<<" ";
        }
        hex_to_bin(sub);
        cout<<"\n Substitution :";
       for(j=0;j<32;++j)
        cout<<bin[j];
       cout<<"\n";
       multiply(bin,i);
       cout<<"\n XOR :";
       for(j=0;j<32;++j)
        {
            cout<<mult[j];
            if(mult[j]==key[i-1][j])
                key[i][j]=0;
            else
                key[i][j]=1;
        }
        cout<<"\n\n";
        for(j=32;j<128;++j)
        {
            if(key[i][j-32]==key[i-1][j])
                key[i][j]=0;
            else
                key[i][j]=1;
        }
        cout<<"\n Key "<<i<<"\n";
        for(j=0;j<128;++j)
            cout<<key[i][j];
        cout<<"\n\n";



    }
}
int hexadecimalToDecimal(string hexVal)
{
    int len = hexVal.length();
    int base = 1;
    int dec_val = 0;
    for (int i=len-1; i>=0; i--)
    {
        if (hexVal[i]>='0' && hexVal[i]<='9')
        {
            dec_val += (hexVal[i] - 48)*base;
            base = base * 16;
        }
        else if (hexVal[i]>='a' && hexVal[i]<='f')
        {
            dec_val += (hexVal[i] - 85)*base;
            base = base*16;
        }
    }

    return dec_val;
}
void bin_ascii(int cipher[128])
{
	string s="";
	int i;
	for(i=0;i<128;++i)
	{
		if(cipher[i]==1)
		s=s+"1";
		else
		s=s+"0";
		
		
	}
	std::string data = s;
    std::stringstream sstream(data);
    std::string output;
    while(sstream.good())
    {
        std::bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        output += c;
    }

    std::cout << output;
}
void decToHexa(int n ,char hexaDeciNum[100])
{
    //char hexaDeciNum[100];
    int i = 0;
    while(n!=0)
    {
        int temp  = 0;
        temp = n % 16;
        if(temp < 10)
        {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else
        {
            hexaDeciNum[i] = temp + 87;
            i++;
        }
        n = n/16;
    }
   //for(int j=i-1; j>=0; j--)
        //cout << hexaDeciNum[j];
        //return hexaDeciNum;
}

void hexadecimaltobinary(string hexad,int b[20])
{
    //string b;
    int i=0;
    int j=0;
    //cout<<"\n";
    //cout<<hexad;
    //cout<<"\n";
    //cout<<hexad[0];
for(i=0;i<2;++i)
        {
             if(hexad[i]=='0')
                       { b[j++]=0;
                        b[j++]= 0;
                        b[j++]=0;
                        b[j++]=0;}

                       if(hexad[i]=='1')
                       { b[j++]=0;
                        b[j++]= 0;
                        b[j++]=0;
                        b[j++]=1;}
                        if(hexad[i]=='2')
                       { b[j++]=0;
                        b[j++]= 0;
                        b[j++]=1;
                        b[j++]=0;}
                        if(hexad[i]=='3')
                       { b[j++]=0;
                        b[j++]= 0;
                        b[j++]=1;
                        b[j++]=1;}
                        if(hexad[i]=='4')
                       { b[j++]=0;
                        b[j++]= 1;
                        b[j++]=0;
                        b[j++]=0;}
                        if(hexad[i]=='5')
                       { b[j++]=0;
                        b[j++]= 1;
                        b[j++]=0;
                        b[j++]=1;}
                        if(hexad[i]=='6')
                       { b[j++]=0;
                        b[j++]= 1;
                        b[j++]=1;
                        b[j++]=0;}
                        if(hexad[i]=='7')
                       { b[j++]=0;
                        b[j++]= 1;
                        b[j++]=1;
                        b[j++]=1;}
                        if(hexad[i]=='8')
                       { b[j++]=1;
                        b[j++]= 0;
                        b[j++]=0;
                        b[j++]=0;}
                        if(hexad[i]=='9')
                       { b[j++]=1;
                        b[j++]= 0;
                        b[j++]=0;
                        b[j++]=1;}
                       if(hexad[i]=='a')
                       { b[j++]=1;
                        b[j++]= 0;
                        b[j++]=1;
                        b[j++]=0;}
                        if(hexad[i]=='b')
                       { b[j++]=1;
                        b[j++]= 0;
                        b[j++]=1;
                        b[j++]=1;}
                        if(hexad[i]=='c')
                       { b[j++]=1;
                        b[j++]= 1;
                        b[j++]=0;
                        b[j++]=0;}
                        if(hexad[i]=='d')
                       { b[j++]=1;
                        b[j++]= 1;
                        b[j++]=0;
                        b[j++]=1;}
                        if(hexad[i]=='e')
                       { b[j++]=1;
                        b[j++]= 1;
                        b[j++]=1;
                        b[j++]=0;}
                       if(hexad[i]=='f')
                       { b[j++]=1;
                        b[j++]= 1;
                        b[j++]=1;
                        b[j++]=1;}



        }
        //cout<<"hello";
        b[j]='\0';
        //b1=b;
        //for(i=0;i<j;++i)
   //cout<<b;
}


void xorop(string s,string mix1,char xor1[20])
{
    int i;
    for(i=0;i<mix1.length();++i)
    {
        if(s[i]==mix1[i])
          xor1[i]='0';
        else
            xor1[i]='1';
    }
    xor1[i]='\0';
}
int ptxt[10][128];
void decrypt(int p[128])
{
int i,j,k,l,j1;
    for(i=0;i<128;++i)
    cout<<p[i];
    cout<<"\n Pre-Round Output: ";
    for(i=0;i<128;++i)
    {
        if(p[i]==key[10][i])
           ptxt[10][i]=0;
        else
            ptxt[10][i]=1;
    }
    for(i=0;i<128;++i)
        cout<<ptxt[10][i];
		
		
	
for(i=9;i>=0;--i)
{	

for(j=0;j<4;++j)
    for(k=0;k<4;++k)
    mix2[j][k]="\0";
        int temp1[130],c2=0;
        cout<<"\n\n Round "<<i<<"\n";
        for(j=0;j<128;++j)
            temp1[j]=cipher[i+1][j];
        bin_to_hex(temp1,128);
        cout<<"\n binary to hexadecimal conversion: ";
        cout<<hex1;
        cout<<"\n";
        cout<<"\n substitution: ";
int c1=0,t1,t2;
string sub[40];
        for(j=0;j<h;j=j+2)
        {
            if(isdigit(hex1[j]))
                t1=(int)hex1[j]-48;
            else
                t1=(int)hex1[j]-87;
            if(isdigit(hex1[j+1]))
                t2=(int)hex1[j+1]-48;
            else
                t2=(int)hex1[j+1]-87;
            //cout<<"\n"<<t1<<"\n"<<t2;
            sub[c1++]=sbox[t1][t2];
            cout<<sub[c1-1]<<" ";
        }
        cout<<"\n";
        string xw1,xw2,xw3,xw4;

string mat[4][4];
mat[0][0]=sub[0];
mat[0][1]=sub[4];
mat[0][2]=sub[8];
mat[0][3]=sub[12];
mat[1][0]=sub[1];
mat[1][1]=sub[5];
mat[1][2]=sub[9];
mat[1][3]=sub[13];
mat[2][0]=sub[2];
mat[2][1]=sub[6];
mat[2][2]=sub[10];
mat[2][3]=sub[14];
mat[3][0]=sub[3];
mat[3][1]=sub[7];
mat[3][2]=sub[11];
mat[3][3]=sub[15];
cout<<"\n Shift rows:\n";
for(int i1=0;i1<4;++i1)
    {for(int i2=0;i2<4;++i2)
    cout<<mat[i1][i2]<<" ";
    cout<<"\n";}
    
xw1=mat[0][0]+mat[1][0]+mat[2][0]+mat[3][0];
xw2=mat[0][1]+mat[1][1]+mat[2][1]+mat[3][1];
xw3=mat[0][2]+mat[1][2]+mat[2][2]+mat[3][2];
xw4=mat[0][3]+mat[1][3]+mat[2][3]+mat[3][3];

cout<<"\n";
cout<<"\n Add round key :";
for(int j1=0;j1<128;j1=j1+1)
{

        char a2=key[i][j1]+48;
    if(j1>=0 && j1<=31)
    {
        char a1=xw1[j1];
        
        if(a1==a2)
           {

               ptxt[i][j1]=0;

           }
        else
            {
                ptxt[i][j1]=1;}
    }
    else if(j1>=32 && j1<=63)
    {
        char a1=xw2[j1-32];
        if(i==10)
        {
        	
        	//cout<<j1;
        	//cout<<"\n"<<j1<<a1<<a2;
		}
        if(a1==a2)
            ptxt[i][j1]=0;
        else
            ptxt[i][j1]=1;
    }
    else if(j1>=64 && j1<=95)
    {
        char a1=xw3[j1-64];
        if(a1==a2)
            ptxt[i][j1]=0;
        else
            ptxt[i][j1]=1;
    }
    else if(j1>=96 && j1<=127)
    {
        char a1=xw4[j1-96];
        if(a1==a2)
            ptxt[i][j1]=0;
        else
            ptxt[i][j1]=1;
    }
}
//cout<<mat[0][2];
if(i!=0){
	cout<<"\n Mix Columns:";
string mix[16][16];
string m[4][4]={"02","03","01","01",
             "01","02","03","01",
             "01","01","02","03",
             "03","01","01","02"};
for(j=0;j<4;j++)
{
    //cout<<"hello";
for(k=0;k<4;k++)
{
mix2[j][k]="00000000";
for(l=0;l<4;l++)
{
    //cout<<"lll";
//mul[i][j]+=a[i][k]*b[k][j];
//cout<<j<<"  "<<l;
string a=mat[l][k];
int b[10];
int nb[8],nb1[8];
string mix1="";
            string s=m[j][l];
            //cout<<s<<" "<<a;
            if (s=="02")
                {
                    //cout<<a;
                    hexadecimaltobinary(a,b);
                    for(int i1=0;i1<7;++i1)
                    {
                    	//cout<<b[i1];
                        nb[i1]=b[i1+1];
                        //cout<<nb[i1];
                    }
                    nb[7]=0;
                    if(b[0]==1)
                    {
                    	//cout<<"op";
                    	//cout<<b[0]<<" "<<a<<" "<<k<<" "<<l<<"\n";
                    	for(int i1=0;i1<8;++i1)
                    	{
                    		if(i1==0 || i1==1 ||i1==2 ||i1==5)
						       nb1[i1]=nb[i1];
						    else
						    {
						    	if(nb[i1]==0)
						    	nb1[i1]=1;
						    	else
						    	nb1[i1]=0;
							}
                    	
                        }
                        for(int i1=0;i1<8;++i1)
					nb[i1]=nb1[i1];
					}
					

//for(int i1=0;i1<8;++i1)
					//cout<<nb[i1];					
                }
            else if(s=="03")
            {
                hexadecimaltobinary(a,b);
                
                for(int i1=0;i1<7;++i1)
                    {
                    	//cout<<b[i1];
                         nb[i1]=b[i1+1];
                    }
                    nb[7]=0;
                    if(b[0]==1)
                    {
                    	         //cout<<"op";           	//cout<<a<<" "<<k<<" "<<l<<"\n";

                    	for(int i1=0;i1<8;++i1)
                    	{
                    		if(i1==0 || i1==1 ||i1==2 ||i1==5)
						       nb1[i1]=nb[i1];
						    else
						    {
						    	if(nb[i1]==0)
						    	nb1[i1]=1;
						    	else
						    	nb1[i1]=0;
							}
                    	
                        }
                        for(int i1=0;i1<8;++i1)
					nb[i1]=nb1[i1];
					}
					
                    for(int i1=0;i1<8;++i1)
                    {
                         if(nb[i1]==b[i1])
                            nb[i1]=0;
                         else
                            nb[i1]=1;
                    }
                    //for(int i1=0;i1<8;++i1)
					//cout<<nb[i1];	
                    
           }
           else
            hexadecimaltobinary(a,b);
           if(s=="02"|| s=="03")
           {
               for(int i1=0;i1<8;++i1)
               {
                   if(nb[i1]==0)
                    mix1=mix1+"0";
                   else
                    mix1=mix1+"1";
               }
               //cout<<mix1;
           }
           else
           {
               for(int i1=0;i1<8;++i1)
               {
                   if(b[i1]==0)
                    mix1=mix1+"0";
                   else
                    mix1=mix1+"1";
               }
           }
           //if(s=="01")
//cout<<mix1<<" ";
            char xor1[20];
            //string xoro;
            xorop(mix2[j][k],mix1,xor1);
            mix2[j][k]=xor1;
}
//cout<<"\n";
//cout<<mix2[j][k]<<"  ";
}
}
for(int i1=0;i1<4;++i1)
{
	for(int i2=0;i2<4;++i2)
	cout<<mix2[i2][i1]<<" ";
}


//cout<<xw1<<"\n"<<xw2<<"\n"<<xw3<<"\n"<<xw4;


}



    for(int j1=0;j1<128;++j1)
     {
	 cout<<cipher[i][j1];
	 if(j1==127)
	 break;
}
if(i==0)
{
	cout<<"\n";
	bin_ascii(ptxt[0]);
}


    }
	
	
	
	
	
	
	
	
	
}
void encrypt(int p[128])
{
    int i,j,k,l,j1;
    for(i=0;i<128;++i)
    cout<<p[i];
    cout<<"\n Pre-Round Output: ";
    for(i=0;i<128;++i)
    {
        if(p[i]==key[0][i])
            cipher[0][i]=0;
        else
            cipher[0][i]=1;
    }
    for(i=0;i<128;++i)
        cout<<cipher[0][i];
    for(i=1;i<11;++i)
    {
        if(i==11)
            exit(0);
for(j=0;j<4;++j)
    for(k=0;k<4;++k)
    mix2[j][k]="\0";
        int temp1[130],c2=0;
        cout<<"\n\n Round "<<i<<"\n";
        for(j=0;j<128;++j)
            temp1[j]=cipher[i-1][j];
        bin_to_hex(temp1,128);
        cout<<"\n binary to hexadecimal conversion: ";
        cout<<hex1;
        cout<<"\n";
        cout<<"\n substitution: ";
int c1=0,t1,t2;
string sub[40];
        for(j=0;j<h;j=j+2)
        {
            if(isdigit(hex1[j]))
                t1=(int)hex1[j]-48;
            else
                t1=(int)hex1[j]-87;
            if(isdigit(hex1[j+1]))
                t2=(int)hex1[j+1]-48;
            else
                t2=(int)hex1[j+1]-87;
            //cout<<"\n"<<t1<<"\n"<<t2;
            sub[c1++]=sbox[t1][t2];
            cout<<sub[c1-1]<<" ";
        }
        cout<<"\n";
        string xw1,xw2,xw3,xw4;

string mat[4][4];
mat[0][0]=sub[0];
mat[0][1]=sub[4];
mat[0][2]=sub[8];
mat[0][3]=sub[12];
mat[1][0]=sub[5];
mat[1][1]=sub[9];
mat[1][2]=sub[13];
mat[1][3]=sub[1];
mat[2][0]=sub[10];
mat[2][1]=sub[14];
mat[2][2]=sub[2];
mat[2][3]=sub[6];
mat[3][0]=sub[15];
mat[3][1]=sub[3];
mat[3][2]=sub[7];
mat[3][3]=sub[11];
cout<<"\n Shift rows:\n";
for(int i1=0;i1<4;++i1)
    {for(int i2=0;i2<4;++i2)
    cout<<mat[i1][i2]<<" ";
    cout<<"\n";}

//cout<<mat[0][2];
if(i!=10){
	cout<<"\n Mix Columns:";
string mix[16][16];
string m[4][4]={"02","03","01","01",
             "01","02","03","01",
             "01","01","02","03",
             "03","01","01","02"};
for(j=0;j<4;j++)
{
    //cout<<"hello";
for(k=0;k<4;k++)
{
mix2[j][k]="00000000";
for(l=0;l<4;l++)
{
    //cout<<"lll";
//mul[i][j]+=a[i][k]*b[k][j];
//cout<<j<<"  "<<l;
string a=mat[l][k];
int b[10];
int nb[8],nb1[8];
string mix1="";
            string s=m[j][l];
            //cout<<s<<" "<<a;
            if (s=="02")
                {
                    //cout<<a;
                    hexadecimaltobinary(a,b);
                    for(int i1=0;i1<7;++i1)
                    {
                    	//cout<<b[i1];
                        nb[i1]=b[i1+1];
                        //cout<<nb[i1];
                    }
                    nb[7]=0;
                    if(b[0]==1)
                    {
                    	//cout<<"op";
                    	//cout<<b[0]<<" "<<a<<" "<<k<<" "<<l<<"\n";
                    	for(int i1=0;i1<8;++i1)
                    	{
                    		if(i1==0 || i1==1 ||i1==2 ||i1==5)
						       nb1[i1]=nb[i1];
						    else
						    {
						    	if(nb[i1]==0)
						    	nb1[i1]=1;
						    	else
						    	nb1[i1]=0;
							}
                    	
                        }
                        for(int i1=0;i1<8;++i1)
					nb[i1]=nb1[i1];
					}
					

//for(int i1=0;i1<8;++i1)
					//cout<<nb[i1];					
                }
            else if(s=="03")
            {
                hexadecimaltobinary(a,b);
                
                for(int i1=0;i1<7;++i1)
                    {
                    	//cout<<b[i1];
                         nb[i1]=b[i1+1];
                    }
                    nb[7]=0;
                    if(b[0]==1)
                    {
                    	         //cout<<"op";           	//cout<<a<<" "<<k<<" "<<l<<"\n";

                    	for(int i1=0;i1<8;++i1)
                    	{
                    		if(i1==0 || i1==1 ||i1==2 ||i1==5)
						       nb1[i1]=nb[i1];
						    else
						    {
						    	if(nb[i1]==0)
						    	nb1[i1]=1;
						    	else
						    	nb1[i1]=0;
							}
                    	
                        }
                        for(int i1=0;i1<8;++i1)
					nb[i1]=nb1[i1];
					}
					
                    for(int i1=0;i1<8;++i1)
                    {
                         if(nb[i1]==b[i1])
                            nb[i1]=0;
                         else
                            nb[i1]=1;
                    }
                    //for(int i1=0;i1<8;++i1)
					//cout<<nb[i1];	
                    
           }
           else
            hexadecimaltobinary(a,b);
           if(s=="02"|| s=="03")
           {
               for(int i1=0;i1<8;++i1)
               {
                   if(nb[i1]==0)
                    mix1=mix1+"0";
                   else
                    mix1=mix1+"1";
               }
               //cout<<mix1;
           }
           else
           {
               for(int i1=0;i1<8;++i1)
               {
                   if(b[i1]==0)
                    mix1=mix1+"0";
                   else
                    mix1=mix1+"1";
               }
           }
           //if(s=="01")
//cout<<mix1<<" ";
            char xor1[20];
            //string xoro;
            xorop(mix2[j][k],mix1,xor1);
            mix2[j][k]=xor1;
}
//cout<<"\n";
//cout<<mix2[j][k]<<"  ";
}
}
for(int i1=0;i1<4;++i1)
{
	for(int i2=0;i2<4;++i2)
	cout<<mix2[i2][i1]<<" ";
}

xw1=mix2[0][0]+mix2[1][0]+mix2[2][0]+mix2[3][0];
xw2=mix2[0][1]+mix2[1][1]+mix2[2][1]+mix2[3][1];
xw3=mix2[0][2]+mix2[1][2]+mix2[2][2]+mix2[3][2];
xw4=mix2[0][3]+mix2[1][3]+mix2[2][3]+mix2[3][3];
//cout<<xw1<<"\n"<<xw2<<"\n"<<xw3<<"\n"<<xw4;


}
else
{
    string nmat[4][4]={"","","","","","","","","","","","","","","",""};
for(int i1=0;i1<4;++i1)
{
    int b[10];
    for(int i2=0;i2<4;++i2)
    {
        hexadecimaltobinary(mat[i1][i2],b);
        
        for(int i3=0;i3<8;++i3)
        {
            if(b[i3]==0)
                nmat[i1][i2]=nmat[i1][i2]+"0";
            else
                nmat[i1][i2]=nmat[i1][i2]+"1";
        }
    }
}

xw1=nmat[0][0]+nmat[1][0]+nmat[2][0]+nmat[3][0];
xw2=nmat[0][1]+nmat[1][1]+nmat[2][1]+nmat[3][1];
xw3=nmat[0][2]+nmat[1][2]+nmat[2][2]+nmat[3][2];
xw4=nmat[0][3]+nmat[1][3]+nmat[2][3]+nmat[3][3];
//cout<<xw1<<"\n"<<xw2<<"\n"<<xw3<<"\n"<<xw4;
}
cout<<"\n";
cout<<"\n Add round key :";
for(int j1=0;j1<128;j1=j1+1)
{

        char a2=key[i][j1]+48;
    if(j1>=0 && j1<=31)
    {
        char a1=xw1[j1];
        
        if(a1==a2)
           {

               cipher[i][j1]=0;

           }
        else
            {
                cipher[i][j1]=1;}
    }
    else if(j1>=32 && j1<=63)
    {
        char a1=xw2[j1-32];
        if(i==10)
        {
        	
        	//cout<<j1;
        	//cout<<"\n"<<j1<<a1<<a2;
		}
        if(a1==a2)
            cipher[i][j1]=0;
        else
            cipher[i][j1]=1;
    }
    else if(j1>=64 && j1<=95)
    {
        char a1=xw3[j1-64];
        if(a1==a2)
            cipher[i][j1]=0;
        else
            cipher[i][j1]=1;
    }
    else if(j1>=96 && j1<=127)
    {
        char a1=xw4[j1-96];
        if(a1==a2)
            cipher[i][j1]=0;
        else
            cipher[i][j1]=1;
    }
}

    for(int j1=0;j1<128;++j1)
     {
	 cout<<cipher[i][j1];
	 if(j1==127)
	 break;
}
if(i==10)
{
	cout<<"\n";
	bin_ascii(cipher[10]);
}


    }
}
int main()
{
    char c[20],p[20];
    int plain[130];
    cout<<"\n Enter the key(16-Characters):";
    gets(c);
    key_generation(c);
    cout<<"\n Enter the plaintext:";
    gets(p);
    int temp[130],count1=0,i,x;
    for(i=0;i<16;++i)
    {
        int t[10],j=0;
        int a=(int)p[i];
        while(a/2!=1 && a!=0)
        {
            t[j++]=a%2;
            a=a/2;
        }
        t[j++]=a%2;
        t[j++]=a/2;

        for(x=j;x<=7;++x)
            t[x]=0;
        for(x=7;x>=0;--x)
            temp[count1++]=t[x];
    }

    for(i=0;i<128;++i)
        {
            plain[i]=temp[i];
            //cout<<plain[i];
        }
        plain[i]='\0';
        //cout<<plain;
    encrypt(plain);
    //decrypt(cipher[10]);
    return 0;
}
