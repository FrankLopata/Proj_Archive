#include <iostream>
using namespace std;
#include "String.h"

void test_constructors_and_print()
{
    cout << "Constructor and operator << TESTS" << endl;
    String s("Hello World");
    cout << "NORMAL: " << "\"" << s << "\"" << endl;
    String chara("s");
    cout << "Single Char: " << "\"" << chara << "\"" << endl;
    String maximum("THIS IS alksdjfal;dkfjal;ewfkjae;lkfjae;lfkjaew;lfkjaew;fkjawe;lfkj;ewlkfjaew;flkjefkjewljae;lfkjaelkjfawelfkjwelfj THIS IS END NOT THIS");
    cout << "Max Char (ends with END): " << "\"" << maximum << "\"" << endl;
    String empty("");
    cout << "Empty String: " << "\"" << empty << "\"" << endl;
}

void test_assignment()
{
    cout << endl << "Assignment TESTS" << endl;
    String s("Hello World");
    String test_s = s;
    String chara("s");
    String test_chara = chara;
    String max("THIS IS alksdjfal;dkfjal;ewfkjae;lkfjae;lfkjaew;lfkjaew;fkjawe;lfkj;ewlkfjaew;flkjefkjewljae;lfkjaelkjfawelfkjwelfj THIS IS END NOT T    HIS");
    String test_max = max;
    cout << " Made past max" << endl;
    String empty("");
    String test_empty = empty;
    cout << "NORMAL: " << "\"" << test_s << "\"" << endl;
    cout << "Single Char: " << "\"" << test_chara << "\"" << endl;
    cout << "MAX: " << "\"" << test_max << "\"" << endl;
    cout << "Empty: " << "\"" << test_empty << "\"" << endl;
}

void test_equals()
{
    cout << endl << "Equals tests" << endl;
    String hello("Hello World");
    String hello2("Hello World");
    cout << "Hello World == Hello World " << (hello == hello2) << endl;
    String case_hello("Hello"); // casing
    String case_hello2("hello");
    cout << "Hello != hello " <<(case_hello == case_hello2) << endl;
    String last("Last Letter");
    String last2("Last LetteR");
    cout << "Last Letter != Last LetteR " << (last == last2) << endl;
    String s("Short");
    String s2("Shorter");
    cout << "Short != Shorter " << (s == s2) << endl;
    String emp("");
    String emp2("");
    cout << "Empty == Empty " << (emp == emp2) << endl;
}

void test_inequals()
{
    cout << endl << "Inequals tests" << endl;
    String hello("Hello World");
    String hello2("Hello World");
    cout << "Hello World == Hello World 0 " << (hello != hello2) << endl;
    String case_hello("Hello"); // casing
    String case_hello2("hello");
    cout << "Hello != hello 1  " <<(case_hello != case_hello2) << endl;
    String last("Last Letter");
    String last2("Last LetteR");
    cout << "Last Letter != Last LetteR 1 " << (last != last2) << endl;
    String s("Short");
    String s2("Shorter");
    cout << "Short != Shorter 1 " << (s != s2) << endl;
    String emp("");
    String emp2("");
    cout << "Empty == Empty 0 " << (emp != emp2) << endl;
}

void test_gt()
{
    cout << endl << "Greater than" << endl;
    String hello("Hello World");
    String hello2("Hello World");
    cout << "Hello World > Hello World 0 " << (hello > hello2) << endl;
    cout << "Hello World > Hello World 0 " << (hello2 > hello) << endl;
    String cap("Hello");
    String low("hello");
    cout << "Hello > hello 0 " << (cap > low) << endl;
    cout << "hello > Hello 1 " << (low > cap) << endl;
    String last("Last LetteR");
    String last2("Last Letter");
    cout << "Last LetteR > Last Letter 0 " << (last > last2) << endl;
    cout << "Last Letter > Last LetteR 1 " << (last2 > last) << endl;
    String s("Short");
    String s2("Shorter");
    cout << "Short > Shorter 0 " << (s > s2) << endl;
    cout << "Shorter > Short 1 " << (s2 > s) << endl;
    String emp("");
    String emp2("a");
    cout << " <emp> > a 0 " << (emp > emp2) << endl;
    cout << " a > <emp> 1 " << (emp2 > emp) << endl;
}

