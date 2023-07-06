#include <iostream>
#ifndef ALLOC_H
#define ALLOC_H
using namespace std;

class Alloc{
    static int total_allocations;
    static int total_bytes;
    static int net_allocations;

public:
    static char * new_char_array(size_t n_bytes);
    static void delete_char_array(char *p);
    static void report_allocations();
};
#endif /* ALLOC_H */
