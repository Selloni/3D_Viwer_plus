#include "s21_facade.h"

bool s21::Facade::set_path(std::string str) {
//  free();
  bool flag = controller_.set_path_file(str);
  if (!flag) controller_.open(str);
  return flag;  // 0 success
}

// void s21::Facade::fmove(s21::Strategy &move, double offset, char direction) {
//   move.s21_move(&controller_.obj.vertexes, offset, controller_.obj.count_vert * 3, direction);
// }

void s21::Facade::test_scale(double scale) {     
  if (scale == 0.0) return;
  for (unsigned int i = 0; i < get_count_vertex() * 3; ++i) {
    get_arr_vertex()[i] *= scale;
  }
}

void s21::Facade::test_rotate(double scale, char direction) {
  double temp_x = 0.0;
  double temp_y = 0.0;
  double temp_z = 0.0;
  switch (direction) {
    case 'x':
      for (unsigned int i = 0; i < get_count_vertex() * 3; i += 3) {
        temp_x = get_arr_vertex()[i];
        temp_y = get_arr_vertex()[i + 1];
        temp_z = get_arr_vertex()[i + 2];

        get_arr_vertex()[i] = temp_x;
        get_arr_vertex()[i + 1] = cos(scale) * temp_y - sin(scale) * temp_z;
        get_arr_vertex()[i + 2] = sin(scale) * temp_y + cos(scale) * temp_z;
      }
      break;
    case 'y':
      for (unsigned int i = 0; i < get_count_vertex() * 3; i += 3) {
        temp_x = get_arr_vertex()[i];
        temp_y = get_arr_vertex()[i + 1];
        temp_z = get_arr_vertex()[i + 2];

        get_arr_vertex()[i] = cos(scale) * temp_x + sin(scale) * temp_z;
        get_arr_vertex()[i + 1] = temp_y;
        get_arr_vertex()[i + 2] = -sin(scale) * temp_x + cos(scale) * temp_z;
      }
      break;
    case 'z':
      for (unsigned int i = 0; i < get_count_vertex() * 3; i += 3) {
        temp_x = get_arr_vertex()[i];
        temp_y = get_arr_vertex()[i + 1];
        temp_z = get_arr_vertex()[i + 2];

        get_arr_vertex()[i] = cos(scale) * temp_x - sin(scale) * temp_y;
        get_arr_vertex()[i + 1] = sin(scale) * temp_x + cos(scale) * temp_y;
        get_arr_vertex()[i + 2] = temp_z;
      }
      break;
  }
}

void s21::Facade::test_move(double scale, char direction) {
  static double diff = 0;
  unit i;
  i = (direction == 'x') ? 0 : ((direction == 'y') ? 1 : ((direction == 'z') ? 2 : 0));
  for (i = 0; i < get_count_vertex() * 3; i += 3) get_arr_vertex()[i] += scale - diff;
  diff = scale;
}

void s21::Facade::free(){
  controller_.free();
}
