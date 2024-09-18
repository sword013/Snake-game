#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>

//DEFINATIONS
#define COLUMNS 50
#define ROWS 50
#define FPS 10
#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2
#define MAX 60  	//maximum length snake can get

//FUNCTIONS USED
void display();
void reshape();
void init();
void drawGrid();
void timer(int);
void keyboard(int,int,int);
void drawSnake();
void drawFood();
void drawLetters();

//GLOBAL VARIABLE DECLARATIONS
int posx[MAX]={25,25,25,25,25},posy[MAX]={25,25,25,25,25},sdirection=RIGHT,snakelength=5;  //SNAKE
int foodx,foody,food=1; //FOOD
int window=1;
int score=0,highscore=0;


int main(int argc,char **argv)
{	
	glutInit(&argc,argv); 
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);  
	glutInitWindowSize(800,800);
	glutCreateWindow("---SnaKe GamE---");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,timer,0);
	glutSpecialFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if(window==1)	
	drawLetters();
		
	else if(window==2)
	{	drawGrid();
 		drawSnake();
		drawFood();
	}
	
	else
	drawLetters();
	glutSwapBuffers();
}

void init()
{
	glClearColor(1,1,0.6,2);
}

void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,COLUMNS,0,ROWS,-1,1);
	glMatrixMode(GL_MODELVIEW);		
}




void drawGrid()
{
	int x,y;
	for(x=0;x<COLUMNS;x++)
	{	
		for(y=0;y<ROWS;y++)
		{
			//THIS WILL DRAW A BLOCK AND SET COLOR
			
			glLineWidth(3);
			if(x==0 || y==0 || x==COLUMNS-1 || y==ROWS-1)
			{
				glColor3f(0,0,1);
				glRectd(x,y+1,x+1,y);
			}
			else
			{
				glColor3f(0.5,0.5,0.5);

				glBegin(GL_LINE_LOOP);
					glVertex2f(x,y);
					glVertex2f(x+1,y);
					glVertex2f(x+1,y+1);
					glVertex2f(x,y+1);
				glEnd();
			}
			
		}
	}
}

void timer(int fps)
{ 
	glutPostRedisplay();
	glutTimerFunc(1000/FPS,timer,0);
}


void keyboard(int key,int mousex,int mousey)
{	
	switch(key) 
	{

		case GLUT_KEY_F1 : window=2; 
				   break;	
	
		case GLUT_KEY_UP : if(sdirection!=DOWN)
				   sdirection=UP; 
				   break;

		case GLUT_KEY_DOWN : if(sdirection!=UP)
				   sdirection=DOWN; 
				   break;

		case GLUT_KEY_RIGHT : if(sdirection!=LEFT)
				   sdirection=RIGHT; 
				   break;

		case GLUT_KEY_LEFT : if(sdirection!=RIGHT)
				   sdirection=LEFT; 
				   break;
	}	
}


void drawSnake()
{	
	int i;
	//TRANSLATION OF SNAKE ACCORDING TO SNAKE DIRECTION (CHANGING BLOCKS) -->DIAGRAM
	for(i=snakelength-1;i>0;i--)
	{	
		posx[i]=posx[i-1];
		posy[i]=posy[i-1];
	}

	//FOR DECIDING AT ANY POINT SNAKE'S NEW DIRECTION(BY DEFAULT ITS SET TO RIGHT)
	if(sdirection==RIGHT)
	posx[0]++;
	else if(sdirection==LEFT)
	posx[0]--;
	else if(sdirection==UP)
	posy[0]++;
	else if(sdirection==DOWN)
	posy[0]--;

	
	//DRAWING SNAKE CONSIDERING HEAD AND BODY
	for(i=0;i<snakelength;i++)
	{
		if(i==0)      		//HEAD
		glColor3f(0,0,0);
		else
		glColor3f(1,0,0);	//BODY

		glRectd(posx[i],posy[i],posx[i]+1,posy[i]+1);
	}

	//COLLISION DETECTION TEST-GAMEOVER OR NOT (ONLY FOR HEAD LOGICALLY) AND DISPLAY SCORE
	if(posx[0]==0 || posx[0]==COLUMNS-1 || posy[0]==0 || posy[0]==ROWS-1 )
	{	
		if(score>highscore)
		highscore=score;
		printf("YOUR SCORE IS : %d\nHIGHSCORE : %d\nKEEP PLAYING GAMES\nGOOD LUCK FOR NEXT TRY :D\n",score,highscore);
		exit(0);
	} 


	//COLLISION WITH ITSELF 
	for(i=1;i<snakelength;i++)
	if(posx[0]==posx[i] && posy[0]==posy[i])
	{ 
		if(score>highscore)
		highscore=score;
		printf("YOUR SCORE IS : %d\nHIGHSCORE : %d\nKEEP PLAYING GAMES\nGOOD LUCK FOR NEXT TRY :D\n",score,highscore);
		exit(0);
	}


	//INCREASING SNAKELEGNTH WHEN SNAKE EATS FOOD	
	if(posx[0]==foodx && posy[0]==foody)
	{
		score++;
		food=1;
		snakelength++;
		if(snakelength>MAX)
		snakelength=MAX;
	}

}

