#include <iostream>
using namespace std;
#include "String.h"
#include "Alloc.h"

void test_constructors_and_print(){
    cout<<"Constructor and operator << TESTS"<<endl;
    String s("Hello  World");
    cout<<"\""<<s<<"\""<<endl;

}

void test_assignment(){

cout<< "Assignment TESTS"<<endl;

String test1("Im a little bird");
cout<<"Test 1 "<<test1<<endl;
String test2("This shouldn't be here");



}

void test_relationals(){

cout<< "Relational TESTS"<<endl;
String s1("equals");
String s2("equals");
cout<<"Test Equal: "<<boolalpha<<(s1==s2)<<endl;
String s3("a");
String s4("b");
cout<<"Test greater: "<<boolalpha<<(s3>s4)<<endl;
cout<<"Test less: " <<boolalpha<<(s4<s3)<<endl;
cout<<"Test equal less for less: "<<boolalpha<<(s4<=s3)<<endl;
cout<<"Test equal less for equal: "<<boolalpha<<(s1<=s2)<<endl;
cout<<"Test equal greater for greater: "<<boolalpha<<(s3>=s4)<<endl;
cout<<"Test equal greater for equal: "<<boolalpha<<(s1>=s2)<<endl;

}

void test_reverse(){

cout<<"Reverse TESTS"<<endl;

String s1("1234567");
s1.reverse();
String s2(s1);

cout<<s2<<endl;

}

void test_concatenate(){
cout<<"Concatenate TESTS"<<endl;
String s1("Hello ");
cout<<"Word 1: "<<s1<<endl;
String s2("World");
cout<<"Word 2: "<<s2<<endl;
String s3(s1+s2);
cout<<s3<<endl;
s1+=s2;
cout<<s1<<" should be Hello World"<<endl;

}

void test_indexOf(){
cout<<"indexOf TESTS"<<endl;
String s1("1234567890");
cout<<"numbers should be in numerical order"<<endl;
for(int i=0;i<10;i++){
    cout<<s1[i]<<endl;
}

}

int main(){
test_constructors_and_print();
test_assignment();
test_relationals();
test_reverse();
test_concatenate();
test_indexOf();
Alloc::report_allocations();
cout<<"ALL TESTS COMPLETED"<<endl<<endl<<endl<<endl;
return 0;



}
