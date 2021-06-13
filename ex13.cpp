#include <iostream>
#include <queue>
#include <list>
#include <stack>
using namespace std;
class smartQueue
{
    private:
    class Node
    {
        private:
        int key;
        Node *next;

        public:
        Node(int key)
        {
            this->key = key;
            this->next = nullptr;
        };
        int get_key() { return this->key; }
        void set_next(Node *next) {this->next = next; }
        Node* get_next() { return this->next; }

    };
    Node *head;
    Node *tail;
    int min_;
    int max_;

    // ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- -----

    public:
    smartQueue(){
        this->head = nullptr;
        this->tail = nullptr;
    }

    void push(int key)
    {
        Node *temp = new Node(key);
        if (this->head == nullptr)
        {
            this->head = temp;
            this->tail = temp;
            this->min_ = key;
            this->max_ = key;
        }
        else
        {
            this->tail->set_next(temp);
            this->tail = temp;
            if (key < this->min_)
                this->min_ = key;
            if (key > this->max_)
                this->max_ = key;
        }
    }

    void pop()
    {
        Node *temp = this->head;
        if (this->max_ == this->head->get_key())
        {
            this->max_ = NULL;
            while (temp->get_next() != nullptr)
            {
                temp = temp->get_next();
                if (this->max_ < temp->get_key())
                    this->max_ = temp->get_key();
            }
        }

        if (this->min_ == this->head->get_key())
        {
            this->min_ = NULL;
            while (temp->get_next() != nullptr)
            {
                temp = temp->get_next();
                if (this->min_ > temp->get_key())
                    this->min_ = temp->get_key();
            }
        }

        temp = this->head;
        this->head = this->head->get_next();
        delete temp;
    }

    int front() { return this->head->get_key(); }
    bool empty() { return this-> head == nullptr; }
    int min() { return this->min_; }
    int max() { return this-> max_; }
};
int main() {
    smartQueue sQ;
    // push 3, 7, 2, 9, 8, 4
    // pop() 
    sQ.push(3);
    cout<<"Push 3:"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 3, "<<sQ.min()<<endl;
    cout<<"   max: 3, "<<sQ.max()<<endl;
   
    sQ.push(7);
    cout<<"Push 7"<<endl;
     cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 3, "<<sQ.min()<<endl;
    cout<<"   max: 7, "<<sQ.max()<<endl;
    sQ.push(2);
    cout<<"Push 2"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl;
    cout<<"   max: 7, "<<sQ.max()<<endl;
    sQ.push(9);
    cout<<"Push 9"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<"front: 3, "<<sQ.front()<<endl;;
    cout<<"  min: 2, "<<sQ.min()<<endl;
    cout<<"  max: 9, "<<sQ.max()<<endl;
    sQ.push(8);
    cout<<"Push 8"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl;
    cout<<"   max: 9, "<<sQ.max()<<endl;
    sQ.push(4);
    cout<<"Push 4"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl;
    cout<<"   max: 9, "<<sQ.max()<<endl;

    cout<<endl<<"Start popping"<<endl<<endl;
    // elements in smartQueue: 3, 7, 2, 9, 8, 4
    sQ.pop();
    cout<<"Popped 3"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 7, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl;
    cout<<"   max: 9, "<<sQ.max()<<endl;
    sQ.pop();
    cout<<"Popped 7"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 2, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl;
    cout<<"   max: 9, "<<sQ.max()<<endl;
    sQ.pop();
    cout<<"Popped 2"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 9, "<<sQ.front()<<endl;
    cout<<"   min: 4, "<<sQ.min()<<endl;
    cout<<"   max: 9, "<<sQ.max()<<endl;
    sQ.pop();
    cout<<"Popped 9"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 8, "<<sQ.front()<<endl;
    cout<<"   min: 4, "<<sQ.min()<<endl;
    cout<<"   max: 8, "<<sQ.max()<<endl;
   
    sQ.push(3);
    cout<<"Pushed 3"<<endl;
    // queue has 8, 4, 3
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 8, "<<sQ.front()<<endl;
    cout<<"   min: 3, "<<sQ.min()<<endl;
    cout<<"   max: 8, "<<sQ.max()<<endl;
    sQ.pop();
    cout<<"Popped 8"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 4, "<<sQ.front()<<endl;
    cout<<"   min: 3, "<<sQ.min()<<endl;
    cout<<"   max: 4, "<<sQ.max()<<endl;
    //cout<<"Print rest of the queue: ";
   // print_queue(sQ);
    return 0;
}
