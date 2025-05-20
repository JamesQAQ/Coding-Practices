#include <iostream>
using namespace std;

int at,height,h[3],s[3][1000],n,step;
void move(int a,int c)
{
    h[a]--;
    s[c][h[c]++]=s[a][h[a]];
    char aa=a+'a',cc=c+'a';
    printf("ring %d : %c -> %c\n",s[a][h[a]],aa,cc);
    step++;
}
void hanoi(int n,int a,int b,int c)
{
    if (n==1)
        move(a,c);
    else
    {
        hanoi(n-1,a,c,b);
        move(a,c);
        hanoi(n-1,b,a,c);
    }
}
int main()
{
    while (cin>>n)
    {
        h[0]=n;
        h[1]=0;
        h[2]=0;
        for (int i=0;i<n;i++)
            s[0][i]=n-i;
        step=0;
        height=n;
        at=0;
        while (height>0)
        {
            int temp,end=(height%2)?1:2;
            if (at==end)
            {
                height--;
                continue;
            }
            if ((at==0||at==1)&&(end==0||end==1))
                temp=2;
            else if ((at==2||at==1)&&(end==2||end==1))
                temp=0;
            else
                temp=1;
            if (height==1)
            {
                move(at,1);
                break;
            }
            else
            {
                hanoi(height-1,at,end,temp);
                move(at,end);
                at=temp;
                height--;
            }
        }
        printf("共移動了 %d 步\n",step);
    }
    return 0;
}
