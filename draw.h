#include <string.h>

typedef struct MenuButton
{
	int xcenter;
	int ycenter;
	int width;
	int height;
	char *text;
} MenuButton;

typedef struct Ghost
{
	int xcenter;
	int ycenter;
	int rcolor;
	int gcolor;
	int bcolor;

	int alive;
	int inplay;
	int killable;

	int speed;
	int direction;
	
} Ghost;

/*Draw number 1*/
void draw_one(int x, int y, int height);

/*Draw number 2*/
void draw_two(int x, int y, int height);

/*Draw number 3*/
void draw_three(int x, int y, int height);

/*Draw number 4*/
void draw_four(int x, int y, int height);

/*Draw number 5*/
void draw_five(int x, int y, int height);

/*Draw number 6*/
void draw_six(int x, int y, int height);

/*Draw number 7*/
void draw_seven(int x, int y, int height);

/*Draw number 8*/
void draw_eight(int x, int y, int height);

/*Draw number 9*/
void draw_nine(int x, int y, int height);

/*Draw number 0*/
void draw_zero(int x, int y, int height);

/*Draw letter A*/
void draw_A(int x, int y, int height);

/*Draw letter B*/
void draw_B(int x, int y, int height);

/*Draw letter C*/
void draw_C(int x, int y, int height);

/*Draw letter D*/
void draw_D(int x, int y, int height);

/*Draw letter E*/
void draw_E(int x, int y, int height);

/*Draw letter F*/
void draw_F(int x, int y, int height);

/*Draw letter G*/
void draw_G(int x, int y, int height);

/*Draw letter H*/
void draw_H(int x, int y, int height);

/*Draw letter I*/
void draw_I(int x, int y, int height);

/*Draw letter J*/
void draw_J(int x, int y, int height);

/*Draw letter K*/
void draw_K(int x, int y, int height);

/*Draw letter L*/
void draw_L(int x, int y, int height);

/*Draw letter M*/
void draw_M(int x, int y, int height);

/*Draw letter N*/
void draw_N(int x, int y, int height);

/*Draw letter O*/
void draw_O(int x, int y, int height);

/*Draw letter P*/
void draw_P(int x, int y, int height);

/*Draw letter Q*/
void draw_Q(int x, int y, int height);

/*Draw letter R*/
void draw_R(int x, int y, int height);

/*Draw letter S*/
void draw_S(int x, int y, int height);

/*Draw letter T*/
void draw_T(int x, int y, int height);

/*Draw letter U*/
void draw_U(int x, int y, int height);

/*Draw letter V*/
void draw_V(int x, int y, int height);

/*Draw letter W*/
void draw_W(int x, int y, int height);

/*Draw letter X*/
void draw_X(int x, int y, int height);

/*Draw letter Y*/
void draw_Y(int x, int y, int height);

/*Draw letter Z*/
void draw_Z(int x, int y, int height);

/*Draw colon*/
void draw_Z(int x, int y, int height);

/*Draw letter using other functions*/
void draw_letter (char c, int x, int y, int height);

/*Draws a square at x,y with width w*/
void draw_square(int x, int y, int w);

/*draw word s starting at position x centered vertically at y with letter height 'height' (proportional width)*/
void draw_word(char *s, int x, int y, int height);

/*draw menubutton using other functions and struct*/
void draw_menubutton(MenuButton m);

/*Draw yellow pacman at x, y, facing theta direction*/
void draw_pacman(int x, int y, int theta);

/*Draws a piece of food at x, y of type "type"*/
void draw_food(int type, int x, int y);

/*Draws a given type of border at x, y with size r*/
void draw_collision_border(int type, int x, int y, int r);

/*Draw circle at center with given radius*/
void draw_circle(int x, int y, int r);

/*Draw menubutton*/
void draw_menubutton(MenuButton m);

