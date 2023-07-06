
#define STACK_CAPACITY 1000
class Stack{
    int t;
    char Stk[STACK_CAPACITY];
public:
    Stack(){
        t = 0;
    }
    void push(char c){
        if(!isFull()){
            Stk[t++]=c;
            }
        else
            return;

    }

    char pop(){
    if(isEmpty()){
        char c = '@';
        return c;
        }
    else{
        return Stk[--t];       
    }
    }
    char top(){
    if(isEmpty()){
        char c = '@';
        return c;
    }
    else{
        return Stk[t-1];
    }
    }
    bool isEmpty(){
    if (t<=0)
         return true;
    else
        return false;
    }
    bool isFull(){
    if(t>=1000)
        return true;
    else
        return false;
    }
    ~Stack(){}
    };
