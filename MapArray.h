#include <vector>
#include <algorithm>
template <typename Key,typename Value>
class MapArray{
    std::vector<std::pair<Key,Value>> vec;
public:
    class iterator {
        std::pair<Key,Value>* current;
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = std::pair<Key,Value>;
        using pointer = value_type*;
        using reference = value_type&;
        using difference_type = std::ptrdiff_t;

        explicit iterator(pointer const ptr = nullptr) : current(ptr){}
        iterator& operator++(){
            ++current;
            return *this;
        }
        iterator& operator--(){
            --current;
            return *this;

        }
        iterator operator++(int){
            iterator temp(current);
            ++current;
            return temp;
        }
        iterator operator--(int){
            iterator temp(current);
            --current;
            return temp;
        }
        iterator& operator+=(difference_type const d){
            current += d;
            return *this;
        }
        iterator& operator-=(difference_type const d){
            current -=d;
            return *this;
        }
        friend iterator operator+(iterator i, difference_type const d){
            return iterator(i.current + d);
        }
        friend iterator operator+(difference_type const d, iterator i){
            return iterator(i.current + d);
        }
        friend iterator operator-(iterator i, difference_type const d){
                return iterator(i.current - d);
        }
        friend iterator operator-(difference_type const d, iterator i){
                return iterator(d - i.current);
        }
        friend difference_type operator-(iterator const i, iterator const j){
            return i.current - j.current;
        }
        auto operator <=>(iterator const& other) const = default;
        reference operator*() const{
            return *current;
        }
        pointer operator->() const{
            return current;
        }
        reference operator[](difference_type const d)const{
            return *(current+d);
            
        }

    };
    static_assert(std::random_access_iterator<iterator>);
    using value_type = std::pair<Key,Value>;
    iterator begin(){
        return iterator(vec.data());
    }
    iterator end(){
        return iterator(vec.data()+vec.size());
    }
    Value& operator[](Key const& key){
            auto findit  = std::lower_bound(vec.begin(),vec.end(),key,[](std::pair<Key,Value>const& p,Key const& key){
                    return key > p.first;
            });
            if(findit == vec.end()||findit->first != key){
                auto x = vec.insert(findit,std::pair{key,Value{}});
                return x->second;
                }
            return findit->second;
                }
        

};
