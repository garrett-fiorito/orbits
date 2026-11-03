#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_fixed_point.h>
#include <bn_vector.h>

#include "Center.h"
#include "Orbiter.h"

// Maximum number of orbiters allowed on the screen
static constexpr int MAX_ORBITERS = 30;

// Default starting posiiton and velocity for Orbiter
static constexpr bn::fixed_point ORBITER_START_POSIITON = {0, 0};
static constexpr bn::fixed_point ORBITER_START_VELOCITY = {0, 5};

// How much each L or R press changes the attraction.
static constexpr bn::fixed MASS_STEP = 0.01;

int main() {
    bn::core::init();

    Center center = Center({30, 40}, .05, 2);
    bn::vector<Orbiter, MAX_ORBITERS> orbiters = {};
    
    while(true) {
        // Add an orbiter when A is pressed if there's room
        if(bn::keypad::a_pressed()) {
            if(orbiters.size() < MAX_ORBITERS) {
                orbiters.push_back(Orbiter(ORBITER_START_POSIITON, ORBITER_START_VELOCITY, center));
            }
        }

        // Remove an orbiter when B is pressed if there's at least one
        if (bn::keypad::b_pressed()) {
            if(orbiters.size() > 0) {
                orbiters.pop_back();
            }
        }

        // L decreases attraction; R increases attraction.
        if(bn::keypad::l_pressed()) {
            center.set_mass(center.mass() - MASS_STEP);
        }
        else if(bn::keypad::r_pressed()) {
            center.set_mass(center.mass() + MASS_STEP);
        }

        center.update();
        for(Orbiter& orbiter : orbiters) {
            orbiter.update();
        }

        bn::core::update();
    }
}