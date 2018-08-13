// File: tile_grid.hpp
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

#ifndef TILE_GRID_HPP
#define TILE_GRID_HPP

// # External
#include <vector>
#include <cmath>

// # Internal
#include "gs2d_engine/assist/tile.hpp"
#include "gs2d_engine/assist/generic_grid.hpp"

struct Unity {

public:
    std::vector<Tile> tiles;

};

class TileGrid : public GenericGrid {

private:
    std::vector<Unity> unities;
    sf::Vector2i checkBoundaries(sf::Vector2i before) const;

public:
    TileGrid();

    TileGrid(int w, int h, int unity_size);

    Unity* getUnity(int x, int y);

    void addTile(Tile tile);

    std::vector<Unity> getUnitiesOnPosition(sf::Vector2f sprite_upper_left) const;

};

#endif