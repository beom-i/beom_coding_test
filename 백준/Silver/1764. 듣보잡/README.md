# [Silver IV] 듣보잡 - 1764 

[문제 링크](https://www.acmicpc.net/problem/1764) 

### 성능 요약

메모리: 10300 KB, 시간: 388 ms

### 분류

자료 구조, 해시를 사용한 집합과 맵, 정렬, 문자열

### 문제 설명

<p>김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다. 이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름과, N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다. 이름은 띄어쓰기 없이 알파벳 소문자로만 이루어지며, 그 길이는 20 이하이다. N, M은 500,000 이하의 자연수이다.</p>

<p>듣도 못한 사람의 명단에는 중복되는 이름이 없으며, 보도 못한 사람의 명단도 마찬가지이다.</p>

### 출력 

 <p>듣보잡의 수와 그 명단을 사전순으로 출력한다.</p>


### 배울 것
1. 해당 문제는 다른 벡터에 넣어서 할 수 있었지만, 각 듣도 / 보도 사람은 중복이 없다했으니 하나의 자료구조에 넣고 sort해서 양옆에 같은 경우에 따로 넣으면 쉽게 풀 수 있을 것 같아서 이렇게 풀게되었다.
