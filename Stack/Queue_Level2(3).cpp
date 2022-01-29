#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    //트럭 무게 생각
    //다리에 올라갈 수 있는 트럭수 = 다리의 길이
    queue<int> q;
    int time = 0;
    int sum = 0;
    int truckIdx = 0;
    
    while(1)
    {    
        time++;
        if(q.size() == bridge_length)
        {
            sum -= q.front();
            q.pop();
        }
        
        // 트럭의 무게가 다리의 무게보다 작으면, 트럭을 삽입
        if(sum + truck_weights[truckIdx] <= weight)
        {
            // 마지막 트럭이 삽입되면 종료
            if(truckIdx == truck_weights.size()-1)
            {
                // 마지막 트럭 도착시간 추가
                time += bridge_length;
                break;
            }
            q.push(truck_weights[truckIdx]);
            sum += truck_weights[truckIdx];
            truckIdx++;
        }
        // 트럭의 무게가 다리의 무게보다 크면, 0을 삽입해서 트럭을 도착점으로 민다
        else
        {
            q.push(0);
        }    
    }

    return time;
}