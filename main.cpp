#include <iostream>
#include <SFML/Graphics.hpp>

#define SCREEN_W 600
#define SCREEN_H 600
#define TITLE "Squad"

using namespace sf;


void handleEvents(RenderWindow *window);

int main(){
  // Create the window
  VideoMode vm(SCREEN_W, SCREEN_H);
  RenderWindow window(vm, TITLE);



  // mainloop
  while (window.isOpen()){
      // get events
      handleEvents(&window);


  }
  return 0;
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
