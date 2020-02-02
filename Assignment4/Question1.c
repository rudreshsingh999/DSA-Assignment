#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


struct Cord {
	int id;
	double slope;
	double dist;
};
struct Cord cord[100-1];
void merge(int l, int mid, int h) {
	struct Cord ar1[mid-l+1];
	struct Cord ar2[h-mid];
	struct Cord ar3[h-l+1];

	for(int x = l; x <= mid; x++) {
		ar1[x-l] = cord[x];
	}

	for(int x = mid+1; x <= h; x++) {
		ar2[x-mid-1] = cord[x];
		// level2[x-mid-1] = level[x];
	}

	int i = 0, j = 0, k = 0;
	while(i < (mid-l+1) && j < (h-mid)) {
		if(ar1[i].slope < ar2[j].slope) {
			ar3[k] = ar1[i];
			k++;
			i++;
		}
		else if(ar1[i].slope > ar2[j].slope){
			ar3[k] = ar2[j];
			k++;
			j++;
		}
		else {
			if(ar1[i].dist < ar2[j].dist) {
				ar3[k++] = ar1[i++];
			}
			else {
				ar3[k++] = ar2[j++];
			}
		}
	}

	while(i < (mid-l+1)) { 
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
		cord[x] = ar3[x-l];
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

int main()
{
	int n;
	scanf("%d", &n);
	
	int ar1[n],ar2[n],ar3[n];
	int min = 10000;
	int min_id;
	for (int x = 0; x < n; x++) {
		scanf("%d%d%d", &ar1[x], &ar2[x], &ar3[x]);
		if(ar3[x] < min) {
			min = ar3[x];
			min_id = x;
		}	
	}
	int i = 0;
	for(int x = 0; x < n; x++) {
		if(x != min_id) {
			cord[i].slope = (double)((ar3[x] - ar3[min_id]))/(ar2[x] - ar2[min_id]);
			cord[i].dist = abs(ar3[x] - ar3[min_id]) + abs(ar2[x] - ar2[min_id]);
			cord[i].id = ar1[x];
			i++;
		}
	}

	merge_sort(0, n-2);

	for(int x = 0; x < n-1; x++) {
		printf("%d %lf %lf\n", cord[x].id, cord[x].slope, cord[x].dist);
	}


	return 0;
}