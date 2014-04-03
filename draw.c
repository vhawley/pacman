#include <stdio.h>
#include <math.h>
#include "gfx.h"
#include "draw.h"
#include <ctype.h>
#include <string.h>

void draw_one(int x, int y, int height)
{
	gfx_line(x, y-(height/2),x, y+(height/2));
	gfx_line(x, y-(height/2),x-(height/4),y-(height/4));
	gfx_line(x-(height/4),y+(height/2), x+(height/4),y+(height/2));
}

void draw_two(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x+(height/4), y-(height/2),x+(height/4),y);
	gfx_line(x+(height/4),y, x-(height/4),y);
	gfx_line(x-(height/4),y, x-(height/4),y+(height/2));
	gfx_line(x-(height/4),y+(height/2), x+(height/4),y+(height/2));
}

void draw_three(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x+(height/4), y-(height/2),x+(height/4),y);
	gfx_line(x+(height/4),y, x-(height/4),y);
	gfx_line(x+(height/4),y, x+(height/4),y+(height/2));
	gfx_line(x+(height/4),y+(height/2), x-(height/4),y+(height/2));
}

void draw_four(int x, int y, int height)
{
	gfx_line(x-(height/4),y-(height/2),x-(height/4), y);
	gfx_line(x-(height/4),y ,x+(height/4),y);
	gfx_line(x+(height/4),y-(height/2), x+(height/4),y+(height/2));
}

void draw_five(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x-(height/4), y-(height/2),x-(height/4),y);
	gfx_line(x+(height/4),y, x-(height/4),y);
	gfx_line(x+(height/4),y, x+(height/4),y+(height/2));
	gfx_line(x-(height/4),y+(height/2), x+(height/4),y+(height/2));
}

void draw_six(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x-(height/4), y+(height/2),x+(height/4),y+(height/2));
	gfx_line(x+(height/4),y+(height/2), x+(height/4),y);
	gfx_line(x+(height/4),y, x-(height/4),y);
}

void draw_seven(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x+(height/4), y-(height/2), x+(height/4),y+(height/2));
}

void draw_eight(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x-(height/4), y-(height/2),x-(height/4),y+(height/2));
	gfx_line(x-(height/4),y+(height/2), x+(height/4),y+(height/2));
	gfx_line(x+(height/4), y-(height/2), x+(height/4),y+(height/2));
	gfx_line(x-(height/4),y, x+(height/4),y);
}

void draw_nine(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y);
	gfx_line(x-(height/4), y,x+(height/4),y);
	gfx_line(x+(height/4),y-(height/2), x+(height/4),y+(height/2));
}

void draw_zero(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x-(height/4), y+(height/2),x+(height/4),y+(height/2));
	gfx_line(x+(height/4),y-(height/2), x+(height/4),y+(height/2));
}

void draw_A(int x, int y, int height)
{
	gfx_line(x, y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x, y-(height/2),x+(height/4), y+(height/2));
	gfx_line(x-(height/8), y,x+(height/8),y);
}


void draw_B(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/4));
	gfx_line(x+(height/4), y-(height/4),x-(height/4),y);
	gfx_line(x-(height/4),y, x+(height/4),y+(height/4));
	gfx_line(x+(height/4),y+(height/4), x-(height/4),y+(height/2));
}


void draw_C(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x-(height/4),y+(height/2), x+(height/4),y+(height/2));
}

void draw_D(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y);
	gfx_line(x+(height/4), y,x-(height/4), y+(height/2));
}

void draw_E(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x-(height/4), y,x, y);
	gfx_line(x-(height/4), y+(height/2),x+(height/4), y+(height/2));
}

void draw_F(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x-(height/4), y,x, y);
}

void draw_G(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x-(height/4),y+(height/2), x+(height/4),y+(height/2));
	gfx_line(x+(height/4),y+(height/2), x+(height/4),y);
	gfx_line(x+(height/4),y, x,y);
}

void draw_H(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x+(height/4), y-(height/2),x+(height/4), y+(height/2));
	gfx_line(x-(height/4), y,x+(height/4), y);
}

void draw_I(int x, int y, int height)
{
	gfx_line(x-(height/8), y-(height/2),x+(height/8), y-(height/2));
	gfx_line(x, y-(height/2),x, y+(height/2));
	gfx_line(x-(height/8), y+(height/2),x+(height/8),y+(height/2));
}

void draw_J(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x, y-(height/2),x, y+(height/2));
	gfx_line(x-(height/4), y+(height/2),x,y+(height/2));
}

void draw_K(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x-(height/4), y,x+(height/4),y-(height/2));
	gfx_line(x-(height/4),y, x+(height/4),y+(height/2));
}

void draw_L(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x-(height/4), y+(height/2),x+(height/4),y+(height/2));
	
}

void draw_M(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x+(height/4),y-(height/2), x+(height/4),y+(height/2));
	gfx_line(x-(height/4), y-(height/2),x, y);
	
	gfx_line(x, y,x+(height/4),y-(height/2));
}

