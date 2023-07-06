#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;


vector<string> read_into(string fileName){
    ifstream inp;
    inp.open(fileName);
    vector<string> v;
    copy(istream_iterator<string>(inp),istream_iterator<string>(),back_inserter(v));
    inp.close();
    std::transform(v.begin(),v.end(),v.begin(),[](string i){transform(begin(i),end(i),begin(i),::tolower); return i;});
    sort(begin(v),end(v));
    return v;
    }


map<string,int> freq(vector<string> samp, set<string> stop){
    sort(begin(samp),end(samp));
    map<string,int> out;
    for_each(samp.begin(),samp.end(),[&out,stop](string s){
        if(stop.find(s) == stop.end()){
            out[s]+=1;
            }});
    return out;

}

void print_out(map<string,int> in){
    ofstream out("frequency.txt");
    for_each(in.begin(),in.end(),[&out](pair<string,int> p){out<< p.first << " " << to_string(p.second)<<endl;});


}
int main(){
    vector<string> sample;
    vector<string> stop_stor;
    stop_stor = read_into("stopwords.txt");
    set<string> stopwords(stop_stor.begin(),stop_stor.end());
    sample = read_into("sample_doc.txt");
    map<string,int> o;
    o = freq(sample,stopwords);
    print_out(o);
    return 0;    


}
