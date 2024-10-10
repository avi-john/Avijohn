#include <iostream>
#include <cmath>
using namespace std;
void approx(int &num, int &den,float number);
void egyptian(int num,int den);
int main()
{
    int num,den;
    float number;
  cout<<"Enter a number:";
    cin>>number;
   approx(num,den,number);
    egyptian(num,den);
}
void approx(int &num,int &den,float number)
{
    int a=0;
    den=1;
    while(a==0)
    {
        num=number*den;
        if(abs(number-float(num)/den)<0.001)
        {
            a=1;
            break;
        }
        den++;
    }
   cout<<"The fraction is:"<<num<<"/"<<den;
}
void egyptian(int num,int den)
{
    int m,p,q,n,c=0;
    p=num;
    q=den;
    m=p/q;
    cout<<"\nThe egyptian fraction is :";
    /*cout<<"\nThe value of p is :"<<p;
    cout<<"\nThe value of q is :"<<q;*/
    cout << m;
    p=num-m*den;
    q=den;
    while(p!=0)
    {
        n=(q + p - 1)/p;
        // cout<<"\nThe value of n is:"<<n;
        cout<<" + 1/"<<n;
        p=n*p-q;
        // cout<<"\nThe value of p is:"<<p;
        q=q*n;
    }

}
