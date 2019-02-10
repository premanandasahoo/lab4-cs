#include <iostream>
using namespace std;

class Stack_arr
{
	public:
		int a1[200];
		int top=0;
		
		void push(int value)
		{
			a1[top]=value;
			top++;
		}
		
		void pop()
		{
			a1[top-1]=0;
			top--;
		}
		
		void display()
		{
			for(int i=0;i<top;i++)
			{
				cout<<a1[i]<<" ";
			}
			
			cout<<endl;
		}
		
		bool isEmpty()
		{
			if(top==0) return true;
			else return false;
		}
		
		int countItems()
		{
			int count=0;
			for(int i=0;i<top;i++)
			{
				count++;
			}
			return count;
		}
};

int main()
{
	Stack_arr s1;
	s1.push(2);
	s1.push(3);
	s1.push(6);
	s1.push(9);
	s1.display();
	s1.pop();
	s1.display();
	cout<<"The no of items in the stack is: "<<s1.countItems();
	return 0;
}
