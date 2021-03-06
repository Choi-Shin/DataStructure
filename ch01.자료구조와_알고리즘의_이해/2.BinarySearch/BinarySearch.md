## Binary Search Algorithm
---
+ 이진 탐색 알고리즘의 조건 
    `배열에 저장된 데이터는 정렬되어 있어야 한다.`
+ 이진 탐색 알고리즘의 구현
    <img src="../images/이진%20탐색%20알고리즘의%20탐색%20시작과%20끝%20위치의%20변화.001.jpeg" width="70%">
    1. first 인덱스와 last 인덱스를 더한 값을 2로 나눈 후 나머지는 버린다.`floor()`
    2. 1의 값을 가지는 인덱스(mid)와 찾으려는 값 x의 비교연산을 수행하여 
        + <!-- $x < arr[mid]$ --> <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=x%20%3C%20arr%5Bmid%5D"> 라면  <!-- $last = mid - 1$ --> <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=last%20%3D%20mid%20-%201">
        + <!-- $x > arr[mid]$ --> <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=x%20%3E%20arr%5Bmid%5D"> 라면 <!-- $first = mid + 1$ --> <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=first%20%3D%20mid%20%2B%201">
        + <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=x%20%3D%3D%20arr%5Bmid%5D"> 라면 탐색 종료
        <!-- $x == arr[mid]$ -->
~~~ C
#include <stdio.h>

int Bsearch(int ar[], int len, int target) {
    int first = 0; //탐색 대상의 시작 인덱스 값
    int last = len-1; //탐색 대상의 마지막 인덱스 값
    int mid;

    while(first <= last) {   // 이 부분이 중요한 이유는 first와 last가 같은 상황이 마지막 연산이기 때문
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
+ ###### BinarySearch.c 실행 결과
> 타겟 저장 인덱스: 3
> 탐색 실패
----
#### Binary Search Algorithm의 시간 복잡도 : 최악의 경우를 기준으로
+ 최악의 경우 : 값이 존재하지 않는 상황으로 설정
    - 데이터의 갯수 
        <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=n">
    - <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=n">이 1이 되기까지 2로 나눈 횟수 <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=k">
    - 마지막 데이터가 남았을 때 비교 연산 1회 진행
    - 최악의 경우에 대한 시간 복잡도 함수 <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=T(n)%3Dk%2B1">
+ <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=T(n)%3Dk%2B1">에 대한 연산 (k값 구하기)
    + n값 정의 
      - <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=n%5Ctimes(%5Cfrac%7B1%7D%7B2%7D)%5Ek%3D1">
      - <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=n%5Ctimes2%5E%7B-k%7D%3D1">
      - <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=n%20%3D%202%5Ek">
    + k값 정의
      - <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=%5Clog_2n%3Dk">
      - <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=%5Ctherefore%20T(n)%3D%5Clog_2n">