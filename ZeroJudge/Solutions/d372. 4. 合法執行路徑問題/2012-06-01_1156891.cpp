#include <cstdio>

int a[1000],n,stack[1000],top;
bool work(char s[]){
    int x=n=0;
    for (int i=0;s[i];i++){
        if (s[i]==' '){
            if (x!=0)
                a[n++]=x,x=0;
        }
        else
            x=x*10+s[i]-48;
    }
    if (x!=0)
        a[n++]=x;
    for (int i=0;i<n;i++)
        stack[i]=0;
    for (int i=0;i<3&&i<n;i++)
        if (a[i]!=i+9)
            return false;
    top=0;
    for (int i=3;i<n-1;i++){
        /*printf("a[i]=%d\n",a[i]);
        for (int j=0;j<top;j++)
            printf("%d ",stack[j]);
        puts("");
        getchar();*/
        if (top==0){
            if (a[i]!=1)
                return false;
            stack[top++]=1;
        }
        else{
            if (stack[top-1]==1){
                if (a[i]!=2)
                    return false;
                stack[top-1]=2;
            }
            else if (stack[top-1]==2){
                if (a[i]!=3&&a[i]!=4)
                    return false;
                if (a[i]==3)
                    stack[top-1]=3;
                else if (a[i]==4)
                    stack[top-1]=4;
            }
            else if (stack[top-1]==3){
                if (a[i]!=7)
                    return false;
                stack[top-1]=7;
            }
            else if (stack[top-1]==4){
                if (a[i]!=5)
                    return false;
                stack[top-1]=5;
            }
            else if (stack[top-1]==5){
                if (stack[top]==0){
                    if (a[i]!=1)
                        return false;
                    stack[top++]=1;
                }
                else if (stack[top]==8){
                    stack[top]=0;
                    if (a[i]!=6)
                        return false;
                    stack[top-1]=6;
                }
            }
            else if (stack[top-1]==6){
                if (stack[top]==0){
                    if (a[i]!=1)
                        return false;
                    stack[top++]=1;
                }
                else if (stack[top]==8){
                    stack[top]=0;
                    if (a[i]!=7)
                        return false;
                    stack[top-1]=7;
                }
            }
            else if (stack[top-1]==7){
                if (a[i]!=8)
                    return false;
                stack[top-1]++;
                top--;
            }
        }
    }
    return top==0&&a[n-1]==12&&n>4;
}
int main()
{
    char s[10000];
    while (gets(s),s[0]!='0'||s[1]!=0)
        puts((work(s))?"valid":"invalid");
}
