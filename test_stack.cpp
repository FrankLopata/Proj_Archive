#include "stack.h"
#include <iostream>
#include <string>
using namespace std;



int main(){
    string words;
    Stack s;
    while (getline(cin,words)){
        for(int i = 0;i<words.length();i++){
            s.push(words[i]);
        }
    while(!s.isEmpty()){
        cout<<s.pop();
    }
    cout << endl;
}
return 0;

}
