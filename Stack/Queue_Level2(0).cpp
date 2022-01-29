#include <string>
#include <vector>
#include <queue>

using namespace std;

//뒤의 기능먼저 개발 가능, 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포 -> 큐 사용
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;   
   
    for(int i = 0; i!=progresses.size(); i++){
        int day = 0;
        if(progresses[i] != 100){
            day = 100 - progresses[i];
            
            if(day%speeds[i] != 0){
                day = day / speeds[i];
                day += 1;
                q.push(day);
            } else {
                day = day / speeds[i];
                q.push(day);
            }
        }
    }
    
    while (!q.empty()) {
        int pop_day = q.front(), count = 1;
        q.pop();
 
        while ((!q.empty()) && (q.front() <= pop_day)) {
            q.pop();
            count++;
        }
        answer.push_back(count);
    }    
    
    return answer;
}