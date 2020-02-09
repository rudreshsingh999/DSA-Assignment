#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void merge (int ar[], int l, int mid, int h) {
	int ar1[mid - l + 1];
	int ar2[h - mid];

	for(int x = l; x <= mid; x++) {
		ar1[x-l] = ar[x];
	}

	for(int x = mid+1; x <= h; x++) {
		ar2[x-mid-1] = ar[x];
	}

	int i = 0;
	int j = 0;
	int k = 0;
	int ar3[h-l+1];
	while(i <= (mid - l)  && j <= (h - mid - 1)) {
		if(ar1[i] <= ar2[j]) {
			ar3[k++] = ar1[i++];
		}
		else {
			ar3[k++] = ar2[j++];
		}
	}

	while(i <= (mid - l)) {
		ar3[k++] = ar1[i++];
	}

	while(j <= (h - mid - 1)) {
		ar3[k++] = ar2[j++];
	}

	for(int x = l; x <= h; x++) {
		ar[x] = ar3[x-l];
	}
}

void merge_sort(int ar[], int l, int h) {
	if(l >= h)
		return;
	int mid = (l+h)/2;
	merge_sort(ar, l, mid);
	merge_sort(ar, mid+1, h);
	merge(ar, l, mid, h);
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);

    int ar[n];
    for(int x = 0; x < n; x++) {
    	scanf("%d", &ar[x]);
    }

    merge_sort(ar, 0, n-1);
    int i = 1;
    int ans = 1;
    for(int x = 1; x < n; x++) {
    	if(ar[x] == ar[x-1]) {
    		ans = ans + i;
    	}
    	else {
    		i++;
    		ans = ans + i;
    	}
    }
    printf("%d\n", ans);
}