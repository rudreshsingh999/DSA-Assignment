#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int ar[100];

int merge(int l, int mid, int h) {
	int ar1[mid-l+1];
	int ar2[h-mid];
	int ar3[h-l+1];
	int inv_count = 0;
	for(int x = l; x <= mid; x++) {
		ar1[x-l] = ar[x];
	}

	for(int x = mid+1; x <= h; x++) {
		ar2[x-mid-1] = ar[x];
	}

	int i = 0, j = 0, k = 0;
	while(i < (mid-l+1) && j < (h-mid)) {
		if(ar1[i] <= ar2[j]) {
			ar3[k] = ar1[i];
			k++;
			i++;
		}
		else {
			ar3[k] = ar2[j];
			inv_count += (mid - l + 1 - i); 
			k++;
			j++;
		}
	}

	while(i < (mid-l+1)) { 
		ar3[k] = ar1[i];
		k++;
		i++;
	}

	while(j < (h-mid)) {
		ar3[k] = ar2[j];
		k++;
		j++;
	}

	for (int x = l; x <= h; x++) {
		ar[x] = ar3[x-l];
	}

	return inv_count;
}

int merge_sort(int l, int h) {
	int inv_count = 0;
	if(l == h) {
		return inv_count;
	}
	int mid = (l + h)/2;
	inv_count +=  merge_sort(l, mid);
	inv_count +=  merge_sort(mid+1, h);
	inv_count += merge(l, mid, h);
	return inv_count;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int x = 0; x < n; x++) {
		scanf("%d", &ar[x]);
	}
	int r = merge_sort(0, n-1);
	printf("%d\n", r);
}