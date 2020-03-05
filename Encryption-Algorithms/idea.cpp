#include<iostream>
#include<math.h>
using namespace std;
int subkeys[56][16];
int temp[70];
void notequal(int c1, int d1[20])
{
	int j;
    int d3[16];
		int k=0;
		for(j=0;j<c1;++j)
		d3[j]=d1[j];
	    if(c1!=16)
	    {
	    	for(j=0;j<16-c1;++j)
	    	{
	    		d1[j]=0;
			}
			for(j=16-c1;j<16;++j)
			{
				d1[j]=d3[k++];
			}
		}
	}
int bin_to_dec(int op1[64],int s,int e)
{
	
	int i,j=0;
	unsigned sum=0;
	for(i=e;i>=s;--i,++j)
	{
	if(op1[i]==1)
	sum=sum+pow(2,j);	
	}
	return sum;
}
void ascii_to_bin(char c[20],int temp[130],int l)
{
    int count1=0,i,x;
    for(i=0;i<l;++i)
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
}
void key_generation(char key[20])
{
	int temp[130],i,j,k,subkey[9][130];
	ascii_to_bin(key,temp,16);
	for(i=0;i<128;++i)
	cout<<temp[i];
	cout<<"\n";
	for(i=0;i<7;++i)
	{
		for(j=0;j<128;++j)
		{
			subkey[i][j]=temp[j];
		}
		for(j=25;j<128;++j)
		{
			temp[j-25]=subkey[i][j];
		}
		for(j=103;j<128;++j)
		{
			temp[j]=subkey[i][j-103];
		}
		
	}
	cout<<"\n GENERATED KEY  (52): \n";
	int r=0;
	for(i=0;i<7;++i)
	{
		for(j=0;j<128;++j)
		{
			for(k=0;k<16;++k,++j)
			{
				subkeys[r][k]=subkey[i][j];
				//cout<<subkey[i][j];
			}
			--j;
			r++;
		}
	}
	for(j=0;j<52;++j)
	{
		for(k=0;k<16;++k)
		{
			cout<<subkeys[j][k];
		}
		cout<<" "<<bin_to_dec(subkeys[j],0,15);
		cout<<"\n";
		}	
		
}

int dec_to_bin(int input,int d1[64])
{
        int t=input;
		int count=0,c1=0;
		int temp[40],j;
		 while(t/2!=1)
    {
        temp[count++]=t%2;
        t=t/2;
    }
    temp[count++]=t%2;
    temp[count++]=t/2;
    for(j=count-1;j>=0;--j)
        d1[c1++]=temp[j];
        
    return count;
}
void bin_to_ascii(int op[64],char as[10])
{
	int i,j=0,k;
    unsigned int sum=0;
	cout<<"\n";
	for(j=0;j<64;j=j+8)
	{
	k=0;
	sum=0;
	int h=j;
	for(i=h+7;i>=h;--i,++k)
	{
    	if(op[i]==1)
	    sum=sum+pow(2,k);	
	}

	as[j/8]=(char)sum;
	}
	as[8]='\0';
	//cout<<as<<"\n";
}


