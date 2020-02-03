#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);
	char str[n][52];
	int c = 0;

	for(int x = 0; x < n; x++) {
		scanf("%s", str[x]);
	}

	
	for (int x = 0; x < n; x++) {
		for(int y = 0; y < n-1; y++) {
			if(strlen(str[y]) < strlen(str[y+1]) && str[y][0] != '-' && str[y+1][0] != '-') {
				char temp[52];
				strcpy(temp, str[y]);
				strcpy(str[y], str[y+1]);
				strcpy(str[y+1], temp);
			}
			else if(strlen(str[y]) > strlen(str[y+1]) && str[y][0] == '-' && str[y+1][0] == '-') {
				char temp[52];
				strcpy(temp, str[y]);
				strcpy(str[y], str[y+1]);
				strcpy(str[y+1], temp);
			}
			else if(str[y][0] == '-' && str[y+1][0] != '-') {
				char temp[52];
				strcpy(temp, str[y]);
				strcpy(str[y], str[y+1]);
				strcpy(str[y+1], temp);
			}
			else if(strlen(str[y]) == strlen(str[y+1])) {
				if(str[y][0] == '-' && str[y+1][0] != '-') {
					char temp[52];
					strcpy(temp, str[y]);
					strcpy(str[y], str[y+1]);
					strcpy(str[y+1], temp);
				}
				else if (str[y][0] != '-' && str[y+1][0] == '-') {
				}
				else {
					if(str[y][0] != '-' && str[y+1][0] != '-') {
						for (int z = 0; z <= strlen(str[y]) - 1; z++) {
							if(str[y][z] < str[y+1][z]) {
								char temp[52];
								strcpy(temp, str[y]);
								strcpy(str[y], str[y+1]);
								strcpy(str[y+1], temp);
								break;
							}
							else if(str[y][z] > str[y+1][z]) {
								break;
							}
						}	
					}
					else {
						for (int z = 1; z <= strlen(str[y]) - 1; z++) {
							if(str[y][z] > str[y+1][z]) {
								char temp[52];
								strcpy(temp, str[y]);
								strcpy(str[y], str[y+1]);
								strcpy(str[y+1], temp);
								break;
							}
							else if(str[y][z] < str[y+1][z]) {
								break;
							}
						}	
					}
				}
			}
 		}
	}
	
	for(int x = 0; x < n; x++) {
		printf("%s\n", str[x]);
	}
}	