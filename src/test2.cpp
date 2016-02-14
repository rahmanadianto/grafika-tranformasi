#include <iostream>
#include "gl.hpp"
#include <ncurses.h>
#include "crosshair.hpp"

using namespace std;

int main() {

  crosshair x;

  /*initscr();
  noecho();
  int ch;
  nodelay(stdscr, TRUE);*/

  x.setX(500);
  x.setY(500);

  cout << x.x_pos;
  cout << x.y_pos;

  x.draw_stroke(0xffffffff);
  canvas::get_instance() ->render();

  /*while(true) {

      if ((ch = getch()) == ERR) {
              // user hasn't responded
      }
         else {
          //user has pressed a key ch
          switch(ch) {
            case 65:    // key up
                
                break;
            case 66:    // key down
            
                break;
            case 67:    // key right
                
                break;
            case 68:    // key left
                
                  //clear(vinfo.xres, vinfo.yres);
                break;
            default:
                break;
            }
          }

    
  }*/
  return 0;
}