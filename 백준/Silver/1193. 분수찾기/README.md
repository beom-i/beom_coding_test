# [Silver V] 분수찾기 - 1193 

[문제 링크](https://www.acmicpc.net/problem/1193) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현, 수학

### 문제 설명

<p>무한히 큰 배열에 다음과 같이 분수들이 적혀있다.</p>

<table class="table table-bordered" style="width:30%">
	<tbody>
		<tr>
			<td style="width:5%">1/1</td>
			<td style="width:5%">1/2</td>
			<td style="width:5%">1/3</td>
			<td style="width:5%">1/4</td>
			<td style="width:5%">1/5</td>
			<td style="width:5%">…</td>
		</tr>
		<tr>
			<td>2/1</td>
			<td>2/2</td>
			<td>2/3</td>
			<td>2/4</td>
			<td>…</td>
			<td>…</td>
		</tr>
		<tr>
			<td>3/1</td>
			<td>3/2</td>
			<td>3/3</td>
			<td>…</td>
			<td>…</td>
			<td>…</td>
		</tr>
		<tr>
			<td>4/1</td>
			<td>4/2</td>
			<td>…</td>
			<td>…</td>
			<td>…</td>
			<td>…</td>
		</tr>
		<tr>
			<td>5/1</td>
			<td>…</td>
			<td>…</td>
			<td>…</td>
			<td>…</td>
			<td>…</td>
		</tr>
		<tr>
			<td>…</td>
			<td>…</td>
			<td>…</td>
			<td>…</td>
			<td>…</td>
			<td>…</td>
		</tr>
	</tbody>
</table>

<p>이와 같이 나열된 분수들을 1/1 → 1/2 → 2/1 → 3/1 → 2/2 → … 과 같은 지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.</p>

<p>X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 X(1 ≤ X ≤ 10,000,000)가 주어진다.</p>

### 출력 

 <p>첫째 줄에 분수를 출력한다.</p>

### 배울 것
1) 규칙을 찾기 정말 어려웠다. 가장 그럴듯한 규칙인 1,2,3,4,5씩으로 늘어난다를 가지고 등차수열을 사용해야겠다를 파악해야햇음 (이건 풀이봄)
2) 등차수열을 갖고도 쉽지 않았는데 임의의 수에 해당하는 n을 구했고 (n:등차수열 몇까지의 합 다음인지)
3) n을 가지고 짝수/홀수 케이스로 나누어서 분수 출력하였다.
=> 규칙을 파악하고 그것에 해당하는 범위와 케이스를 나누었다.