void encrypt(char plain[10])
{
	int i,j,p1,p2,p3,p4,k1,k2,k3,k4,k5,k6,d1[64],d2[64],e[20],f[20],c1,c2,k,q[20],o[20],r[20],s[20];
	unsigned long long int b,c,e1,f1,h,m,q1,o1,r1,s1;
	unsigned long long int a,d,g,l;
	ascii_to_bin(plain,temp,8);
	int round=0;
	int r2=0;
	for(i=0;i<8;++i)
	{
			cout<<"\n Round: "<<i+1<<"\n";
		p1=bin_to_dec(temp,0,15);
		p2=bin_to_dec(temp,16,31);
		p3=bin_to_dec(temp,32,47);
		p4=bin_to_dec(temp,48,63);
		k1=bin_to_dec(subkeys[r2++],0,15);
		k2=bin_to_dec(subkeys[r2++],0,15);
		k3=bin_to_dec(subkeys[r2++],0,15);
		k4=bin_to_dec(subkeys[r2++],0,15);
		k5=bin_to_dec(subkeys[r2++],0,15);
		k6=bin_to_dec(subkeys[r2++],0,15);
		cout<<"p1= "<<p1<<"\n";
		cout<<"p2= "<<p2<<"\n";
		cout<<"p3= "<<p3<<"\n";
		cout<<"p4= "<<p4<<"\n";
		cout<<"k1= "<<k1<<"\n";
		cout<<"k2= "<<k2<<"\n";
		cout<<"k3= "<<k3<<"\n";
		cout<<"k4= "<<k4<<"\n";
cout<<"k5= "<<k5<<"\n";
cout<<"k6= "<<k6<<"\n";
		a=k1*p1;
			//cout<<a;
		//while(a>65537)
			a=a%65537;
	//	cout<<"\n"<<a;
		b=k2+p2;
		//while(b>65536)
			b=b%65537;
		c=k3+p3;
		//while(c>65536)
			c=c%65537;
				
		d=k4*p4;
		//while(d>65537)
			d=d%65537;
			//--------------------------------
		//	cout<<"hi";
		c1=dec_to_bin(a,d1);
		c2=dec_to_bin(c,d2);
	notequal(c1,d1);
		//for(j=0;j<16;++j)
		//cout<<d1[j];
		//cout<<"\n";
	notequal(c2,d2);
		
	    //for(j=0;j<16;++j)
		//cout<<d2[j];
		//cout<<"\n";
		for(j=0;j<16;++j)
		{
			
			if(d1[j]==d2[j])
			   e[j]=0;
			   else
			   e[j]=1;
		}
	
		//for(j=0;j<16;++j)
		//cout<<e[j];
		//cout<<"\n";
		e1=bin_to_dec(e,0,15);
		//cout<<e1<<"\n";
		//-----------------------------------------
		c1=dec_to_bin(b,d1);
		c2=dec_to_bin(d,d2);
	notequal(c1,d1);
		//for(j=0;j<16;++j)
		//cout<<d1[j];
		//cout<<"\n";
		notequal(c2,d2);
	    //for(j=0;j<16;++j)
		//cout<<d2[j];
		//cout<<"\n";
		for(j=0;j<16;++j)
		{
			
			if(d1[j]==d2[j])
			   f[j]=0;
			   else
			   f[j]=1;
		}
	
		//for(j=0;j<16;++j)
		//cout<<f[j];
		//cout<<"\n";
		f1=bin_to_dec(f,0,15);
		//cout<<f1<<"\n";
		//---------------------	
	
	g=k5*e1;
	//while(g>65537)
	g=g%65537;
	h=f1+g;
	//while(h>65536)
	h=h%65537;
	l=h*k6;
	//while(l>65537)
	l=l%65537;
	m=g+l;
	//while(m>65536)
	m=m%65537;
	//------------------	
	    c1=dec_to_bin(l,d1);
		c2=dec_to_bin(a,d2);
		notequal(c1,d1);
		//for(j=0;j<16;++j)
		//cout<<d1[j];
		//cout<<"\n";
		notequal(c2,d2);
	    //for(j=0;j<16;++j)
		//cout<<d2[j];
		//cout<<"\n";
		for(j=0;j<16;++j)
		{
			
			if(d1[j]==d2[j])
			   o[j]=0;
			   else
			   o[j]=1;
		}
	
		//for(j=0;j<16;++j)
		//cout<<o[j];
		//cout<<"\n";
		o1=bin_to_dec(o,0,15);
		//cout<<o1<<"\n";
		//-------------------------------
		c1=dec_to_bin(l,d1);
		c2=dec_to_bin(c,d2);
		notequal(c1,d1);
		//for(j=0;j<16;++j)
		//cout<<d1[j];
		//cout<<"\n";
			notequal(c2,d2);
		
	    //for(j=0;j<16;++j)
		//cout<<d2[j];
		//cout<<"\n";
		for(j=0;j<16;++j)
		{
			
			if(d1[j]==d2[j])
			   q[j]=0;
			   else
			   q[j]=1;
		}
	
		//for(j=0;j<16;++j)
		//cout<<q[j];
		//cout<<"\n";
		q1=bin_to_dec(q,0,15);
		//cout<<q1<<"\n";
		//-----------------------------	
		
		c1=dec_to_bin(m,d1);
		c2=dec_to_bin(b,d2);
		notequal(c1,d1);
		//for(j=0;j<16;++j)
		//cout<<d1[j];
		//cout<<"\n";
		notequal(c2,d2);
		
	    //for(j=0;j<16;++j)
		//cout<<d2[j];
		//cout<<"\n";
		for(j=0;j<16;++j)
		{
			
			if(d1[j]==d2[j])
			   r[j]=0;
			   else
			   r[j]=1;
		}
	
		//for(j=0;j<16;++j)
		//cout<<r[j];
		//cout<<"\n";
		r1=bin_to_dec(r,0,15);
		//cout<<r1<<"\n";
		//-------------------------------
		c1=dec_to_bin(m,d1);
		c2=dec_to_bin(d,d2);
		notequal(c1,d1);
		//for(j=0;j<16;++j)
		//cout<<d1[j];
		//cout<<"\n";
			notequal(c2,d2);
		
	    //for(j=0;j<16;++j)
		//cout<<d2[j];
		//cout<<"\n";
		for(j=0;j<16;++j)
		{
			
			if(d1[j]==d2[j])
			   s[j]=0;
			   else
			   s[j]=1;
		}
	
		//for(j=0;j<16;++j)
		//cout<<s[j];
		//cout<<"\n";
		s1=bin_to_dec(s,0,15);
		//cout<<s1<<"\n";
			
				cout<<"a= "<<a<<"\n";
				cout<<"b= "<<b<<"\n";
				cout<<"c= "<<c<<"\n";
				cout<<"d= "<<d<<"\n";
				cout<<"e= "<<e1<<"\n";
				cout<<"f= "<<f1<<"\n";
				cout<<"g= "<<g<<"\n";
				cout<<"h= "<<h<<"\n";
				cout<<"l= "<<l<<"\n";
				cout<<"m= "<<m<<"\n";
				cout<<"o= "<<o1<<"\n";
				cout<<"q= "<<q1<<"\n";
				cout<<"r= "<<r1<<"\n";
				cout<<"s= "<<s1<<"\n";
				for(j=0;j<16;++j)
				temp[j]=o[j];
				for(j=0;j<16;++j)
				temp[16+j]=q[j];
				for(j=0;j<16;++j)
				temp[32+j]=r[j];
				for(j=0;j<16;++j)
				temp[48+j]=s[j];
	}
	cout<<"Round: 9\n";
		p1=bin_to_dec(temp,0,15);
		p2=bin_to_dec(temp,16,31);
		p3=bin_to_dec(temp,32,47);
		p4=bin_to_dec(temp,48,63);
		k1=bin_to_dec(subkeys[48],0,15);
		k2=bin_to_dec(subkeys[49],0,15);
		k3=bin_to_dec(subkeys[50],0,15);
		k4=bin_to_dec(subkeys[51],0,15);
		cout<<"p1= "<<p1<<"\n";
		cout<<"p2= "<<p2<<"\n";
		cout<<"p3= "<<p3<<"\n";
		cout<<"p4= "<<p4<<"\n";
		cout<<"k1= "<<k1<<"\n";
		cout<<"k2= "<<k2<<"\n";
		cout<<"k3= "<<k3<<"\n";
		cout<<"k4= "<<k4<<"\n";
		a=p1*k1;
		//while(a>65537)
			a=a%65537;
		b=p3+k2;
			//while(b>65536)
			b=b%65537;
		c=p2+k3;
			//while(c>65536)
			c=c%65537;
		d=p4*k4;
		//while(d>65537)
			d=d%65537;
				cout<<"a= "<<a<<"\n";
				cout<<"b= "<<b<<"\n";
				cout<<"c= "<<c<<"\n";
				cout<<"d= "<<d<<"\n";
c1=dec_to_bin(a,d1);
c2=dec_to_bin(b,d2);
int c3,c4,d4[20],d5[20],d3[20];
c3=dec_to_bin(c,d4);
c4=dec_to_bin(d,d5);
	notequal(c1,d1);
	notequal(c2,d2);
	notequal(c3,d4);
	notequal(c4,d5);
			
	for(j=0;j<16;++j)
				temp[j]=d1[j];
				for(j=0;j<16;++j)
				temp[16+j]=d2[j];
				for(j=0;j<16;++j)
				temp[32+j]=d4[j];
				for(j=0;j<16;++j)
				temp[48+j]=d5[j];
for(j=0;j<64;++j)
cout<<temp[j];
char cipher[8];
bin_to_ascii(temp,cipher);
cout<<cipher;
}
int dkeys[52][16];
void inverse(long long int i1,long long int i2)
{
	//cout<<"ok";
long long int b,a,x;
	b=bin_to_dec(subkeys[i2],0,15);
	b = b%65537; 
    for ( x=1; x<65537; x++) 
       if ((b*x) % 65537 == 1) 
          a=x;
         int key[16]; 
         //cout<<a<<" "<<b<<" ";
    int c=dec_to_bin(a,key);
    //cout<<c;
    int  k=0,d3[20],j;
		for(j=0;j<c;++j)
		d3[j]=key[j];
	    if(c!=16)
	    {
	    	for(j=0;j<16-c;++j)
	    	{
	    		dkeys[i1][j]=0;
			}
			for(j=16-c;j<16;++j)
			{
				dkeys[i1][j]=d3[k++];
			}
		}
		else
		{
			for(j=0;j<16;++j)
			dkeys[i1][j]=key[j];
		}
    
}



