#include<iostream>
#include<string>
#include<stack>
#include<vector>

struct Node //定义节点
{
	int x;
	int y;
	int val;
	int director[4] = { 1 }; //记录四个方向的节点状态
};
//迷宫类
class maze
{
public:
	maze(int row, int col)
	:m_row(row), m_col(col), two_d_array(row, std::vector<Node>(col))
	{}
	void setNode() //设置节点信息
	{
		for (int i = 0; i < m_row; ++i)
		{
			for (int j = 0; j < m_col; ++j)
			{	
				int a = 0;
				two_d_array[i][j].x = i;
				two_d_array[i][j].y = j;
				std::cout << "请输入" << i << "," << j << "处的节点状态（0 or 1）" << std::endl;
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
				//记录各方向状态
				if (i - 1 >= 0) //up
				{
					std::cout << "已记录其上方" << i - 1 << "," << j << "处状态" << std::endl;
					two_d_array[i][j].director[0] = two_d_array[i - 1][j].val;
				}
				if (j + 1 < m_col) //right
				{
					std::cout << "已记录其右方" << i << "," << j + 1 << "处状态" << std::endl;
					two_d_array[i][j].director[1] = two_d_array[i][j + 1].val;
				}
				if (i + 1 < m_row) //down
				{
					std::cout << "已记录其下方" << i + 1 << "," << j << "处状态" << std::endl;
					two_d_array[i][j].director[2] = two_d_array[i + 1][j].val;
				}
				if (j - 1 >= 0) //left
				{
					std::cout << "已记录其左方" << i << "," << j - 1 << "处状态" << std::endl;
					two_d_array[i][j].director[3] = two_d_array[i][j - 1].val;
				}
			}
		}
		m_state = 2;
	}
	void display() //显示迷宫
	{
		if (m_state == 0)
		{
			std::cout << "请先初始化迷宫状态！" << std::endl;
		}
		else if (m_state == 1)
		{
			std::cout << "请先初始化迷宫方向！" << std::endl;
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
	int m_state = 0; //迷宫状态
	int m_row;
	int m_col;
	std::vector<std::vector<Node>> two_d_array;
};

void deeply_search(maze& ma)
{
	std::stack<Node> node_stack;
	if (ma.two_d_array[0][0].val == 1)
	{
		std::cout << "入口处状态为1，无法搜索！" << std::endl;
		return;
	}

	//记录当前位置
	int i = 0;
	int j = 0;
	node_stack.push(ma.two_d_array[i][j]);
	
	//开始搜索
	while (!node_stack.empty())
	{	
		//检查是否到达出口
		if (i == ma.m_row - 1 && j == ma.m_col - 1)
		{
			std::cout << "找到出口！" << std::endl;
			while (!node_stack.empty())
			{
				ma.two_d_array[node_stack.top().x][node_stack.top().y].val = 8;
				node_stack.pop();
			}
			return;
		}

		//判断可行方向并入栈，改变其方向状态
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

		//若无可行方向则出栈，从上一步走
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

	//搜索路径
	deeply_search(m1);
	m1.display();
	return 0;
}