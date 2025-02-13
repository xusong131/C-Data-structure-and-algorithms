#include<iostream>
using namespace std;
//template<class T>
struct node
{	
	node(int date = 0) : date(date), next(nullptr) {}
	int date;
	node* next;
};
class listnote
{
public:
	listnote()
	{
		head = new node();
	}
	~listnote() 
	{
		node* p = head->next;
		node* q = head;
		while (p != nullptr)
		{
			delete q;
			q = p;
			p = p->next;
		}
	}
public:
	//β�巨 O(n)
	void push_back(int val)
	{	
		node* p = head;
		while (p->next != nullptr) 
		{
			p = p->next;
		}
		node* a = new node(val);
		p->next = a;
	}
	//ͷ�巨 O(1)
	void push_front(int val)
	{
		node* a = new node(val);
		a->next = head->next;
		head->next = a;
	}
	void print()
	{
		node* p = head->next;
		while (p != nullptr)
		{
			cout << p->date << " ";
			p = p->next;
		}
		cout << endl;
	}
	void delete_val(int val)
	{
		node* p = head->next;
		node* q = head;
		while (p != nullptr)
		{
			if (p->date == val)
			{
				q->next = p->next;
				delete p;
				p = q->next;		
			}
			else
			{
				q = q->next;
				p = p->next;
			}				
		}
	}
	bool find(int val)
	{
		node* p = head->next;
		while (p != nullptr)
		{
			if (p->date == val)
			{
				return true;
			}
			p = p->next;
		}
		return false;
	}
private:
	node* head;
};
int main()
{
	listnote arr;
	arr.push_back(2);
	arr.push_back(7);
	arr.push_back(8);
	arr.push_front(42);
	arr.push_front(42);
	arr.push_front(830);
	arr.print();
	arr.delete_val(42);
	arr.print();
	if (arr.find(2))
	{
		cout << "yes" << endl;
	}
	else
		cout << "NO" << endl;
}