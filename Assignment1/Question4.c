#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	char s[1000000];
	fgets(s,1000000,stdin);
	int l=1;
	int h=strlen(s)-1;
	// printf("%d\n",h);
	int ini=0;
	while(l<=h)
	{
		int mid = (l+h)/2;
		int alpha[26];
		for(int x=0;x<26;x++)
			alpha[x]=0;
		int f=0;
		for(int x=0;x<mid;x++)
		{
			alpha[s[x]-97]++;
			if(alpha[s[x]-97]>=2)
			{
				f=1;
				// printf("Yes");
			}
		}
		if(f==0)
		{
			ini=0;
		}
		if(f==1)
		{
			int i=0;
			for(int x=mid;x<strlen(s)-1;x++)
			{
				alpha[s[i]-97]--;
				i++;
				alpha[s[x]-97]++;
				int flag=0;
				for(int y=0;y<26;y++)
				{
					if(alpha[y]>=2)
					{
						// printf("yes");
						flag=1;
						break;
					}
				}
				if(flag == 0)
				{
					f=0;
					ini=i;
					break;
				}
			}
		}

		if(f==0)
		{
			l = mid+1;
			// printf("%d\n",l);
		}
		else
		{
			h = mid-1;
			// printf("%d\n",h);
		}
	}
	printf("%d %d",l-1,ini);
	printf("\n");
	return 0;
}