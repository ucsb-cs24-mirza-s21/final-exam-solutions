// Credits: Code based on solution implemented by Zach Han
// Test cases added by Justin Kasowski
#include <iostream>
#include <queue>
#include <list>
using namespace std;

class smartQueue{
private:
    queue<int> nums;
    list<int> smallest; // Keep track of minimums, list can be replaced by deque with no additional modifications
    list<int> largest; // Keep track of maximums, list can be replaced by deque with no additional modifications
public:
    void push(int num)
    {
        nums.push(num);
        while(!smallest.empty() && num < smallest.back()) // remove all numbers that are bigger than the new number
        {
            smallest.pop_back();  //pop off numbers until it's not smaller than the next number
            // No numbers that are popped from the main queue will ever be the min of the queue
            // because the newest number added is smaller.
            // This also ensures the number in the front is always the smallest, but you're still
            // keeping track of the other smallest numbers for after the current min is popped
        }
       
        smallest.push_back(num);

        while(!largest.empty() && num > largest.back()) //same logic as smallest
        {
            largest.pop_back();
        }

        largest.push_back(num);
    }

    void pop()
    {
        int temp = nums.front();
        nums.pop();
     
        if(temp == smallest.front())
        {
            smallest.pop_front();
        }
        if(temp == largest.front())
        {
            largest.pop_front();
        }
    }
    int front()
    {
        return nums.front();
    }
    bool empty()
    {
        return nums.empty();
    }
    int min()
    {
        return smallest.front();
    }
    int max()
    {
        return largest.front();
    }
};

void print_queue(smartQueue q)
{
    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

int main() {
    smartQueue sQ;
   
    sQ.push(3);
    cout<<"Push 3:"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 3, "<<sQ.min()<<endl; // smallest: 3
    cout<<"   max: 3, "<<sQ.max()<<endl; // largest: 3
   
    sQ.push(7);
    cout<<"Push 7"<<endl;
     cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 3, "<<sQ.min()<<endl; // smallest: 3 7
    cout<<"   max: 7, "<<sQ.max()<<endl; // largest: 7
    sQ.push(2);
    cout<<"Push 2"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl; // smallest: 2
    cout<<"   max: 7, "<<sQ.max()<<endl; // largest: 7 2
    sQ.push(9);
    cout<<"Push 9"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<"front: 3, "<<sQ.front()<<endl;;
    cout<<"  min: 2, "<<sQ.min()<<endl; // smallest: 2 9
    cout<<"  max: 9, "<<sQ.max()<<endl; // largest: 9
    sQ.push(8);
    cout<<"Push 8"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl; // smallest: 2 8
    cout<<"   max: 9, "<<sQ.max()<<endl; // largest: 9 8
    sQ.push(4);
    cout<<"Push 4"<<endl;
    cout<<" Expected, Actual"<<endl;
    cout<<" front: 3, "<<sQ.front()<<endl;
    cout<<"   min: 2, "<<sQ.min()<<endl; // smallest: 2 4
    cout<<"   max: 9, "<<sQ.max()<<endl; // largest: 9 8 4

    cout<<endl<<"Start popping"<<endl<<endl;
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
    print_queue(sQ);
    return 0;
}
