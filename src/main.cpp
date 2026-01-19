#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>



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

  bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(-40, 40);
  bn::sprite_ptr myCircle2 = bn::sprite_items::dot.create_sprite(-30, 40);
  bn::sprite_ptr myCircle3 = bn::sprite_items::dot.create_sprite(-20, 40);
  bn::sprite_ptr myCircle4 = bn::sprite_items::dot.create_sprite(-10, 40);
  bn::sprite_ptr myCircle5 = bn::sprite_items::dot.create_sprite(0, 40);
  bn::sprite_ptr myCircle6 = bn::sprite_items::dot.create_sprite(10, 40);
  bn::sprite_ptr myCircle7 = bn::sprite_items::dot.create_sprite(20, 40);
  bn::sprite_ptr myCircle8 = bn::sprite_items::dot.create_sprite(30, 40);
  bn::sprite_ptr myCircle9 = bn::sprite_items::dot.create_sprite(40, 40);


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
