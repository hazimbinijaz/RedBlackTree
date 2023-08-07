#include<iostream>
using namespace std;
bool Black = 0, Red = 1;
template <typename t>

class Node
{
public:
	t Data;
	Node<t> * Left;
	Node<t> * Right;
	Node<t> * Parent;
	bool Color = Red; // Black is 0 & Red is 1
};

template <typename t>

class RedBlackTree
{

	Node<t> * Root;
	bool InsertDirection;
public:
	RedBlackTree()
	{
		Root = NULL;
	}

	
	void RotateLeft(Node<t> * GP)
	{
		Node<t> * GPsSon = GP->Right;
		if (GP->Right = NULL) 
			return;
		else
		{
			if (GPsSon->Left != NULL) 
			{
				GP->Right = GPsSon->Left;
				GPsSon->Left->Parent = GP;
			}
			else
				GP->Right = NULL;
			if (GP->Parent != NULL)
				GPsSon->Parent = GP->Parent;
			
			if (GP->Parent == NULL)
			{
				Root = GPsSon;
				Root->Parent = NULL;
			}
				
			
			else
			{
				if (GP == GP->Parent->Left) 
					GP->Parent->Left = GPsSon;
				else
					GP->Parent->Right = GPsSon;
			}
		
			
			GPsSon->Left = GP;
			GP->Parent = GPsSon;
		}
	}

	void RotateRight(Node<t> * GP)
	{
		Node<t> * GPsSon = GP->Left;
		if (GP->Left = NULL) 
			return;
		else
		{
			if (GPsSon->Right != NULL) 
			{
				GP->Left = GPsSon->Right;
				GPsSon->Right->Parent = GP;
			}
			else
				GP->Left = NULL;
			if (GP->Parent != NULL)
				GPsSon->Parent = GP->Parent;

			if (GP->Parent == NULL)
			{
				Root = GPsSon;
				Root->Parent = NULL;
			}


			else
			{
				if (GP == GP->Parent->Left) 
					GP->Parent->Left = GPsSon;
				else
					GP->Parent->Right = GPsSon;
			}


			GPsSon->Right = GP;
			GP->Parent = GPsSon;
		}
	}

	void RBTCheckerAndFixer(Node<t> * & AN)
	{
		Node<t> * GP;
		Node<t>* Uncle;
		if (Root == AN)
		{
			AN->Color = Black;
		}

		while ((AN->Parent != NULL) && (AN->Parent->Color == Red))
		{
			GP = AN->Parent->Parent;
			if (InsertDirection == 0) //Insertion is left
			{
				if (GP->Right != NULL)
				{
					Uncle = GP->Right;
					if (Uncle->Color == Red) 
					{
						AN->Parent->Color = Black;
						Uncle->Color = Black;
						GP->Color = Red;
						AN = GP;
					}
					else 
					{
						if (AN->Parent->Right == AN) 
						{
							AN = AN->Parent;
							RotateLeft(AN);
						}
						AN->Parent->Color = Black;	
						GP->Color = Red;
						RotateRight(GP);
					}
				}
				else 
				{
					if (AN->Parent->Right == AN) 
					{
						AN = AN->Parent;
						RotateLeft(GP);
					}
					AN->Parent->Color = Black;	
					GP->Color = Red;
					RotateRight(GP);
				}
			}
		

			else //if InsertDirection=1//right
			{
				if (GP->Left!=NULL)
				{
					Uncle = GP->Left;
					if (Uncle->Color == Red) 
					{
						AN->Parent->Color = Black;
						Uncle->Color = Black;
						GP->Color = Red;
						AN = GP;
					}
					else 
					{
						if (AN->Parent->Left == AN) 
						{
							AN = AN->Parent;
							RotateRight(AN); 
						}
						AN->Parent->Color = Black;	
						GP->Color = Red;
						RotateLeft(GP);
					}
				}
				else 
				{
					if (AN->Parent->Left == AN) 
					{
						AN = AN->Parent;
						RotateRight(AN); 
					}
					AN->Parent->Color = Black;	
					GP->Color = Red;
					RotateLeft(GP);
				}
			}
			Root->Color = Black;
		}
		
	
	}
	
