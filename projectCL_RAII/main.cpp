/*shared_ptr
  unique_ptr
  */

#include <iostream>
#include <memory>



/*int main(){
    int * ptr  = new int(17);
    std::cout<<*ptr<<"\n";
    delete ptr;

    std::unique_ptr<int> smart = std::make_unique<int> (17); //Ссылку не изменить и не передать (нужнее для динамической памяти)
    std::cout<<*smart<<"\n";
    }
*/



/*
int* f () {
    return new int(17);
}
std::unique_ptr<int> g() {
    return std::make_unique<int>(17);
}
int main() {
    f();
    g();
}
*/



#include <utility>


/*
void sendIn(std::unique_ptr<Logger> x) {
    //....
}

int main() {
    auto smart = std::make_unique<Logger>();
    sendIn (std::move(smart));
    //....

}
*/



/*
template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> next;
    };
    std::unique_ptr<Node> head;
public:
    void PushFront(const T& elem) {
        head = std::make_unique<Node>(elem, std::move(head));
    }
    void PopFront() {
        head = std::move(head -> next);
    }
    const T& Front() const {
        return head -> data;
    }
    bool Empty() const {
        return head == nullptr;
    }
    ~ForwardList() {
        while(!Empty()) {
            PopFront();

        }
    }

}; //закрываем класс
*/



int main () {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(17); //shared можно копировать и изменять
    std::cout<<*ptr1<<"\n";
    std::cout<<ptr1.use_count()<<"\n";
    auto ptr2 = ptr1;
    std::cout<<*ptr1<<"\n";
    std::cout<<*ptr2<<"\n";
    std::cout<<"ptr1.use_count() = "<<ptr1.use_count()<<"\n";
    std::cout<<"ptr2.use_count() = "<<ptr2.use_count()<<"\n";
    std::shared_ptr<int> ptr3;
    std::cout<<"ptr3.use_count()"<<ptr3.use_count()<<"\n";
    ptr3 = ptr1;
    std::cout<<*ptr3<<"\n";
    std::cout<<ptr3.use_count()<<"\n";

}