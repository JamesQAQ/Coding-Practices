#include <cstdio>

int num=0;
struct Node {int l,r,v;} tree[10000];
char password[26][15]={"---."
               ,"--...."
               ,".-..-"
               ,"-----"
               ,".--"
               ,"..-.-"
               ,"--..--"
               ,"-..."
               ,"-.--"
               ,"..-..-.--"
               ,"..-..--"
               ,"----."
               ,"..---"
               ,"-.-."
               ,"--.-"
               ,"--...-"
               ,"..-..-..-"
               ,".-.-"
               ,"-..-"
               ,"..."
               ,".-..."
               ,"..-..."
               ,"..--."
               ,"..-..-.-."
               ,"--..-."
               ,"..-..-..."};
void newnode(int x){
    tree[x].l=tree[x].r=tree[x].v=-1;
}
void insert(char s[],int v){
    int at=0;
    for (int i=0;s[i];i++){
        if (s[i]=='-'){
            if (tree[at].l==-1){
                newnode(num);
                tree[at].l=num++;
            }
            at=tree[at].l;
        }
        else{
            if (tree[at].r==-1){
                newnode(num);
                tree[at].r=num++;
            }
            at=tree[at].r;
        }
    }
    tree[at].v=v;
}
void work(char s[]){
    int at=0;
    for (int i=0;s[i];i++){
        if (s[i]==' '){
            putchar(' ');
            continue;
        }
        else if (s[i]=='-'){
            at=tree[at].l;
            if (tree[at].v!=-1)
                putchar(tree[at].v+'A'),at=0;
        }
        else{
            at=tree[at].r;
            if (tree[at].v!=-1)
                putchar(tree[at].v+'A'),at=0;
        }
    }
}
int main()
{
    newnode(0);
    num=1;
    for (int i=0;i<26;i++)
        insert(password[i],i);
    int cases;
    scanf("%d",&cases);
    char s[201];
    gets(s);
    while (cases--){
        gets(s);
        work(s);
        puts("");
    }
}
