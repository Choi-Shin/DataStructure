~~~ C
#include <stdio.h>

int Bsearch(int ar[], int len, int target) {
    int first = 0; //탐색 대상의 시작 인덱스 값
    int last = len-1; //탐색 대상의 마지막 인덱스 값
    int mid;

    while(first <= last) {
        mid = (first+last) / 2; //탐색 대상의 중앙 인덱스

        if(target == ar[mid]) { //중앙 인덱스의 값이 타켓과 같으면
            return mid; //탐색 완료
        }
        else {
            if(target < ar[mid])
                last = mid - 1; //직전 중앙 인덱스 값보다 작으므로 마지막 인덱스는 
                                //중앙보다 하나 작은 값으로 설정되어야한다.
            else
                first = mid + 1;
        }
    }
    return -1;
}

int main(void) {
    int arr[] = {1,3,5,7,9};
    int idx;

    idx = Bsearch(arr, sizeof(arr)/sizeof(int), 7);
    if (idx == -1)
        printf("탐색 실패 \n");
    else
        printf("타겟 저장 인덱스: %d \n", idx);

    idx = Bsearch(arr, sizeof(arr)/sizeof(int), 4);
    if (idx == -1)
        printf("탐색 실패 \n");
    else
        printf("타겟 저장 인덱스: %d \n", idx);
    
    return 0;
}
~~~