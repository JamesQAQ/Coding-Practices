#include <cstdio>
#include <queue>

int no[1000000],o[1000000];
int main()
{
    int n,tmp,temp,cases=0;
    char s[10];
    while (scanf("%d",&n)==1){
        cases++;
        std::queue <int> Q,team[1000];
        for (int i=0;i<n;i++){
            scanf("%d",&tmp);
            while (tmp--){
                scanf("%d",&temp);
                no[temp]=i;
                o[temp]=cases;
            }
        }
        printf("Line #%d\n",cases);
        while (scanf("%s",s),s[0]!='S'){
            if (s[0]=='D'){
                if (!Q.empty()){
                    int NO=Q.front();
                    if (NO>=1000000){
                        printf("%d\n",Q.front()-1000000);
                        Q.pop();
                    }
                    else{
                        printf("%d\n",team[NO].front());
                        team[NO].pop();
                        if (team[NO].empty())
                            Q.pop();
                    }
                }
            }
            else{
                int p;
                scanf("%d",&p);
                if (o[p]!=cases)
                    Q.push(p+1000000);
                else{
                    if (team[no[p]].empty())
                        Q.push(no[p]);
                    team[no[p]].push(p);
                }
            }
        }
    }
}
