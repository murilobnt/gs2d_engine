// File: threaded_level_loader.hpp
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

#ifndef FOX_THREADED_LEVEL_LOADER_HPP_
#define FOX_THREADED_LEVEL_LOADER_HPP_

#include <thread>

#include "foxer/app/level.hpp"

namespace fox {

// ThreadedLevelLoader is a class that allows one to load a level using threads.
// That's why the load() method of Level might sound the same as the
// constructor. However, the constructor is called once any level is created,
// while load() can be called inside the run() method of this class.

class ThreadedLevelLoader {
public:
  // Destructor.
  ~ThreadedLevelLoader();

  // Loads a level and stores it.
  void run(std::shared_ptr<Level> level);

  // Getter for the reference of a loaded level.
  std::shared_ptr<Level> get_level();

private:
  // Loaded level reference.
  std::shared_ptr<Level> level;

  // Thread to load a level.
  std::thread level_loader;

  // Method that is passed to the thread. Calls level->load();
  void load_level();
};

} // namespace fox

#endif
