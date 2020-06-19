/*
문제 링크 : https://nypc.github.io/2019/2019_online_4.html

code by Song Kitae(DKSH)
*/


#include <stdio.h>

int main() {
	
	int arr1[101] = {0, };
	int arr2[101] = {0, };
	int n, tmp;
	int res = 100;
	
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		scanf("%d", &arr1[i]);
	}
	for(int i=0;i<n;i++) {
		scanf("%d", &arr2[i]);
	}
	for(int i=0;i<n;i++) {
		if(arr1[i] == 0) {
			tmp = 0;
			break;
		}
		if(arr2[i] == 0) {
			continue;	
		}
		tmp = arr1[i] / arr2[i];
		if(tmp < res) {
			res = tmp;
		}
	}
	printf("%d", tmp);
		
	return 0;
}
