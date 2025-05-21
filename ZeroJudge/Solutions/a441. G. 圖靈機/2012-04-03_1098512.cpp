#include <cstdio>
#include <cstring>

int S,M;
struct Node {char c,m;int s;} ch[101][26];
char s[200000];
void test(){
    int at=0,st=3,len=strlen(s)+1;
    for (int i=len;i>0;i--)
        s[i]=s[i-1];
    s[0]='s';
    while (1){
        Node *p=&ch[st][s[at]-'a'];
        st=p->s;
        if (st==1){
            printf("yes %s\n",s);
            return;
        }
        else if (st==2){
            puts("no");
            return;
        }            
        s[at]=p->c;
        if (p->m=='>')
            at++;
        else if (p->m=='<')
            at--;
        if (at>=len)
            s[len]='u',s[++len]='\0';
    }
}
int main()
{
    int T,P,Q,n;
    char A,B,D;
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        scanf("%d %d",&S,&M);
        int all=(S-2)*(M+2);
        for (int i=0;i<all;i++){
            scanf("%d %c %d %c %c",&P,&A,&Q,&B,&D);
            Node *p=&ch[P][A-'a'];
            p->c=B,p->m=D,p->s=Q;
        }
        scanf("%d",&n);
        gets(s);
        for (int i=0;i<n;i++){
            gets(s);
            test();
        }
    }
    return 0;
}