void draw_N(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x+(height/4),y-(height/2), x+(height/4),y+(height/2));
	gfx_line(x-(height/4), y-(height/2),x+(height/4),y+(height/2));	
}

void draw_O(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x-(height/4), y+(height/2),x+(height/4),y+(height/2));
	gfx_line(x+(height/4),y-(height/2), x+(height/4),y+(height/2));
}

void draw_P(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x-(height/4), y ,x+(height/4),y);
	gfx_line(x+(height/4),y-(height/2), x+(height/4),y);
}

void draw_Q(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/3));
	gfx_line(x-(height/4), y+(height/3),x+(height/4),y+(height/3));
	gfx_line(x+(height/4),y-(height/2), x+(height/4),y+(height/3));
	gfx_line(x+(height/8),y+(height/4), x+(height/4),y+(height/2));
}

void draw_R(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/6), y-(height/2));
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x-(height/4), y ,x+(height/6),y);
	gfx_line(x+(height/6),y-(height/2), x+(height/6),y);
	gfx_line(x+(height/6), y ,x+(height/4),y+(height/2));
}

void draw_S(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y);
	gfx_line(x-(height/4), y,x+(height/4),y);
	gfx_line(x+(height/4),y, x+(height/4),y+(height/2));
	gfx_line(x-(height/4),y+(height/2), x+(height/4),y+(height/2));
}

void draw_T(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x, y-(height/2),x, y+(height/2));
}

void draw_U(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x-(height/4), y+(height/2),x+(height/4),y+(height/2));
	gfx_line(x+(height/4),y-(height/2), x+(height/4),y+(height/2));
}

void draw_V(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x, y+(height/2));
	gfx_line(x, y+(height/2),x+(height/4),y-(height/2));
}

void draw_W(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x-(height/6), y+(height/2));
	gfx_line(x-(height/6), y+(height/2),x, y);
	gfx_line(x, y,x+(height/6),y+(height/2));
	gfx_line(x+(height/6),y+(height/2), x+(height/4),y-(height/2));
}

void draw_X(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y+(height/2));
	gfx_line(x-(height/4), y+(height/2),x+(height/4), y-(height/2));
}

void draw_Y(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x, y);
	gfx_line(x, y,x+(height/4), y-(height/2));
	gfx_line(x, y,x,y+(height/2));
}

void draw_Z(int x, int y, int height)
{
	gfx_line(x-(height/4), y-(height/2),x+(height/4), y-(height/2));
	gfx_line(x+(height/4), y-(height/2),x-(height/4), y+(height/2));
	gfx_line(x-(height/4), y+(height/2),x+(height/4),y+(height/2));
}

void draw_colon(int x, int y, int height)
{
	draw_square(x-height/6,y-height/5,height/8);
	draw_square(x-height/6,y+height/5,height/8);
}

void draw_letter(char c, int x, int y, int height)
{
	switch (c)
	{
		case '0':
			draw_zero(x,y,height);
			break;
		case '1':
			draw_one(x,y,height);
			break;
		case '2':
			draw_two(x,y,height);
			break;
		case '3':
			draw_three(x,y,height);
			break;
		case '4':
			draw_four(x,y,height);
			break;
		case '5':
			draw_five(x,y,height);
			break;
		case '6':
			draw_six(x,y,height);
			break;		
		case '7':
			draw_seven(x,y,height);
			break;		
		case '8':
			draw_eight(x,y,height);
			break;
		case '9':
			draw_nine(x,y,height);
			break;
		case 'A':
			draw_A(x,y,height);
			break;
		case 'B':
			draw_B(x,y,height);
			break;
		case 'C':
			draw_C(x,y,height);
			break;
		case 'D':
			draw_D(x,y,height);
			break;
		case 'E':
			draw_E(x,y,height);
			break;
		case 'F':
			draw_F(x,y,height);
			break;
		case 'G':
			draw_G(x,y,height);
			break;
		case 'H':
			draw_H(x,y,height);
			break;
		case 'I':
			draw_I(x,y,height);
			break;
		case 'J':
			draw_J(x,y,height);
			break;
		case 'K':
			draw_K(x,y,height);
			break;
		case 'L':
			draw_L(x,y,height);
			break;
		case 'M':
			draw_M(x,y,height);
			break;
		case 'N':
			draw_N(x,y,height);
			break;
		case 'O':
			draw_O(x,y,height);
			break;
		case 'P':
			draw_P(x,y,height);
			break;
		case 'Q':
			draw_Q(x,y,height);
			break;
		case 'R':
			draw_R(x,y,height);
			break;
		case 'S':
			draw_S(x,y,height);
			break;
		case 'T':
			draw_T(x,y,height);
			break;
		case 'U':
			draw_U(x,y,height);
			break;
		case 'V':
			draw_V(x,y,height);
			break;
		case 'W':
			draw_W(x,y,height);
			break;
		case 'X':
			draw_X(x,y,height);
			break;
		case 'Y':
			draw_Y(x,y,height);
			break;
		case 'Z':
			draw_Z(x,y,height);
			break;
		case ':':
			draw_colon(x,y,height);
			break;
		default:
			break;
	}
}

