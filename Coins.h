

const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME= 10, CENTS_PER_NICKEL = 5;
class Coins
{
public:
    Coins(int q, int d,int n, int p){
    quarters=q;
    dimes = d;
    nickels = n;
    pennies= p;
    }
    void deposit_coins(Coins & c){
    quarters += c.quarters;
    dimes += c.dimes;
    nickels += c.nickels;
    pennies += c.pennies;
    }
    Coins extract_exact_change(Coins c){
    if (quarters < c.quarters || dimes < c.dimes || nickels < c.nickels|| pennies < c.pennies){
    cout << "(ERROR: Insuffecient Funds)" << endl;

    return Coins(0,0,0,0);
    }
    quarters -= c.quarters;
    dimes -= c.dimes;
    nickels -= c.nickels;
    pennies -= c.pennies;
    return Coins(c.quarters,c.dimes,c.nickels,c.pennies);

    }

    bool has_exact_change_for_coins(Coins c){
    if (quarters >= c.quarters && dimes >= c.dimes && nickels >= c.nickels && pennies >= c.pennies)
         return true;
    return false;

    }

    int total_value_in_cents(){
    return quarters * CENTS_PER_QUARTER + dimes * CENTS_PER_DIME + nickels * CENTS_PER_NICKEL + pennies;
    }
    void print(ostream & out){
    out << quarters;
    out << " quarters, ";
    out << dimes;
    out << " dimes, ";
    out << nickels;
    out<< " nickels, ";
    out<< pennies;
    out<< " pennies";
    }   
private:
int quarters,dimes,nickels,pennies;

};
ostream & operator << (ostream & out, Coins c){
c.print(out);
return out;
}

Coins coins_required_for_cents(int amount_in_cents){
    int q = 0;
    int d = 0;
    int n = 0;
    int p = 0;
    int i = 0;
    while( i < amount_in_cents){
    if (amount_in_cents - i >25){
        q+=1;
        i+=25;}
   else {   
        if (amount_in_cents -i > 10){
        d+=1;
        i+=10;
        }
         else{
             if(amount_in_cents - i > 5){
                 n +=1;
                 i+=5;
                 }
            else{

                 if(amount_in_cents - i >= 1){
                 p+=1;
                 i+=1;
                 }
            }
        }
    }
    }

    return Coins(q,d,n,p);
    }
