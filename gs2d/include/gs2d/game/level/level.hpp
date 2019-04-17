// File: level.hpp
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

#ifndef GS_LEVEL_HPP
#define GS_LEVEL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "gs2d/game/level/collision_map.hpp"
#include "gs2d/game/level/layer_container.hpp"
#include "gs2d/game/level/level_proxy.hpp"
#include "gs2d/game/level/tilemap.hpp"

namespace gs {

class Level : public sf::Drawable {
protected:
  LevelProxy *level_proxy;

  sf::Vector2u tile_size;
  sf::Vector2u level_size;

  std::vector<TileMap> layers;
  CollisionMap collision_map;

  TileMap get_layer(int index) const;
  LayerContainer get_layers(int from, int to) const;
  LayerContainer get_layers() const;

  virtual void draw(sf::RenderTarget &target,
                    sf::RenderStates states) const = 0;

public:
  virtual void load() = 0;
  virtual void init() = 0;
  virtual void handle_events(const float &delta_time) = 0;
  void set_level_proxy(LevelProxy *level_proxy);
  void change_level(Level *level);
  void change_level(std::shared_ptr<Level> level);
};

} // namespace gs

#endif