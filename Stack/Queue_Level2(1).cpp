#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    int sp = 0, count = 0;
    
    int m = priorities[1];
    
    for (int i = 0; i < priorities.size(); i++){
        
        if(m<priorities[i]){
            m = priorities[i];
            sp = i;
        }
    }
    
    for(int i = sp; i < priorities.size(); i++){
        q.push(priorities[i]);
        count++;
        
        if(location == i){
            answer = count;
        }
    }
    
    if(sp != 0){
        for(int i = 0; i<sp; i++){
            q.push(priorities[i]);
            count++;
        
            if(location == i){
             answer = count;
            }
        }
    }
    
    return answer;
}