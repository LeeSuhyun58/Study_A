#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    //키와 값의 조합을 생각 -> 동일 값을 가지는 의상은 입을 수 없음 -> 이 경우를 제외하고 경우의 수를 생각해야함
    int answer = 1;
    int result = 0;
    map<string, int> m;
    
    for(auto c:clothes){
        //2차원 배열의 [][1]이 의상의 종류 -> c[1]
        //동일한 종류의 의상인 경우 count +1
        m[c[1]] += 1;
    }
    
    for(auto i = m.begin(); i!=m.end(); i++){
        //map 키 -> first, 값 -> second
        // 의상의 종류 각각 아무것도 선택하지 않는 경우의 수가 포함되어 있어야 함 
        //-> 의상 종류 중 어떠한 것도 선택을 하지 않은 경우는 답에서 제외(-1)
        answer *= i->second+1;
    }

    return answer-1;
}