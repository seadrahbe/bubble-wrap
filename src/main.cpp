#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>


int main() {
    bn::core::init();
    bn::backdrop::set_color(bn::color(28, 10, 17));

    if (bn::keypad::a_pressed()) {
    bn::backdrop::set_color(bn::color(5, 5, 5));
  }

    while(true) {

      if (bn::keypad::a_pressed()) {
        bn::backdrop::set_color(bn::color(5, 5, 5));
      }

      if (bn::keypad::b_pressed()) {
          bn::backdrop::set_color(bn::color(20, 0, 3));
      }

      bn::core::update();
    }
}
