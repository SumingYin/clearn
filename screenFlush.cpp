// test for clearing the screen 


#include <stdlib.h>
#include <iostream>
#include "unistd.h"
using namespace std;
#include "stdio.h"
#include <cstring>

#define HEIGHT 50
#define WIDTH 50

//void drawGraph(char [][]canvas,int height,int width); // this is wrong declartion
//void drawGraph(char (*canvas)[WIDTH],int height,int width);// this way is also not very useful
void drawGraph(char **canvas,int height,int width);
// draw Basic Graph for snake
void drawGraph(char **canvas,int height,int width)
{
	/*

	*************************
	*                       *
	*                       *
	*                       *
	*                       *
height	*                       *
	*                       *
	*                       *
	*                       *
	*                       *
	*************************
                  width

	 */
	
	int i;
	// use cuut to draw the graph,announce height pointers towards height string
	string * heightString = new string[height] ;
	for(i = 0; i < height ;i++)
	{

		heightString[i] = string(canvas[i]);
		if( i != height - 1)
			cout << heightString[i] << '\n';
		else
			cout << heightString[i] << flush;
	}
						
			
	delete [] heightString;	



}




int main()
{



	int height = 20;
	int width = 50;
	char ** canvas = new char*[height];

	int i,j;
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

	drawGraph(canvas,height,WIDTH);	
	// free each sub-array
	for(int i = 0;i < height;i++)
		delete [] canvas[i];
	// free the array of pointers
	delete [] canvas;


	sleep(4);	
	int  n;
	printf("\033[2J");        /*  clear the screen  */
	printf("\033[H");         /*  position cursor at top-left corner */

	for (i=1; i<=20; i++)  {
		    printf("The current count is: %d\n", i);
		    printf("what about tow lines? with i++,%d",i+1);
		    fflush(stdout);
		    sleep(1);
		    printf(i < 20 ? "\033[H" : "\n");
	}
	
	// how about the c++ version to implement above code
	cout << "\033[2J";
	cout << "\033[H";
	for(i = 1;i <= 10;i++)
	{
		cout << "count is:" << i <<'\n';
		cout << "tow lines?" << i + 1 << '\n';
		cout.flush();
		sleep(1);
		cout << "\033[H";
	}
	
	cout << "\033[2J";


	
	// what I want to do is that:
	// like draw picture for each frame
	// here we want to something in the console output!
	// it seems to have two steps
	// first use cout to output something on the screen
	// second,wait for like 0.1 second.
	// next,clear the console out put,wait for another output
	// last,cout the content to console screen
	// cout will not died,until we press <Esc> or <Ctrl + c>
	
	
	while(1)
	{

		//1. start a BaseGraph object
		BaseGraph graph;
		graph.initialize(); // draw map 

		//2. start a snake object,you can point its position and head char type
		Snake snake;

		//3. generate random obstacle,TODO:now only one obstracle,will be multiple
		// I think it should use graph to generate obstacles,now only one obstacle.
		node obstacle = graph.randGenerate(snake);// with snake it can exclude the snake's postions
		//4. draw snake and obstacle
		graph.draw(snake);
		graph.draw(obstacle);
		//5. listen command and try to move snake position,means update
		//   here,if the snake hit wall or itself it will crash
		bool crash = false;
		char direction = '\0';

		char updateDirection = listen(time);// within the time if it not pass the command it will reuse its original direction 
		char checkDirection = snake.checkValidDirection(direction,updateDirection);
		crash = snake.changeSnakePosition(graph,obstacle,checkDirection);// should be snake call because snake listen the command.
		if(crash)// judge wether wrong
		{
			cout << "GG" << endl;
			break;
		}
		sleep(1);
	}
		





















		







	return 0;
}
