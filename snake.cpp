// snake.cpp -- use terminal console to implement snake game
#include "snake.h"
#include <set>
#include <algorithm>
#include <cstring>
#include <iostream>
Snake::Snake(int x1,int y1,char headType)
{
	head = new node { x1 , y1 , headType,node::SNAKEHEAD,nullptr};

	snakeNodes.push_back(head);// store the head node of snake
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

	directionVec temVec = getDirectionVec(tempDirection);
	directionVec upVec = getDirectionVec(updateDirection);
	if(tempDirection == updateDirection || (temVec.x+upVec.x == 0 && temVec.y+upVec.y == 0))
		return tempDirection;
	else if(   updateDirection != 'w' && updateDirection != 'W'
		&& updateDirection != 's' && updateDirection != 'S'
		&& updateDirection != 'a' && updateDirection != 'A'
		&& updateDirection != 'd' && updateDirection != 'D'
	       )
		// invalid key
		return tempDirection;
	else{
		directionVec tempVec = getDirectionVec(tempDirection);
		directionVec updateVec = getDirectionVec(updateDirection);
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
		return false;// don't move	
	int tempx = head->x + dv.x;
	int tempy = head->y + dv.y;

	std::cout << "tempx: " << tempx << std::endl;
	std::cout << "tempy: " << tempy << std::endl;
	if(tempx == obstacle.x && tempy == obstacle.y) // catch the obstacle,change the head;
	{
		std::cout << "OOps,catch the obstacle " << std::endl;
		node * newHeadNode = new node {obstacle.x,obstacle.y,obstacle.type,obstacle.typeint,nullptr};//copy
		node * tempNode = newHeadNode;
		tempNode->type = '@';// obstacle type changed
		tempNode->typeint = head->typeint;// enum changed
		head->type = '#'; // change head to body
		head->typeint = node::SNAKEBODY;

		tempNode->next = head;
		head = tempNode;
		snakeNodes.push_back(tempNode);
		obstacle.typeint = node::SNAKEBODY;
		return false;
	}
	else
	{
		// check whether hit the wall
		if(tempx == 0 || tempy == 0 || tempx == graph.Width() - 1 || tempy == graph.Height() - 1)
			return true;
		// check whether hit itself
		node * tempNode = head;
		while(tempNode)
		{
			if(tempNode->x == tempx && tempNode->y == tempy)
				return true; // hit itself
			tempNode = tempNode->next;
		}

		// nothing wrong ,all nodes will move to new place,its father position
		int oldx = head->x;
		int oldy = head->y;
		tempNode = head;// note,it should be reassigned
		while(tempNode)
		{
			std::cout << "here,snake should move " << std::endl;
					
			tempNode->x = tempx;
			tempNode->y = tempy;
			std::cout << "tempNode.x = " << tempNode->x << std::endl;
			std::cout << "tempNode.y = " << tempNode->y << std::endl;
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

		return false;
	}
}

// here,direction will be prepared to correct direction so it will never go to default selection.
directionVec Snake::getDirectionVec(char direction)
{
	switch(direction)
	{
		case 'w':
		case 'W':
			return {0,-1,true};
		case 's':
		case 'S':
			return {0,1,true};
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

const std::vector<node *> & Snake::getSnakeNodes() const
{
	return snakeNodes;
}


BaseGraph::BaseGraph(int h1,int w1):height(h1),width(w1),isFull(false){}


BaseGraph::~BaseGraph()
{
	// free each sub-array
	for(int i = 0;i < height;i++)
		delete [] canvas[i];
	// free the array of pointers
	delete [] canvas;

}

void BaseGraph::changeObstaclePosition(node & obstacle,int x, int y)
{
	obstacle.x = x;
	obstacle.y = y;
}

void BaseGraph::initialize()
{
	int i,j;
	canvas = new char* [height];
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


void BaseGraph::reset()
{	
	int i,j;
	// initialize canvas contents with '*' and ' '
	for(i = 0; i < height; i++)
	{
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
	const std::vector<node *>& snakeNodes = s.getSnakeNodes();
	int i;
	for(i = 0 ; i < snakeNodes.size(); i++)
	{	
		int x = snakeNodes[i]->x;
		int y = snakeNodes[i]->y;
		canvas[y][x] = snakeNodes[i]->type;
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
	const std::vector<node *>& snakeNodes = s.getSnakeNodes();
	// delete snakes node position 
	for(int i = 0 ; i < snakeNodes.size();i++)
	{
		xset.erase(snakeNodes[i]->x);
		yset.erase(snakeNodes[i]->y);
	}	
	if(xset.size() == 0 && yset.size() == 0)
	{
		isFull = true;
		return {-1,-1,'e',node::OBSTACLE,nullptr};
	}
	// random select position to generate node.
	int  xr = rand() % xset.size(); // not_really_random
	int  yr = rand() % yset.size();

	auto xit = std::begin(xset);
	auto yit = std::begin(yset);
	std::advance(xit,xr);
	std::advance(yit,yr);
	auto x = *xit;
	auto y = *yit;
	return {x,y,'o',node::OBSTACLE,nullptr};

}

void BaseGraph::add(node & n)
{
	canvas[n.y][n.x] = n.type;
}

	
void BaseGraph::drawGraph() const
{
	std::cout << "start to draw graph" << std::endl;
	//std::cout << "\033[H";
	int i;
	std::string * heightString = new std::string[height];
	for(i = 0 ; i < height; i++)
	{
		heightString[i] = std::string(canvas[i]);
		if(i != height - 1)
			std::cout << heightString[i] << '\n';
		else
			std::cout << heightString[i] << std::flush;
	}
	std::cout.flush();
	delete [] heightString;
}

bool BaseGraph::checkIsFull() const
{
	return isFull;
}

int BaseGraph::Height() const
{
	return height;
}

int BaseGraph::Width() const
{
	return width;
}

char ** BaseGraph::Canvas() const
{
	return canvas;
}

