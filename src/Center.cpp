#include "Center.h"
#include "movement.h"
#include "bn_sprite_items_square.h"

Center::Center(bn::fixed_point starting_position, bn::fixed mass, bn::fixed speed) : 
            _sprite(bn::sprite_items::square.create_sprite(starting_position)),
            _mass(mass),
            _speed(speed) {
        }

bn::fixed_point Center::position() {
    return _sprite.position();
}

void Center::update() {
    dPadMoveSprite(_sprite, _speed);
}

bn::fixed Center::mass() {
    return _mass;
}