#include <cstdio>

int len;
char number[5][100]={"..#######...#.###################"
                    ,"..#..#..#.#.#.##..#..#.##.##.##.#"
                    ,"..####################.########.#"
                    ,"..##....#.#...#..##.#..##.#..##.#"
                    ,"..#######.....#######..##########"};
char c[20]={"123+4567890"};
char s[5][1000];
char ans[500];
bool cmp(int x,int y){
    for (int i=0;i<5;i++)
        for (int j=0;j<3;j++)
            if (number[i][x+j]!=s[i][y+j])
                return false;
    return true;
}
void work(){
    int num=0,len=0;
    for (int i=0;s[0][i];i++){
        if (s[i+2]==0)
            break;
        int p=-1;
        for (int j=0;j<11;j++)
            if (cmp(j*3,i)){
                p=j;
                break;
            }
        if (p!=-1){
            ans[len++]=c[p];
            i+=2;
        }
    }
    ans[len]=0;
    int x=0,sum=0;
    for (int i=0;ans[i];i++){
        if (ans[i]=='+'){
            sum+=x;
            x=0;
        }
        else
            x=x*10+ans[i]-48;
    }
    printf("%d\n",sum+x);
}
int main()
{
    int cases;
    char tmp[1000];
    scanf("%d",&cases);
    while (cases--){
        for (int i=0;i<5;i++)
            scanf("%s",s[i]);
        work();
    }
}

/*
..#######...#.###################
..#..#..#.#.#.##..#..#.##.##.##.#
..####################.########.#
..##....#.#...#..##.#..##.#..##.#
..#######.....#######..##########
*/
