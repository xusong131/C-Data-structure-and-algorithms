#include<iostream>

enum State {
	Unused,
	Using,
	Delete
};

template<typename T>
class Hash_Table
{
public:
	Hash_Table(unsigned int size = 3, double loadfactor = 0.75) 
		:_UseNodeCount(0),_LoadFactor(loadfactor),_Prime_Index(0)
	{
		//调整构造时的size为素数
		if (size != 3)
		{
			for (; _Prime_Index < _Prime_size; _Prime_Index++)
			{
				if (_Prime_Table[_Prime_Index] > size)
					break;
			}
			if (_Prime_Index == _Prime_size)
			{
				_Prime_Index--;
			}
		}

		_size = _Prime_Table[_Prime_Index];
		_table = new Node[_size];
	}

	~Hash_Table()
	{
		delete[] _table;
		_table = nullptr;
	}

public:
	bool insert(T data)
	{
		//判断是否需要扩容
		if (_UseNodeCount*1.0 / _size >= _LoadFactor)
		{
			std::cout << "loadfactor break limit! expand!" << std::endl;
			expand();
		}

		int index = data % _size;
		int i = index;
		do
		{
			if (_table[i]._node_state != Using)
			{
				_table[i]._node_state = Using;
				_table[i]._data = data;
				_UseNodeCount++;
				return true;
			}
			i = (i + 1) % _size;
		} while (i != index);

		return false;
	}

	bool query(T data)
	{	
		int index = data % _size;
		int i = index;
		do
		{
			if (_table[i]._node_state == Using && _table[i]._data == data)
			{
				return true;
			}
			i = (i + 1) % _size;
		} while (_table[i]._node_state != Unused && i != index);

		return false;
	}

	void remove(T data)
	{
		int index = data % _size;
		int i = index;
		do
		{	
			if (_table[i]._node_state == Using && _table[i]._data == data)
			{
				_table[i]._node_state = Delete;
				_UseNodeCount--;
			}
			i = (i + 1) % _size;
		} while (_table[i]._node_state != Unused && i != index);
	}

private:
	//扩容
	void expand()
	{
		int new_size = 0;
		for (int i = 0; i < _Prime_size; ++i)
		{
			if (_Prime_Table[i] > _size)
			{
				new_size = _Prime_Table[i]; 
				break;
			}
		}


		if (new_size <= _size)
		{
			std::cout << "Hash_Table is full!" << std::endl;
			return;			
		}

		Node* new_table = new Node[new_size];
		
		for (int j = 0; j < _size; ++j)
		{
			if (_table[j]._node_state == Using)
			{	
				int index = _table[j]._data % new_size;

				int a = index;
				do
				{
					if (new_table[a]._node_state != Using)
					{
						new_table[a]._node_state = Using;
						new_table[a]._data = _table[j]._data;
						break;
					}
					a = (a + 1) % new_size;
				} while (a != index);
			}
		}

		delete[]_table;

		_size = new_size;
		_table = new_table;
	}

private:
	struct Node
	{
		Node(T data = 0,State node_state = Unused):_data(data),_node_state(node_state) {};
		T _data;
		State _node_state;
	};
	Node* _table;
	unsigned int _size;
	unsigned int _UseNodeCount; 
	double _LoadFactor; //装载因子
	
	int _Prime_Index; //素数表下标
	static const int _Prime_size = 10; //素数表大小
	static int _Prime_Table[_Prime_size]; //素数表
};

template<typename T>
int Hash_Table<T>::_Prime_Table[_Prime_size] = { 3,7,23,47,97,251,443,911,1471,42773 };

void test()
{
	Hash_Table<int> hashTable(3,0.3);

	// 插入数据
	hashTable.insert(10);
	hashTable.insert(20);
	hashTable.insert(30);
	hashTable.insert(40);
	hashTable.insert(50);
	hashTable.insert(100);
	hashTable.insert(200);
	hashTable.insert(200);
	hashTable.insert(300);

	// 查询数据
	std::cout << std::boolalpha;  // 打印 true/false 而不是 1/0
	std::cout << "Query 10: " << hashTable.query(10) << std::endl;
	std::cout << "Query 60: " << hashTable.query(60) << std::endl;
	std::cout << "Query 40: " << hashTable.query(40) << std::endl;
	hashTable.remove(40);
	std::cout << "(after delete)Query 40:" << hashTable.query(40) << std::endl;
	std::cout << "Query 100: " << hashTable.query(100) << std::endl;
	std::cout << "Query 200: " << hashTable.query(200) << std::endl;
	hashTable.remove(200);
	std::cout << "(after delete)Query 200:" << hashTable.query(200) << std::endl;
	std::cout << "Query 300: " << hashTable.query(300) << std::endl;
} //测试函数

int main()
{
	test();
	return 0;
}