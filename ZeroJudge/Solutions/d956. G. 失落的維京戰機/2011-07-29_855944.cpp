#include <cstdio>
#include <cstring>

int cases,len,stack[101],top,op;
char s[101];
bool ope[101];
void count(bool t){
    top--;
    stack[top-1]=(t)?stack[top-1]*stack[top]:stack[top-1]+stack[top];
}
int main()
{
    scanf("%d",&cases);
    while (cases--){
        scanf("%s",s);
        top=op=0;
        len=strlen(s);
        for (int i=0;i<len;i++){
            /*printf("at i %d\n",i);
            for (int j=0;j<top;j++)
                printf("%d ",stack[j]);
                puts("");
            for (int j=0;j<op;j++)
                printf("%d ",ope[j]);
                puts("");*/
            if (s[i]=='+'){
                while (op){
                    count(ope[op-1]);
                    op--;
                }
                ope[op++]=false;
            }
            else if (s[i]=='*'){
                while (op&&ope[op-1]){
                    count(ope[op-1]);
                    op--;
                }
                ope[op++]=true;
            }
            else
                stack[top++]=s[i]-48;
        }
        while (op){
            count(ope[op-1]);
            op--;
        }
        printf("%d\n",stack[0]);
    }
    return 0;
}
