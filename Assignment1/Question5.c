#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s[1000000];
	fgets(s,1000000,stdin);
	
	char words[1000][1000];
	char temp[1000];
	int i=0;
	int j=0;
	for (int x=0;x<strlen(s)-1;x++)
	{
		if(s[x]==32)
		{
			temp[i]='\0';
			strcpy(words[j],temp);
			j++;
			i=0;
			temp[0]='\0';
		}
		else
		{
			temp[i] = s[x];
			i++;
		}
	}

	temp[i]='\0';
	strcpy(words[j],temp);
	j++;
	i=0;
	temp[0]='\0';

	// for(int x=0;x<=j;x++)
	// {
	// 	printf("%s ",words[x]);
	// }

	char str[1000][1000];
	for(int x=0;x<=j;x++)
	{
		int i=0;
		for(int y=strlen(words[x])-1;y>=0;y--)
		{
			str[x][i] = words[x][y];
			i++;
		}
		str[x][i]='\0';
	}

	for(int x=0;x<=j;x++)
	{
		printf("%s ",str[x]);
	}
	printf("\n");
	for(int x=0;x<=j;x++)
	{
		if(strcmp(str[x],words[x]) == 0)
			printf("%s\n",words[x]);
	}
	printf("\n");
	return 0;

}