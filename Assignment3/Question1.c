#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int ar[500];
void merge(int l, int mid, int h) {
	int ar1[mid-l+1];
	int ar2[h-mid];
	int ar3[h-l+1];
	for (int x = l; x <= mid; x++)
		ar1[x-l] = ar[x];

	for (int x = mid+1; x <= h; x++)
		ar2[x-mid-1] = ar[x];

	int i = 0, j = 0, k = 0;
	while(i <= mid-l && j <= h-mid-1) {
		if(ar1[i] <= ar2[j])
			ar3[k++] = ar1[i++];
		else 
			ar3[k++] = ar2[j++];
	}

	while(i <= mid-l) {
		ar3[k++] = ar1[i++];

	while (j <= h-mid-1)
		ar3[k++] = ar2[j++];

	for (int x = l; x <= h; x++)
		ar[x] = ar3[x-l];
}

void mergesort(int l, int h) {
	if (l == h) 
		return;
	int mid = (l+h)/2;
	mergesort(l, mid);
	mergesort(mid+1, h);
	merge(l, mid, h);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int x = 0; x < n; x++) {
		scanf("%d",&ar[x]);
	}

	mergesort(0,n-1);

	// for (int x = 0; x < n; x++) {
	// 	printf("%d ", ar[x]);
	// }

	int r = n/2;
	int c1 = 0, c2 = 0;
	for (int x = 0; x < n; x++) {
		if (ar[x] == ar[r]) 
			c1++;
		if (ar[x] == ar[r-1]) 
			c2++;
	}

	if(c1 >= (n+1)/2)
		printf("%d", ar[r]);
	else if(c2 >= (n+1)/2)
		printf("%d", ar[r-1]);
	else
		printf("NO MAJORITY ELEMENT");

	printf("\n");
	return 0;
}