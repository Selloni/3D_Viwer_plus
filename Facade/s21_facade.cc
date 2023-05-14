#include "s21_facade.h"

bool s21::Facade::SetPath(std::string str) {
//  free();
  bool flag = controller_.set_path_file(str);
  if (!flag) controller_.open(str);
  return flag;  // 0 success
}

// void s21::Facade::fmove(s21::Strategy &move, double offset, char direction) {
//   move.s21_move(&controller_.obj.vertexes, offset, controller_.obj.count_vert * 3, direction);
// }

void s21::Facade::Scale(double scale) {     
  if (scale == 0.0) return;
  for (unsigned int i = 0; i < GetCountVertex() * 3; ++i) {
    GetArrVertex()[i] *= scale;
  }
}

void s21::Facade::Rotate(double scale, char direction) {
  double temp_x = 0.0;
  double temp_y = 0.0;
  double temp_z = 0.0;
  switch (direction) {
    case 'x':
      for (unsigned int i = 0; i < GetCountVertex() * 3; i += 3) {
        temp_x = GetArrVertex()[i];
        temp_y = GetArrVertex()[i + 1];
        temp_z = GetArrVertex()[i + 2];

        GetArrVertex()[i] = temp_x;
        GetArrVertex()[i + 1] = cos(scale) * temp_y - sin(scale) * temp_z;
        GetArrVertex()[i + 2] = sin(scale) * temp_y + cos(scale) * temp_z;
      }
      break;
    case 'y':
      for (unsigned int i = 0; i < GetCountVertex() * 3; i += 3) {
        temp_x = GetArrVertex()[i];
        temp_y = GetArrVertex()[i + 1];
        temp_z = GetArrVertex()[i + 2];

        GetArrVertex()[i] = cos(scale) * temp_x + sin(scale) * temp_z;
        GetArrVertex()[i + 1] = temp_y;
        GetArrVertex()[i + 2] = -sin(scale) * temp_x + cos(scale) * temp_z;
      }
      break;
    case 'z':
      for (unsigned int i = 0; i < GetCountVertex() * 3; i += 3) {
        temp_x = GetArrVertex()[i];
        temp_y = GetArrVertex()[i + 1];
        temp_z = GetArrVertex()[i + 2];

        GetArrVertex()[i] = cos(scale) * temp_x - sin(scale) * temp_y;
        GetArrVertex()[i + 1] = sin(scale) * temp_x + cos(scale) * temp_y;
        GetArrVertex()[i + 2] = temp_z;
      }
      break;
  }
}

void s21::Facade::Move(double scale, char direction) {
  static double diff_x = 0;
  static double diff_y = 0;
  static double diff_z = 0;
  if (direction == 'x') {
    for (unit i = 0; i < GetCountVertex() * 3; i += 3) GetArrVertex()[i] += scale - diff_x;
    diff_x = scale;
  } else if (direction == 'y') {
    for (unit i = 1; i < GetCountVertex() * 3; i += 3) GetArrVertex()[i] += scale - diff_y;
    diff_y = scale;
  } else {
    for (unit i = 2; i < GetCountVertex() * 3; i += 3) GetArrVertex()[i] += scale - diff_z;
    diff_z = scale;
  }
}

void s21::Facade::FreeMemory(){
  controller_.free();
}
