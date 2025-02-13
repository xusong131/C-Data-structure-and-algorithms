#include<iostream>
using namespace std;

class seqstack
{
public:
	seqstack(int size = 10)
		:m_size(size)
		,m_top(0)
	{
		m_stack = new int[size]();
	}
	~seqstack()
	{
		delete[]m_stack;
		m_stack = nullptr;
	}
public:
	void push(int val)
	{
		if (full())
		{
			m_resize(m_stack);
		}
		m_stack[m_top] = val;
		m_top++;
	}
	void pop() 
	{
		if (empty())
		{
			throw "stack is empty!";
		}
		m_top--;
	}
	void show()
	{
		while (m_top != 0)
		{
			cout << m_stack[m_top-1] << " ";
			pop();
		}
		cout << endl;
		return;
	}
	bool empty() const
	{
		return m_top == 0;
	}
	bool full() const
	{
		return m_top == m_size;
	}
private:
	int* m_stack;
	int m_top;
	int m_size;
	void m_resize(int* stack) 
	{
		m_size = m_size * 2;
		m_stack = new int[m_size]();
		for (int i = 0; i < m_size; ++i)
		{
			m_stack[i] = stack[i];
		}
	}
};
int main()
{
	seqstack s1;
	int a[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	for (int i = 0; i < sizeof(a) / sizeof(a[1]); ++i)
	{
		s1.push(a[i]);
	}
	s1.show();
	return 0;
}