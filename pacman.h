#define W_WIDTH 800
#define W_HEIGHT 600

#define B_WIDTH 28
#define B_HEIGHT 31

#define FPS 10

#define GhostNum 4

//returns adjusted x value in array for position of pacman (column)
int adjustedx(int x);

//returns adjusted y value in array for position of pacman (row)
int adjustedy(int y);

//Opens main menu
void open_menu();

//Processes menu clicks
void menu_click(int x, int y);

//Starts a new game
void new_game(char *levelcollision, char *levelfood);

//update cycle for game
void game_cycle();

//Pauses game
void pause();

//Draws text outside of game in window
void draw_UI_elements();

//Reads and processes level data (food or collision) from file
void get_data( char *s, int b[B_HEIGHT][B_WIDTH] );

//Prints game board (collision or food)
void print_board( int b[B_HEIGHT][B_WIDTH] );

//Spawns a ghost based on current game situation
void spawn_ghost();

//Moves ghosts in game
void move_ghosts();

//Resets pacman's position when game starts / after death
void reset_pacman_position();

//calculates whether the level is done or not. returns 1 if all food was eaten; returns 2 if pacman dead
int is_level_over();

//Draws ghosts on screen
void draw_ghosts();

//Draws food
void draw_food_board();

//Draws borders
void draw_collision_board();

//returns 1 if a space is walkable (no borders)
int is_walkable_space(int x, int y);

//returns 1 if a space on the board is valid
int is_valid_space( int x, int y);

//Main
int main(int argc, char * argv[]);

