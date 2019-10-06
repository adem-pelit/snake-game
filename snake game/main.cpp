#include<GL/freeglut.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

void keyboard(unsigned char key, int x, int y);
void display(void);

	bool tahta[30][30],gameover=1;
	int snake[900][2],speed,boy=0,direction=1,dotx=5,doty=5,press,basamak;
	int x,y,z,t,pulse,xs;
	int xpos, ypos;

int main(int argc,char** argv)
{
	pulse=10;
	
	for(x=0;x<5;x++){
	snake[x][0]=15;
	snake[x][1]=15+x;}
	
	for(x=0;x<boy+5;x++){
		tahta[snake[x][1]][snake[x][0]]=1;}

	glutInit(&argc,argv);
	glutInitWindowSize(960,960);
	glutCreateWindow("snake game");
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
	return 1;
}



void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 119:
			if(direction!=0){
			direction=2;	
			}
			break;
			
		case 100:
			if(direction!=3){
			direction=1;	
			}
			break;
			
		case 115:
			if(direction!=2){
			direction=0;	
			}
			break;
			
		case 97:
			if(direction!=1){
			direction=3;	
			}
			break;
			
			case 'p':
			pulse++;
			break;
			
		case 'o':
			pulse--;
			break;
	}
}

void display()
{
	for(xs=0;xs<pulse;xs++){
		Sleep(1);
		if(xs==0){
		
	snake[boy+5][0]=(snake[boy+4][0]+(direction==2)-(direction==0))%30;
	snake[boy+5][1]=(snake[boy+4][1]+(direction==1)-(direction==3))%30;
	if(snake[boy+5][0]<0) snake[boy+5][0]=30;
	if(snake[boy+5][1]<0) snake[boy+5][1]=30;
	
	if(snake[boy+4][0]==dotx&&snake[boy+4][1]==doty){
	boy++;
	dotx=rand() % 30;
	doty=rand() % 30;	
	snake[boy+5][0]=(snake[boy+4][0]+(direction==2)-(direction==0))%30;
	snake[boy+5][1]=(snake[boy+4][1]+(direction==1)-(direction==3))%30;
	if(snake[boy+5][0]<0) snake[boy+5][0]=30;
	if(snake[boy+5][1]<0) snake[boy+5][1]=30;
	}
	
	//if(!(snake[boy+4][0]==dotx&&snake[boy+4][1]==doty)){
	for(x=0;x<boy+5;x++){
		snake[x][1]=snake[x+1][1];
		snake[x][0]=snake[x+1][0];}
		
	for(x=0;x<boy+4;x++){
		if(snake[boy+4][1]==snake[x][1]&&snake[boy+4][0]==snake[x][0]) gameover=0;
		
		}}
	}
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,960,0,960);
	glClear(GL_COLOR_BUFFER_BIT);
	
	
		//glPolygonMode(GL_FRONT,GL_FILL);
		glBegin(GL_QUADS);
		
		for(t=0;t<10;t++){
	glColor3f(1,1,1);
	//glColor3f(1.0f,1.0f,1.0f);
	for(x=0;x<boy+4;x++){
		glColor3f((boy%4+1)/4.f,(boy%16)/16.f,(boy%64+1)/64.f);	
		
		glVertex2f(snake[x][1]*32,snake[x][0]*32);
		glVertex2f(snake[x][1]*32+30,snake[x][0]*32);
		glVertex2f(snake[x][1]*32+30,snake[x][0]*32+30);
		glVertex2f(snake[x][1]*32,snake[x][0]*32+30);
		
		}
		glColor3f((rand()%16)/16.f,(rand()%16)/16.f,(rand()%16)/16.f);
		glVertex2f(doty*32,dotx*32);
		glVertex2f(doty*32+29,dotx*32);
		glVertex2f(doty*32+29,dotx*32+29);
		glVertex2f(doty*32,dotx*32+29);
		
		if(!gameover){
		glVertex2f(snake[x][1]*32+30,snake[x][0]*+30);
		glVertex2f(snake[x][1]*32+30,snake[x][0]*32+30);
		glVertex2f(snake[x][1]*32+30+30,snake[x][0]*32+30+30);
		glVertex2f(snake[x][1]*32+30,snake[x][0]*32+30+30);
		}
		
		for(x=0;x<boy;x++){
		glColor3f(1.0f,(rand()%16)/16.f,1.0f);	
		
		glVertex2f(x*32,0);
		glVertex2f(x*32+30,0);
		glVertex2f(x*32+30,30);
		glVertex2f(x*32,30);
		
		}
		
		for(x=0;x<(boy%30)/30;x++){
		glColor3f(1.0f,(rand()%16)/16.f,1.0f);	
		
		glVertex2f(x*32,32);
		glVertex2f(x*32+30,32);
		glVertex2f(x*32+30,64);
		glVertex2f(x*32,64);
		
		}
		
	//Sleep(pulse);
	/*glVertex2f(rand()%1080,rand()%1080);
	glVertex2f(rand()%1080,rand()%1080);

	glVertex2f(rand()%1080,rand()%1080);
	glVertex2f(rand()%1080,rand()%1080);*/
	}
	

		
	glEnd();
	glFlush();
	
}
