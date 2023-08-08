# [D2] 간단한 369게임 - 1926 

[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PTeo6AHUDFAUq) 

### 성능 요약

메모리: 13,544 KB, 시간: 5 ms, 코드길이: 3,011 Bytes

헤맨 이유 : 
1) 문자열이나 배열에서 특정 문자가 있는 여부를 알아채리거나 어디 index에 위치하는지 판단할 수 있는 함수 find를 처음써봤고, 그 find의 경우 npos값으로 나오는 것을 어떻게 해야할지 모르겠었다. 그래서 그냥 3,6,9가 존재하면 prove라는 bool 변수로 있는지 없는지 판단하고 만약 3,6,9가 없으면 한번에 문자열을 출력했다.
이렇게 하면 좋은 점은 2자리수 숫자일 경우에 하나하나 출력하지 않아도 되는 점도 한번에 해결할 수 있었다.


> 출처: SW Expert Academy, https://swexpertacademy.com/main/code/problem/problemList.do
