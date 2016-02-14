#include <iostream>
#include "gl.hpp"
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <ncurses.h>
#include "crosshair.hpp"

using namespace std;

int main() {

  crosshair x;

  initscr();
  noecho();
  int ch;
  nodelay(stdscr, TRUE);

  //x.scale(10);
  x.setX(500);
  x.setY(500);

  x.draw_stroke(0xffffffff);
  canvas::get_instance() ->render();

  while(true) {

      if ((ch = getch()) == ERR) {
        // user hasn't responded
        x.draw_stroke(0xffffffff);
        canvas::get_instance() ->render();
        canvas::get_instance()->clear();  
      }
         else {
          //user has pressed a key ch
          switch(ch) {
            case 65:    // key up
                x.moveY(-10);
                x.draw_stroke(0xffffffff);
                canvas::get_instance() ->render();
                canvas::get_instance()->clear();  
                break;
            case 66:    // key down
                x.moveY(10);
                x.draw_stroke(0xffffffff);
                canvas::get_instance() ->render();
                canvas::get_instance()->clear();              
                break;
            case 67:    // key right
                x.moveX(10);
                x.draw_stroke(0xffffffff);
                canvas::get_instance() ->render();
                canvas::get_instance()->clear();  
                break;
            case 68:    // key left
                x.moveX(-10);
                x.draw_stroke(0xffffffff);
                canvas::get_instance() ->render();
                canvas::get_instance()->clear();  
                  //clear(vinfo.xres, vinfo.yres);
                break;
            default:
                break;
            }
          }

    
  }
  return 0;
}