#include <iostream>
#include <cctype>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <fstream>
using namespace std;

void to_lowercase(string & str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}


int main(){

    map<string, int>word_count;
    set<string> stopwords;
    string word= " ";
    ifstream fil;
    fil.open("stopwords.txt");
    while(fil>>word){
        to_lowercase(word);
        stopwords.insert(word);
    }
    fil.close();
    fil.open("sample_doc.txt");
    while(fil>>word){
     to_lowercase(word);
     if (stopwords.find(word)==stopwords.end()){
        word_count[word]+=1;
     }
}
    fil.close();
    ofstream out("frequency.txt");
    for(auto wc:word_count){
        out<<wc.first<<" "<<wc.second<<endl;
    }
    out.close();

}
