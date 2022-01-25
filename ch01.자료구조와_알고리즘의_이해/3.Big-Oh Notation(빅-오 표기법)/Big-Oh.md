## Big-Oh Notation
---
#### 목차
1. [Big-Oh란?](#1-big-oh란)
2. [단순하게 빅-오 구하기](#2-단순하게-빅-오-구하기)
3. [대표적인 빅-오](#3-대표적인-빅-오)
4. [순차&이진 탐색 알고리즘의 비교](#4-순차--이진-탐색-알고리즘의-비교)
5. [빅-오에 대한 수학적 접근](#5-빅-오에-대한-수학적-접근)
---
#### 1. Big Oh란?
함수 <img style="transform: translateY(0.1em); background: white; width:2em;" src="https://render.githubusercontent.com/render/math?math=T(n)">에서 가장 영향력이 큰 부분이 어딘가를 따지는 것.
> <img style="transform: translateY(0.2em);" src="https://render.githubusercontent.com/render/math?math=T(n)%3Dn%5E2%2B2n%2B1"> 에서
> <img style="transform: translateY(0.1em); width:1em;" src="https://render.githubusercontent.com/render/math?math=n%5E2">이 차지하는 비율의 증가

| <img style="transform: translateY(0.1em); background: white; width:1em;" src="https://render.githubusercontent.com/render/math?math=n"> | <img style="transform: translateY(0.1em); width:2em;" src="https://render.githubusercontent.com/render/math?math=n%5E2"> | <img style="transform: translateY(0.1em); width:2em;" src="https://render.githubusercontent.com/render/math?math=2n"> | <img style="transform: translateY(0.1em); width:3em;" src="https://render.githubusercontent.com/render/math?math=T(n)"> | <img style="transform: translateY(0.1em); width:2em;" src="https://render.githubusercontent.com/render/math?math=n%5E2">의 비율 |
| --------------------------------------------------------------------------------------------------------------------------------------: | -----------------------------------------------------------------------------------------------------------------------: | --------------------------------------------------------------------------------------------------------------------: | ----------------------------------------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------------------------------------------: |
|                                                                                                                                      10 |                                                                                                                      100 |                                                                                                                    20 |                                                                                                                     120 |                                                             83.33%                                                              |
|                                                                                                                                     100 |                                                                                                                   10,000 |                                                                                                                   200 |                                                                                                                  10,200 |                                                             98.04%                                                              |
|                                                                                                                                   1,000 |                                                                                                                1,000,000 |                                                                                                                 2,000 |                                                                                                               1,002,000 |                                                             99.80%                                                              |
|                                                                                                                                  10,000 |                                                                                                              100,000,000 |                                                                                                                20,000 |                                                                                                             100,002,000 |                                                             99.98%                                                              |
|                                                                                                                                 100,000 |                                                                                                           10,000,000,000 |                                                                                                               200,000 |                                                                                                          10,000,002,000 |                                                             99.99%                                                              |

+ 표에서 알 수 있듯이 <img style="transform: translateY(0.2em); width:1.5em;" src="https://render.githubusercontent.com/render/math?math=n%5E2">이 차지하는 비율은 절대적이다. <img style="transform: translateY(0.2em); width:1em;" src="https://render.githubusercontent.com/render/math?math=n">이 조금만 증가해도 이내 <img style="transform: translateY(0.2em); width:1.5em;" src="https://render.githubusercontent.com/render/math?math=n%5E2">이 차지하는 비율은 99%를 넘어선다.
+ <img style="transform: translateY(0.2em); width:1em;" src="https://render.githubusercontent.com/render/math?math=n">이 증가함에 따라서 <img style="transform: translateY(0.2em); width:3em;" src="https://render.githubusercontent.com/render/math?math=2n%2B1">이 미치는 영향은 미미해지므로 다음과 같이 간략화할 수 있다.
    > <img style="transform: translateY(0.2em); width:6em;" src="https://render.githubusercontent.com/render/math?math=T(n)%3Dn%5E2">
+ 이를 Big-Oh Notation으로 표현하면 다음과 같다.
    > <img style="transform: translateY(0.2em); width:3.5em;" src="https://render.githubusercontent.com/render/math?math=O(n%5E2)">

#### <img style="transform: translateY(0.2em); width:12em;" src="https://render.githubusercontent.com/render/math?math=%5Ctherefore%20T(n)%3Dn%5E2%2B2n%2B1"> 의 Big-Oh는 <img style="transform: translateY(0.2em); width:1.8em;" src="https://render.githubusercontent.com/render/math?math=n%5E2">

> 이는 <img style="transform: translateY(0.2em); width:1em;" src="https://render.githubusercontent.com/render/math?math=n">의 증가 및 감소에 따른 <img style="transform: translateY(0.2em); width:2.5em;" src="https://render.githubusercontent.com/render/math?math=T(n)">의 변화 정도가 <img style="transform: translateY(0.2em); width:1.8em;" src="https://render.githubusercontent.com/render/math?math=n%5E2">의 형태를 띰을 의미한다.

#### 2. 단순하게 빅-오 구하기
> <img style="transform: translateY(0.2em); width:2em;" src="https://render.githubusercontent.com/render/math?math=T(n)">이 다항식으로 표현이 된 경우, 최고차항의 차수가 빅-오가 된다.

#### 3. 대표적인 빅-오
+ <img style="transform: translateY(0.2em); width:2.3em;" src="https://render.githubusercontent.com/render/math?math=O(1)">

  - 상수형 빅-오
  - 데이터 수에 상관없이 `연산횟수가 고정`인 유형의 알고리즘
  - 연산의 횟수가 1이 아니라고 해도 연산횟수가 고정이라면 1로 표기한다.
+ <img style="transform: translateY(0.2em); width:4em;" src="https://render.githubusercontent.com/render/math?math=O(%5Clog%20n)">

    - 로그형 빅-오
    - `데이터 수의 증가율`에 비해서 `연산횟수의 증가율`이 훨씬 낮은 알고리즘
    - 로그의 밑이 얼마냐에 따라서 차이가 나긴 하지만, 성능관점에서 미미하기 때문에 대부분의 경우에서 무시된다.

+ <img style="transform: translateY(0.2em); width:2.5em;" src="https://render.githubusercontent.com/render/math?math=O(n)">

    - 선형 빅-오
    - 데이터의 수와 연산횟수가 비례하는 알고리즘

+ <img style="transform: translateY(0.2em); width:5em;" src="https://render.githubusercontent.com/render/math?math=O(n%5Clog%20n)">

    - 선형로그형 빅-오
    - 데이터의 수가 두 배로 늘 때, 연산횟수는 두 배를 조금 넘게 증가하는 알고리즘을 의미한다.

+ <img style="transform: translateY(0.2em); width:3em;" src="https://render.githubusercontent.com/render/math?math=O(n%5E2)">

    - `데이터 수의 제곱`에 해당하는 연산횟수를 요구하는 알고리즘
    - 중첩된 반복문 내에서 알고리즘 연산이 진행되는 경우 발생
    - 데이터 수가 많을 경우 적용이 부적절하다.

+ <img style="transform: translateY(0.2em); width:3em;" src="https://render.githubusercontent.com/render/math?math=O(n%5E3)">

    - `데이터 수의 세제곱`에 해당하는 연산횟수를 요구하는 알고리즘
    - 삼중 중첩 반복문 내에서 알고리즘 연산이 진행되는 경우 발생

+ <img style="transform: translateY(0.2em); width:3em;" src="https://render.githubusercontent.com/render/math?math=O(2%5En)">

    - 지수형 빅-오
    - 사용하기에 매우 무리가 있는, 사용 자체가 비현실적인 알고리즘이다.
    - `지수적 증가`라는 매우 무서운 연산횟수의 증가를 보이기 때문이다.

> ###### 빅-오 표기들의 성능(수행시간, 연산횟수)의 대소 비교 
> <img style="transform: translateY(0.2em);" src="https://render.githubusercontent.com/render/math?math=O(1)%20%3C%20O(%5Clog%20n)%20%3C%20O(n)%20%3C%20O(n%5Clog%20n)%20%3C%20O(n%5E2)%20%3C%20O(n%5E3)%20%3C%20O(2%5En)">
<img src="https://media.vlpt.us/images/eensungkim/post/fb28de15-9b96-4068-94ad-97961bd0d77e/1omv0tmikzeaj24z8ps2.jpeg" width="70%">

`시간 복잡도 함수의 그래프`



#### 4. 순차 & 이진 탐색 알고리즘의 비교

+ <img style="transform: translateY(0.2em); width:5em;" src="https://render.githubusercontent.com/render/math?math=T(n)%3Dn"> `순차 탐색 알고리즘의 함수`
  <img style="transform: translateY(0.2em); width:5em;" src="https://render.githubusercontent.com/render/math?math=%5Crightarrow%20O(n)">
+ <img style="transform: translateY(0.2em); width:9em;" src="https://render.githubusercontent.com/render/math?math=T(n)%3D%5Clog_2n%2B1"> `이진 탐색 알고리즘의 함수`
  <img style="transform: translateY(0.2em); width:7em;" src="https://render.githubusercontent.com/render/math?math=%5Crightarrow%20O(%5Clog%20n)">

~~~ C
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
~~~

> 실행결과: BSWorstOpCount.c
> \> 비교연산횟수: 9
> \> 탐색 실패
> 
> \> 비교연산횟수: 13
> \> 탐색 실패
> 
> \> 비교연산횟수: 16
> \> 탐색 실패

##### 두 알고리즘의 비교연산횟수 비교
| <img style="transform: translateY(0.2em); width:1em;" src="https://render.githubusercontent.com/render/math?math=n"> | 순차 탐색 연산횟수 | 이진 탐색 연산횟수 |
| :------------------------------------------------------------------------------------------------------------------: | :----------------: | :----------------: |
|                                                         500                                                          |        500         |         9          |
|                                                        5,000                                                         |       5,000        |         13         |
|                                                        50,000                                                        |       50,000       |         16         |

#### 5. 빅-오에 대한 수학적 접근

+ ##### 빅-오에 대한 수학적 정의
> 두 개의 함수 <img style="transform: translateY(0.2em); width:2em;" src="https://render.githubusercontent.com/render/math?math=f(n)">과 <img style="transform: translateY(0.2em); width:2em;" src="https://render.githubusercontent.com/render/math?math=g(n)">이 주어졌을 때, 모든 <img style="transform: translateY(0.2em); width:3em;" src="https://render.githubusercontent.com/render/math?math=n%5Cgeq%20K">에 대하여 
> <img style="transform: translateY(0.2em); width:7em;" src="https://render.githubusercontent.com/render/math?math=f(n)%5Cleq%20Cg(n)">을 만족하는 두 개의 상수 <img style="transform: translateY(0.2em); width:0.9em;" src="https://render.githubusercontent.com/render/math?math=C">와 <img style="transform: translateY(0.2em); width:1em;" src="https://render.githubusercontent.com/render/math?math=K">가 존재하면, 
> <img style="transform: translateY(0.2em); width:2.5em;" src="https://render.githubusercontent.com/render/math?math=f(n)">의 빅-오는 <img style="transform: translateY(0.2em); width:4em;" src="https://render.githubusercontent.com/render/math?math=O(g(n))">이다.

+ ##### 빅-오 증명해보기
    - <img style="transform: translateY(0.2em); width:9em;" src="https://render.githubusercontent.com/render/math?math=f(n)%3D5n%5E2%2B100"> 의 빅-오 : <img style="transform: translateY(0.2em); width:3em;" src="https://render.githubusercontent.com/render/math?math=O(n%5E2)">
      - <img style="transform: translateY(0.2em); width:19em;" src="https://render.githubusercontent.com/render/math?math=f(n)%5Cleq%20Cg(n)%5Crightarrow%205n%5E2%2B100%5Cleq%203500n%5E2">
      - 상수 $C=3500$ , $K=12$ 두 수 모두 임의의 큰 수이다.
        `임의의 큰 수로 설정한 이유`
        > + n의 값이 계속해서 커지면서 함수의 비교식을 항상 만족하기만 하면 되기 때문에 k의 값을 크게 잡아도 상관이 없다.
        > + ~의 증가율 패턴(이 예에선 <img style="transform: translateY(0.2em); width:1em;" src="https://render.githubusercontent.com/render/math?math=n%5E2">)을 넘지 못한다는 것을 증명하기 위해 <img style="transform: translateY(0.2em); width:1em;" src="https://render.githubusercontent.com/render/math?math=n%5E2">의 증가율 패턴을 보이면서 C가 큰 수식을 만든 것이다.
    - $T(n)=3n+2\rightarrow O(n)$
      - 증명
        > \> if <img style="transform: translateY(0.2em); width:3em;" src="https://render.githubusercontent.com/render/math?math=C%3D4">
        > \> <img style="transform: translateY(0.2em); width:6em;" src="https://render.githubusercontent.com/render/math?math=3n%2B2%20%5Cleq%204n">
        > \> <img style="transform: translateY(0.2em); width:6em;" src="https://render.githubusercontent.com/render/math?math=2%20%5Cleq%204n-3n">
        > \> <img style="transform: translateY(0.2em); width:3em;" src="https://render.githubusercontent.com/render/math?math=2%20%5Cleq%20n">
        > <img style="transform: translateY(0.2em); width:19em;" src="https://render.githubusercontent.com/render/math?math=f(n)%5Cleq%20Cg(n)%5Crightarrow%203n%2B2%5Cleq%204n">
      - 상수 C: 4, K: 2
      - 위 식은 만족하므로 <img style="transform: translateY(0.2em); width:2.5em;" src="https://render.githubusercontent.com/render/math?math=f(n)">의 빅-오는 <img style="transform: translateY(0.2em); width:4em;" src="https://render.githubusercontent.com/render/math?math=O(g(n))">이다.
    - $T(n)=7n^3+3n^2+2\rightarrow O(n^3)$
      - 증명(<img style="transform: translateY(0.2em); width:10em;" src="https://render.githubusercontent.com/render/math?math=f(n)%3D7n%5E3%2B3n%5E2%2B2">, <img style="transform: translateY(0.2em); width:5em;" src="https://render.githubusercontent.com/render/math?math=g(n)%3Dn%5E3">)
        > \> <img style="transform: translateY(0.2em); width:11em;" src="https://render.githubusercontent.com/render/math?math=n%5Cgeq%200%5Crightarrow%207n%5E3%5Cleq7g(n)">을 항상 만족 
        > \> <img style="transform: translateY(0.2em); width:11em;" src="https://render.githubusercontent.com/render/math?math=n%5Cgeq%203%5Crightarrow%203n%5E2%5Cleq3g(n)">을 항상 만족
        > \> <img style="transform: translateY(0.2em); width:10em;" src="https://render.githubusercontent.com/render/math?math=n%5Cgeq%202%5Crightarrow%202%5Cleq%202g(n)">을 항상 만족
        > \> <img style="transform: translateY(0.2em); width:4.5em;" src="https://render.githubusercontent.com/render/math?math=%5Ctherefore%20n%5Cgeq%203"><img style="transform: translateY(0.2em); width:12.5em;" src="https://render.githubusercontent.com/render/math?math=%5Crightarrow%207n%5E3%2B3n%5E2%2B2%5Cleq%2012g(n)">
      - 상수 C: 12, K: 3
      - 위의 식은 성립하므로 빅-오는 <img style="transform: translateY(0.2em); width:3em;" src="https://render.githubusercontent.com/render/math?math=O(n%5E3)">이다.