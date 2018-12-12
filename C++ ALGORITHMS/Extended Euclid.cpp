/*
  #include <iostream>
  #include <math.h>
  using namespace std;
 long long gcd(long long a, long long b)
 {long long r;
  while (b!=0)
    {r=a%b;
     a=b;
     b=r;
    }
  return a;
  }
void extended_euclid(long long a, long long b, long long &x1, long long &y1)
{ int q, r, x2,  y2,  t;
  x1 = 1; y1 = 0;
  x2 = 0; y2 = 1;
  while (b != 0)
        {q = a/ b;
         r = a % b;
         a=b;b=r;
         t=x2;
         x2=x1-q*x2;
         x1=t;
         t=y2;
         y2=y1-q*y2;
         y1=t;
        }
}

  int main()
{long long n,n1,n2,d,a,b,c,x,y,res,x0,y0,i;
 long long kmin, kmax;
 cin>>n>>n1>>n2;
 d=gcd(n1,n2);
 if (n%d==0)
  {a=n1/d;b=n2/d;c=n/d;
   extended_euclid(a,b, x, y);
   x0=x*c; y0=y*c;
   kmin = (long long)ceil(-1.0 * x0 / b);
   kmax = (long long)floor(1.0 * y0 / a);
   cout<<"x0="<<x0<<" y0="<<y0<<endl;
   cout<<"kmin="<<kmin<<" kmax="<<kmax<<endl;
   res = kmax - kmin + 1;
   if (res)
       if (a>b) cout<<x0+b*kmax<<" "<<y0-a*kmax<<endl;
       else cout<<x0+b*kmin<<" "<<y0-a*kmin<<endl;
   else cout<<"Impossible\n";
  }
 else cout<<"Impossible\n";
}
*/
#include <iostream>

int xGCD(int a, int b, int &x, int &y) {
    if(b == 0) {
       x = 1;
       y = 0;
       return a;
    }

    int x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int main()
{
   int a = 7, b = 15, x, y, gcd;

   if(a < b) std::swap(a, b);

   gcd = xGCD(a, b, x, y);
   std::cout << "GCD: " << gcd << ", x = " << x << ", y = " << y << std::endl;

   return 0;
}
