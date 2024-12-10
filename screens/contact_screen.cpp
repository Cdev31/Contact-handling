#include <ncurses.h>


void contactScreen(){
    start_color();

    int maxHorizontalSize =0, maxVerticalSize = 0;

    getmaxyx( stdscr, maxHorizontalSize, maxVerticalSize);

    WINDOW* contactWindow = newwin( maxHorizontalSize, maxVerticalSize, 0, 0 );
    box( contactWindow, 0, 0);


   mvwprintw(contactWindow, 20, 70, "Q para salir");


   wgetch( contactWindow) ;

   resize_term( maxHorizontalSize, maxVerticalSize );

}