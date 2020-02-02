#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ar[100];
void merge(int l, int mid, int h) {
	int ar1[mid-l+1];
	int ar2[h-mid];
	int ar3[h-l+1];

	for(int x = l; x <= mid; x++) {
		ar1[x-l] = ar[x];
		// level1[x-l] = level[x];
	}

	for(int x = mid+1; x <= h; x++) {
		ar2[x-mid-1] = ar[x];
		// level2[x-mid-1] = level[x];
	}

	int i = 0, j = 0, k = 0;
	while(i < (mid-l+1) && j < (h-mid)) {
		if(ar1[i] <= ar2[j]) {
			ar3[k] = ar1[i];
			// level3[k] = level1[i];
			k++;
			i++;
		}
		else {
			ar3[k] = ar2[j];
			// level3[k] = level2[j];
			k++;
			j++;
		}
	}

	while(i < (mid-l+1)) { 
		// level3[k] = level1[i];
		ar3[k] = ar1[i];
		k++;
		i++;
	}

	while(j < (h-mid)) {
		ar3[k] = ar2[j];
		// level3[k] = level2[j];
		k++;
		j++;
	}

	for (int x = l; x <= h; x++) {
		ar[x] = ar3[x-l];
		// level[x] = level3[x-l];
	}
}

void merge_sort(int l, int h) {
	if(l == h) {
		return;
	}
	int mid = (l + h)/2;
	merge_sort(l, mid);
	merge_sort(mid+1, h);
	merge(l, mid, h);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int x = 0; x < m; x++) {
		scanf("%d", &ar[x]);
	}

	merge_sort(0, m-1);

	int r;
	scanf("%d", &r);
	int q[r];
	for(int x = 0; x < r; x++) {
		scanf("%d", &q[x]);
	}

	for (int x = 0; x < r; x++) {
		int f = 0;
		for (int y = 1; y < m; y++) {
			if(q[x] <= ar[y] && q[x] >= ar[y-1]) {
				printf("%d\n", (ar[y]-q[x]) < (q[x]-ar[y-1]) ? (ar[y]-q[x]) : (q[x]-ar[y-1]));
				f = 1;
				break;
			}
		}
		if(f == 0) {
			printf("%d\n", q[x] - ar[m-1]);
		}
	}

}