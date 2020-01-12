#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	char s[1000000];
	char w[1000000];
	fgets(s, 1000000, stdin);
	fgets(w, 1000000, stdin);
	printf("%s",s);

	int l = 0;
	int h = strlen(s)-1;

	int alpha_w[26];
	for (int x=0;x<26;x++)
		alpha_w[x]=0;

	for (int x=0;x<strlen(w)-1;x++)
	{
		alpha_w[w[x]-97]++;
	}

	for(int x=0;x<26;x++)
		printf("%d ",alpha_w[x]);
	printf("\n");

	int ini=0;
	while(l<=h)
	{
		int mid = (l+h)/2;
		int alpha[26];
		for (int x=0;x<26;x++)
			alpha[x]=0;

		for (int x=0;x<mid;x++)
		{
			if(s[x]!=32)
				alpha[s[x]-97]++;

		}

		int f=0;
		for (int x=0;x<26;x++)
		{
			if(alpha_w[x] > alpha[x])
			{
				f=1;
				break;
			}
		}

		if(f==0)
		{
			ini = 0;
		}

		if(f==1)
		{
			int i = 0;
			int j = mid;
			for(int x=j;x<strlen(s)-1;x++)
			{
				if(s[x]==32)
				{
					alpha[s[i]-97]--;
					i++;
					continue;
				}
				alpha[s[x]-97]++;
				alpha[s[i]-97]--;
				i++;
				int flag=0;
				for (int y=0;y<26;y++)
				{
					if(alpha_w[y] > alpha[y])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					f=0;
					ini = i;
					break;
				}
			}
		}

		if(f==0)
		{
			h = mid-1;
		}
		else
		{
			l = mid+1;
		}
	}

	printf("%d %d\n",ini,ini+l-1);
	return 0;
}