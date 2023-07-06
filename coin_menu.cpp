#include <iostream>
#include <iomanip>
using namespace std;
#include "Coins.h"
int main(){

 Coins myCoins(0,0,0,0);
 while(true){
    cout<<"Coin Menu"<<endl;
    cout<<endl;
    cout<<"1. Deposit Change"<<endl;
    cout<<"2. Extract Change"<<endl;
    cout<<"3. Print Balance"<<endl;
    cout<<"4. Exit"<<endl;
    int inp = 0;
    cin>>inp;
    cout<<endl<<"User Input:"<<inp<<endl;
    
    if(inp == 1||inp==2){
    int q = 0,d=0,n=0,p=0;
    cout<<endl<<"Quarters?";
    cin>>q;
    cout<<endl<<"Dimes?";
    cin>>d;
    cout<<endl<<"Nickles?";
    cin>>n;
    cout<<endl<<"Pennies?";
    cin>>p;
    Coins tempCoins(q,d,n,p);
    if(inp==1){
        myCoins.deposit_coins(tempCoins);
    }
    if (inp==2){
        myCoins.extract_exact_change(tempCoins);    
    }
    }
    if(inp==3){
        cout<<endl<<"$";
       double o = myCoins.total_value_in_cents();
       if (o<1000.0){
            cout<<0;
       }
       cout<<setprecision(2)<<fixed<<o/100.0<<endl;
    

    }
    if(inp==4){
        return 0;
    }
    cout<<"Thank You!"<<endl;
        

}



}
