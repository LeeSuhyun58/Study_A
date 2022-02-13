#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    
    //우선순위 큐를 이용해서 vector 값을 정렬 -> 오름차순
    priority_queue<int, vector<int>, greater<int>> m_pq; //최솟값을 가지는 q
    priority_queue<int, vector<int>> M_pq; //최댓값을 가지는 q
    int cnt = 0;
    
    for(string op : operations) { 
        // 큐가 빈경우 -> 초기화 
        if(cnt == 0) { 
            while(!m_pq.empty()) m_pq.pop(); 
            while(!M_pq.empty()) M_pq.pop(); 
        }
        
        // String I인 경우 -> 삽입 
        if(op[0] == 'I') { 
            M_pq.push(stoi(op.substr(2))); 
            m_pq.push(stoi(op.substr(2))); 
            cnt++; 
        } 
        
        // String D인 경우 -> 삭제 -> 다시 if문으로 경우 나눔(최댓값/최솟값) 
        else { 
            // 빈 큐에 데이터를 삭제하라는 연산일 경우 무시 
            if(cnt == 0) continue; 
            
            // D 1인 경우 -> 최댓값 삭제 
            if(op[2] == '1') 
            { 
                M_pq.pop(); 
                cnt--; 
            } 
            
            // D -1인 경우 -> 최솟값 삭제 
            else 
            { 
                m_pq.pop(); 
                cnt--; 
            } 
        } 
    } 
    
    if(cnt != 0) { 
        answer[0] = M_pq.top(); 
        answer[1] = m_pq.top(); 
    }

    return answer;
}