#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int low[1000];
int high[1000];

void merge(int l, int mid, int h) {
	int ar1[mid-l+1];
	int ar2[h-mid];
	int ar3[h-l+1];

	int level1[mid-l+1];
	int level2[h-mid];
	int level3[h-l+1];
	for(int x = l; x <= mid; x++) {
		ar1[x-l] = high[x];
		level1[x-l] = low[x];
	}

	for(int x = mid+1; x <= h; x++) {
		ar2[x-mid-1] = high[x];
		level2[x-mid-1] = low[x];
	}

	int i = 0, j = 0, k = 0;
	while(i < (mid-l+1) && j < (h-mid)) {
		if(ar1[i] < ar2[j]) {
			ar3[k] = ar1[i];
			level3[k] = level1[i];
			k++;
			i++;
		}
		else if(ar1[i] > ar2[j]) {
			ar3[k] = ar2[j];
			level3[k] = level2[j];
			k++;
			j++;
		}
		else {
			if(level1[i] < level2[j]) {
				level3[k] = level2[j];
				ar3[k] = ar2[j];
				k++;
				j++;
			}
			else {
				ar3[k] = ar1[i];
				level3[k] = level1[i];
				k++;
				i++;
			}
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
		high[x] = ar3[x-l];
		low[x] = level3[x-l];
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


	for(int x = 0; x < n; x++) {
		scanf("%d %d", &low[x], &high[x]);
	}
	merge_sort(0, n-1);
	
	// for (int x = 0; x < n; x++) {
	// 	printf("%d %d\n", low[x], high[x]);
	// }

	int c = 1;
	int h = high[0];
	for (int x = 1; x < n; x++) {
		if(low[x] > h) {
			c++;
			h = high[x];
		}
	}

	printf("%d\n", c);
}