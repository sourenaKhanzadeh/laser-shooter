#include <iostream>
#include <SFML/Graphics.hpp>
#include "include/player.h"

#define SCREEN_W 600
#define SCREEN_H 600
#define TITLE "Squad"

using namespace sf;

// Prototypes
void handleEvents(RenderWindow *window);
///////////////////////////////////////


int main(){
  // Create the window
  VideoMode vm(SCREEN_W, SCREEN_H);
  RenderWindow window(vm, TITLE);

  // Player
  Player *p = new Player(&window, 10, 10);


  // mainloop
  while (window.isOpen()){
      // get events
      handleEvents(&window);

      window.clear();

      p->update();

      window.display();

  }
  return EXIT_SUCCESS;
}


void handleEvents(RenderWindow *window){
  /**
  * Handle User inputs and events
  **/
  if(Keyboard::isKeyPressed(Keyboard::Escape))
    window->close();

  Event ev;
  while (window->pollEvent(ev)){
      if(ev.type == Event::Closed)
          window->close();
  }


}
