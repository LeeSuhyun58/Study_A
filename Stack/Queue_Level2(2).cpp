#include <string>
#include <vector>
#include <queue>

using namespace std;

//사실 이 문제는 q를 사용한는 의미가 없음
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    queue<int> q;
    
    for(int i = 0; i < prices.size(); i++){
        q.push(prices[i]);
    }
    
    while(!q.empty())
    {
        
        for(int j = 0; j < prices.size(); j++){
            int count = 0;
            int v = q.front();
            q.pop();
            
            for(int k = j+1; k< prices.size(); k++) {
                count++;
                if(v > prices[k]){
                    break;
                } 
            }
            answer.push_back(count);
        }
    }
    
    return answer;
        
}