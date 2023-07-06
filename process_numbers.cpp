#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>
using namespace std;




void process_numbers(){
    ifstream inp("rand_numbers.txt");
    vector<int> V;
    copy(istream_iterator<int>(inp),istream_iterator<int>(),back_inserter(V));
    sort(begin(V),end(V));
    ofstream out("odds.txt");
    copy_if(begin(V),end(V),ostream_iterator<int>(out," "),[](int x){return x % 2 !=0;});
    out<<endl;
    out.close();
    ofstream even("evens.txt");
    copy_if(begin(V),end(V),ostream_iterator<int>(even,"\n"),[](int x){return x % 2 ==0;});
    even.close();



}

int main(){

    process_numbers();
    
    return 0;
}
