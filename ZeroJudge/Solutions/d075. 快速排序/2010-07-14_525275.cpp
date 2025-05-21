#include <iostream>
#include <sstream>
#include <stdio.h>
using namespace std;

int a[100001]={};
bool compar(int i, int j)
{
	if (a[i]>a[j])
		return 1;
	if (a[i]<a[j])
		return 0;
	return 1;
}
int main()
{
	string s;
	int t[100001]={};
	while (getline(cin,s))
	{
		stringstream ss(s);
		int i=0;
		while (ss>>a[i])
			i++;
		for (int j=0;j<i;j++)
			t[j]=j;
		sort(t,t+i,compar);
		for (int j=0;j<i;j++)
			printf("%d ",a[t[j]]);
		printf("\n");
	}
	//system("pause");
	return 0;
}
