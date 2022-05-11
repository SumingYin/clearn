// snake.h -- use terminal console to implement snake game

#include <vector>
typedef struct
{
	int x; // postion x
	int y; // postion y
	char type; // head is '@',body is '#',obstacle is 'o'
	node * next;// obstacles doesn't need next
} node;
struct directionVec
{
	int x;
	int y;
	bool isValid;
};



class Snake
{
private:
	node * head;
	vector<node> snakeNodes;
	
public:
	Snake(int x1 = 1, int y1 = 1,char headType = '@'); // head x and y should not be invalid place
	~Snake();
	char checkValidDirection(const char & tempDirection,const char & updateDirection);	
	bool changeSnakePosition(BaseGraph & graph,node & obstacle,char direction);	
	directionVec getDirectionVec(char direction);
	const vector<node> &  getSnakeNodes() const;

}



class BaseGraph
{

private:
	int height;
	int width;
	char ** canvas = nullptr;
public:
	BaseGraph(int h1=20,int w1=50);
	~BaseGraph();
	void initialize();
	void add(Snake & s); // two draw funtion uses its position and type to change canvas contents.
	void add(node & n);
	int Height() const;
	int Width() const;
	node randGerate(Snake & s); // random generate obstacle exclude snake object position
}