void test_lt()
{
    cout << endl << "Less than" << endl;
    String hello("Hello World");
    String hello2("Hello World");
    cout << "Hello World < Hello World 0 " << (hello < hello2) << endl;
    cout << "Hello World < Hello World 0 " << (hello2 < hello) << endl;
    String cap("Hello");
    String low("hello");
    cout << "Hello < hello 1 " << (cap < low) << endl;
    cout << "hello < Hello 0 " << (low < cap) << endl;
    String last("Last LetteR");
    String last2("Last Letter");
    cout << "Last LetteR < Last Letter 1 " << (last < last2) << endl;
    cout << "Last Letter < Last LetteR 0 " << (last2 < last) << endl;
    String s("Short");
    String s2("Shorter");
    cout << "Short < Shorter 1 " << (s < s2) << endl;
    cout << "Shorter < Short 0 " << (s2 < s) << endl;
    String emp("");
    String emp2("a");
    cout << " <emp> < a 1 " << (emp < emp2) << endl;
    cout << " a < <emp> 0 " << (emp2 < emp) << endl;
}

void test_gteq()
{
    cout << endl << "Greater than EQ" << endl;
    String hello("Hello World");
    String hello2("Hello World");
    cout << "Hello World >= Hello World 1 " << (hello >= hello2) << endl;
    cout << "Hello World >= Hello World 1 " << (hello2 >= hello) << endl;
    String cap("Hello");
    String low("hello");
    cout << "Hello >= hello 0 " << (cap >= low) << endl;
    cout << "hello >= Hello 1 " << (low >= cap) << endl;
    String last("Last LetteR");
    String last2("Last Letter");
    cout << "Last LetteR >= Last Letter 0 " << (last >= last2) << endl;
    cout << "Last Letter >= Last LetteR 1 " << (last2 >= last) << endl;
    String s("Short");
    String s2("Shorter");
    cout << "Short >= Shorter 0 " << (s >= s2) << endl;
    cout << "Shorter >= Short 1 " << (s2 >= s) << endl;
    String emp("");
    String emp2("a");
    cout << " <emp> >= a 0 " << (emp >= emp2) << endl;
    cout << " a >= <emp> 1 " << (emp2 >= emp) << endl;
    String true_emp("");
    String true_emp2("");
    cout << " <emp> >= <emp> 1 " << (true_emp >= true_emp2) << endl;
}

void test_lteq()
{
    cout << endl << "Less than" << endl;
    String hello("Hello World");
    String hello2("Hello World");
    cout << "Hello World <= Hello World 1 " << (hello <= hello2) << endl;
    cout << "Hello World <= Hello World 1 " << (hello2 <= hello) << endl;
    String cap("Hello");
    String low("hello");
    cout << "Hello <= hello 1 " << (cap <= low) << endl;
    cout << "hello <= Hello 0 " << (low <= cap) << endl;
    String last("Last LetteR");
    String last2("Last Letter");
    cout << "Last LetteR <= Last Letter 1 " << (last <= last2) << endl;
    cout << "Last Letter <= Last LetteR 0 " << (last2 <= last) << endl;
    String s("Short");
    String s2("Shorter");
    cout << "Short <= Shorter 1 " << (s <= s2) << endl;
    cout << "Shorter <= Short 0 " << (s2 <= s) << endl;
    String emp("");
    String emp2("a");
    cout << " <emp> <= a 1 " << (emp <= emp2) << endl;
    cout << " a <= <emp> 0 " << (emp2 <= emp) << endl;
    String true_emp("");
    String true_emp2("");
    cout << " <emp> <= <emp> 1 " << (true_emp <= true_emp2) << endl;
}

