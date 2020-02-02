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
	int n;
	scanf("%d", &n);
	// int ar[n];
	for(int x = 0; x < n; x++) {
		scanf("%d", &ar[x]);
	}

	int r;
	scanf("%d", &r);
	int i = -1;
	for(int x = 0; x < n; x++) {
		if(ar[x] == r)
			i = x;
	}
	int f = 0;

	for(int x = 0; x < i; x++) {
		if(ar[x] > r) {
			f=1;
			break;
		}
	}

	for(int x = i+1; x < n; x++) {
		if(ar[x] < r) {
			f = 1;
			break;
		}
	}

	if(f==0) {
		printf("ALL SET");
	}
	else {
		merge_sort(0, n-1);
		for(int x = 0; x < n; x++) {
			printf("%d ", ar[x]);
		}
	}
	printf("\n");

}