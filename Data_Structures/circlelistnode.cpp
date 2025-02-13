#if 0
#include<iostream>
#include<string>
#include<time.h>
using namespace std;
class circlelistnode
{
public:
	circlelistnode()
	{
		head = new Node();
		tail = head;
		head->next = head;
	}
	~circlelistnode()
	{
		Node* p = head->next;
		while (p != head)
		{
			head->next = p->next;
			delete p;
			p = head->next;
		}
		delete head;
	}
	void push_front(int val)
	{
		Node* node = new Node(val);
		node->next = head->next;
		head->next = node;	
		if (node->next == head)
		{
			tail = node;
		}
	}
	void push_back(int val)
	{
		Node* node = new Node(val);
		tail->next = node;
		node->next = head;
		tail = node;
	}
	void delete_val(int val)
	{
		Node* pre_node = head;
		Node* node = head->next;
		while (node!=head)
		{
			pre_node = pre_node->next;
			node = node->next;
			if (val == node->val)
			{
				pre_node->next = node->next;
				delete node;
				node = pre_node->next;
				if (node == head)
				{
					tail = pre_node;
				}
			}
		}
		return;
	}
	void print()
	{
		Node* p = head->next;
		while (p != head)
		{
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
private:
	struct Node
	{
		Node(int val = 0) : val(val), next(nullptr) {}
		int val;
		Node* next;
	};
	Node* head;
	Node* tail;
};
int main()
{
	circlelistnode test;
	for (int i = 0; i < 10; ++i)
	{
		test.push_back(rand() % 100);
	}
	test.print();
	test.delete_val(67);
	test.delete_val(64);
	test.delete_val(164);
	test.print();
	return 0;
}
#endif