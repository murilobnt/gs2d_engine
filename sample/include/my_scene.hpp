// File: my_scene.hpp
// Author: Murilo Bento
//
// MIT License
//
// Copyright (c) 2018-2020 Murilo Bento
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef MY_SCENE_HPP_
#define MY_SCENE_HPP_

#include <SFML/Graphics.hpp>
#include <foxer/app.hpp>
#include <foxer/logical.hpp>
#include <foxer/time.hpp>

#include "character.hpp"
#include "level_one.hpp"
#include "level_two.hpp"

class MyScene : public fox::Scene {
public:
  MyScene();
  void start();
  void update();
  void draw_entities();

private:
  const float delta_time;

  fox::TimeHandler physics_rate;
  Character character;
  fox::LevelBundle bundle;

  fox::Textbox textbox;
  sf::Font font;
  float y_scale;
};

#endif
