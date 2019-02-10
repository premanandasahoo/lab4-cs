#include <iostream>
using namespace std;

class Queue_arr
{
	public:
		int arr[200];
		int front=0;
		int end=0;
		
		void enqueue(int value)
		{
			arr[end]=value;
			end++;
		}
		
		void dequeue()
		{
			arr[front]=0;
			front++;
		}
		
		void display()
		{
			for(int i=front;i<end;i++)
			{
				cout<<arr[i]<<" ";
				
			}
			cout<<endl;
		}
		
			bool isEmpty()
		{
			if(end==0) return true;
			else return false;
		}
		
		int countItems()
		{
			int count=0;
			for(int i=front;i<end;i++)
			{
				count++;
			}
			return count;
		}
};

int main()
{
	Queue_arr q1;
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(6);
	q1.enqueue(9);
	q1.display();
	q1.dequeue();
	q1.display();
}