void draw_circle(int x, int y, int r)
{
	float t=0;
	float dt=.01;
	
	for (t=0;t<2*M_PI;t+=dt)
	{
		gfx_line(x+r*cos(t),y+r*sin(t),x+r*cos(t+dt),y+r*sin(t+dt));
	}

}

void draw_square(int x, int y, int w)
{
	gfx_line(x-w/2,y-w/2,x+w/2,y-w/2);
	gfx_line(x+w/2,y-w/2,x+w/2,y+w/2);
	gfx_line(x+w/2,y+w/2,x-w/2,y+w/2);
	gfx_line(x-w/2,y+w/2,x-w/2,y-w/2);
}

void draw_food(int type, int x, int y)
{
	int i;
	switch (type)
	{
		case 1: //Small
			gfx_color(227,220,192);			
			draw_circle(x,y,2);
			break;
		case 2: //Super
			gfx_color(249,211,165);
			draw_circle(x,y,5);
			break;
	}
}

void draw_collision_border(int type, int x, int y, int r)
{
	float t=0;
	float dt=.01;
	switch (type)
	{
		case 1: //vertical border
			gfx_line(x,y-r/2,x,y+r/2);
			break;
		case 2: //horizontal border
			gfx_line(x-r/2,y,x+r/2,y);
			break;
		case 3: //top left corner
			for (t=M_PI;t<M_PI*3/2;t+=dt)
			{
				gfx_line(x+(r/2)*(cos(t)+1),y+(r/2)*(sin(t)+1),x+(r/2)*(cos(t+dt)+1),y+(r/2)*(sin(t+dt)+1));
			}
			break;
		case 4: //top right border
			for (t=M_PI*3/2;t<2*M_PI;t+=dt)
			{
				gfx_line(x+(r/2)*(cos(t)-1),y+(r/2)*(sin(t)+1),x+(r/2)*(cos(t+dt)-1),y+(r/2)*(sin(t+dt)+1));
			}
			break;
		case 5: //bottom left corner
			for (t=M_PI/2;t<M_PI;t+=dt)
			{
				gfx_line(x+(r/2)*(cos(t)+1),y+(r/2)*(sin(t)-1),x+(r/2)*(cos(t+dt)+1),y+(r/2)*(sin(t+dt)-1));
			}
			break;
		case 6: //bottom right corner
			for (t=0;t<M_PI/2;t+=dt)
			{
				gfx_line(x+(r/2)*(cos(t)-1),y+(r/2)*(sin(t)-1),x+(r/2)*(cos(t+dt)-1),y+(r/2)*(sin(t+dt)-1));
			}
			break;
		default:
			break;
	}
}

void draw_word(char *s, int x, int y, int height)
{
	int l = strlen(s);
	int i = 0;
	while (s[i])
	{
		draw_letter(toupper(s[i]),x+(i)*(height/1.5), y, height);
		i++;
	}
}

void draw_pacman(int x, int y, int theta)
{
	gfx_color(255,255,0);
	int r = 10;
	double t = M_PI/4-(M_PI/2)*theta, dt = 0.01;
	gfx_line(x+r*cos(t),y+r*sin(t),x,y);		
	for (t=M_PI/4-(M_PI/2)*theta;t<(7.5/4.1)*M_PI-(M_PI/2)*theta;t+=dt)
	{
		gfx_line(x+r*cos(t),y+r*sin(t),x+r*cos(t+dt),y+r*sin(t+dt));
	}
	gfx_line(x+r*cos(t),y+r*sin(t),x,y);
	//only outline to help with processing time
}

void draw_ghost(Ghost g)
{
	if (g.killable)
	{
		gfx_color(0,0,255);
	}
	else
	{
		gfx_color(g.rcolor,g.gcolor,g.bcolor);
	}
	int r=10;
	draw_circle(g.xcenter, g.ycenter,r); //only circle due to processing time
}

void draw_menubutton(MenuButton m)
{
	gfx_line(m.xcenter-m.width/2,m.ycenter-m.height/2,m.xcenter+m.width/2,m.ycenter-m.height/2);
	gfx_line(m.xcenter+m.width/2,m.ycenter-m.height/2,m.xcenter+m.width/2,m.ycenter+m.height/2);
	gfx_line(m.xcenter+m.width/2,m.ycenter+m.height/2,m.xcenter-m.width/2,m.ycenter+m.height/2);
	gfx_line(m.xcenter-m.width/2,m.ycenter+m.height/2,m.xcenter-m.width/2,m.ycenter-m.height/2);

	draw_word(m.text, m.xcenter-m.width/2 + 25, m.ycenter, m.height * .75);
	
}

