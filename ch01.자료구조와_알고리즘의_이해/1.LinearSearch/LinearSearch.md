### 순차 탐색 알고리즘과 시간 복잡도 분석의 핵심요소
###### Linear Search Algorithm
---
~~~ C
#include <stdio.h>
// standard input output.header(입출력 담당.헤더 확장자)
int LSearch(int ar[], int len, int target) {
    int i;
    for(i=0; i<len; i++) {
        if(ar[i] == target) {
            return i; // 찾은 대상의 인덱스 값 반환
        }
    }
    return -1; // 찾지 못했음을 의미하는 값 반환
}

int main(void) {
    int arr[] = {3,5,2,4,9};
    int idx;

    idx = LSearch(arr, sizeof(arr)/sizeof(int), 4);
    if(idx == -1)
        printf("탐색 실패 \n");
    else printf("타겟 저장 인덱스: %d \n", idx);

    idx = LSearch(arr, sizeof(arr)/sizeof(int), 7);
    if(idx == -1)
        printf("탐색 실패 \n");
    else printf("타겟 저장 인덱스: %d \n", idx);

    return 0;
}
~~~

+ ###### LinearSearch.c 실행 결과
> 타겟 저장 인덱스: 3
> 탐색 실패
---
+ 탐색 알고리즘 내에서 연산횟수의 기준이 되는 연산자
    - <!-- $==$ --> <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=%3D%3D"> (동등비교 연산자)
    - 비교 연산의 횟수가 줄어든다는 것은 <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=%3C%2C%20%3E%2C%20%2B%2B%2C%20--"> 등 반복문 종료에 다다르기 위한 연산의 수행횟수가 줄어들기 때문이다.
    - 다른 연산들은 동등비교 연산자에 의존적이다.
    - <!-- $\therefore$ --> <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=%5Ctherefore"> == 연산의 횟수를 대상으로 시간 복잡도를 분석한다.
---
+  순차탐색 알고리즘의 비교연산횟수 계산해보기
    - 최선의 경우(best case) : 찾고자 하는 값이 첫번째 인덱스에 존재할 때
    그 수행의 횟수는 1이다.
    - 최악의 경우(worst case) : 찾고자 하는 값이 마지막 인덱스에 존재할 때나, 값이 없는 경우는 비교연산의 수행횟수가 n(탐색의 대상이 되는 요소의 수)이다.
    - 데이터의 수가 많아질 수록 `최악의 경우`에 수행하게 되는 연산의 횟수는
    큰 차이를 보인다. (`최선의 경우에는 항상 1회 수행`)
    - `평균적인 경우(average case)`가 합리적이어 보이지만
    실제론 평균이라는 기준에 부합하는 요소가 다각도에서 수집되어야하므로
    논란의 소지가 존재할 수 있다.
    - <!-- $\therefore$ --> <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=%5Ctherefore"> 알고리즘의 판단요소는 `최악의 경우`이다.
    1. Linear Search - worst case
        > 데이터의 수가 n개일 때, 최악의 경우에 해당하는 연산횟수는 n이다.
        <!-- $T(n) = n$ --> <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=T(n)%20%3D%20n"> 
    2. Linear Search - average case
        > + 가정 1. 탐색 대상이 배열에 존재하지 않을 확률은 50%이다.
        `탐색 대상이 존재하지 않는 경우의 연산횟수`<!-- $n$ --> <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=n">
        > + 가정 2. 배열의 첫 요소부터 마지막 요소까지, 탐색 대상이 존재할 확률은 동일하다.
        `탐색 대상이 존재하는 경우의 연산횟수`<!-- $\frac{n}{2}$ --> <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=%5Cfrac%7Bn%7D%7B2%7D"> <!-- $\larr$ --> <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=%5Clarr">_근사치_
        - 두 가정에 따른 시간복잡도 함수를 하나로 묶어 평균적인 경우를 계산
            <!-- $n\times\frac{1}{2}+\frac{n}{2}\times\frac{1}{2} = \frac{3}{4}n$ --> <img style="transform: translateY(0.1em); background: white; width:8.5em;" src="https://render.githubusercontent.com/render/math?math=n%5Ctimes%5Cfrac%7B1%7D%7B2%7D%2B%5Cfrac%7Bn%7D%7B2%7D%5Ctimes%5Cfrac%7B1%7D%7B2%7D%20%3D%20%5Cfrac%7B3%7D%7B4%7Dn">
            `가정 1 + 가정 2 = 평균적인 케이스`