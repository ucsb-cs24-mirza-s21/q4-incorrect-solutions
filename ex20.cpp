#include <iostream>
#include <queue>
#include <list>
#include <stack>
using namespace std;
class smartQueue{
queue<int> reg;
// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void push(int value){
reg.push(value);
  vdata.push_back(value);
   // Percolate up from the last index to restore heap property
   PercolateUp(vdata.size()-1);
}

void PercolateUp(int nodeIndex) {
   while (nodeIndex > 0) {
      // Compute the parent node's index
      int parentIndex = (nodeIndex - 1) / 2;
            
      if (vdata.at(nodeIndex) >= vdata.at(parentIndex)) {
         // No violation, so percolate up is done.
         return;
      }
      else {
         // Swap parent and child for in vdata
         int temp = vdata.at(nodeIndex);
         vdata.at(nodeIndex) = vdata.at(parentIndex);
         vdata.at(parentIndex) = temp;
                    
         // Continue the loop from the parent node
         nodeIndex = parentIndex;
      }
   }
}
// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void pop(){
reg.pop(value);
//int minValue = vdata.at(0);
   // Move the last item in the array into index 0
   if (vdata.size() > 0) {
      int replaceValue = vdata.at(vdata.size() - 1);
      vdata.at(0) = replaceValue;
     
     vdata.pop_back();
      // Percolate down to restore min-heap property
      if(vdata.size()>1){
      PercolateDown(0);
     }
   }
                
   // Return the min value
}
void PercolateDown(int nodeIndex) {
   int childIndex = 2 * nodeIndex + 1;
   int value = vdata.at(nodeIndex);
   int size = vdata.size(); //-1
   while (childIndex < size) {
      // Find the min among the node and all the node's children
      int minValue = value;
      int minIndex = -1;
      int i = 0;
      while (i < 2 && i + childIndex < size) {
         if (vdata.at(i + childIndex) < minValue) {
            minValue = vdata.at(i + childIndex);
            minIndex = i + childIndex;
         }
         i++;
      }

      // Check for a violation of the min-heap property
      if (minValue == value) {
         return;
      }
      else {
         // Swap
         int temp = vdata.at(nodeIndex);
         vdata.at(nodeIndex) = vdata.at(minIndex);
         vdata.at(minIndex) = temp;
                    
         // Continue loop from the min index node
         nodeIndex = minIndex;
         childIndex = 2 * nodeIndex + 1;
      }
   }
}

// Returns the minimum element in the heap
int min(){
   if (empty()){
      return 0;
   }
  return vdata.at(0);
}

// Returns true if the heap is empty, false otherwise
bool empty(){
  return (vdata.size()==0);
}
    
void print(){
   for (int i = 0; i<vdata.size();i++){
      cout<<vdata.at(i);
   }
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
