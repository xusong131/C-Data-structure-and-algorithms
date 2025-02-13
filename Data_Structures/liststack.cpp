#include<iostream>
using namespace std;
class ListStack
{
public:
	ListStack()
	{
		head = new Node();
	}
	~ListStack()
	{
		Node* p = head->next;
		while (p!=nullptr)
		{
			head->next = p->next;
			delete p;
			p = head->next;
		}
		delete head;
	}
public:
	void push(int val) 
	{
		Node* p = new Node(val);
		p->next = head->next;
		head->next = p;
		head->m_data++;
	}
	void pop() 
	{
		if (head->next == nullptr)
		{
			throw "stack is empty!";
		}
		Node* p = head->next;
		head->next = p->next;
		delete p;
	}
	void show()
	{
		while(head->next != nullptr)
		{
			cout << head->next->m_data << " ";
			pop();
		}
		cout << endl;
	}
	int size()const
	{
		return head->m_data;
	}
	int top()const 
	{
		if (empty())
		{
			throw "stack is empty!";
		}
		return head->next->m_data;
	}
	bool empty()const 
	{
		return head->next=nullptr;
	}
private:
	struct Node
	{
		Node(int data = 0)
			:m_data(data)
			, next(nullptr)
		{}
		int m_data;
		Node* next;
	};
private:
	Node* head;
};
int main()
{
	ListStack s1;
	int a[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	for (int i = 0; i < sizeof(a) / sizeof(a[1]); ++i)
	{
		s1.push(a[i]);
	}
	s1.show();
	cout << s1.size() << endl;
	return 0;
}