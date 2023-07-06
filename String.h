#include <iostream>
#ifndef STRING_H
#define STRING_H

class String
{
public:

explicit String( const char * s = "");
String(const String & s);
String(String && s);
String & operator =(const String & s);
char & operator [](int index);
size_t size();
String reverse();
int indexOf(const char c);
int indexOf(const String s);
bool operator == (const String s);
bool operator !=(String s);
bool operator >(String s);
bool operator <(String s);
bool operator <=(String s);
bool operator >=(String s);
String operator +(const String &  s);
String operator +=(const String & s);
void print(ostream & out)const;
void read( istream & in);
bool in_bounds(int i);
String & operator =(String && s);
~String();


private:
    
    char * buf;
    static size_t strlen( const char * s);
    static char * strcpy( char * dest, const char * src);
    static char * strncpy( char * dest, const char * src, int n);
    static char * strcat(char * dest, const char * src);
    static char strncat( char * dest, const char * src, int n);
    static int strcmp( const char * left, const char * right);
    static int strncmp(const char * left, const char * right,int n);
    static void reverse_cpy( char * dest, const  char * src);
    static char * strchr(char * str, char c);
    static bool helper(char * cut, const char * needle,int indice);
    static char * strstr(char * haystack, const char * needle);
    static const char * strstr( const char * haystack, const char * needle);
    static char * strdup(const char * s);

    };

    ostream & operator << (ostream & out,String s);
    istream & operator >> (istream & in, String & s);
#endif /* STRING_H */
