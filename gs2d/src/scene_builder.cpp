#include "gs2d_engine/scene/scene_builder.hpp"
#include "gs2d_engine/scene/scene.hpp"

namespace gs {

void SceneBuilder::build_scene(Scene *scene,
                               SceneProxy *scene_proxy,
                               sf::RenderWindow *app_window,
                               ClockHandler *app_clock) {
   scene->set_scene_proxy(scene_proxy);
   scene->set_app_window(app_window);
   scene->set_app_clock(app_clock);
}

}
