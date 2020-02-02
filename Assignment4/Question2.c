#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int ar[100];
int level[100];
void merge(int l, int mid, int h) {
	int ar1[mid-l+1];
	int ar2[h-mid];
	int ar3[h-l+1];

	int level1[mid-l+1];
	int level2[h-mid];
	int level3[h-l+1];
	for(int x = l; x <= mid; x++) {
		ar1[x-l] = ar[x];
		level1[x-l] = level[x];
	}

	for(int x = mid+1; x <= h; x++) {
		ar2[x-mid-1] = ar[x];
		level2[x-mid-1] = level[x];
	}

	int i = 0, j = 0, k = 0;
	while(i < (mid-l+1) && j < (h-mid)) {
		if(ar1[i] <= ar2[j]) {
			ar3[k] = ar1[i];
			level3[k] = level1[i];
			k++;
			i++;
		}
		else {
			ar3[k] = ar2[j];
			level3[k] = level2[j];
			k++;
			j++;
		}
	}

	while(i < (mid-l+1)) { 
		level3[k] = level1[i];
		ar3[k] = ar1[i];
		k++;
		i++;
	}

	while(j < (h-mid)) {
		ar3[k] = ar2[j];
		level3[k] = level2[j];
		k++;
		j++;
	}

	for (int x = l; x <= h; x++) {
		ar[x] = ar3[x-l];
		level[x] = level3[x-l];
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
	// int index[n];
	for (int x = 0; x < n; x++) {
		scanf("%d", &ar[x]);
		level[x] = x+1;
	}
	merge_sort(0, n-1);
	int r;
	scanf("%d", &r);
	// for (int x = 0; x < n; x++) {
	// 	printf("%d ", ar[x]);
	// }	
	int i = -1;
	for (int x = 0; x < n; x++) {
		if(r > 0) {
			r -= ar[x];
			i = x;
		}
	}
	if(r > 0) {
		printf("NO CHANCE");
	}
	else {
		for(int x = 0; x <= i; x++) {
			printf("%d ", level[x]);
		}
	}
	printf("\n");
}