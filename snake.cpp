// snake.cpp -- use terminal console to implement snake game
#include "snake.h"
#include <set>
#include <algorithm>


Snake::Snake(int x1,int y1,char headType):x(x1),y(y1)
{
	head = new node { x , y , headType};
	head->next = nullptr;
	snakeNodes.push_back(*head);// store the head node of snake
}

Snake::~Snake()
{
	// free memory
	node * tempNode = head;
	node * nextNode = nullptr;
	while(tempNode)
	{
		nextNode = tempNode->next;
		delete tempNode;
		tempNode = nextNode;
	}
}


char Snake::checkValidDirection(const char & tempDirection,const char & updateDirection)
{
	if(tempDirecion == updateDirection)
		return tempDirection;
	else if(updateDirection != 'w' || updateDirection != 'W'
		updateDirection != 's' || updateDirection != 'S'
		updateDirection != 'a' || updateDirection != 'A'
		updateDirecrion != 'd' || updateDirection != 'D'
	       )
		// invalid key
		return tempDirection;
	else{
		directionVec tempVec = getDirection(tempDirection);
		directionVec updateVec = getDirection(updateDirection);
		if(tempVec.x + updateVec.x == 0 && tempVec.y + updateVec.y == 0)// invalid opposition
			return tempDirection;
		else
			return updateDirection;
	}




}


bool Snake::changeSnakePosition(BaseGraph & graph,node & obstacle,char direction)
{

	// check the UpdateDirection is valid
	directionVec dv = getDirectionVec(direction);
	if(dv.x == 0 & dv.y == 0 && dv.isValid)
		return true;// don't move	
	int tempx = head->x + dv.x;
	int tempy = head->y + dv.y;

	if(tempx == obstacle.x && tempy == obstacle.y) // catch the obstacle,change the head;
	{
		node * tempNode = &obstacle;
		tempNode->type = head->type;
		head->type = '#'; // change head to body
		tempNode->next = head;
		head = tempNode;
		snakeNodes.push_back(*head);
		return true;
	}
	else
	{
		// check whether hit the wall
		if(tempx == 0 || tempy == 0 || tempx == graph.Width() - 1 || tempy == graph.Height() - 1)
			return false;
		// check whether hit itself
		node * tempNode = head;
		while(tempNode)
		{
			if(tempNode->x == tempx && tempNode->y == tempy)
				return false; // hit itself
			tempNode = tempNode->next;
		}

		// nothing wrong ,all nodes will move to new place,its father position
		int oldx = head->x;
		int oldy = head->y;
		while(tempNode)
		{
			tempNode->x = tempx;
			tempNode->y = tempy;
			tempNode = tempNode->next;
			if(tempNode)
			{
				// update oldx,y and tempx,y
				tempx = oldx;
				tempy = oldy;
				
				oldx = tempNode->x;
				oldy = tempNode->y;
			}
		}

		return true;
	}
}

// here,direction will be prepared to correct direction so it will never go to default selection.
directionVec Snake::getDirectionVec(char direction)
{
	switch(direction)
	{
		case 'w':
		case 'W':
			return {0,1,true};
		case 's':
		case 'S':
			return {0,-1,true};
		case 'a':
		case 'A':
			return {-1,0,true};
		case 'd':
		case 'D':
			return {1,0,true};
		case '\0':
			// don't move
			return {0,0,true};
		default:
			return {0,0,false};
	}
}

const vector<node> & Snake::getSnakeNodes() const
{
	return snakeNodes;
}


BaseGraph::BaseGraph(int h1,int w1):height(h1),width(w1){}


BaseGraph::~BaseGraph()
{
	// free each sub-array
	for(int i = 0;i < height;i++)
		delete [] canvas[i];
	// free the array of pointers
	delete [] canvas;

}

void BaseGraph::initialize()
{
	// initialize canvas contents with '*' and ' '
	for(i = 0; i < height; i++)
	{
		canvas[i] = new char[width];

		for(j = 0; j < width;j++)
		{
			if(i == 0 || i == height - 1 || j == 0 || j == width - 1)
			{
				canvas[i][j] = '*';
			}else
				canvas[i][j] = ' ';
		}
	}

}


void BaseGraph::add(Snake & s)
{
		
	
	const vector<node>& snakeNodes = s.getSnakeNodes();
	int i;
	for(i = 0 ; i < snakeNodes.size(); i++)
	{	
		int x = snakeNodes[i].x;
		int y = snakeNodes[i].y;
		canvas[x][y] = snakeNodes[i].type;
	}
}



node BaseGraph::randGenerate(Snake & s)
{
	std::set<int> xset;
	std::set<int> yset;

	for(int i = 1; i < width - 1; i++)
		xset.insert(i);
	for(int i = 1; i < height - 1;i++)
		yset.insert(i);
	const vector<node>& snakeNodes = s.getSnakeNodes();
	// delete snakes node position 
	for(int i = 0 ; i < snakeNodes.size();i++)
	{
		xset.erase(snakeNodes[i].x);
		yset.erase(snakeNodes[i].y);
	}	
	// random select position to generate node.
	



}

void BaseGraph::add(node & n)
{
	canvas[n.x][n.y] = n.type;
}

	










