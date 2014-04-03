#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "gfx.h"
#include "math.h"
#include "draw.h"
#include "pacman.h"


int debug = 0;
int score = 0;
int hiscore = 0;
int lives = 0;

int boardx0 = (W_WIDTH-W_HEIGHT);
int boardy0 = 0;

char scoretext[15];
char hiscoretext[15];
char livestext[10];

int collision_board[B_HEIGHT][B_WIDTH]; //Board for walkable/unwalkable spaces only
int food_board[B_HEIGHT][B_WIDTH]; //Board for food/super food/fruit ONLY

int pacx;
int pacy;
int pacdirection = 0; //0 = right; 1 = up; 2 = left; 3 = down
int pacnextdirection = 0;
int pacspeed = 7; //speed moved per "frame"
int pacsupertimer = 0;

MenuButton menuButtons[2];
Ghost ghosts[GhostNum];

int spawntimer = 0;

int adjustedx(int x) //Column
{
	return ceil((x - boardx0 - 98)/15);
}

int adjustedy(int y) //Row
{
	return ceil((y - boardy0 - 60)/15);
}

int is_valid_space( int x, int y)
{
	if (x > -1 && x < B_HEIGHT && y > -1 && y < B_WIDTH)
	{
		return 1;
	}
	return 0;
}

int is_walkable_space(int x, int y)
{
	if (is_valid_space(x, y) && collision_board[x][y])
	{
		return 1;
	}
	return 0;
}

void draw_food_board()
{
	int i, j;
	for (i=0;i<B_HEIGHT;i++)
	{
		for(j=0;j<B_WIDTH;j++)
		{
			draw_food(food_board[i][j],boardx0+98+15*j,boardy0+60+15*i);	
		}
	}
	gfx_color(255,255,255);
}

void draw_collision_board()
{
	
	int width = 15;

	gfx_color(0,0,255);
	int i, j;
	for (i=0;i<B_HEIGHT;i++)
	{
		for(j=0;j<B_WIDTH;j++)
		{
			int x = boardx0 + 98 + 15*j;
			int y = boardy0 + 60 + 15*i;
			if (!collision_board[i][j])
			{
				//top left borders				
				if (!is_walkable_space(i+1,j) && 
					!is_walkable_space(i,j+1) && 
					(((is_walkable_space(i-1,j) || !is_valid_space(i-1,j)) &&
					(is_walkable_space(i,j-1) || !is_valid_space(i,j-1))) ||
					is_walkable_space(i+1,j+1)))
				{
					draw_collision_border(3, x, y, width);
					continue;
				}

				//top right borders				
				if (!is_walkable_space(i+1,j) && 
					!is_walkable_space(i,j-1) && 
					(((is_walkable_space(i-1,j) || !is_valid_space(i-1,j)) &&
					(is_walkable_space(i,j+1) || !is_valid_space(i,j+1))) || 
					is_walkable_space(i+1,j-1)))
				{
					draw_collision_border(4, x, y, width);
					continue;
				}

				//bottom left borders				
				if (!is_walkable_space(i-1,j) && 
					!is_walkable_space(i,j+1) && 
					(((is_walkable_space(i+1,j) || !is_valid_space(i+1,j)) &&
					(is_walkable_space(i,j-1) || !is_valid_space(i,j-1))) || 
					is_walkable_space(i-1,j+1)))
				{
					draw_collision_border(5, x, y, width);
					continue;
				}

				//bottom right borders				
				if (!is_walkable_space(i-1,j) && 
					!is_walkable_space(i,j-1) && 
					(((is_walkable_space(i+1,j) || !is_valid_space(i+1,j)) &&
					(is_walkable_space(i,j+1) || !is_valid_space(i,j+1))) ||
					is_walkable_space(i-1,j-1)))
				{
					draw_collision_border(6, x, y, width);
					continue;
				}

				//Vertical borders
				if (!is_walkable_space(i+1,j) && 
					!is_walkable_space(i-1,j) && 
					(is_walkable_space(i,j+1) || is_walkable_space(i,j-1)))
				{
					draw_collision_border(1, x, y, width);
					continue;
				}

				//Horizontal borders				
				if (!is_walkable_space(i,j+1) && 
					!is_walkable_space(i,j-1) && 
					(is_walkable_space(i+1,j) || is_walkable_space(i-1,j)))
				{
					draw_collision_border(2, x, y, width);
					continue;
				}
				
			}	
		}
	}
	gfx_color(255,255,255);
}

