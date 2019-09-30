#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <foxer/scene_components.hpp>
#include <iostream>

#include "facing_position.hpp"

class Character : public fox::MainObject {
private:
  FacingPosition current_facing_pos;
  bool do_animate;

public:
  Character(sf::Texture const &texture,
            sf::Vector2f position = sf::Vector2f(0, 0));
  Character();
  void control_entity(float delta_time);
  void move(float delta_time);
  void move();
  void animate();
};

#endif