string complement(int i2) 
{ 
  string str;
  int i;
  for(i=0;i<16;++i)
  {
  	if(subkeys[i2][i]==1)
  	str=str+"1";
  	else
  	str=str+"0";
  }
    int n = str.length(); 

    for (i = n-1 ; i >= 0 ; i--) 
        if (str[i] == '1') 
            break; 
  
    // If there exists no '1' concatenate 1 at the 
    // starting of string 
    if (i == -1) 
        return '1' + str; 
  
    // Continue traversal after the position of 
    // first '1' 
    for (int k = i-1 ; k >= 0; k--) 
    { 
        //Just flip the values 
        if (str[k] == '1') 
            str[k] = '0'; 
        else
            str[k] = '1'; 
    } 
  
    // return the modified string 
    return str;; 
} 
void con(string s,int i1)
{
	int i;
	for(i=0;i<16;++i)
	{
		if(s[i]=='1')
		dkeys[i1][i]=1;
		else
		dkeys[i1][i]=0;
	}
}

void same(int i1,int i2)
{
	int i;
	for(i=0;i<16;++i)
	{
		dkeys[i1][i]=subkeys[i2][i];
	}
}
void decrypt_key()
{
	//cout<<"ji";
	inverse(0,48);
	//for(int u=0;u<16;++u)
	//cout<<dkeys[0][u];
	string s;
	s=complement(49);
	con(s,1);
	s=complement(50);
	con(s,2);
	inverse(3,51);
	int i1=4,i2=46,i;
	for(i=0;i<8;++i)
	{
		same(4+(i*6),46-(i*6));
		same(5+(i*6),47-(i*6));
		inverse(6+(i*6),42-(i*6));
		s=complement(44-(i*6));
		con(s,7+(i*6));
		s=complement(43-(i*6));
		con(s,8+(i*6));
		inverse(9+(i*6),45-(i*6));
		}
	cout<<"\n DECRYPTION KEYS\n";
	int j;
for(i=0;i<52;++i)
{
	for(j=0;j<16;++j)
	cout<<dkeys[i][j];
	cout<<" "<<bin_to_dec(dkeys[i],0,15);
	cout<<"\n";
	}	
}



