#include <stdio.h>

int main() {
	
	int n;
	int mx = -1000001, mn = 1000001;
	
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		int tmp;
		scanf("%d", &tmp);
        if(mn > tmp) {
			mn = tmp;
		}
		if(mx < tmp) {
			mx = tmp;
		}
        
	}
	printf("%d %d", mn, mx);
	
	return 0;
}