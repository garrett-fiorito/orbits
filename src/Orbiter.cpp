#include "Orbiter.h"
#include "bn_sprite_items_dot.h"

// A scaling factor by which to reduce the force applied when orbiting.
// Important for numerical stability.
static constexpr bn::fixed FORCE_SCALE = 10;

Orbiter::Orbiter(bn::fixed_point starting_location,
                 bn::fixed_point starting_velocity,
                 Center& center) :
    _sprite(bn::sprite_items::dot.create_sprite(starting_location)),
    _velocity(starting_velocity),
    _center(center) {
}

void Orbiter::update() {
    // A vector from the Orbiter to the Center.
    bn::fixed_point delta = _center.position() - _sprite.position();

    // Apply the mass and scaling separately to preserve fixed point precision.
    bn::fixed_point force = delta * _center.mass();
    force /= FORCE_SCALE;

    // Update velocity and position.
    _velocity += force;
    _sprite.set_position(_sprite.position() + _velocity);
}