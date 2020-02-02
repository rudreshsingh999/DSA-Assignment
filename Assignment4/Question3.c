#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void countSort() {
	int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++) { 
    	char r = arr[i][leng[i]]-48;
        count[arr[i][leng[i]]]++;
    }
	
	for (i = 1; i < 10; i++) 
        count[i] += count[i - 1];


}

void radixsort(char arr[][52], int n, int leng[], int len) { 
    for (int x = 0; x < len; x++) {
    	countSort();
    } 
}

int main() {
	int n;
	scanf("%d", &n);
	char str[n][52];
	int c = 0;
	for(int x = 0; x < n; x++) {
		scanf("%s", str[x]);
		if(str[x][0] == '-') {
			c++;
		}
	}

	
	char s1[c][52];
	char s2[n-c][52];
	int leng1[c];
	int leng2[n-c];
	int i = 0, j = 0;
	int len1 = 0;
	int len2 = 0;
	for(int x = 0; x < n; x++) {
		if(str[x][0] == '-') {
			strcpy(s1[i], str[x]);
			if(strlen(s1[i]) > len1)
				len1 = strlen(s1[i]);
			leng1[i] = strlen(s1[i]);
			i++;
		}
		else {
			strcpy(s2[j], str[x]);
			if(strlen(s2[j]) > len2)
				len2 = strlen(s2[j]);
			leng2[j] = strlen(s2[j]);
			j++;
		}
	}



	for(int x = 0; x < c; x++) {
		printf("%s\n", s1[x]);
	}
}	