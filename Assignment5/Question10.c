#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


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

    int r;
    scanf("%d", &r);

    int l = 0;
    int h = n-1;
    int i = -1;
    while(l<=h) {
    	int mid = (l+h)/2;
    	if(ar[mid] < ar[mid-1]) {
    		i = mid;
    		break;
    	}

    	if(ar[mid] < ar[h]) {
    		h = mid - 1;
    	}
    	else {
    		l = mid + 1;
    	}
    }
    int found = -1;
    if(r <= ar[n-1]) {
    	int low = i;
    	int high = n-1;
    	while(low <= high) {
    		int mid = (low + high)/2;
    		if(ar[mid] == r) {
    			found = mid;
    			break;
    		}
    		else if(ar[mid] < r) {
    			low = mid + 1;
    		}
    		else 
   				high = mid - 1;
    	}
    }
    else {
    	int low = 0;
    	int high = i-1;
    	while(low <= high) {
    		int mid = (low + high)/2;
    		if(ar[mid] == r) {
    			found = mid;
    			break;
    		}
    		else if(ar[mid] < r) {
    			low = mid + 1;
    		}
    		else 
   				high = mid - 1;
    	}
    }

    if(found == -1) 
    	printf("NO");
    else
    	printf("YES\n%d\n", found);
}