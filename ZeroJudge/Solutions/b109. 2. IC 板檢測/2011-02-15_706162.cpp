/**********************************************************************************/
/*  Problem: b109 "2. IC 板檢測" from 93全國資訊學科能力決賽         */
/*  Language: CPP                                                                 */
/*  Result: WA (line:3) on ZeroJudge                                              */
/*  Author: no306100 at 2010-12-08 14:14:03                                       */
/**********************************************************************************/


#include <iostream>
using namespace std;

int main()
{
    int s[100000],at[100000][2],n,t,num;
    int cases=1;
    while (cin>>n)
    {
        for (int i=1;i<=n;i++)
        {
            cin>>s[i];
            at[i][0]=5;
            at[i][1]=5;
        }
        while (cin>>t>>num)
        {
            if (num==0&&t==0)
                break;
            int miniat=1,mini=(at[1][1]>t+5)?at[1][1]+(num-1)/s[1]+11:t+(num-1)/s[1]+16;
            for (int i=2;i<=n;i++)
            {
                int p=(at[i][1]>t+5)?at[i][1]+(num-1)/s[i]+11:t+(num-1)/s[i]+16;
					 if (p<mini||p==mini&&s[i]>s[miniat])
                {
                    miniat=i;
                    mini=p;
                }
            }
            at[miniat][0]=(at[miniat][1]>t+5)?at[miniat][1]:t+5;
            at[miniat][1]=mini+5;
        }
        int ans=-1;
        for (int i=1;i<=n;i++)
            if (ans==-1||at[i][1]>at[ans][1])
                ans=i;
        cout<<at[ans][0]<<" "<<ans<<endl;
        cases++;
    }
    return 0;
}
