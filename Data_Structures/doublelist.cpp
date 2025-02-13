#include<iostream>
#include<ctime>
using namespace std;

struct Node
{
	Node(int data = 0)
		: _data(data)
		, next(nullptr)
		, pre(nullptr) {}
	int _data;
	Node* next;
	Node* pre;
};
class doublelist
{
public:
	doublelist()
	{
		head = new Node();
	}
	~doublelist()
	{
		
	}
	void push_front(int val)
	{
		Node* node = new Node(val);
		if (head->next != nullptr)
			head->next->pre = node;
		node->next = head->next;
		node->pre = head;
		head->next = node;
	}
	void push_back(int val)
	{
		Node* node = new Node(val);
		Node* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = node;
		node->pre = p;
	}
	void deletenode(int val)
	{
		Node* p = head->next;
		while (p != nullptr)
		{
			if (p->_data == val)
			{
				if (p->next != nullptr)
				{
					p->next->pre = p->pre;
				}
				p->pre->next = p->next;
				Node* temp = p;
				p = p->next;
				delete temp;
				continue;
			}
			p = p->next;
		}
	}
	void show()
	{
		Node* p = head->next;
		while (p != nullptr)
		{
			cout << p->_data << " ";
			p = p->next;
		}
		cout << endl;
	}
private:
	Node* head;
};
int main()
{
	doublelist a;
	for (int i = 0; i < 5; ++i)
	{
		a.push_front(rand() % 100);
	}
	a.push_back(64);
	a.push_back(64);
	a.push_back(64);
	for (int i = 0; i < 5; ++i)
	{
		a.push_back(rand() % 100);
	}
	a.show();
	a.deletenode(41);
	a.deletenode(0);
	a.deletenode(64);
	a.deletenode(69);
	a.show();
}