#include <stdio.h>
// standard input output.header(입출력 담당.헤더 확장자)
int LSearch(int ar[], int len, int target) {
    int i;
    for(i=0; i<len; i++) {
        if(ar[i] == target) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int arr[] = {3,5,2,4,9};
}