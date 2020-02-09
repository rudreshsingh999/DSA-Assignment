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

    int n, m, l;
    scanf("%d %d %d", &n, &m, &l);
    int u, v, a, b, k;
    scanf("%d%d%d%d%d", &u, &v, &a, &b, &k);

    int ar1[m];
    for(int x = 0; x < m; x++) {
    	scanf("%d", &ar1[x]);
    }
    int ar2[l];
    for(int x = 0; x < l; x++) {
    	scanf("%d", &ar2[x]);
    }

    merge_sort(ar1, 0, m-1);
    merge_sort(ar2, 0, l-1);
    int i,j;
    for(int x = 0; x < m; x++) {
    	if(ar1[x] == u) {
    		i = x;
    	}
    	if(ar1[x] == v) {
    		j = x;
    	}
    }
    int ans = 0;
    for(int x = i; x < j; x++) {
    	int r = ar1[x+1] - ar1[x];
    	r = (r - b) > 0 ? (r-b) : 0;
    	if(r%a != 0) {
    		r = r/a + 1;
    	}
    	else {
    		r = r/a;
    	}
    	if(r == 0)
    		r = 1;
    	
    	int low = 0;
    	int high = l-1;
    	while(low <= high) {
    		int mid = (low+high)/2;
    		if(ar2[mid] < r) {
    			low = mid + 1;
    		}
    		else {
    			high = mid - 1;
    		}
    	}

    	ans = ans + ar2[low];
    }

    printf("%d\n", ans*k);
}