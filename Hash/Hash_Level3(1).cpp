#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map <string, int> music;
    map <string, map<int, int>> musicList;
    
    for(int i=0; i<genres.size(); i++){
        music[genres[i]] += plays[i];
        musicList[genres[i]][i] = plays[i];
    }
   
    while(music.size() > 0) {
        string genre{};
        int Max{0};
        //장르 중에서 제일 높은 것 찾기
        for(auto mu:music){
            if(Max < mu.second){
                Max = mu.second;
                genre = mu.first;
            }
        }
        
        //2곡을 넣어야하므로 2번 반복
        for (int i = 0; i < 2; i++){
            int val = 0, ind = -1;
            //노래 중에서 제일높은 것 찾기
            for (auto ml : musicList[genre]) {
                if (val < ml.second) {
                    val = ml.second;
                    ind = ml.first;
                }
            }
            //만약 노래가 0~1곡밖에없다면 반복문 탈출
            if (ind == -1)    break;
            //리턴할 리스트에 노래번호 추가
            answer.push_back(ind);
            musicList[genre].erase(ind);
        }
        //map 에서 사용한 장르삭제
        music.erase(genre);
    }
    
    return answer;
}