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
		}
		tail=temp;
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
	            if (tail==NULL){tail=temp;}
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
    	
    	else if(pos==n)
    	{
    	    Node *current=head;
    	    int k=0;
    	    while(k<n-2)
    	    {
    	        current=current->next;
    	        k++;
    	    }
    	    Node *temp=current->next;
    	    current->next=NULL;
    	    tail=current;
    	    delete temp;
    	}
    	//for position = 1
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











class Queue
{
	public:
		Node *end;
		Node *front;
		LinkedList l1;
	
		Queue()
		{
			front=l1.tail;
			end=l1.head;
		}
		
		void enqueue(int value)
		{
			l1.insertAt(1,value);
			end=l1.head;
			front=l1.tail;
			
			
		}
		
		void dequeue()
		{

			int n=l1.countItems();
			if(n!=0)
			{
			l1.deleteAt(n);
			front=l1.tail;
			
			end=l1.head;
			
			}
			else cout<<"There are no elements in the queue";
		}
		bool isEmpty()
		{
			if(end==NULL) return true;
			else return false;
		}
		int size()
		{
			return l1.countItems();
		}
		void display_front()
		{
			cout<<front->data;
		}
		
		void display_end()
		{
			cout<<end->data;;
		}
		void display()
		{
			l1.display();
		}
			
};

int main()
{
	Queue q1;
	for(int i=0;i<5;i++)
	{
		q1.enqueue(i);
	}
	q1.display();
	q1.dequeue();
	q1.display();
	return 0;
}


