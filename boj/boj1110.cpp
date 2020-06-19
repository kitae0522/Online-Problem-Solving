/*
문제 링크 : https://www.acmicpc.net/problem/1110

code by Song Kitae(DKSH)
*/


#include <stdio.h>

int main() {
    int num, new_number;
    int check_number = 0;
    int i = 0;
    scanf("%d", &num);
    check_number = num;
    
    while (1) {
        int tmp;
        tmp = (num/10) + (num%10);
        new_number = 10*(num%10) + (tmp%10);
        i++;
		num = new_number;
        if(num == check_number) {
            break;
        }
    }
    printf("%d", i);

    return 0;
}
