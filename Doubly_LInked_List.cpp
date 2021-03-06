// Author: Aslam Khan
// Email : aslamkhanofficial@yahoo.com
// Institute : Air University Islamabad

#include<iostream>
#include<conio.h>
using namespace std;

class Node
{
public:
	int data;
	Node* next; // to store address of next node
	Node* prev;// to store address of previous node
	Node()
	{
		data = 0;
	}
	Node(int d)
	{
		data = d;
		next = NULL;
		prev = NULL;
	}
};

class Linked_list
{
public:
	Node* head;// To store address of head node
	Linked_list();
	int Node_count();				// It will count the Number of Nodes in the list
	void Append_node(Node* n);		// It will add New node to the End
	void Prepend_node(Node* n);		// It will add New node to the front
	void Insert_node(int p, Node*);	// It will add New node at specific location
	void Display_forward();			// It will Print List data in Forward Direction
	void Display_backward();		// It will Print List of data in Backward Direction
	void Update_node(int p, int d); // it will Update Data of Specific Node
	void Delete_node(int p);		// It will delete a node from the list
	void Search_data(int d);		// it will search for data in the list
	




};

Linked_list::Linked_list()
{
	head = NULL;
}

int Linked_list::Node_count()
{
	int count = 0;
	Node* temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}


void Linked_list::Append_node(Node* n)
{
	Node* ptr = head;

	if (head == NULL)// check if the list is empty then it will add node to head
	{
		head = n;
		n->prev = NULL;
		n->next = NULL;
		cout << "Node Appended" << endl;
	}
	else
	{
		while (ptr->next != NULL)// Loop will executed untill the Last node
		{
			ptr = ptr->next;
		}
		ptr->next = n; // the next address of last node will point toward the new node
		n->prev = ptr;// the Previous address of new node will points toward the last node
		

		cout << "Node Appended" << endl;

	}
	_getch();


}

void Linked_list::Prepend_node(Node* n)// Add Node to the Front of the list
{
	Node* ptr;
	if (head == NULL)// check if the list is empty then it will add new node to the head
	{
		head = n;
		n->prev = NULL;
		n->next = NULL;
		cout << "Node Prepended" << endl;

	}
	else
	{
		head->prev = n;// The previous pointer of head will points toward the new node
		n->next = head;// the Next pointer of New node will points towrads the head of list
		n->prev = NULL;// the Previous pointer of new node will points to NULL 
		head = n;	// The Node will become the head of the List
		cout << "Node Prepended" << endl;
		
	}
	_getch();

}

void Linked_list::Insert_node(int p, Node* n)// Insert Node at Possition p
{
	int count = Node_count(); // store the number of Nodes in count
	Node* ptr = head; 
	Node* temp;
	if (p > count || p < 1)// Input Validation
	{
		cout << "Invalid Node Entered.." << endl;
	}
	else
	{
		if (p == 1)// if Position is 1, then it will add Node to the head
		{
			n->next = head;
			head->prev = n;
			head = n;
			cout << "Node Inserted.." << endl;
		}
		else
		{
			for (int i = 2; i < p; i++)// The loop will Executed untill the "ptr" pointer Points toward the address of Node at Posstion 'p'
			{
				ptr = ptr->next;
			}

			temp = ptr->next; // temp will store the address of Node 'p'
			n->next = temp; // the Next pointer of new node will points to the temp (next of Node p)
			n->prev = ptr; // the Previous Pointer of new node will points to the Node 'p'
			ptr->next = n;// The Next pointer of Node 'p' is now pointing toward the new node
			cout << "Node Inseted.." << endl;
			
		}

	}
	_getch();
}

void Linked_list::Display_forward()// Display Elements of List in Forward Direction
{
	int i = 1;			// use for counting
	Node* ptr = head;
	if (head == NULL) // check if the list is empty
	{
		cout << "List is Empty" << endl;
	}
	else
	{
		while (ptr != NULL)// The loop will Executed till the end of the List
		{
			cout << "Node " << i << " = " << ptr->data << endl;
			ptr = ptr->next;
			i++;

		}
	}
	_getch();
}

