#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int index = 0;
    
    map <string, int> music;
    //map을 이용해서 키 = genres, 값 = plays로 설정
    for(int i=0; i<plays.size(); i++){
        music[genres[i]] = plays[i];
    }
    
    //max 값을 구하기 -> second(plays값 비교)
    int M=0;

    for(auto i=music.begin(); i !=music.end(); i++){
        if(M < i->second){
            M = i->second;
        }
    }
    
    //구한 M값을 이용해서 가장 많이 들은 장르 구하기
    //다시 그 장르를 이용해 장르 중 가장 많이 들은 번호 2개를 answer에 저장
    for(int i=0; i<genres.size(); i++){
        
    }
    
    return answer;
}