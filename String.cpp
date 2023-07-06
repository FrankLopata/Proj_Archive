#include <iostream>
using namespace std;
#include "String.h"
#include "Alloc.h"



    char * String::strdup(const char *  s){
        char * out = Alloc::new_char_array(strlen(s)+1);
        return strcpy(out,s);
    }



     size_t String::strlen( const char * s){
        int out = 0;
        for(int i = 0;s[i] != '\0';++i){
            out++;
            }
        return out;
    }
     char * String::strcpy( char * dest, const char * src){
        int i;
        int halt = strlen(src);
        for(i=0;src[i]!='\0'&&i<halt;i++){
            dest[i] = src[i];
        }
        dest[i] = '\0';
        return dest;
    }
     char * String::strncpy( char * dest, const char * src, int n){
        int i;
        for(i=0;i<n;i++){
            dest[i] = src[i];
        }
        dest[i] = '\0';
        return dest;
    }
     char * String::strcat(char * dest, const char * src){
        int s = strlen(dest);
       int i=0;
       for(;src[i] != '\0';++i){
            dest[s+i] = src[i];
        }
        if(dest[i+s-1]!='\0')
            dest[i+s] = '\0';
        return dest;
    }
     char String::strncat( char * dest, const char * src, int n){
        int s = strlen(dest);
        int i;
        for (i = 0;i+s<n;i++){
            dest[s+i] = src[i];
        }
        dest[s+i] = '\0';
        return * dest;
    }
     int String::strcmp( const char * left, const char * right){
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
     int String::strncmp(const char * left, const char * right,int n){
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
     void String::reverse_cpy( char * dest, const  char * src){
        int i=0;
        int stop = strlen(src);
        for(;i<stop;++i){
            dest[i] = src[stop-i-1];
        }
        dest[i] ='\0';
    }
     char * String::strchr(char * str, char c){
        int i;
        for( i =0;str[i]!='\0';i++){
            if(str[i]==c)
                return str+i;
        }
        return nullptr;
    }
    
     bool String::helper(char * cut, const char * needle,int indice){
        int i =0;
        for (;i<strlen(needle);i++){
            if(cut[i+indice]!=needle[i])
                return false;
        }
        return true;
    
    }

    char  * String::strstr(char * haystack, const char * needle){
        int needle_len = strlen(needle);
            
        for (int i=0; i < strlen(haystack); ++i ){
            if(helper(haystack,needle,i))
                return haystack+i;
          }
    return nullptr;
    
    }
    const char * String::strstr( const char * haystack, const char * needle){
        return const_cast<char *>(String::strstr(const_cast<char *>(haystack), needle));
        }

        // DIVIDER FOR HELPER AND PUBLIC

      String::String( const char * s){
        
        buf = strdup(s);
    }
      String::String(const String & s){
        buf =  strdup(s.buf);
        
    }
    String::String(String && s){
    Alloc::delete_char_array(buf);
    buf = s.buf;
    s.buf = nullptr;

    }
    String & String::operator =(const String & s){
        strcpy(buf,s.buf);
        return *this;
    }
    String & String::operator =(String && s){
        Alloc::delete_char_array(buf);
        buf = s.buf;
        s.buf = nullptr;
        return *this;
    }
    char & String::operator [](int index){
        if(in_bounds(index))
            return buf[index];
        return buf[0];
    }
    size_t String::size(){
        return strlen(buf);
    }

    String String::reverse(){
    //size_t siz = strlen(buf)+1;
    //int i;
    //char * out = Alloc::new_char_array(strlen(buf)+1);
  	//for ( i = 0 ; i < siz; ++i )
  	//	out[i]=buf[siz-i];
    //out[i]='\0';
    //String result(out);
  	//return result;
    char * buftemp = Alloc::new_char_array(strlen(buf)+1);
    reverse_cpy(buftemp,buf);
    String out(buftemp);
    Alloc::delete_char_array(buftemp);
    return out;

    }
    int String::indexOf(const char c){
        char *p=strchr(buf,c);
        if(p==nullptr)
            return -1;
        return p-buf;
    
    }
    int String::indexOf(const String s){
        char *p=strstr(buf,s.buf);
        if(p==nullptr)
            return -1;
        return p-buf;
        


    }
    bool String::operator == (const String s){
        if(strcmp(buf,s.buf)==0)
            return true;
        return false;
    }

    bool String::operator !=(String s){
        if(strcmp(buf,s.buf)!=0)
            return true;
        return false;
 }   bool String::operator >(String s){
        if(strcmp(buf,s.buf)== 1)
            return true;
        return false;
}    bool String::operator <(String s){
        if(strcmp(buf,s.buf)==-1)
            return true;
        return false;

}
    bool String::operator <=(String s){
        if(strcmp(buf,s.buf)==-1||strcmp(buf,s.buf)==0)
            return true;
        return false;

}
    bool String::operator >=(String s){
    if(strcmp(buf,s.buf)==1||strcmp(buf,s.buf)==0)
        return true;
    return false;

}
   String String::operator +(const String & s){
   char * r = Alloc::new_char_array(strlen(s.buf)+1);
   char * container = Alloc::new_char_array(strlen(buf)+strlen(s.buf)+1);
   strcpy(container,buf);
   strcpy(r,s.buf);
    strcat(container,r);
    String o(container);
    Alloc::delete_char_array(container);
    Alloc::delete_char_array(r);
    return o;
  
}
    String String::operator +=(const String & s){
    int b = strlen(buf);
    int st = strlen(s.buf);
    char * t = Alloc::new_char_array(b+st+1);
    strcpy(t,buf);
    strcat(t,s.buf);
    Alloc::delete_char_array(buf);
    buf = t;

    return *this;

  }
    void String::print(ostream & out)const{
        out<<buf;
        
    }
    void String::read( istream & in){
        char local[1024];
        in>>local;
        strcpy(buf,local);
    }

    String::~String(){
    Alloc::delete_char_array(buf);
    }

    bool String::in_bounds(int i){
        int siz = strlen(buf);
        return i>=0&&i<siz;
    }

ostream & operator << (ostream & out,String s){
s.print(out);
return out;
}
istream & operator >> (istream & in, String & s){
s.read(in);
return in;
}