void print_board( int b[B_HEIGHT][B_WIDTH] )
{
	int i, j;
	for (i=0;i<B_HEIGHT;i++)
	{
		for(j=0;j<B_WIDTH;j++)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
}



void get_data( char *s, int b[B_HEIGHT][B_WIDTH] )
{
	FILE *f = fopen(s, "r");
	if (!f)
	{
		printf("Could not open file\n");
	}
	else
	{
		if (debug)
		{
			printf("File %s opened\n", s);
		}
		
		int i = 0, j = 0, t;
		for (i=0; i < B_HEIGHT; i++)
		{
			for (j=0; j < B_WIDTH - 1; j++)
			{
				fscanf(f, "%1d", &b[i][j]);
			}
			fscanf(f, "%d\n", &b[i][B_WIDTH-1]);
		}
		fclose(f);
		if (debug)
		{
			print_board(b);
		}
	}
}

void draw_UI_elements()
{
	draw_word(scoretext,40,40,15);
	draw_word(hiscoretext,40,70,15);
	draw_word(livestext,40,100,15);
	draw_word("press p to pause",40,130,10);
	draw_word("control with w a s d",40,160,10);
	gfx_line(W_WIDTH-W_HEIGHT, 0, W_WIDTH-W_HEIGHT, W_HEIGHT);
}

void pause()
{
	gfx_color(255,165,0);
	draw_word("PAUSED", 40, 200, 30);
	gfx_color(255,255,255);
	MenuButton quit;
	quit.xcenter = 80;
	quit.ycenter = 240;
	quit.width = 80;
	quit.height = 25;
	quit.text = "quit";
	draw_menubutton(quit);
	while (1)
	{
		if (gfx_event_waiting())
		{
			char c = gfx_wait();
			int x = gfx_xpos();
			int y = gfx_ypos();
			switch (c)
			{
				case 'p':
					game_cycle();
					break;
				case 1:
					
					if ( (x > quit.xcenter-(quit.width)/2) && 
					(x < quit.xcenter+ (quit.width)/2) && 
					(y > quit.ycenter-(quit.height)/2) && 
					(y < quit.ycenter+(quit.height)/2) )
					{
						open_menu();
					}
					break;
				default:
					break;	
			}
		}
		usleep(1000000 / FPS); //Update FPS times per second
	}
}

void move_pacman()
{
	switch (pacnextdirection)
	{		
		case 0:
			if (is_walkable_space(adjustedy(pacy),adjustedx(pacx)+1))
			{
				pacdirection = pacnextdirection;
			}
			break;
		case 1:
			if (is_walkable_space(adjustedy(pacy)-1,adjustedx(pacx)))
			{
				pacdirection = pacnextdirection;
			}
			break;
		case 2:
			if (is_walkable_space(adjustedy(pacy),adjustedx(pacx)-1))
			{
				pacdirection = pacnextdirection;
			}
			break;
		case 3:
			if (is_walkable_space(adjustedy(pacy)+1,adjustedx(pacx)))
			{
				pacdirection = pacnextdirection;
			}
			break;
		default:
			printf("Invalid nextdirection passed.");
			break;
	}	
	switch (pacdirection)
	{
		case 0:
			if (is_walkable_space(adjustedy(pacy),adjustedx(pacx)+1))
			{
				pacx = pacx + pacspeed;
			}
			else if (!is_valid_space(adjustedy(pacy),adjustedx(pacx)+1))
			{
				pacx = boardx0 + 98;
			}
			else
			{
				pacdirection = pacnextdirection;
			}
			break;
		case 1:
			if (is_walkable_space(adjustedy(pacy)-1,adjustedx(pacx)))
			{
				pacy = pacy - pacspeed;
			}
			else if (!is_valid_space(adjustedy(pacy)-1,adjustedx(pacx)))
			{
				pacy = boardy0 + 60 + 15*B_HEIGHT;
			}
			else
			{
				pacdirection = pacnextdirection;
			}
			break;
		case 2:
			if (is_walkable_space(adjustedy(pacy),adjustedx(pacx)-1))
			{
				pacx = pacx - pacspeed;
			}
			else if (!is_valid_space(adjustedy(pacy),adjustedx(pacx)-1))
			{
				pacx = boardx0 + 98 + 15*B_WIDTH;
			}
			else
			{
				pacdirection = pacnextdirection;
			}
			break;
		case 3:
			if (is_walkable_space(adjustedy(pacy)+1,adjustedx(pacx)))
			{
				pacy = pacy + pacspeed;
			}
			else if (!is_valid_space(adjustedy(pacy)+1,adjustedx(pacx)))
			{
				pacy = boardy0 + 60;
			}
			else
			{
				pacdirection = pacnextdirection;
			}
			break;
		default:
			printf("Invalid direction passed.");
			break;
	}
	switch (food_board[adjustedy(pacy)][adjustedx(pacx)])
	{	
		case 1:
			food_board[adjustedy(pacy)][adjustedx(pacx)] = 0;
			score+= 10;
			sprintf(scoretext,"Score: %d", score);
			break;
		case 2:
			food_board[adjustedy(pacy)][adjustedx(pacx)] = 0;
			score+= 50;
			sprintf(scoretext,"Score: %d", score);
			pacsupertimer = FPS * 12;

	}
	int g;
	for (g=0;g<GhostNum;g++)
	{
		if (abs(ghosts[g].xcenter - pacx) < 10 && abs(ghosts[g].ycenter - pacy) < 10)
		{
			if (ghosts[g].killable)
			{
				ghosts[g].alive = 0;
				score+= 200; //Flat score for eating ghosts for now... might perfect later if time allows
				sprintf(scoretext,"Score: %d", score);
			}
			else if (ghosts[g].alive)
			{
				reset_pacman_position();
				lives--;
				sprintf(livestext,"Lives: %d", lives);
				sleep(3);
			}
		}
	}
	if (score > 5000)
	{
		lives++;
		sprintf(livestext,"Lives: %d", lives);
	}
}

void draw_ghosts()
{
	int i;
	for (i = 0; i<GhostNum;i++)
	{
		if (ghosts[i].alive)
		{
			draw_ghost(ghosts[i]);
		}
		
	}
}

void spawn_ghost()
{
	int spawned = 0, i = 0;
	while (!spawned && i < GhostNum)
	{
		if (ghosts[i].inplay == 0)
		{
			ghosts[i].xcenter = boardx0+W_HEIGHT/2;
			ghosts[i].ycenter = boardy0+W_HEIGHT/2-75;
			ghosts[i].inplay = 1;
			spawned = 1;
		}
		i++;
	}
}

void move_ghosts()
{
	int i = 0;
	
	for (i=0;i<GhostNum;i++)
	{
		int j = 0;
		int directionsavailable[4] = {-1,-1,-1,-1};
		int possibledirections = 0;
		if (ghosts[i].inplay)
		{
			if (is_walkable_space(adjustedy(ghosts[i].ycenter)-1,adjustedx(ghosts[i].xcenter))) //up
			{
				directionsavailable[j]=1;
				j++;
			}
			if (is_walkable_space(adjustedy(ghosts[i].ycenter)+1,adjustedx(ghosts[i].xcenter))) //down
			{
				directionsavailable[j]=3;
				j++;
			}
			if (is_walkable_space(adjustedy(ghosts[i].ycenter),adjustedx(ghosts[i].xcenter)-1)) //left
			{
				directionsavailable[j]=2;
				j++;
			}
			if (is_walkable_space(adjustedy(ghosts[i].ycenter),adjustedx(ghosts[i].xcenter)+1)) //right
			{
				directionsavailable[j]=0;
				j++;
			}
			if (debug)
			{
				printf("j = %d\n", j);
			}
			if (j > 2)
			{
				ghosts[i].direction = directionsavailable[rand() % j]; //change direction if more than 3 directions available
			}
			switch (ghosts[i].direction) //walk the same regardless of killable or not. minor. will address if time
			{
				case 0:
					if (is_walkable_space(adjustedy(ghosts[i].ycenter),adjustedx(ghosts[i].xcenter)+1))
					{
						ghosts[i].xcenter = ghosts[i].xcenter + ghosts[i].speed;
					}
					else if (!is_valid_space(adjustedy(pacy),adjustedx(pacx)+1))
					{
						ghosts[i].xcenter = boardx0 + 98;
					}
					else
					{
						ghosts[i].direction = directionsavailable[rand() % j]; 
					}
					break;
				case 1:
					if (is_walkable_space(adjustedy(ghosts[i].ycenter)-1,adjustedx(ghosts[i].xcenter)))
					{
						ghosts[i].ycenter = ghosts[i].ycenter - ghosts[i].speed;
					}
					else if (!is_valid_space(adjustedy(ghosts[i].ycenter)-1,adjustedx(ghosts[i].xcenter)))
					{
						ghosts[i].ycenter = boardy0 + 60 + 15*B_HEIGHT;
					}
					else
					{
						ghosts[i].direction = directionsavailable[rand() % j]; 
					}
					break;
				case 2:
					if (is_walkable_space(adjustedy(ghosts[i].ycenter),adjustedx(ghosts[i].xcenter)-1))
					{
						ghosts[i].xcenter = ghosts[i].xcenter - ghosts[i].speed;
					}
					else if (!is_valid_space(adjustedy(pacy),adjustedx(pacx)-1))
					{
						ghosts[i].xcenter = boardx0 + 98 + 15*B_WIDTH;
					}
					else
					{
						ghosts[i].direction = directionsavailable[rand() % j]; 
					}
					break;
				case 3:
					if (is_walkable_space(adjustedy(ghosts[i].ycenter)+1,adjustedx(ghosts[i].xcenter)))
					{
						ghosts[i].ycenter = ghosts[i].ycenter + ghosts[i].speed;
					}
					else if (!is_valid_space(adjustedy(pacy)+1,adjustedx(pacx)))
					{
						ghosts[i].ycenter = boardy0 + 60;
					}
					else
					{
						ghosts[i].direction = directionsavailable[rand() % j]; 
					}
					break;
				default:
					printf("Invalid direction passed.");
					break;
			}
		}
		
	}
}

int is_level_over()
{
	if (lives < 1) //Pacman dead
	{
		return 2;
	}
	int i, j;
	int sum;
	for (i=0;i<B_HEIGHT;i++)
	{
		for (j=0;j<B_WIDTH;j++)
		{
			sum+=food_board[i][j];
		}
	}
	if (!sum) //returns 1 if level food eaten
	{
		return 1;
	}
	return 0;
}

void game_cycle()
{
	while (!is_level_over())
	{
		int i;
		spawntimer++;
		if (spawntimer==(FPS * 7)) //every 7 seconds
		{
			spawn_ghost();
			spawntimer=0;
		}
		if (pacsupertimer) //every 7 seconds
		{
			pacsupertimer--;
			for (i=0;i<GhostNum;i++)
			{
				if (ghosts[i].inplay)
				{
					ghosts[i].killable = 1;
				}
			}
		}
		else
		{
			for (i=0;i<GhostNum;i++)
			{
				if (ghosts[i].inplay)
				{
					ghosts[i].killable = 0;
				}
			}
		}
		gfx_clear();
		draw_collision_board();
		draw_food_board();
		draw_UI_elements();
		draw_pacman(pacx, pacy, pacdirection);
		draw_ghosts();
		gfx_flush();
		if (gfx_event_waiting())
		{
			char c = gfx_wait();
			switch (c)
			{
				case 1:
					break;
				case 'p':
					pause();
					break;
				case 'q':
					if (debug)
					{
						exit(0);
					}
					break;
				case 'w':
					if (is_walkable_space(adjustedy(pacy)-1,adjustedx(pacx)))
					{
						pacdirection = 1;
					}
					pacnextdirection = 1;
					break;
				case 'a':
					if (is_walkable_space(adjustedy(pacy),adjustedx(pacx)-1))
					{
						pacdirection = 2;
					}
					pacnextdirection = 2;
					break;
				case 's':
					if (is_walkable_space(adjustedy(pacy)+1,adjustedx(pacx)))
					{
						pacdirection = 3;
					}
					pacnextdirection = 3;
					break;
				case 'd':
					if (is_walkable_space(adjustedy(pacy),adjustedx(pacx)+1))
					{
						pacdirection = 0;
					}
					pacnextdirection = 0;
					break;
				default:
					break;	
			}
		}
		usleep(1000000 / FPS); //Update FPS times per second
		move_pacman();
		move_ghosts();
	}
	switch(is_level_over())
	{
		case 1:
			gfx_color(0,255,0);
			draw_word("YOU WIN!", 40, 200, 30);
			break;
		case 2:		
			gfx_color(255,0,0);
			draw_word("GAME OVER", 40, 160, 30);;
			break;
		default:
			break;
	}
	gfx_color(255,255,255);
	MenuButton menu;
	menu.xcenter = 100;
	menu.ycenter = 240;
	menu.width = 160;
	menu.height = 25;
	menu.text = "go to menu";
	draw_menubutton(menu);	
	while (1)
	{
		if (gfx_event_waiting())
		{
			char c = gfx_wait();
			int x = gfx_xpos();
			int y = gfx_ypos();
			switch (c)
			{
				case 1:
					if ( (x > menu.xcenter-(menu.width)/2) && 
					(x < menu.xcenter+ (menu.width)/2) && 
					(y > menu.ycenter-(menu.height)/2) && 
					(y < menu.ycenter+(menu.height)/2) )
					{
						open_menu();
					}
					break;
				default:
					break;
			}
		}
	}
}

void reset_pacman_position()
{
	pacx = boardx0+W_HEIGHT/2;
	pacy = W_HEIGHT / 2+15;
}

void new_game(char *levelcollision, char *levelfood)
{
	gfx_clear();
	score = 0;
	sprintf(scoretext,"Score: %d", score);
	//hiscore?
	lives = 3;
	sprintf(livestext,"Lives: %d", lives);
	get_data(levelcollision, collision_board);
	get_data(levelfood, food_board);
	reset_pacman_position();
	int i;

	ghosts[0].rcolor=255;
	ghosts[0].gcolor=182;
	ghosts[0].bcolor=193;
	ghosts[1].rcolor=173;
	ghosts[1].gcolor=216;
	ghosts[1].bcolor=230;
	ghosts[2].rcolor=238;
	ghosts[2].gcolor=221;
	ghosts[2].bcolor=130;
	ghosts[3].rcolor=255;
	ghosts[3].gcolor=0;
	ghosts[3].bcolor=0;

	spawntimer = 0;

	for (i=0;i<GhostNum;i++)
	{
		ghosts[i].xcenter = boardx0+265+25*i;
		ghosts[i].ycenter = W_HEIGHT/2-25;
		ghosts[i].alive = 1;
		ghosts[i].inplay = 0;
		ghosts[i].killable = 0;
		ghosts[i].direction = 0;
		ghosts[i].speed = 9;
	}
	if (debug)
	{
		printf("(%d, %d)", adjustedx(pacx), adjustedy(pacy));
	}
	game_cycle();
	
}

void menu_click(int x, int y)
{
	int i;
	for (i=0; i<2; i++)
	{
		if ( (x > menuButtons[i].xcenter-(menuButtons[i].width)/2) && 
		(x < menuButtons[i].xcenter+ (menuButtons[i].width)/2) && 
		(y > menuButtons[i].ycenter-(menuButtons[i].height)/2) && 
		(y < menuButtons[i].ycenter+(menuButtons[i].height)/2) )
		{
			switch (i)
			{
				case 0:
					new_game("level1collision.dat","level1food.dat");
					break;
				case 1:
					exit(0);
					break;
				default:
					break;
			}
		}

	}

}

void open_menu()
{
	gfx_clear();
	gfx_color(0,255,0);
	menuButtons[0].xcenter = W_WIDTH / 2;
	menuButtons[0].ycenter = W_HEIGHT - 200;
	menuButtons[0].width = 100;
	menuButtons[0].height = 30;
	menuButtons[0].text = "start";
	draw_menubutton(menuButtons[0]);

	gfx_color(255,0,0);
	menuButtons[1].xcenter = W_WIDTH / 2;
	menuButtons[1].ycenter = W_HEIGHT - 140;
	menuButtons[1].width = 100;
	menuButtons[1].height = 30;
	menuButtons[1].text = "quit";
	draw_menubutton(menuButtons[1]);
	
	gfx_color(255,255,0);
	draw_word("PAC MAN",100,200,150);
	gfx_color(255,255,255);
	
	while (1)
	{
		if (gfx_event_waiting())
		{
			char c = gfx_wait();
			switch (c)
			{
				case 1:
					menu_click(gfx_xpos(),gfx_ypos());
					break;
				default:
					break;	
			}
		}
		usleep(1000000 / FPS); //Update FPS times per second
	}
}

int main(int argc, char *argv[])
{	
	gfx_open(W_WIDTH,W_HEIGHT,"PAC-MAN");
	open_menu();
}
