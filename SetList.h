template  <typename T>
class SetList{
    struct ListNode{
        T data;
        ListNode* next;
        };
    ListNode* head;
public:
    class iterator{
        ListNode* current;
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using pointer = value_type*;
        using reference = value_type&;
        using difference_type = ptrdiff_t;
        
        explicit iterator(ListNode* const ptr = nullptr) : current(ptr){}
        iterator& operator++(){
            current = current ->next;
            return *this;
        }
        iterator operator++(int){
            current = current->next;
            return current->data;   
        }
        reference operator*() const{
            return current->data;
        }
        pointer operator->() const{
            return &(current->data);
        }
        bool operator==(iterator const& other ) const = default;
    };
    static_assert(std::forward_iterator<iterator>);
public:
    using value_type = T;
    
    SetList(){
        head = nullptr;
    }
    SetList(SetList const& other) = delete;
    SetList& operator=(SetList const& other) = delete;
    iterator begin(){
        return iterator(head);
        }
    iterator end(){
        return iterator(nullptr);

    }
    iterator find(T value){
        for(auto p = begin(); p!=end(); ++p){
            if(*p == value)
                return p;
        }
        return end();
    }
    iterator insert(iterator const, T value){
        if(find(value) == end()){
            head = new ListNode(value, head);
            return iterator(head);
            }
        return find(value);
    }


    ~SetList(){
        while(iterator(head) != end()){
            ListNode* temp = head->next;
            delete head;
            head = temp;
            }
    }
};
