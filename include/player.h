#include <SFML/Graphics.hpp>

#ifndef PLAYER_H
#define PLAYER_H

#define P_RAD 10.0f
#define P_COLOR sf::Color::Red

class Player{
private:

  int x;
  int y;
  sf::Color color = P_COLOR;
  sf::RenderWindow *window;
  float radius;

  void draw();
public:
  Player(sf::RenderWindow *window, int x, int y, float rad=P_RAD);
  ~Player();
  void update();
};



#endif
