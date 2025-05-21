#include <cstdio>

long long v,A=2,B=3;
struct Node {int l,r;} match[200];
int isp[128],icp[128],len,num,now[200],all;
bool use[200];
char se[400],*p;
long long cnt(){
    long long stack[400];
    int top=0;
    for (int i=0;se[i];i++){
        if (se[i]=='a')
            stack[top++]=A;
        else if (se[i]=='b')
            stack[top++]=B;
        else{
            top--;
            if (se[i]=='+')
                stack[top-1]+=stack[top];
            else
                stack[top-1]*=stack[top];
        }
    }
    return stack[0];
}
void insert(char c,char stack[],int &top){
    if (c==')'){
        while (stack[top-1]!='(')
            se[len++]=stack[top-1],top--;
        top--;
        return;
    }
    while (top&&icp[c]<=isp[stack[top-1]])
        se[len++]=stack[top-1],top--;
    stack[top++]=c;
}
void work(char s[]){
    char stack[200];
    len=0;
    int top=0;
    for (int i=1;i<all-1;i++){
        if (s[i]=='x'){
            se[len++]='a';
            insert('+',stack,top);
            se[len++]='b';
        }
        else if (s[i]!=' ')
            insert(s[i],stack,top);
    }
    while (top)
        se[len++]=stack[top-1],top--;
    se[len]='\0';
}
void search(char s[]){
    int stack[200],top=0;
    for (int i=1;s[i+1];i++){
        if (s[i]=='(')
            stack[top++]=i;
        else if (s[i]==')'){
            match[num].l=stack[top-1];
            match[num].r=i;
            num++;
            top--;
        }
    }
}
bool ok(int cut){
    char s[400];
    for (int i=0;p[i];i++)
        s[i]=p[i];
    for (int i=0;i<cut;i++){
        int j=now[i];
        s[match[j].l]=s[match[j].r]=' ';
    }
    work(s);
    return cnt()==v;
}
bool dfs(int x,int d,int cut){
    if (x==cut)
        return ok(cut);
    for (int i=d;i<num+x-cut+1;i++)
        if (!use[i]){
            use[i]=true;
            now[x]=i;
            if (dfs(x+1,i+1,cut))
                return true;
            use[i]=false;
        }
    return false;
}
int main()
{
    isp['+']=icp['+']=1;
    isp['*']=icp['*']=2;
    icp['(']=3;
    isp['(']=0;
    char s[300];
    p=s;
    int cases;
    scanf("%d",&cases);
    gets(s);
    while (cases--){
        gets(s);
        int space=0,at;
        for (int i=0;;i++){
            space+=(int)(s[i]==' ');
            if (space==2){
                at=i+1;
                break;
            }
        }
        all=0;
        for (int i=0;s[i+at-1];i++){
            all++;
            s[i]=s[i+at];
        }
        num=0;
        search(s);
        all--;
        work(s);
        v=cnt();
        int ans;
        for (ans=1;ans<=num;ans++){
            for (int j=0;j<num;j++)
                use[j]=false;
            if (!dfs(0,0,ans))
                break;
        }
        printf("%d\n",ans-1);
    }
}
