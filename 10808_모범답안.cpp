#include <iostream>

using namespace std;



int main() {
    //int int_arr[26];는 배열 초기화가 안되는 것 같다. ={0} 으로 해줘야함
    //fill(int_arr,int_arr+26,0)도 가능
    int int_arr[26] ={0};
    //C,C++ 표준 입출력 스트림을 끊는다.(printf scanf 동시에 사용할 수는 없지만 속도 빨라짐)
    ios::sync_with_stdio(0); 
    //cin cout을 묶지 않고 따로 떼어네서 시간 단축
    cin.tie(0);
    //입력 받을 단어 선언
    string str;
    //단어 입력 받음
    cin >> str;

    //입력받은 문자열 하나씩 방문하면서 해당 알파벳 ascii - 97로
    //a를 0으로 바꿔서 0~26 0으로 초기화 된 배열을 해당 알파벳마다 추가함.
    for(int i = 0 ; i<str.length();i++){
        int stor = (int) str.at(i) - 97;
        int_arr[stor] ++;
    }
    /*ascii코드 변경할 때 
    for(auto c:s)
    int_arr[c-'a']++; 으로 ascii코드를 좀 쉽게 다룰 수 있음 해당 정수로 말고 같은 알파벳으로
    */ 
    for(int i = 0; i<26;i++){
        cout << int_arr[i] << ' '; 
    }
}