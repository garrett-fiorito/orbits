#include "movement.h"
#include <bn_keypad.h>

/**
 * Moves sprite up/down/left/right based on the d-pad being held.
 * 
 * Dimensions are moved independently, meaning that diagonal motion is faster than moving in one
 * dimension.
 * 
 * @param sprite the sprite to move
 * @param speed the speed at which to move the sprite in each dimension
 */
void dPadMoveSprite(bn::sprite_ptr& sprite, bn::fixed speed) {
    bn::fixed dx = 0;
    bn::fixed dy = 0;

    if(bn::keypad::left_held()) {
        dx -= speed;
    }
    if(bn::keypad::right_held()) {
        dx += speed;
    }
    if(bn::keypad::up_held()) {
        dy -= speed;
    }
    if(bn::keypad::down_held()) {
        dy += speed;
    }

    sprite.set_position(sprite.position() + bn::fixed_point(dx, dy));
}