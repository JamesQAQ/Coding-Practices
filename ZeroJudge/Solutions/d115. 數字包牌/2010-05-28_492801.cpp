#include <iostream>
using namespace std;

int a[100];
int s[100];
void count(int i1,int i2,int n,int m);
int main()
{
    int n,m,temp;
    int i1=0,i2=0;
    while (cin>>n)
    {
        if (n==0)
            break;
        for (int i=0;i<n;i++)
            cin>>a[i];
        cin>>m;
        for (int i=n-1;i>0;i--)
        {
            for (int j=0;j<i;j++)
            {
                if (a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        count(i1,i2,n,m);
        cout<<endl;
        i1=0;
        i2=0;
    }
    //system("pause");
    return 0;
}

void count(int i1,int i2,int n,int m)
{
    if (i2==m-1)
    {
        while (i1<n)
        {
            s[i2]=a[i1];
            for (int i=0;i<m;i++)
                cout<<s[i]<<" ";
            cout<<endl;
            i1++;
        }
    }
    else
    {
        while (i1<n)
        {
            s[i2]=a[i1];
            count(i1+1,i2+1,n,m);
            i1++;
        }
    }
}
