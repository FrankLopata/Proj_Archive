#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;
#define quiz_weight 0.4
#define hw_weight 0.3
#define test_weight 0.3
void error(string msg){
    cout<<"Error: "<<msg<<endl;
}

class Student{
    string first_name;
    string last_name;
    vector<int> quiz;
    vector<int> hw;
    double quiz_ave;
    double hw_ave;
    double final_score;
    int course_score;
    string course_grade;

public:



    
    Student(){
        first_name = "Missing";
        last_name = "Name";
        quiz_ave = 0.0;
        hw_ave = 0.0;
        final_score = 0.0;
        course_score = 0;
        string course_grade = "";
    }

    void quiz_push_back(int x){
        if(x>100 ||x<0)
            error("Error: invalid percentage " + to_string(x));
        quiz.push_back(x);}
    void hw_push_back(int x){
        if(x>100||x<0)
            error("Error: invalid percentage" + to_string(x));
        hw.push_back(x);}

    void calc_quiz_ave(){
         if (quiz.size() == 0)
        {
            quiz_ave = 0.0;
        }
        else if (quiz.size() == 1)
        {
            quiz_ave = quiz[0];
        }
        else
        {
            int l = *min_element(quiz.begin(),quiz.end());
            quiz_ave = (accumulate(quiz.begin(),quiz.end(),0.0)-l)/(quiz.size()-1);}}
    
    void calc_hw_ave(){
        if(hw.size()==0){
            hw_ave=0;
        }else{
        hw_ave = accumulate(hw.begin(), hw.end(), 0.0) / (hw.size());}
        }
    void set_first_name(string s){
        first_name = s;}
    void set_last_name(string s){
        last_name = s;}
    void set_final_score(double x){
        final_score = x;}

    string get_first_name(){
        return first_name;}
    string get_last_name(){
        return last_name;}
    
    string per_to_letter(int x){
              if(x >= 97)
                  return "A+";
              if(x>=93)
                  return "A";
              if(x>=90)
                  return "A-";
              if(x>=87)
                  return "B+";
              if(x>=83)
                 return "B";
             if(x>=80)
                 return "B-";
             if(x>=77)
                  return "C+";
              if(x>=73)
                  return "C";
              if(x>=70)
                 return "C-";
             if(x>=67)
                 return "D+";
             if(x>=63)
                 return "D";
             if(x>=60)
                 return "D-";
             return "F";
 
 
 
         }

    void compute_grade(){
        course_score = round(quiz_weight*quiz_ave+hw_weight*hw_ave+test_weight*final_score);
        course_grade = per_to_letter(course_score);
    }
    

    void read(istream & s){
                string word = "";
                while(s>>word){
                if(word == "Name"){
                    s>>word;
                     first_name = word;
                     s>>word;
                     last_name = word;
                     while(s>>word && word !=""){
                        if(last_name=="")
                             last_name = word;
                         else
                             last_name = last_name+" "+ word;}
                }

                 if (word == "Quiz"){
                     while(s>>word){
                         quiz.push_back(stoi(word));
                  }
                     calc_quiz_ave();
                     }
                if(word == "HW"){
                     while(s>>word){
                         hw.push_back(stod(word));
                         }
                          calc_hw_ave();
                 }
                 if(word =="Final"){
                     s>>word;
                     final_score = stod(word);
                     }

            }

            }

    void print(ostream & out)const{
            out<<"Name"<<'\t'<<first_name<<" "<<last_name<<endl;
            out<<"HW Ave:"<<'\t'<<hw_ave<<endl;
            out<<"QZ Ave:"<<'\t'<<quiz_ave<<endl;
            out<<"Final:"<<'\t'<< final_score<<endl;
            out<<"Total:"<<'\t'<< round(course_score) <<endl;
            out<<"Grade:"<<'\t'<<course_grade<<endl<<endl;            
    }

    friend ostream & operator <<(ostream & out,const Student & student){
        student.print(out);
        return out;
    }
    friend istream & operator >>(istream & in, Student & student){

        student.read(in);
        return in;
    }

};

class Gradebook{
    vector<Student> students;
public:



        Gradebook(){}




    
        void compute_grades(){
        for_each(begin(students),end(students),[](Student & s){s.compute_grade();});


        }

        void sort(){
            std::sort(students.begin(),students.end(),[](Student stu1, Student stu2){if(stu1.get_last_name() == stu2.get_last_name())return stu1.get_first_name()<stu2.get_first_name(); return stu1.get_last_name()<stu2.get_last_name();});
                

        }

        void print(ostream & out)const{
            for_each(begin(students),end(students),[&out](Student s){s.print(out);});
        
        }

        void read(istream & in){
            string s = "";
            
            while(in){
                Student Stud;
                for(int i =0;i<5;i++){
                        getline(in,s);
                        stringstream data(s);
                        string word = "";
                        
                        Stud.read(data);

                }
                if(s.empty()){
                    if(Stud.get_first_name() != "Missing"){
                        students.push_back(Stud);
                    }else{
                        cout<< s<<endl;
                        getline(in,s);
                }}else{
                    students.push_back(Stud);
                students.push_back(Stud);
            }
       }
}

       friend ostream & operator <<(ostream & out, const Gradebook & gb){
        gb.print(out);
        return out;
        }
        friend istream & operator >>(istream & in, Gradebook & gb){
            gb.read(in);
            return in;
        }

};

int main(){
    ifstream in("gradebook.txt");
    Gradebook gb;
    in>>gb;
    gb.sort();
    gb.compute_grades();
    ofstream out("course_grades.txt");
    out<<gb;
    return 0;
}
        


