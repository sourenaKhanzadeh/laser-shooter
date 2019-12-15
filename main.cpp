#include <iostream>

// GAMEOBJECT
#include "include/stage.h"

using namespace sf;

// Prototypes
void handleEvents(RenderWindow *window);
///////////////////////////////////////


int main(){
  // randomness
  srand(time(NULL));

  // Create the window
  VideoMode vm(SCREEN_W, SCREEN_H);
  RenderWindow window(vm, TITLE);
  //SET  FramerateLimit
  window.setFramerateLimit(FPS);

  // Create a stage
  Stage stage(&window);

  // mainloop
  while (window.isOpen()){
      // get events
      handleEvents(&window);

      window.clear();
      stage.update();
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
