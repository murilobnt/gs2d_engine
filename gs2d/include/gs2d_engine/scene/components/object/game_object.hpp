#ifndef GS_GAME_OBJECT_HPP
#define GS_GAME_OBJECT_HPP

#include <SFML/Graphics.hpp>

#include "gs2d_engine/scene/components/graphic/sprited_entity.hpp"
#include "gs2d_engine/scene/components/object/movable_object.hpp"

namespace gs {

class GameObject : public SpritedEntity, public MovableObject {
public:
    GameObject(sf::Texture const &texture, sf::Vector2i sprite_pos_at_tex,
                  sf::Vector2i sprite_dimensions);

    GameObject();

    virtual void move(float delta_time) = 0;
    virtual void move() = 0;
};

}

#endif