void test_relationals()
{
   test_equals();
   test_inequals();
   test_gt();
   test_lt();
   test_gteq();
   test_lteq();
}

void test_reverse()
{
    cout << endl << "REVERSE TESTS" << endl;
    String hello("Hello World");
    cout << hello << " reverse: " << "\"" << hello.reverse() << "\"" << endl;
    String empty("");
    cout << empty << " reverse: " << "\"" << empty.reverse() <<  "\"" << endl;
    String longest("THIS IS alksdjfal;dkfjal;ewfkjae;lkfjae;lfkjaew;lfkjaew;fkjawe;lfkj;ewlkfjaew;flkjefkjewljae;lfkjaelkjfawelfkjwelfj THIS IS END NOT T    HIS");
    cout << longest << " reverse: " << "\"" << longest.reverse() << "\"" << endl;
}

void test_concat_self()
{
    cout << endl << "+= Concatenation" << endl;
    String hello("Hello ");
    String world("World");
    hello += world;
    cout << "Hello World: " << hello << endl;
    String emp("");
    hello += emp;
    cout << "Hello World: " << hello << endl;
    String longest("THIS IS alksdjfal;dkfjal;ewfkjae;lkfjae;lfkjaew;lfkjaew;fkjawe;lfkj;ewlkfjaew;flkjefkjewljae;lfkjaelkjfawelfkjwelfj THIS IS END NOT THIS");
    cout << "Longest word (no error): ";
    longest+= emp;
    cout << longest << endl;
    cout << "Longest word (error): ";
    longest+= hello;
    cout << longest << endl;
    cout << "Testing empty added to (hello world): " << "\"";
    emp+= hello;
    cout << emp << "\"" << endl;
}

void test_concatenate()
{
    cout << endl << "CONCATENATE TESTS" << endl;
    String hello("Hello ");
    String world("World");
    cout << "Hello World: " << (hello + world) << endl;
    String emp("");
    cout << "Hello: " << (hello + emp) << endl;
    String longest("THIS IS alksdjfal;dkfjal;ewfkjae;lkfjae;lfkjaew;lfkjaew;fkjawe;lfkj;ewlkfjaew;flkjefkjewljae;lfkjaelkjfawelfkjwelfj THIS IS END NOT T        HIS");
    String chara("a");
    String emp2("");
    cout << "Long + Error: " << (longest + chara) << endl;
    cout << "Long + emp: " << (longest + emp) << endl;
    cout << "Emp + emp: " << "\"" << (emp + emp2) << "\"" << endl;
    test_concat_self();
}

void test_indexOfChars()
{
    cout << endl << "Index Characters TESTS" << endl;
    String norm("Hello World");

    cout << "Hello World contains H at 0: " << norm.indexOf('H') << endl;
    cout << "Hello World does not contain h (-1) " << norm.indexOf('h') << endl;
    cout << "Hello World contains d at 10: " << norm.indexOf('d') << endl;
    cout << "Hello World contains o at 4: " << norm.indexOf('o') << endl;
    String emp;
    cout << "Empty does not contain a (-1) " << norm.indexOf('h') << endl;

}

void test_indexOfStrs()
{
    cout << endl << "Index String TESTS" << endl;
    String norm("Hello World");
    String hello("Hello");
    cout << "Hello World contains Hello at 0: " << norm.indexOf(hello) << endl;
    String world("llo World");
    cout << "Hello World contains llo World at 2: " << norm.indexOf(world) << endl;
    String worlf("Worlf");
    cout << "Hello World does not contain Worlf (-1): " << norm.indexOf(worlf) << endl;
    String emp("");
    String emp2("");
    cout << "Empty contains empty at 0: " << emp.indexOf(emp2) << endl;
}

void test_indexOf()
{
    test_indexOfChars();
    test_indexOfStrs();
}

int main()
{
    test_constructors_and_print();
    test_assignment();
    test_relationals();
    test_reverse();
    test_concatenate();
    test_indexOf();
}