	void Insert(t V)
	{
		if (Root == NULL)
		{
			Node<t> * temp = new Node<t>;
			temp->Data = V;
			temp->Left = NULL;
			temp->Right = NULL;
			Root = temp;
			RBTCheckerAndFixer(temp);
		}
		else
		{
			Node<t> * AddedNode;
			Node<t>*Current = new Node<t>;
			Current = Root;
			AddedNode=Insertion(Current, V);
			RBTCheckerAndFixer(AddedNode);
			
		}

	}

	void Search(t v)
	{
		if (Search1(v, Root))
			cout << "\nValue Found!\n";
		else
			cout << "\nValue Not Found!\n";
	}
	
	void Display()
	{
		DisplayPostOrder(Root);
	}

private:
	
	void DisplayPostOrder(Node<t>* Root)
	{
		if (Root == NULL)
			return;
		else
		{

			DisplayPostOrder(Root->Left);
			cout << "Node Data: " << Root->Data << " ";
			
			
			if (Root->Color == Black)
				cout << "Color: Black ";
			else
				cout << "Color: Red ";
			if (Root->Parent != NULL)
				cout << "Parent:   " << Root->Parent->Data << " " << endl;
			else
				cout << "Parent:   " << "NULL" << " " << endl;

			DisplayPostOrder(Root->Right);
		}

	}

	bool Search1(t v, Node<t>* Root)
	{
		if (Root->Data == v)
			return true;

		else
		{
			if (Root->Left == NULL && Root->Right == NULL)
			{
				return false;
			}
			else
			{


				if (Root->Data < v)
				{
					Search1(v, Root->Right);
				}
				else if (Root->Data > v)
				{
					Search1(v, Root->Left);
				}
				else
				{
					Search1(v, Root->Left);
				}
			}
		}
	}
	
	
	Node<t>* Insertion(Node<t>* Current, t v)
	{
		if (Current->Data > v)
		{
			if (Current->Left == NULL)
			{
				Node<t> * temp = new Node<t>;
				temp->Data = v;
				temp->Left = NULL;
				temp->Right = NULL;
				Current->Left = temp;
				temp->Parent = Current;
				InsertDirection = 0;
				return temp;
			}
			else
			{
				Insertion(Current->Left, v);
			}
		}

		else if (Current->Data < v)
		{
			if (Current->Right == NULL)
			{
				Node<t> * temp = new Node<t>;
				temp->Data = v;
				temp->Left = NULL;
				temp->Right = NULL;
				Current->Right = temp;
				temp->Parent = Current;
				InsertDirection = 1;
				return temp;
			}
			else
			{
				Insertion(Current->Right, v);
			}
		}

		else //For Equal Data
		{
			if (Current->Left == NULL)
			{
				Node<t> * temp = new Node<t>;
				temp->Data = v;
				temp->Left = NULL;
				temp->Right = NULL;
				Current->Left = temp;
				temp->Parent = Current;
				InsertDirection = 0;
				return temp;
			}
			else
			{
				Insertion(Current->Left, v);
			}
		}
	}

	
};




void main()
{
	int choice = 0;
	RedBlackTree <int>a;
	while (true)
	{
		cout << "\n 1. Insertion";
		cout << "\n 2. search";
		cout << "\n 3. Display";
		cout << "\n 4. Exit ";
		cout << "\nEnter Choice: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "\nEnter Value Io Insert: \n";
			cin >> choice;
			a.Insert(choice);
			cout << "\nNode Inserted.\n";
		}
		else if (choice == 2)
		{
			cout << "\nEnter Value Io Search: \n";
			cin >> choice;
			a.Search(choice);
		}
		else if (choice == 3)
		{
			cout << "\n\t\t**************************************" << endl;
			a.Display();
			cout << "\n\t\t**************************************" << endl;
		}
		else if (choice == 4)
		{
			break;
		}
		else
		{
			cout << "\nEnter a valid choiceoice...";
		}
	}
	

}