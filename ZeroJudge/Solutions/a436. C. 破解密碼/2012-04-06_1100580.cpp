#include <cstdio>
#include <cstring>

int n,len[8],Anslen,F[8][40000],K[8];
char A[8][40000],B[8][40000],C[8][40000],ANS[40000];
char cut(char b,char a){
    if (b<a)
        return b+26-a;
    return b-a;
}
void count_f(char s[],int f[],int len){
    int k=f[0]=-1;
    for (int i=1;i<len;i++){
        while (k!=-1&&s[k+1]!=s[i])
            k=f[k];
        if (s[k+1]==s[i])
            k++;
        f[i]=k;
    }
}
void Match(char s[],char p[],int f[],int len,int &k){
    k=-1;
    for (int i=0;i<len;i++){
        while (k!=-1&&p[k+1]!=s[i])
            k=f[k];
        if (p[k+1]==s[i])
            k++;
    }
    if (k==len-1)
        k=f[k];
}
void work(){
    for (int i=0;i<n;i++)
        if (len[i]-K[i]-1>Anslen)
            Anslen=len[i]-K[i]-1;
    while (1){
        bool fail=false;
        for (int i=0;i<n;i++){
            if (K[i]==-1)
                continue;
            while (K[i]!=-1&&len[i]-K[i]-1<Anslen)
                K[i]=F[i][K[i]];
            if (len[i]-K[i]-1>Anslen)
                Anslen=len[i]-K[i]-1,fail=true;
        }
        if (!fail)
            break;
    }
    for (int i=0;i<n;i++)
        if (len[i]>=Anslen){
            for (int j=0;j<Anslen;j++)
                ANS[j]=C[i][j];
            break;
        }
    for (int i=0;i<n;i++)
        for (int j=0;j<len[i]&&j<Anslen;j++)
            if (C[i][j]!=ANS[j]){
                puts("-");
                return;
            }
    ANS[Anslen]='\0';
    puts(ANS);
}
int main()
{
    int cases;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            scanf("%s %s",A[i],B[i]);
            len[i]=strlen(A[i]);
            for (int j=0;j<len[i];j++)
                C[i][j]=cut(B[i][j],A[i][j])+'A';
            C[i][len[i]]='\0';
            //printf("%s %s %s\n",A[i],B[i],C[i]);
            count_f(B[i],F[i],len[i]);
            Match(C[i],B[i],F[i],len[i],K[i]);
            //printf("K %d\n",K[i]);
        }
        Anslen=0;
        work();
    }
}
