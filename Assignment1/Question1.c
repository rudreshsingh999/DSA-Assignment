#include <stdio.h>
int main() {

	int n1, m1;
	scanf("%d%d", &n1, &m1);
	int ar1[n1][m1];
	for (int x = 0; x < n1; x++) {
		for (int y = 0; y < m1; y++) {
			scanf("%d",&ar1[x][y]);
		}
	}

	int n2, m2;
	scanf("%d%d", &n2, &m2);
	int ar2[n2][m2];
	for (int x = 0; x < n2; x++) {
		for (int y = 0; y < m2; y++) {
			scanf("%d",&ar2[x][y]);
		}
	}

	for (int x = 0; x < n1; x++) {
		for (int y = 0; y < m1; y++) {
			printf("%d ", ar1[x][y]);
		}
		printf("\n");
	}
	int flag = 0;
	int flag1 = 0;
	for (int x = 0; x < n1-n2+1; x++) {
		for (int y = 0; y < m1-m2+1; y++) {
			flag = 0;
			for (int i = 0; i < n2; i++) {
				for (int j = 0; j < m2; j++) {
					if (ar2[i][j] != ar1[x+i][y+j]) {
						flag = 1;
						break;
					}
				} 
				if (flag == 1)
					break;
			}
			if (flag == 0) {
				printf("YES\n");
				printf("%d %d\n",x,y);
				flag1 = 1;
				break;
			}
		}
		if (flag1 == 1)
			break;
	}
	if (flag1 == 0)
		printf("NO\n");
	return 0;
}