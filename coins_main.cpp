#include <iostream>
#include <iomanip>
using namespace std;
#include "Coins.h"


int main(){
Coins pocket(5,3,6,8);
Coins piggyBank(50,50,50,50);

pocket.extract_exact_change(coins_required_for_cents(68));
cout << "Bought Chips"<< endl;
cout<< "Pocket: "<< pocket<<endl;
cout<<endl;

Coins take(8,0,1,0);
Coins out = piggyBank.extract_exact_change(take);
pocket.deposit_coins(out);

cout << "Transfer Money to Pocket"<<endl;
cout<< "Pocket: "<<pocket<<endl;
cout << "Piggy Bank: "<< piggyBank<<endl;

Coins couch_change(10,10,10,10);
piggyBank.deposit_coins(couch_change);
cout<<endl<<"Vacumming Change"<<endl;
double output = piggyBank.total_value_in_cents()/100.0;
cout << "Piggy Bank: $"<< setprecision (2)<<fixed<<output<< endl<<endl;

}
