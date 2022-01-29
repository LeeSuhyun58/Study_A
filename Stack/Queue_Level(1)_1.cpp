#include <string>
#include <vector>
#include <queue>
 
using namespace std;
 
int solution(vector<int> priorities, int location) {
    int answer = 0, count = 0;
    //일반큐
    queue<pair<int, int>> q;
    //우선순위 큐
    priority_queue <int> pq;
 
    for (int i = 0; i < priorities.size(); i++) {
        //큐에 들어온 순서와 중요도를 넣음
        q.push(make_pair(i, priorities[i]));
        //우선순큐에 넣음
        pq.push(priorities[i]);
    }
    
    while (!q.empty()) {
        int index = q.front().first;
        int value = q.front().second;
        q.pop();
        //우선순위 1순위와 현재값이 같다면
        if (pq.top() == value) {
            pq.pop();
            count++;
            //현재 나간것이 원하는것과 같다면
            if (index == location) {
                answer = count;
                break;
            }
        }
        else
            q.push(make_pair(index, value));
    }
    return answer;
}