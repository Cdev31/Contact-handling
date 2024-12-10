#include <ncurses.h>
#include <iostream>

#include "screens/contact_screen.cpp"

int main(){
    initscr();
    curs_set(0);
    cbreak();

    contactScreen();


    endwin();

}