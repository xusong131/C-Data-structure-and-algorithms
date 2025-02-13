#include<iostream>
using namespace std;

template<typename T>
class vector
{
public:
	vector(int size = 10)
	{ 
		m_size = size;
		m_first = new T[m_size](); 
		m_last = m_first;
		m_end = m_first + m_size;
	}
	~vector()
	{
		delete[]m_first;
		m_first = m_last = m_end = nullptr;
	}
	vector(const vector<T>& source)
	{
		this->m_size = source.m_size;
		int len = source.m_last - source.m_first;
		this->m_first = new T[m_size]();
			for (int i = 0; i < len; ++i)
			{
				this->m_first[i] = source.m_first[i];
			}
		this->m_last = m_first + len;
		this->m_end = m_first + m_size;
	}
	vector<T>& operator=(const vector<T>& source)
	{
		if (this == &source)
			return* this;
		delete[]this->m_first;
		this->m_size = source.m_size;
		int len = source.m_last - source.m_first;
		this->m_first = new T[m_size]();
		for (int i = 0; i < len; ++i)
		{
			this->m_first[i] = source.m_first[i];
		}
		this->m_last = m_first + len;
		this->m_end = m_first + m_size;
		return *this;
	}
public:
	void push_back(const T &val)
	{
		if (full())
		{
			m_expand();
		}
		*m_last = val;
		m_last++;
	}
	void pop_back()
	{
		if (empty())
		{	//throw "vector is empty!";
			return;
		}
		m_last--;
	}
	T back()
	{
		return *(m_last-1);
	}
	bool full()const
	{
		return m_last == m_end;
	};
	bool empty()const
	{
		return m_first == m_last;
	}
	int count()
	{
		return m_last - m_first;
	}
	//迭代器的实现
	class iterator
	{
	public:
		iterator(T* ptr = nullptr)
		:_ptr(ptr){}
		//对各运算符重载
		bool operator!=(const iterator &it)const
		{
			return _ptr != t._ptr;
		}
	
	private:
		T* _ptr;
		iterator begin() { return iterator(m_first); } //通过迭代器的方法获取容器的首元素
		iterator end() { return iterator(m_last); } //通过迭代器的方法获取容器的尾元素后继位置
	};
private:
	T* m_first;
	T* m_last;
	T* m_end;
	int m_size;
private:
	void m_expand()
	{
		m_size = 2*(m_end - m_first);
		T* temp = new T[m_size]();
		for (int i = 0; i < m_size/2; ++i)
		{
			temp[i] = m_first[i];
		}
		delete[]m_first;
		m_first = temp;
		this->m_last = m_first + m_size/2;
		this->m_end = m_first + m_size;
	}
};
int main()
{
	vector<int> v;
	for (int i = 0; i < 20; ++i)
	{
		v.push_back(rand()%100); 
	}
	cout << v.count() << endl;
	while(!v.empty())
	{
		cout << v.back() << " ";
		v.pop_back();
	}
	std::cout << std::endl;
	return 0;
}