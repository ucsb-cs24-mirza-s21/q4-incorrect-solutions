#include <iostream>
#include <queue>
#include <list>
#include <stack>
using namespace std;
class smartQueue{
    public:
        int min() const;
        int max() const;
        void pop();
        void push(const int x); 
        int front() const; 
        bool empty() const; 
    private:
        queue<int> q;
        queue<int> q2;
        stack<int> mins;
        stack<int> maxs;

};

void smartQueue::push(const int x) {
    q.push(x);
    if (mins.empty() && maxs.empty()){
        mins.push(x);
        maxs.push(x);
    } else if (x < mins.top()){
        mins.pop();
        mins.push(x);
    } else if (x > maxs.top()){
        maxs.pop();
        maxs.push(x);
    }
}

int smartQueue::front() const {
    return q.front();
}

bool smartQueue::empty() const {
    return q.empty();
}

void smartQueue::pop() {
    if (q.front() == mins.top()){
        mins.pop();
        while (!q.empty()){
            q2.push(q.front()); 
            q.pop();
        }
        int i = 1;
        while (!q2.empty()){
            if (i == 1){
                mins.push(q2.front());
            } else if (q2.front() < mins.top()){
                mins.pop();
                mins.push(q2.front());
            }
            q.push(q2.front());
            q2.pop();
            i++;
        }
    } else if (q.front() == maxs.top()){
        maxs.pop();
        while (!q.empty()){
            q2.push(q.front()); 
            q.pop();
        }
        int i = 1;
        while (!q2.empty()){
            if (i == 1){
                maxs.push(q2.front());
            } else if (q2.front() > maxs.top()){
                maxs.pop();
                maxs.push(q2.front());
            }
            q.push(q2.front());
            q2.pop();
            i++;
        }
    }
    q.pop();
}

int smartQueue::min() const {
    return mins.top();
}

int smartQueue::max() const {
    return maxs.top();
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
