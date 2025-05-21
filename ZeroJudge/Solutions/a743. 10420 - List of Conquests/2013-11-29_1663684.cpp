#include <stdio.h>
#include <string.h>
#include <algorithm>

char name[2000][100];
int num=0,cnt[2000];

int get(char s[]){
    for (int i=0;i<num;i++)
        if (strcmp(name[i],s)==0)
            return i;
    strcpy(name[num],s);
    num++;
    cnt[num-1]=0;
    return num-1;
}

void work(char s[]){
    for (int i=0;s[i];i++)
        if (s[i]==' '){
            s[i]='\0';
            break;
        }
    int x=get(s);
    cnt[x]++;
}

int t[2000];

bool cmp(int i,int j){
    return strcmp(name[i],name[j])<0;
}

int main()
{
    int n;
    char s[100];
    scanf("%d",&n);
    gets(s);
    for (int i=0;i<n;i++)
        gets(s),work(s);
    for (int i=0;i<num;i++)
        t[i]=i;
    std::stable_sort(t,t+num,cmp);
    for (int j=0;j<num;j++){
        int i=t[j];
        printf("%s %d\n",name[i],cnt[i]);
    }
}
