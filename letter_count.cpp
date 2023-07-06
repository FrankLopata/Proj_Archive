#include <iostream>
using namespace std;

int main(){
    int counters[26] = {0};
    char letters[26];
    for (int i=65;i<91;i++){
        letters[i-65] = char(i);
    }
    string str = "";
   while( getline(cin,str)){
    for (int x = 0; x <str.length();x++){
        int aletter = int(str[x]);
        if (aletter > 64 && aletter < 91){
            counters[aletter-65] +=1;
        }
        if(aletter>96 && aletter < 123){
            counters[aletter -97] +=1;
        }
    }
    }
    for (int z = 0; z<26;z++){
        cout<<letters[z]<<" "<<counters[z]<<endl;
    }
    
    }



