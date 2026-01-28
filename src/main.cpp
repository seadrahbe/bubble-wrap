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

    // Vector for affine matts error
    // bn::vector<bn::sprite_ptr, 41> circlesTest = {};

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

    // Affine mats error example

    // for(int x = -40; x <= 40; x += 2) {
    //   BN_LOG("x value", x);
    //   count++;

    //   int c = x - 2;
    //   if (count == 2) {
    //       circlesTest.push_back(bn::sprite_items::dot.create_sprite(c, y));
    //       count = 0;
    //   } else {
    //       circlesTest.push_back(bn::sprite_items::dot.create_sprite(x, y));
    //   }

    //   y += 2;

    // }

    // Affine mats error
    // for(int x = 0; x < 40; x++){
    //   circlesTest[x].set_scale(0.1);
    // }

    // Set testing
    circles[0].set_scale(1.8);
    circles[0].set_horizontal_scale(1.7);
    circles[1].set_scale(0.4);
    circles[1].set_vertical_scale(1.7);
    circles[2].set_scale(.8);
    circles[2].set_mosaic_enabled(true);
    circles[3].set_scale(2.0);
    circles[3].set_shear(1.3);
    circles[4].set_scale(0.6);
    circles[4].set_vertical_flip(2.4);
    circles[5].set_blending_enabled(true);
    circles[6].set_visible(false);
    circles[7].set_top_left_x(20);
    circles[8].set_horizontal_shear(2.3);

    

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
