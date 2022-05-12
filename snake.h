// snake.h -- use terminal console to implement snake game
#include <vector>
struct node
{
	int x; // postion x
	int y; // postion y
	char type; // head is '@',body is '#',obstacle is 'o'
	enum  { SNAKEHEAD,SNAKEBODY,OBSTACLE } typeint;
	node * next;// obstacles doesn't need next
};
struct directionVec
{
	int x;
	int y;
	bool isValid;
};
class Snake;
class BaseGraph
{

private:
	int height;
	int width;
	char ** canvas = nullptr;
	bool isFull;
public:
	BaseGraph(int h1=20,int w1=50);
	~BaseGraph();
	void initialize();
	void reset();
	void add(Snake & s); // two draw funtion uses its position and type to change canvas contents.
	void add(node & n);
	int Height() const;
	int Width() const;
	void changeObstaclePosition(node & obstacle,int x,int y);
	node randGenerate(Snake & s); // random generate obstacle exclude snake object position
	void drawGraph() const;
	bool checkIsFull() const;
	char ** Canvas() const;

};




class Snake
{
private:
	node * head;
	std::vector<node *> snakeNodes;
	
public:
	Snake(int x1 = 1, int y1 = 1,char headType = '@'); // head x and y should not be invalid place
	~Snake();
	char checkValidDirection(const char & tempDirection,const char & updateDirection);	
	bool changeSnakePosition(BaseGraph & graph,node & obstacle,char direction);	
	directionVec getDirectionVec(char direction);
	const std::vector<node *> &  getSnakeNodes() const;

};