void Linked_list::Update_node(int p,int d)
{
	int count = Node_count();
	Node* ptr = head;
	if (p > count || p < 1) // Input Validation
	{
		cout << "Invalid Node Entered" << endl;
	}
	else
	{
		for (int i = 1; i < p; i++) // The Node will executed until the "ptr" pointer is pointing towards the Node 'p'
		{
			ptr = ptr->next;
		}
		ptr->data = d;				// The New data Enterd by user is updated to the node
		cout << "Node Updated " << endl;
	}
	
	_getch();
}

void Linked_list::Delete_node(int p)
{
	int count = Node_count();
	Node* temp = head;
	if (p > count || p < 1)		// Input Validation
	{
		cout << "Invalid Node Entered ..." << endl;
	}
	else
	{
		if (p == 1) // check if the head has to delete
		{
			head = head->next;
			
			cout << "Node Deleted.." << endl;
		}
		else
		{
			Node* next;
			Node* ptr;
			for (int i = 1; i < p; i++) // the loop will executed until the temp pointer points towards Node p
			{
				temp = temp->next;

			}
			ptr = temp->prev; // Ptr will store the previous address of Node p
			next = temp->next; // Next will store the next address of Node p
			ptr->next = next; // the next  Pointer of node ptr(before Node p) will points to next (next to Node p)
			next->prev = ptr; // the previous pointer of "next" will pointer will points to the "ptr" (before Node p)
			delete temp;
			cout << "Node Deleted..." << endl;

		}
	}
	_getch();
}

void Linked_list::Display_backward()
{
	cout << "Reverse Display" << endl;
	Node* end = NULL; 
	Node* ptr = head;
	if (head == NULL) // check if the list is Empty 
	{
		cout << "List is Empty..." << endl;
	}
	else
	{
		while (ptr != NULL)// it will executed until the last node of the list to find the address of last node
		{
			if (ptr != NULL)
			{
				end = ptr;// it will store the address of last node
			}
			ptr = ptr->next;
			
		}

		int i = Node_count();
		while (end != NULL)// Loop will executed from end of the list to head of list
		{
			cout << "Node " << i << " = " << end->data << endl;
			end = end->prev; // change the address to the previous node
			i--;
		}
	}

	_getch();


}

void Linked_list::Search_data(int d)
{
	Node* ptr = head;
	bool flag = false;
	int n = 1;
	while (ptr != NULL)
	{
		if (ptr->data == d)
		{
			flag = true;
			cout << d << " Found at Node " << n << endl;

			break;

		}
		n++;
		ptr = ptr->next;
	}
	if (flag == false)
	{
		cout << "The Enterd data Not Found at any Node..." << endl;
	}
	_getch();
}




int main()
{
	Linked_list S;
	int data, pos;
	int ch;
	while (true)
	{
		system("cls");
		cout << "1 = Append Node" << endl;
		cout << "2 = Prepend Node" << endl;
		cout << "3 = Insert Node " << endl;
		cout << "4 = Display Forward" << endl;
		cout << "5 = Updata Node " << endl;
		cout << "6 = Delete Node" << endl;
		cout << "7 = Display Backward" << endl;
		cout << "8 = Search Data " << endl;
		cout << "Enter Choice = ";
		Node* N = new Node();
		cin >> ch;
		switch (ch)
		{
		case 1:
			system("cls");
			cout << "Enter Data = ";
			cin >> data;
			N->data = data;
			S.Append_node(N);

			break;

		case 2:
			system("cls");
			cout << "Enter Data = ";
			cin >> data;
			N->data = data;
			S.Prepend_node(N);
			break;

		case 3:
			system("cls");
			cout << "Enter Position = ";
			cin >> pos;
			cout << "Enter Data = ";
			cin >> data;
			N->data = data;
			S.Insert_node(pos, N);
			break;
			
		case 4:
			system("cls");
			S.Display_forward();
			break;

		case 5:
			system("cls");
			cout << "Enter Position = ";
			cin >> pos;
			cout << "Enter Data = ";
			cin >> data;
			N->data = data;
			S.Update_node(pos, data);
			break;

		case 6:
			system("cls");
			cout << "Enter Possition = ";
			cin >> pos;
			S.Delete_node(pos);
			break;

		case 7:
			system("cls");
			S.Display_backward();
			break;

		case 8:
			system("cls");
			cout << "Enter Data to Search = ";
			cin >> data;
			S.Search_data(data);
			break;

		}


	}




	system("pause");
}
