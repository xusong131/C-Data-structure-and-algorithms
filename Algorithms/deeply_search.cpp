#include<iostream>
#include<string>
#include<stack>
#include<vector>

struct Node //����ڵ�
{
	int x;
	int y;
	int val;
	int director[4] = { 1 }; //��¼�ĸ�����Ľڵ�״̬
};
//�Թ���
class maze
{
public:
	maze(int row, int col)
	:m_row(row), m_col(col), two_d_array(row, std::vector<Node>(col))
	{}
	void setNode() //���ýڵ���Ϣ
	{
		for (int i = 0; i < m_row; ++i)
		{
			for (int j = 0; j < m_col; ++j)
			{	
				int a = 0;
				two_d_array[i][j].x = i;
				two_d_array[i][j].y = j;
				std::cout << "������" << i << "," << j << "���Ľڵ�״̬��0 or 1��" << std::endl;
				std::cin >> two_d_array[i][j].val;
				//two_d_array[i][j].val = rand() % 2;
			}
		}
		m_state = 1;
	}
	void setdirector()
	{
		for (int i = 0; i < m_row; ++i)
		{
			for (int j = 0; j < m_col; ++j)
			{
				//��¼������״̬
				if (i - 1 >= 0) //up
				{
					std::cout << "�Ѽ�¼���Ϸ�" << i - 1 << "," << j << "��״̬" << std::endl;
					two_d_array[i][j].director[0] = two_d_array[i - 1][j].val;
				}
				if (j + 1 < m_col) //right
				{
					std::cout << "�Ѽ�¼���ҷ�" << i << "," << j + 1 << "��״̬" << std::endl;
					two_d_array[i][j].director[1] = two_d_array[i][j + 1].val;
				}
				if (i + 1 < m_row) //down
				{
					std::cout << "�Ѽ�¼���·�" << i + 1 << "," << j << "��״̬" << std::endl;
					two_d_array[i][j].director[2] = two_d_array[i + 1][j].val;
				}
				if (j - 1 >= 0) //left
				{
					std::cout << "�Ѽ�¼����" << i << "," << j - 1 << "��״̬" << std::endl;
					two_d_array[i][j].director[3] = two_d_array[i][j - 1].val;
				}
			}
		}
		m_state = 2;
	}
	void display() //��ʾ�Թ�
	{
		if (m_state == 0)
		{
			std::cout << "���ȳ�ʼ���Թ�״̬��" << std::endl;
		}
		else if (m_state == 1)
		{
			std::cout << "���ȳ�ʼ���Թ�����" << std::endl;
		}
		else
		{
			for (int i = 0; i < m_row; ++i)
			{
				for (int j = 0; j < m_col; ++j)
				{
					std::cout << two_d_array[i][j].val;
				}
				std::cout << std::endl;
			}
		}
	}
public:
	int m_state = 0; //�Թ�״̬
	int m_row;
	int m_col;
	std::vector<std::vector<Node>> two_d_array;
};

void deeply_search(maze& ma)
{
	std::stack<Node> node_stack;
	if (ma.two_d_array[0][0].val == 1)
	{
		std::cout << "��ڴ�״̬Ϊ1���޷�������" << std::endl;
		return;
	}

	//��¼��ǰλ��
	int i = 0;
	int j = 0;
	node_stack.push(ma.two_d_array[i][j]);
	
	//��ʼ����
	while (!node_stack.empty())
	{	
		//����Ƿ񵽴����
		if (i == ma.m_row - 1 && j == ma.m_col - 1)
		{
			std::cout << "�ҵ����ڣ�" << std::endl;
			while (!node_stack.empty())
			{
				ma.two_d_array[node_stack.top().x][node_stack.top().y].val = 8;
				node_stack.pop();
			}
			return;
		}

		//�жϿ��з�����ջ���ı��䷽��״̬
		if (node_stack.top().director[0] == 0)
		{
			node_stack.top().director[0] = 1;
			i -= 1;
			node_stack.push(ma.two_d_array[i][j]);
			node_stack.top().director[2] = 1;
			continue;
		}
		if (node_stack.top().director[1] == 0)
		{
			node_stack.top().director[1] = 1;
			j += 1;
			node_stack.push(ma.two_d_array[i][j]);
			node_stack.top().director[3] = 1;
			continue;
		}
		if (node_stack.top().director[2] == 0)
		{
			node_stack.top().director[2] = 1;
			i += 1;
			node_stack.push(ma.two_d_array[i][j]);
			node_stack.top().director[0] = 1;
			continue;
		}
		if (node_stack.top().director[3] == 0)
		{
			node_stack.top().director[3] = 1;
			j -= 1;
			node_stack.push(ma.two_d_array[i][j]);
			node_stack.top().director[1] = 1;
			continue;
		}

		//���޿��з������ջ������һ����
		node_stack.pop();
	}
}
int main()
{	
	maze m1(4,4);
	m1.display();
	m1.setNode();
	m1.setdirector();
	m1.display();

	//����·��
	deeply_search(m1);
	m1.display();
	return 0;
}