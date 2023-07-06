#ifndef PICTURE_H
#define PICTURE_H

#include <string>
#include <iostream>
using namespace std;
#include "Shape.h"


class Picture{
    struct ListNode{
        Shape * data;
        ListNode * next;

        ListNode(Shape * new_data,ListNode * new_next){
            data = new_data;
            next = new_next;
        }
        };

        ListNode * head;
        ListNode * tail;

public:

    Picture(){
        tail = nullptr;
        head =nullptr;
    }

    void add(Shape * sp){
        if(head == nullptr){
            head = new ListNode(sp,nullptr);
            tail = head;
       } else{
            tail->next = new ListNode(sp,nullptr);
            tail = tail->next;
    }

    }
    
    double total_area(){
        double out = 0.0;
        for(ListNode * tmp = head; tmp !=nullptr;tmp = tmp->next){
            out += tmp->data->area();
       } return out;

    }

    void draw_all(){
        for(ListNode * tmp = head; tmp != nullptr; tmp = tmp->next)
            tmp->data->draw();        
    }

    void print_all(){
        for(ListNode * tmp = head; tmp != nullptr;tmp = tmp->next)
                tmp->data->print();
        
    }

    ~Picture(){
        ListNode * temp = nullptr;
        ListNode * tmp = head;
        while(tmp !=nullptr){
            temp = tmp->next;
            delete tmp->data;
            delete tmp;
            tmp = temp;
            }

    }

};
#endif
