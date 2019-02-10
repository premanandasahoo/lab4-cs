#include<iostream>
using namespace std;

class Node
{
	public:
		//Data
		int data;
		//Pointer to the next node	
		Node *next;
		//Constructor that makes the pointer Null
		Node()
		{
			next=NULL;
		}
		
};


class LinkedList
{
	//Head + Nodes inside linked with each other
	public:
	//Head -> Node type pointer
	Node *head;
	Node *tail;
	//constructor
	LinkedList()
	{
		head=NULL;
		tail=NULL;
	}
	//circled inside linked with each other
	//rules how circles will be linked
	//Insert
	void insert(int value)
	{
		//If first node is added
		Node *temp = new Node;
		//insert data in the node
		temp->data = value;
		//1st Node only
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		//Any other Node only
		else
		{
			tail->next=temp;
			tail=temp;
		}
		
	}
	//Deletion of last element
	void delet()
	{
	  
	//store the tail in temp
	Node *temp=tail;
	//before tail has to point to NULL
	Node *current=head;
	while(current->next!=tail)
	{
	    current=current->next;
	}
	current->next=NULL;
	//update tail
	tail=current;
	//delete temp
	delete temp;
	}
	void display()
	{
	
		Node *current=head;
		while(current!=NULL)
		{
			cout<<current->data<<" ";
			current=current->next;
		}
		cout<<endl;
	}
	void insertAt(int pos, int value)
	{
	    //Reach the place before the position
	    Node *current=head;
	    int i=1;
	    if(pos!=1)
	    {
	        while(i<pos-1)
	        {
	            i++;
	            current=current->next;
	        }
	        //Create a node
	        Node *temp=new Node;
	        temp->data=value;
	        //moving pointers
	        temp->next=current->next;
	        current->next=temp;
	        
	    }
	    else
	        
	        {
	            //create new node
	            Node *temp=new Node;
	            //insert value in the Node
	            temp->data=value;
	            //point the new first node to the previously first node
	            temp->next=head;
	            //point the head to the new first node 
	            head=temp;
	            
	            if(tail==NULL) {tail=temp;}
	        }     
	}
	//Delete at a particular position
	void deleteAt(int pos)
	{
	    int i=1;
	    int j=1;
	    int n=countItems();
    	//for all cases except position=1
    	//reach the nodes before and after the node to be deleted 
    	if(pos!=1&&pos!=n)
    	{
    	    //the node before
    	    Node *current=head;
    	    //the node after
    	    Node *current2=head;
    	    //reaching the node before
    	    while(i<pos-1)
    	    {
    	        i++;
    	        current=current->next;
    	    }
    	    //reaching the node after
    	    while(j<pos+1)
    	    {
    	        j++;
    	        current2=current2->next;
    	    }
    	    //store the node to be deleted in a temp variable
    	    Node *temp=current->next;
    	    //link the two nodes:before and after
    	    current->next=current2;
    	    //point the node to be deleted to NULL
    	    temp->next=NULL;
    	    //delete temp
    	    delete temp;
    	}
    	
    
    	else
    	{
    	    //Store the first node in a  temp variable
    	    Node *temp=head;
    	    //point head to the 2nd Node
    	    head=head->next;
    	    //delete temp
    	    delete temp;
    	}
	}	
	//Counting no of items in the linked list
	int countItems()
	{
	    //setting up a count variable
	    int count=0;
	    //create a current variable to reach the end of the linked list
	    Node *current=head;
	    //reach the end of the linked list
	    while(current!=NULL)
	    {
	        current=current->next;
	        count++;
	    }
	    return count;
	    
	}
	
	void revDisp()
	{
	    
	    revDisp();
	    
	}
	
};





class Stack
{
	public:
		Node *top;
		LinkedList l1;
		Stack()
		{
			top=l1.head;
		}	
		//adds an element on the top
		void push(int value)
		{
			l1.insertAt(1,value);
			//top= new_head
			top=l1.head;
			
		}
		//deletes an element from the top
		void pop()
		{
			//void deleteAt(int pos)
			l1.deleteAt(1);
			//top= new_head
			top=l1.head;
		}
		//to find if the stack is empty or not
		bool isEmpty()
		{
			if(top==NULL) return true;
			else return false;
		}
		int size()
		{
			return l1.countItems();
		}
		
		//returns the top element
		void topDisplay()
		{
			
		}
		//displays the elements
		void display()
		{
			l1.display();
		}
		
};


class Queue_stack
{
	public:	
		Stack s1,s2;
		
		void enqueue(int value)
		{
			s1.push(value);
		}
		
		void dequeue()
		{
			int i=1;
			int j=1;
			int n=s1.size();
			if(n!=0)
			{
    			while(i<n)
    			{
    				s2.push(s1.top->data);
    				s1.pop();
    				i++;
    			}
                s1.pop();
    			while(j<n)
    			{
    			    s1.push(s2.top->data);
    			    s2.pop();
    			    j++;
    			}
			}
			
			else cout<<"The Queue does not have any items"<<endl;
		}
		
		void display()
		{
			s1.display();
		}
		
};

int main()
{
	Queue_stack q1;
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(6);
	q1.display();
	q1.dequeue();
	q1.display();
	q1.dequeue();
	q1.display();
	q1.dequeue();
	q1.display();
	q1.dequeue();
	q1.display();
	q1.dequeue();
	q1.display();
	return 0;
	
	
}
