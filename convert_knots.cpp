#include <iostream>
using namespace std;

double knots_to_miles_per_minute(int n){
return n * 0.0191797;
}
int main(){
int knots = 0;
cin>>knots;
cout<< knots_to_miles_per_minute(knots)<<endl;
return 0;
}
