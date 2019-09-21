
#include <bits/stdc++.h>
using namespace std;
bool greater1(string s11,string s22)
{
    if(s11.length()>s22.length())
        return true;
    else if(s11.length()<s22.length())
        return false;
    else
    {
        for(int i=0;i<s11.length();i++)
        {
            if(s11[i]==s22[i])
                continue;
            if(s11[i]>s22[i])
                return true;
            else
                return false;
        }
    }
    return true;
}
bool equal1(string s11,string s22)
{
    if(s11.length()!=s22.length())
        return false;
    else
    {
        for(int i=0;i<s11.length();i++)
        {
            if(s11[i]==s22[i])
                continue;
            else
                return false;
        }
    }
    return true;
}
string add1(int a1[],int a2[], int m, int n)
{
    string s;
    int w;
    if(m<=n)
    {    int a3[n+1]={0};
         int j=m-1;
         for(int i=n;j>=0;--i)
        {   a3[i]+=a1[j];
            --j;
        }
        int k=n;
        int q=0;
        for(int i=n-1;i>=0;--i)
        {   a3[k]+=a2[i]+q;
            q=a3[k]/10;
            a3[k]%=10;
            --k;
        }
          //a3[0]=q;
            for(int i=0;i<=m;++i)
            {     if(a3[i]==0)
                  continue;
                else
                {   w=i;
                    break;
                }
            }
            for(int i=w;i<=n;++i)
            s+=a3[i]+48;
    }
    else
    {
         int a3[m+1]={0};
         int j=n-1;
         for(int i=m;j>=0;--i)
        {   a3[i]+=a2[j];
            --j;
        }
        int k=m;
        int q=0;
        for(int i=m-1;i>=0;--i)
        {   a3[k]+=a1[i]+q;
            q=a3[k]/10;
            a3[k]%=10;
            --k;
        }
          //a3[0]=q;
            for(int i=0;i<=m;++i)
            {   if(a3[i]==0)
                    continue;
                else
                {   w=i;
                    break;
                }
            }
                for(int i=w;i<=m;++i)
                s+=a3[i]+48;
    }
   return s;
}
string add(string s11, string s22, int m, int n)
{
    int a1[m]={0};
    int a2[n]={0};
    for(int i=0;i<m;i++)
    a1[i]=s11[i]-48;
    for(int i=0;i<n;i++)
    a2[i]=s22[i]-48;
    string s;
    int w;
    if(m<=n)
    {    int a3[n+1]={0};
         int j=m-1;
         for(int i=n;j>=0;--i)
        {   a3[i]+=a1[j];
            --j;
        }
        int k=n;
        int q=0;
        for(int i=n-1;i>=0;--i)
        {   a3[k]+=a2[i]+q;
            q=a3[k]/10;
            a3[k]%=10;
            --k;
        }
          a3[0]=q;
            for(int i=0;i<=m;++i)
            {     if(a3[i]==0)
                  continue;
                else
                {   w=i;
                    break;
                }
            }
            for(int i=w;i<=n;++i)
            s+=a3[i]+48;
    }
    else
    {
         int a3[m+1]={0};
         int j=n-1;
         for(int i=m;j>=0;--i)
        {   a3[i]+=a2[j];
            --j;
        }
        int k=m;
        int q=0;
        for(int i=m-1;i>=0;--i)
        {   a3[k]+=a1[i]+q;
            q=a3[k]/10;
            a3[k]%=10;
            --k;
        }
          a3[0]=q;
            for(int i=0;i<=m;++i)
            {   if(a3[i]==0)
                    continue;
                else
                {   w=i;
                    break;
                }
            }
                for(int i=w;i<=m;++i)
                s+=a3[i]+48;
    }
   return s;
}

string sub(string s11,string s22,int m, int n)
{
    if(greater1(s22,s11))
    {
        string ns=sub(s22,s11,s22.length(),s11.length());
        string mb="-";
        ns=mb+ns;
        return ns;
    }

    else
    {
    int a1[m]={0};
    int a2[n]={0};
    for(int i=0;i<m;i++)
    a1[i]=s11[i]-48;
    for(int i=0;i<n;i++)
    a2[i]=s22[i]-48;
    string s,ss;
    int a3[n];
    int a4[1]={1};
    for(int i=0;i<n;i++)
    a3[i]=9-a2[i];
    s=add1(a3,a4,n,1);
    //return s;
    if(n<m)
    {
        int y=m-n;
        while(y>0)
        {
            ss+='9';
            --y;
        }
    }
    ss+=s;
   //return ss;
    int a5[ss.length()]={0};
    for(int i=0;i<ss.length();i++)
     a5[i]=ss[i]-48;
    return add1(a1,a5,m,ss.length());
    }
}    

string multi(string s11,string s22)
{
    int m=s11.length();
    int n=s22.length();
    int a1[m]={0};
    int a2[n]={0};
    for(int i=0;i<m;i++)
    a1[i]=s11[i]-48;
    for(int i=0;i<n;i++)
    a2[i]=s22[i]-48;
    string s;
    int m1=m+n;
        int a3[m1]={0};
        for(int i=m-1;i>=0;--i)
        {
            for(int j=n-1;j>=0;--j)
            {
                a3[i+j+1]+=a1[i]*a2[j];
                if(a3[i+j+1]>9)
                {
                 a3[i+j]+=a3[i+j+1]/10;
                 a3[i+j+1]=a3[i+j+1]%10;
                }
            }
        }   int w=0;
            for(int i=0;i<=m1;++i)
            {   if(a3[i]==0)
                    continue;
                else
                {   w=i;
                    break;
                }
            }
                for(int i=w;i<m1;++i)
                s+=a3[i]+48;

    return s;
}
string gcd(string s11,string s22)
{
    if(equal1(s11,s22))
        return s11;
    else if(greater1(s11,s22))
        return gcd(sub(s11,s22,s11.length(),s22.length()),s22);
    else if(greater1(s22,s11))
        return gcd(s11,sub(s22,s11,s22.length(),s11.length()));
    return "";
}
string factorial(string s11)
{
    string one="1";
    string zero="0";
    if(equal1(s11,one))
    return one;
    while(greater1(s11,zero))
    {
      return multi(s11,factorial(sub(s11,one,s11.length(),one.length())));
    }
    return "";
}

string pow1(string s11,string s22)
{
    string one="1";
    string zero="0";
    string five="5";
    if(equal1(s22,zero))
        return "1";
    else if(equal1(s22,one))
        return s11;

    
    else
    {
    string s33;
    s33=s22;
    s33=multi(s33,five);
    s33.pop_back();
    //cout<<s33<<" "<<s33[s33.length()-1]<<" "<<s33.length()<<endl;
    string temp=pow1(s11,s33);
   // cout<<temp<<endl;
    
      if(s22[s22.length()-1]%2==1)
        {   
        return multi(multi(temp,temp),s11);
        }
     else
        {
        return multi(temp,temp);
        }
    }
    return "";
}

int main()
{
	int t;
	cin>>t;
	while(t>0)
	{
		int tx;
		cin>>tx;
		if(tx==1)
		{
			string s1,s2;
    		cin>>s1>>s2;
    		cout<<pow1(s1,s2)<<endl;
		}

		if(tx==2)
		{
			string s1,s2;
    		cin>>s1>>s2;
    		cout<<gcd(s1,s2)<<endl;

		}
    	if(tx==3)
    	{
    		string s1;
    		cin>>s1;
    		cout<<factorial(s1)<<endl;
    	}
    
   // cout<<factorial(s2)<<endl;
    
   	t--;
   	}
    return 0;
}
