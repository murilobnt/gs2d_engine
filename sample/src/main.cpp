#include "gs2d/core.hpp"
#include "my_scene.hpp"
#include <X11/Xlib.h>

int main() {
  XInitThreads();
  gs::App app(480, 320, "GS2D Game Sample");
  app.app_start(new MyScene(), false, false);
}
