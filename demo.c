#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

#define DELAY 60000

int main(int argc, char *argv[]) {
   int x,y = 0;
   int max_y,max_x = 0;
   int next_x,next_y = 0;
   int dx = 1;
   int dy = 1;

   initscr();
   noecho();
   curs_set(FALSE);

   while(1) 
   {
      clear();
      mvprintw(y, x, "o");
      refresh();

      getmaxyx(stdscr, max_y, max_x);

      usleep(DELAY);

      next_x = x + dx;
      next_y = y + dy;

      if (next_x >= max_x || next_x < 0) {
         dx*=-1;
      } else if (next_y >= max_y || next_y < 0) {
         dy*=-1;
      } else {
         x+=dx;
         y+=dy;
      }
   }
   endwin(); // Restore normal Terminal behaviour.
}
