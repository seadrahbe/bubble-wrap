#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>
#include <bn_log.h>
#include <bn_vector.h>


int main() {
    bn::core::init();
    bn::backdrop::set_color(bn::color(28, 10, 17));

    // Sprite art

    // bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(50, 40);
    // bn::sprite_ptr myCircle2 = bn::sprite_items::dot.create_sprite(-50, 40);
    // bn::sprite_ptr myCircle3 = bn::sprite_items::dot.create_sprite(50, -40);
    // bn::sprite_ptr myCircle4 = bn::sprite_items::dot.create_sprite(-50, -40);
    // bn::sprite_ptr myCircle5 = bn::sprite_items::dot.create_sprite(25, 20);
    // bn::sprite_ptr myCircle6 = bn::sprite_items::dot.create_sprite(-25, -20);
    // bn::sprite_ptr myCircle7 = bn::sprite_items::dot.create_sprite(0, 0);

    // Brute force

    // bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(-40, 40);
    // bn::sprite_ptr myCircle2 = bn::sprite_items::dot.create_sprite(-30, 40);
    // bn::sprite_ptr myCircle3 = bn::sprite_items::dot.create_sprite(-20, 40);
    // bn::sprite_ptr myCircle4 = bn::sprite_items::dot.create_sprite(-10, 40);
    // bn::sprite_ptr myCircle5 = bn::sprite_items::dot.create_sprite(0, 40);
    // bn::sprite_ptr myCircle6 = bn::sprite_items::dot.create_sprite(10, 40);
    // bn::sprite_ptr myCircle7 = bn::sprite_items::dot.create_sprite(20, 40);
    // bn::sprite_ptr myCircle8 = bn::sprite_items::dot.create_sprite(30, 40);
    // bn::sprite_ptr myCircle9 = bn::sprite_items::dot.create_sprite(40, 40);

    // For loop #1

    // Vector to hold sprites
    bn::vector<bn::sprite_ptr, 10> circles = {};

    int y = -40;
    int count = 0;

    for(int x = -40; x <= 40; x += 10) {
      BN_LOG("x value", x);
      count++;

      int c = x - 10;
      if (count == 2) {
          circles.push_back(bn::sprite_items::dot.create_sprite(c, y));
          count = 0;
      } else {
          circles.push_back(bn::sprite_items::dot.create_sprite(x, y));
      }

      y += 10;

    }

    if (bn::keypad::a_pressed()) {
      bn::backdrop::set_color(bn::color(5, 5, 5));
    }
  

    while(true) {

      bn::backdrop::set_color(bn::color(28, 10, 17));

      if (bn::keypad::a_held()) {
        bn::backdrop::set_color(bn::color(5, 5, 5));
      }

      if (bn::keypad::b_held()) {
          bn::backdrop::set_color(bn::color(20, 0, 3));
      }

      bn::core::update();
    }
}
