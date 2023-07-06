#include <iostream>

#define MAXLEN 128

class String
{

    char buf[MAXLEN];
    
    static int strlen( const char * s){
        int out = 0;
        for(int i = 0;s[i] != '\0';i++){
            out++;
            }
        return out;
    }
    static char * strcpy( char * dest, const char * src){
        int i;
        int halt = strlen(src);
        for(i=0;src[i]!='\0'&&i<halt;i++){
            dest[i] = src[i];
        }
        dest[i] = '\0';
        return dest;
    }
    static char * strncpy( char * dest, const char * src, int n){
        int i;
        for(i=0;i<n;i++){
            dest[i] = src[i];
        }
        dest[i] = '\0';
        return dest;
    }
    static char * strcat(char * dest, const char * src){
        int s = strlen(dest);
        int halt = strlen(src);
       int i=0;
       for(;src[i] != '\0'&&i<halt;i++){
            dest[s+i] = src[i];
        }
        dest[i+s] = '\0';
        return dest;
    }
    static char strncat( char * dest, const char * src, int n){
        int s = strlen(dest);
        int i;
        for (i = 0;i+s<n;i++){
            dest[s+i] = src[i];
        }
        dest[s+i] = '\0';
        return * dest;
    }
    static int strcmp( const char * left, const char * right){
       int i;
       for(i = 0; left[i]!='\0'&& right[i]!='\0';i++){
            if(left[i] != right[i]){
                if( left[i] > right[i]){
                    return 1;
                }else{
                    return -1;
                }
            }

        }
        if(left[i] =='\0'&&right[i]!='\0')
            return -1;
        if(left[i]!='\0'&&right[i]=='\0')
            return 1;
    
        
        return 0;
    }
    static int strncmp(const char * left, const char * right,int n){
        int i;
        for(i = 0;i<n;i++){
            if(left[i]!=right[i]){
                if(left[i]>right[i]){
                    return 1;
                }else{
                    return -1;
                }
            }
        }
          if(left[i] =='\0'&&right[i]!='\0')
              return -1;
          if(left[i]!='\0'&&right[i]=='\0')
              return 1;
        return 0;
    }
    static void reverse_cpy( char * dest, const  char * src){
        int i=0;
        int stop = strlen(src);
        for(;i<stop;i++){
            dest[i] = src[stop-i-1];
        }
        dest[i] ='\0';
    }
    static char * strchr(char * str, char c){
        int i;
        for( i =0;str[i]!='\0';i++){
            if(str[i]==c)
                return str+i;
        }
        return nullptr;
    }
    
    static bool helper(char * cut, const char * needle,int indice){
        int i =0;
        for (;i<strlen(needle);i++){
            if(cut[i+indice]!=needle[i])
                return false;
        }
        return true;
    
    }

    static char * strstr(char * haystack, const char * needle){
        int needle_len = strlen(needle);
            
        for (int i=0; i < strlen(haystack); ++i ){
            if(helper(haystack,needle,i))
                return haystack+i;
          }
    return nullptr;
    
    }
    static const char * strstr( const char * haystack, const char * needle){
        return const_cast<char *>(String::strstr(const_cast<char *>(haystack), needle));
        }

public:

    explicit String( const char * s = ""){
        strncpy(buf,s,MAXLEN-1);
    }
    String(const String & s){
        strcpy(buf,s.buf);
        
    }
    String & operator =(const String & s){
        strcpy(buf,s.buf);
        return *this;
    }
    char & operator [](int index){
        if(in_bounds(index))
            return buf[index];
        return buf[0];
    }
    size_t size(){
        return strlen(buf);
    }

    String reverse(){
        char buftemp[strlen(buf)];
        String out(buftemp);
        reverse_cpy(out.buf,buf);
        return out;
    }
    int indexOf(const char c){
        char *p=strchr(buf,c);
        if(p==nullptr)
            return -1;
        return p-buf;
    
    }
    int indexOf(const String s){
        char *p=strstr(buf,s.buf);
        if(p==nullptr)
            return -1;
        return p-buf;
        


    }
    bool operator == (const String s){
        if(strcmp(buf,s.buf)==0)
            return true;
        return false;
    }
    bool operator !=(String s){
        if(strcmp(buf,s.buf)!=0)
            return true;
        return false;
 }   bool operator >(String s){
        if(strcmp(buf,s.buf)== 1)
            return true;
        return false;
}    bool operator <(String s){
        if(strcmp(buf,s.buf)==-1)
            return true;
        return false;

}
    bool operator <=(String s){
        if(strcmp(buf,s.buf)==-1||strcmp(buf,s.buf)==0)
            return true;
        return false;

}
    bool operator >=(String s){
    if(strcmp(buf,s.buf)==1||strcmp(buf,s.buf)==0)
        return true;
    return false;

}
    String operator +(const String s){
    String output(buf);
    strncat(output.buf,s.buf,MAXLEN-1);
    return output;
  
}
    String operator +=(const String s){
    strncat(buf,s.buf,MAXLEN-1);
    return *this;

  }
    void print(ostream & out){
        out<<buf;
        
    }
    // I learned at this point we were allowed to use the functions written before public:
    // I apologize for the code before this point. Know that however much pain your just felt reading it
    // I have felt amillion times more writing it
    void read( istream & in){
        char local[2*MAXLEN];
        in>>local;
        strncpy(buf,local,MAXLEN-1);
    }

    ~String(){
    }

private:

    bool in_bounds(int i){

        return i>=0&&i<strlen(buf);
    }
};

ostream & operator << (ostream & out,String s){
s.print(out);
return out;
}
istream & operator >> (istream & in, String & s){
s.read(in);
return in;
}
