#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    // 섞은 횟수를 세는 변수 필요 = answer
    // K와 만들어낸 스코빌 지수를 비교 -> 넘은 경우 answer 반환
    // 넘지 못하는 경우 -1을 반환
    
    // 우선순위 큐 -> 작은 수 ~ 큰 수 순으로 정렬
    priority_queue<int, vector<int>, greater<int>> pq; 
    for(int e: scoville) 
        pq.push(e); 
    
    while(pq.top() < K) { 
        // pq의 사이즈가 1이라는 의미 = 스코빌 지수를 K 이상으로 만들 수 없음 
        // -1 리턴 
        if(pq.size()==1) 
            return -1; 
        
        // top을 이용해 가장 위의 값을 읽음 = 가장 작은 값
        int tmp1 = pq.top(); 
        pq.pop(); 
        
        // 그 다음 작은 값 
        int tmp2 = pq.top(); 
        pq.pop(); 
        
        // 문제에서 주어진 공식으로 섞은 후의 K값 구하기
        int new_sco = tmp1 + (tmp2*2); 
        pq.push(new_sco); 
        
        answer++; 
    }
  
    return answer;
}