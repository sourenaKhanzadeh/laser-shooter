#include <iostream>

// GAMEOBJECT
#include "include/gameObject.h"

// Player Object
#include "include/player.h"

using namespace sf;

// Prototypes
void handleEvents(RenderWindow *window);
///////////////////////////////////////


int main(){
  // Create the window
  VideoMode vm(SCREEN_W, SCREEN_H);
  RenderWindow window(vm, TITLE);

  // Player
  Player *p = new Player(&window, 0, 0);


  // mainloop
  while (window.isOpen()){
      // get events
      handleEvents(&window);

      window.clear();

      if(p != NULL)
        p->update();



      window.display();



  }
  return EXIT_SUCCESS;
}


void handleEvents(RenderWindow *window){
  /**
  * Handle User inputs and events
  **/
  if( Key(Escape))
    window->close();


  Event ev;
  while (window->pollEvent(ev)){
      if(ev.type == Event::Closed)
          window->close();
  }


}
