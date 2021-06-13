#include <iostream>
#include <queue>
#include <list>
#include <stack>
using namespace std;

class smartQueue {
    public:
        void push(int n);
        void pop();
        int front() {return normQ.front();};
        bool empty() {return normQ.empty();};
        int min() {return minStack.top();}
        int max() {return maxStack.top();}
    private:
        stack<int> minStack;
        stack<int> maxStack;
        queue<int> normQ;
};

void smartQueue::push(int n) {
    normQ.push(n);
    if (minStack.empty() && maxStack.empty()) {
        minStack.push(n);
        maxStack.push(n);
    }
    else if (n < minStack.top()) {
        minStack.push(n);
    }
    else if (n > maxStack.top()) {
        maxStack.push(n);
    }
}

void smartQueue::pop() {
    if (minStack.top() == normQ.front()) {
        normQ.pop();
        minStack.pop();
    }
    else if (maxStack.top() == normQ.front()) {
        normQ.pop();
        maxStack.pop();
    }
    else {
        normQ.pop();
    }
}
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
    cout<<"Print rest of the queue: ";
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
    cout<<"Print rest of the queue: ";
   // print_queue(sQ);
    return 0;
}