void drawFood()
{	
	//RANDOM NUMBER GENERATOR FROM 1 TO 50
	if(food)	
	{
		
		foodx=rand()%48+1;
		foody=rand()%48+1;
		food=0;
		
	}

	glColor3f(0,0.3,0);
	glRectd(foodx,foody,foodx+1,foody+1);
		
}

void drawLetters()
{
	glColor3f(0,0,0);
	glLineWidth(12);

	glBegin(GL_LINES); 
	//S
	glVertex2f(6,43);
	glVertex2f(12,43);

	glVertex2f(6,43);
	glVertex2f(6,38);

	glVertex2f(6,38);
	glVertex2f(12,38);

	glVertex2f(12,38);
	glVertex2f(12,33);

	glVertex2f(12,33);
	glVertex2f(6,33);
			
	//N
	glVertex2f(15,33);
	glVertex2f(15,43);

	glVertex2f(15,43);
	glVertex2f(19,33);

	glVertex2f(19,33);
	glVertex2f(19,43);

	//A
	glVertex2f(22,33);
	glVertex2f(24,43);

	glVertex2f(24,43);
	glVertex2f(26,33);

	glVertex2f(23,38);
	glVertex2f(25,38);
		
	//K
	glVertex2f(29,33);
	glVertex2f(29,43);

	glVertex2f(29,38);
	glVertex2f(33,43);

	glVertex2f(29,38);
	glVertex2f(33,33);

	//E
	glVertex2f(36,33);
	glVertex2f(36,43);

	glVertex2f(36,33);
	glVertex2f(41,33);

	glVertex2f(36,43);
	glVertex2f(41,43);

	glVertex2f(36,38);
	glVertex2f(39,38);

	//G
	glVertex2f(6,30);
	glVertex2f(12,30);

	glVertex2f(6,30);
	glVertex2f(6,20);

	glVertex2f(6,20);
	glVertex2f(12,20);

	glVertex2f(12,20);
	glVertex2f(12,25);

	glVertex2f(10,25);
	glVertex2f(14,25);

	//A
	glVertex2f(16,20);
	glVertex2f(19,30);

	glVertex2f(19,30);
	glVertex2f(22,20);
		
	glVertex2f(17,25);
	glVertex2f(21,25);

	//M
	glVertex2f(25,20);
	glVertex2f(25,30);
	
	glVertex2f(25,30);
	glVertex2f(27,27);

	glVertex2f(27,27);
	glVertex2f(29,30);

	glVertex2f(29,30);
	glVertex2f(29,20);

	//E
	glVertex2f(32,30);
	glVertex2f(32,20);

	glVertex2f(32,20);
	glVertex2f(37,20);

	glVertex2f(32,30);
	glVertex2f(37,30);

	glVertex2f(32,25);
	glVertex2f(35,25);

	glColor3f(1,0,0);
	//F
	glVertex2f(12,15);
	glVertex2f(15,15);

	glVertex2f(12,15);
	glVertex2f(12,9);

	glVertex2f(12,12);
	glVertex2f(15,12);

	//1

	glVertex2f(17,9);
	glVertex2f(17,15);

		
	glEnd();
}
