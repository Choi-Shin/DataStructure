#include <stdio.h>

int BSearch(int ar[], int len, int target){
    int first = 0;
    int mid;
    int last = len-1;
    int opCount = 0; //연산횟수 기록 (기준은 "==")

    while (first <= last) {
        mid = (first + last) / 2;
        if (ar[mid] == target)
            return mid;
        else {
            if(target < ar[mid]) {
                last = mid - 1;
            } else
                first = mid + 1;
        }
        opCount += 1; //while문 한번 돌 때마다 카운트 1씩 올려줌.
    }
    printf("비교연산횟수: %d \n", opCount);
    return -1;
}

int main(void) {
    int arr1[500] = {0,};
    int arr2[5000] = {0,};
    int arr3[50000] = {0,};
    int idx;
    //존재하지 않는 타켓 정수로 검색=>실패하므로 모든 연산의 횟수가 출력
    idx = BSearch(arr1, sizeof(arr1)/sizeof(int), 1);
    if (idx == -1)
        printf("탐색실패 \n\n");
        else printf("타겟 저장 인덱스: %d \n", idx);

    idx = BSearch(arr2, sizeof(arr2)/sizeof(int), 2);
    if (idx == -1)
        printf("탐색실패 \n\n");
        else printf("타겟 저장 인덱스: %d \n", idx);

    idx = BSearch(arr3, sizeof(arr3)/sizeof(int), 3);
    if (idx == -1)
        printf("탐색실패 \n\n");
        else printf("타겟 저장 인덱스: %d \n", idx);
    
    return 0;
}