#include <array>
#include <cstdint>
#include <ncurses.h>

static int current_player = 1;

void draw_board(int row, int col) {
  clear();
  mvprintw(0, 0, "BitBoard: Tic-Tac-Toe");

  const int top = 2;
  const int left = 0;
  const int cell_width = 4;
  const int cell_hight = 2;

  // Horizontal lines
  for (int i = 0; i <= 3; i++) {
    int y = top + i * cell_hight;
    mvhline(y, left, ACS_HLINE, cell_width * 3 + 1);
  }

  // Vertical lines
  for (int i = 0; i <= 3; i++) {
    int x = left + i * cell_width;
    mvvline(top, x, ACS_VLINE, cell_hight * 3 + 1);
  }

  int status_y = top + cell_hight * 3 + 1;
  mvprintw(status_y, 0, "Player %d's turn (Press q to quit)", current_player);

  int curs_y = top + row * cell_hight + 1;
  int curs_x = left + col * cell_width + 2;
  move(curs_y, curs_x);
  refresh();
}

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  int row = 0;
  int col = 0;
  int game_status = 1;

  while (true) {
    draw_board(row, col);
    int ch = getch();

    if (ch == 'q')
      break;
  }

  draw_board(row, col);
  if (game_status < 0)
    mvprintw(0, 0, "Player %d wins! \nPress any key to exit.", game_status);
  else
    mvprintw(9, 0, "Game Draw! \nPress any key to exit.");
  getch();
  endwin();
  return 0;
}
