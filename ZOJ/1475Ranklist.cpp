//00:00.30 1232k

#include <iostream>
#include <string>
#include <stdio.h>
#include <strstream>
//bignum routine
//written by Peter Tjq, last revised: 8-18-2001
#include <iomanip.h>
#include <string.h>

const long dlen=1000; //dlen*4 decimal digits
class bignum
{
	short data[dlen];
public: long datalen;
    public:
    bignum(long x=0):datalen(0){memset(data,0,sizeof(data));*this=x;};
    long compare(const bignum &a,long d=0);//d!=0 compare first n digits
    void operator=(long x);
    void operator+=(const bignum &a);
    void operator+=(long x);
    void operator-=(const bignum &a);
    void operator-=(long x);
    void multi(const bignum &a,const bignum &b);
    void operator*=(long x);
    long operator/=(long x);//return the remainder
    long operator%(long x);
    void div(bignum &a,const bignum &b);//after the division,the remainder is stored in a
	long sqrt(const bignum &a);//a=sqrt(b):a.sqrt(b), return 0 if a is square
    void add(const bignum &a,const bignum &b){*this=a;*this+=b;}
    void add(const bignum &a,long x){*this=a;*this+=x;}
    void minus(const bignum &a,const bignum &b){*this=a;*this-=b;}
    void minus(const bignum &a,long x){*this=a;*this-=x;}
    void multi(const bignum &a,long x){*this=a;*this*=x;}
    void operator*=(const bignum &a){bignum b=*this;multi(a,b);}
    friend ostream& operator<<(ostream &out,const bignum &a);
    friend istream& operator>>(istream &in,bignum &a);
};
long bignum::compare(const bignum &a, long d)
{
long i;
if (d==0)
   {
   if (datalen>a.datalen) return 1;
   if (datalen<a.datalen) return -1;
   }
d=datalen>a.datalen?a.datalen:datalen;
for (i=1;i<=d;i++)
    if (data[datalen-i]!=a.data[a.datalen-i])
       return data[datalen-i]>a.data[a.datalen-i]?1:-1;
return 0;
}
void bignum::operator=(long x)
{
	memset(data,0,datalen*sizeof(data[0]));
	datalen=0;
	while (x>0)
    {
		data[datalen++]=x%10000;
		x/=10000;
    }
}
void bignum::operator+=(const bignum &a)
{
long i;
if (a.datalen==0) return;
if (datalen<a.datalen) datalen=a.datalen;
for (i=0;i<datalen;i++)
    {
    if ((data[i]+=a.data[i])>=10000)
       {
       data[i]-=10000;
       data[i+1]++;
       }
    }
if (data[datalen]) datalen++;
}
void bignum::operator+=(long x)
{
long i=0;
while (x>0)
      {
      x+=data[i];
      data[i++]=x%10000;
      x/=10000;
      }
if (i>datalen) datalen=i;
}
void bignum::operator-=(const bignum &a)
{
long i;
if (a.datalen==0) return;
for (i=0;i<a.datalen;i++)
    {
    if ((data[i]-=a.data[i])<0)
       {
       data[i]+=10000;
       data[i+1]--;
       }
    }
while (data[i]<0)
      {
      data[i]+=10000;
      data[++i]--;
      }
while (datalen>0 && data[datalen-1]==0) datalen--;
}
void bignum::operator-=(long x)
{
long i=-1;
while (x>0)
      {
      data[++i]-=x%10000;
      x/=10000;
      if (data[i]<0)
         {
         data[i]+=10000;
         x++;
         }
      }
while (datalen>0 && data[datalen-1]==0) datalen--;
}
void bignum::multi(const bignum &a,const bignum &b)
{
long i,j,k,t;
memset(data,0,datalen*sizeof(data[0]));
if ((a.datalen==0) || (b.datalen==0))
   {
   datalen=0;
   return;
   }
for (i=0;i<a.datalen;i++)
    {
    if (a.data[i]==0) continue;
    t=0;
    k=i;
    for (j=0;j<=b.datalen;j++)
        {
        t+=long(a.data[i])*b.data[j]+data[k];
        data[k++]=t%10000;
        t/=10000;
        }
    }
datalen=a.datalen+b.datalen;
if (datalen>0 && data[datalen-1]==0) datalen--;
}
void bignum::operator*=(long x)
{
long i,t=0;
if (x==0)
   {
   memset(data,0,datalen*sizeof(data[0]));
   datalen=0;
   return;
   }
if (x==1) return;
for (i=0;i<datalen;i++)
    {
    t+=data[i]*x;
    data[i]=t%10000;
    t/=10000;
    }
while (t>0)
      {
      data[datalen++]=t%10000;
      t/=10000;
      }
}
long bignum::operator/=(long x)
{
long i,ys=0;
if (x==1) return 0;
for (i=datalen-1;i>=0;i--)
    {
    (ys*=10000)+=data[i];
    data[i]=ys/x;
    ys%=x;
    }
while (datalen>0 && data[datalen-1]==0) datalen--;
return ys;
}
long bignum::operator%(long x)	
{
long i,ys=0;
if (x==1) return 0;
for (i=datalen-1;i>=0;i--)
    ((ys*=10000)+=data[i])%=x;
return ys;
}
void bignum::div(bignum &a,const bignum&b)
{
long i,k,bk,c;
memset(data,0,datalen*sizeof(data[0]));
datalen=0;
if (a.datalen==0 || b.datalen==0) return;
if ((datalen=a.datalen-b.datalen+1)<0) datalen=0;
while (a.compare(b)>=0)
      {
      k=a.datalen-b.datalen-1;
      c=a.compare(b,1);
      if (c>=0)
         {
         k++;
         if (a.datalen==1) bk=a.data[0]/b.data[0]; else
         if ((bk=(a.data[a.datalen-1]*10000l+a.data[a.datalen-2])/(b.data[b.datalen-1]*10000l+b.data[b.datalen-2]+1))==0) bk=1;
         }
      else
          {
          bk=(10000l*a.data[a.datalen-1]+a.data[a.datalen-2])/(b.data[b.datalen-1]+1);
          }
      data[k]+=bk;
      c=0;
      for (i=0;i<=b.datalen;i++)
          {
          c+=bk*b.data[i];
          a.data[i+k]-=c%10000;
          c/=10000;
          if (a.data[i+k]<0)
             {
             a.data[i+k]+=10000;
             c++;
             }
          }
      while (a.datalen>0 && a.data[a.datalen-1]==0) a.datalen--;
      }
if (datalen>0 && data[datalen-1]==0) datalen--;
}
long bignum::sqrt(const bignum &a)
{
bignum s[2];
long op=1,r;
s[0].datalen=a.datalen/2+1;
s[0].data[s[0].datalen-1]=a.datalen%2?100:1;
while (1)
      {
      *this=a;
      s[op].div(*this,s[1-op]);
      s[op]+=s[1-op];
      s[op]/=2;
      if (s[op].compare(s[1-op])>=0) break;
      op=1-op;
      }
r=datalen;
*this=s[1-op];
return r;
}
ostream& operator<<(ostream &out,const bignum &a)
{
long i;
if (a.datalen==0) out<<0; else
   {
   out<<a.data[a.datalen-1]<<setfill('0');
   out.setf(ios::right,ios::adjustfield);
   for (i=a.datalen-2;i>=0;i--)
       out<<setw(4)<<a.data[i];
   out<<setfill(' ');
   out.unsetf(ios::right);
   }
return out;
}

istream& operator>>(istream &in,bignum &a)
{
	char s[dlen*4];
	long n10[]={1,10,100,1000},i,k;
	memset(a.data,0,a.datalen*sizeof(a.data[0]));
	a.datalen=0;
	in>>setw(sizeof(s))>>s;
	for (i=strlen(s)-1,k=0;i>=0;i--,k++)
	{
		if (k==4)
		{
			k=0;
			a.datalen++;
		}
		a.data[a.datalen]+=n10[k]*(s[i]-'0');
	}
	a.datalen++;
	while (a.datalen>0 && a.data[a.datalen-1]==0) a.datalen--;
	return in;
}

int N;
bignum f[201], C[201], temp;

void Run ()
{
	int n, i;
	for (f[0] = 1, f[1] = 1, n = 2, C[0] = 1, C[1] = 1; n <= 200; n ++) {
		for (i = n; i >= 1; i --)
			C[i] += C[i - 1];
		for (i = n; i >= 1; i --) {
			temp = C[i];
			temp *= f[n - i];
			f[n] += temp;
		}
	}
}

int main()
{
	Run ();
	for (cin >> N; N > 0; cin >> N)
		if (N > 1)
			cout << f[N] << endl;
		else cout << 1 << endl;
	return 0;
}
