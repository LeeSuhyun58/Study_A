#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    vector<string> v;
    
    for(int i=0; i<completion.size(); i++){
        for(int k = 0; k != participant.size(); k++){
            if(completion[i] == participant[k]) {
                participant.erase(participant.begin()+k);
                break;
            }
        }
    }
    
   answer = participant[0];
    
    return answer;
}