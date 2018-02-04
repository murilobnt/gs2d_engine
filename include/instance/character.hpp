// File: character.hpp
// Author: Murilo Bento
//
// MIT License
//
// Copyright (c) 2018 Murilo Bento
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include <SFML/Graphics.hpp>

#include "gamesimple/components/animatedentity.hpp"
#include "gamesimple/components/controlableentity.hpp"
#include "gamesimple/components/spritedentity.hpp"
#include "gamesimple/concrete/timehandler.hpp"
#include "instance/facingposition.hpp"

class Character : public AnimatedEntity, public ControlableEntity {
private:
  sf::Vector2f movement;
  TimeHandler animationTimeHandler;
  FacingPosition lastFacingPosition;
  bool facingUp;
  bool facingDown;
  bool facingLeft;
  bool facingRight;

public:
  Character(sf::Texture const &texture, int spriteX, int spriteY, int spriteW,
            int spriteH, int spriteInitX, int spriteEndX, int spriteInitY,
            int spriteEndY, int animationFramesPerSeconds);
  Character();
  void controlEntity(sf::Keyboard::Key key, bool release);
  void moveCharacter();
  void animate();
};

#endif