void decrypt()
{
	int i,j,p1,p2,p3,p4,k1,k2,k3,k4,k5,k6,d1[64],d2[64],e[20],f[20],c1,c2,k,q[20],o[20],r[20],s[20];
	unsigned long long int b,c,e1,f1,h,m,q1,o1,r1,s1;
	unsigned long long int a,d,g,l;
	//ascii_to_bin(plain,temp,8);
	int round=0;
	int r2=0;
	for(i=0;i<8;++i)
	{
			cout<<"\n Round: "<<i+1<<"\n";
		p1=bin_to_dec(temp,0,15);
		p2=bin_to_dec(temp,16,31);
		p3=bin_to_dec(temp,32,47);
		p4=bin_to_dec(temp,48,63);
		k1=bin_to_dec(dkeys[r2++],0,15);
		k2=bin_to_dec(dkeys[r2++],0,15);
		k3=bin_to_dec(dkeys[r2++],0,15);
		k4=bin_to_dec(dkeys[r2++],0,15);
		k5=bin_to_dec(dkeys[r2++],0,15);
		k6=bin_to_dec(dkeys[r2++],0,15);
		cout<<"p1= "<<p1<<"\n";
		cout<<"p2= "<<p2<<"\n";
		cout<<"p3= "<<p3<<"\n";
		cout<<"p4= "<<p4<<"\n";
		cout<<"k1= "<<k1<<"\n";
		cout<<"k2= "<<k2<<"\n";
		cout<<"k3= "<<k3<<"\n";
		cout<<"k4= "<<k4<<"\n";
cout<<"k5= "<<k5<<"\n";
cout<<"k6= "<<k6<<"\n";
		a=k1*p1;
			//cout<<a;
		//while(a>65537)
			a=a%65537;
	//	cout<<"\n"<<a;
		b=k2+p2+1;
		//while(b>65536)
			b=b%65537;
		c=k3+p3+1;
		//while(c>65536)
			c=c%65537;
				
		d=k4*p4;
		//while(d>65537)
			d=d%65537;
			//--------------------------------
		//	cout<<"hi";
		c1=dec_to_bin(a,d1);
		c2=dec_to_bin(c,d2);
	notequal(c1,d1);
		//for(j=0;j<16;++j)
		//cout<<d1[j];
		//cout<<"\n";
	notequal(c2,d2);
		
	    //for(j=0;j<16;++j)
		//cout<<d2[j];
		//cout<<"\n";
		for(j=0;j<16;++j)
		{
			
			if(d1[j]==d2[j])
			   e[j]=0;
			   else
			   e[j]=1;
		}
	
		//for(j=0;j<16;++j)
		//cout<<e[j];
		//cout<<"\n";
		e1=bin_to_dec(e,0,15);
		//cout<<e1<<"\n";
		//-----------------------------------------
		c1=dec_to_bin(b,d1);
		c2=dec_to_bin(d,d2);
	notequal(c1,d1);
		//for(j=0;j<16;++j)
		//cout<<d1[j];
		//cout<<"\n";
		notequal(c2,d2);
	    //for(j=0;j<16;++j)
		//cout<<d2[j];
		//cout<<"\n";
		for(j=0;j<16;++j)
		{
			
			if(d1[j]==d2[j])
			   f[j]=0;
			   else
			   f[j]=1;
		}
	
		//for(j=0;j<16;++j)
		//cout<<f[j];
		//cout<<"\n";
		f1=bin_to_dec(f,0,15);
		//cout<<f1<<"\n";
		//---------------------	
	
	g=k5*e1;
	//while(g>65537)
	g=g%65537;
	h=f1+g;
	//while(h>65536)
	h=h%65537;
	l=h*k6;
	//while(l>65537)
	l=l%65537;
	m=g+l;
	//while(m>65536)
	m=m%65537;
	//------------------	
	    c1=dec_to_bin(l,d1);
		c2=dec_to_bin(a,d2);
		notequal(c1,d1);
		//for(j=0;j<16;++j)
		//cout<<d1[j];
		//cout<<"\n";
		notequal(c2,d2);
	    //for(j=0;j<16;++j)
		//cout<<d2[j];
		//cout<<"\n";
		for(j=0;j<16;++j)
		{
			
			if(d1[j]==d2[j])
			   o[j]=0;
			   else
			   o[j]=1;
		}
	
		//for(j=0;j<16;++j)
		//cout<<o[j];
		//cout<<"\n";
		o1=bin_to_dec(o,0,15);
		//cout<<o1<<"\n";
		//-------------------------------
		c1=dec_to_bin(l,d1);
		c2=dec_to_bin(c,d2);
		notequal(c1,d1);
		//for(j=0;j<16;++j)
		//cout<<d1[j];
		//cout<<"\n";
			notequal(c2,d2);
		
	    //for(j=0;j<16;++j)
		//cout<<d2[j];
		//cout<<"\n";
		for(j=0;j<16;++j)
		{
			
			if(d1[j]==d2[j])
			   q[j]=0;
			   else
			   q[j]=1;
		}
	
		//for(j=0;j<16;++j)
		//cout<<q[j];
		//cout<<"\n";
		q1=bin_to_dec(q,0,15);
		//cout<<q1<<"\n";
		//-----------------------------	
		
		c1=dec_to_bin(m,d1);
		c2=dec_to_bin(b,d2);
		notequal(c1,d1);
		//for(j=0;j<16;++j)
		//cout<<d1[j];
		//cout<<"\n";
		notequal(c2,d2);
		
	    //for(j=0;j<16;++j)
		//cout<<d2[j];
		//cout<<"\n";
		for(j=0;j<16;++j)
		{
			
			if(d1[j]==d2[j])
			   r[j]=0;
			   else
			   r[j]=1;
		}
	
		//for(j=0;j<16;++j)
		//cout<<r[j];
		//cout<<"\n";
		r1=bin_to_dec(r,0,15);
		//cout<<r1<<"\n";
		//-------------------------------
		c1=dec_to_bin(m,d1);
		c2=dec_to_bin(d,d2);
		notequal(c1,d1);
		//for(j=0;j<16;++j)
		//cout<<d1[j];
		//cout<<"\n";
			notequal(c2,d2);
		
	    //for(j=0;j<16;++j)
		//cout<<d2[j];
		//cout<<"\n";
		for(j=0;j<16;++j)
		{
			
			if(d1[j]==d2[j])
			   s[j]=0;
			   else
			   s[j]=1;
		}
	
		//for(j=0;j<16;++j)
		//cout<<s[j];
		//cout<<"\n";
		s1=bin_to_dec(s,0,15);
		//cout<<s1<<"\n";
			
				cout<<"a= "<<a<<"\n";
				cout<<"b= "<<b<<"\n";
				cout<<"c= "<<c<<"\n";
				cout<<"d= "<<d<<"\n";
				cout<<"e= "<<e1<<"\n";
				cout<<"f= "<<f1<<"\n";
				cout<<"g= "<<g<<"\n";
				cout<<"h= "<<h<<"\n";
				cout<<"l= "<<l<<"\n";
				cout<<"m= "<<m<<"\n";
				cout<<"o= "<<o1<<"\n";
				cout<<"q= "<<q1<<"\n";
				cout<<"r= "<<r1<<"\n";
				cout<<"s= "<<s1<<"\n";
				for(j=0;j<16;++j)
				temp[j]=o[j];
				for(j=0;j<16;++j)
				temp[16+j]=q[j];
				for(j=0;j<16;++j)
				temp[32+j]=r[j];
				for(j=0;j<16;++j)
				temp[48+j]=s[j];
	}
	cout<<"Round: 9\n";
		p1=bin_to_dec(temp,0,15);
		p2=bin_to_dec(temp,16,31);
		p3=bin_to_dec(temp,32,47);
		p4=bin_to_dec(temp,48,63);
		k1=bin_to_dec(dkeys[48],0,15);
		k2=bin_to_dec(dkeys[49],0,15);
		k3=bin_to_dec(dkeys[50],0,15);
		k4=bin_to_dec(dkeys[51],0,15);
		cout<<"p1= "<<p1<<"\n";
		cout<<"p2= "<<p2<<"\n";
		cout<<"p3= "<<p3<<"\n";
		cout<<"p4= "<<p4<<"\n";
		cout<<"k1= "<<k1<<"\n";
		cout<<"k2= "<<k2<<"\n";
		cout<<"k3= "<<k3<<"\n";
		cout<<"k4= "<<k4<<"\n";
		a=p1*k1;
		//while(a>65537)
			a=a%65537;
		b=p3+k3+1;
			//while(b>65536)
			b=b%65537;
		c=p2+k2+1;
			//while(c>65536)
			c=c%65537;
		d=p4*k4;
		//while(d>65537)
			d=d%65537;
				cout<<"a= "<<a<<"\n";
				cout<<"b= "<<b<<"\n";
				cout<<"c= "<<c<<"\n";
				cout<<"d= "<<d<<"\n";
c1=dec_to_bin(a,d1);
c2=dec_to_bin(b,d2);
int c3,c4,d4[20],d5[20],d3[20];
c3=dec_to_bin(c,d4);
c4=dec_to_bin(d,d5);
	notequal(c1,d1);
	notequal(c2,d2);
	notequal(c3,d4);
	notequal(c4,d5);
			
	for(j=0;j<16;++j)
				temp[j]=d1[j];
				for(j=0;j<16;++j)
				temp[16+j]=d2[j];
				for(j=0;j<16;++j)
				temp[32+j]=d4[j];
				for(j=0;j<16;++j)
				temp[48+j]=d5[j];
for(j=0;j<64;++j)
cout<<temp[j];
char cipher[8];
bin_to_ascii(temp,cipher);
cout<<cipher;
}













int main()
{
	char key[20],plain[10];
	cout<<"\n Enter the key: ";
	cin>>key;
	key_generation(key);
	decrypt_key();
	cout<<"\n Enter the plain text: ";
	cin>>plain;
	encrypt(plain);
    decrypt();
	return 0;
}
