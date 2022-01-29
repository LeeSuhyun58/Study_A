#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int length = 0;
    string phone_number1 = "";
    string phone_number2 = "";
    
    for(int i = 0; i< phone_book.size(); i++) {
        phone_number1 = phone_book[i];
        length = phone_number1.length();
            
        for(int j = i+1; j<phone_book.size(); j++){
            phone_number2 = phone_book[j];
            if(phone_number1 == phone_number2.substr(0,length)){
                answer = false;
                break;
            }
        }
    }
    
    return answer;
}