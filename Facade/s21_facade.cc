#include "s21_facade.h"

// bool s21::Facade::SetPath(std::string str) {
// //  free();
//   bool flag = controller_.set_path_file(str);
//   if (!flag) controller_.open(str);
//   return flag;  // 0 success
// }

// void s21::Facade::fmove(s21::Strategy &move, double offset, char direction) {
//   move.s21_move(&controller_.obj.vertexes, offset, controller_.obj.count_vert * 3, direction);
// }

// void s21::Facade::Scale(double scale) {     
//   if (scale == 0.0) return;
//   for (unsigned int i = 0; i < GetCountVertex() * 3; ++i) {
//     GetArrVertex()[i] *= scale;
//   }
// }

// void s21::Facade::Rotate(double scale, char direction) {
//   double temp_x = 0.0;
//   double temp_y = 0.0;
//   double temp_z = 0.0;
//   switch (direction) {
//     case 'x':
//       for (unsigned int i = 0; i < GetCountVertex() * 3; i += 3) {
//         temp_x = GetArrVertex()[i];
//         temp_y = GetArrVertex()[i + 1];
//         temp_z = GetArrVertex()[i + 2];

//         GetArrVertex()[i] = temp_x;
//         GetArrVertex()[i + 1] = cos(scale) * temp_y - sin(scale) * temp_z;
//         GetArrVertex()[i + 2] = sin(scale) * temp_y + cos(scale) * temp_z;
//       }
//       break;
//     case 'y':
//       for (unsigned int i = 0; i < GetCountVertex() * 3; i += 3) {
//         temp_x = GetArrVertex()[i];
//         temp_y = GetArrVertex()[i + 1];
//         temp_z = GetArrVertex()[i + 2];

//         GetArrVertex()[i] = cos(scale) * temp_x + sin(scale) * temp_z;
//         GetArrVertex()[i + 1] = temp_y;
//         GetArrVertex()[i + 2] = -sin(scale) * temp_x + cos(scale) * temp_z;
//       }
//       break;
//     case 'z':
//       for (unsigned int i = 0; i < GetCountVertex() * 3; i += 3) {
//         temp_x = GetArrVertex()[i];
//         temp_y = GetArrVertex()[i + 1];
//         temp_z = GetArrVertex()[i + 2];

//         GetArrVertex()[i] = cos(scale) * temp_x - sin(scale) * temp_y;
//         GetArrVertex()[i + 1] = sin(scale) * temp_x + cos(scale) * temp_y;
//         GetArrVertex()[i + 2] = temp_z;
//       }
//       break;
//   }
// }

// void s21::Facade::Move(double scale, char direction) {
//   static double diff = 0;
//   unit i;
//   i = (direction == 'x') ? 0 : ((direction == 'y') ? 1 : ((direction == 'z') ? 2 : 0));
//   for (i = 0; i < GetCountVertex() * 3; i += 3) GetArrVertex()[i] += scale - diff;
//   diff = scale;
// }

//  void s21::Facade::FreeMemory(){
//   //  controller_.free();
//  }

void s21::Facade::s21_rotate(double **vertex, char xyz, double angle, unint i) {
  model_.s21_rotate(vertex, xyz, angle, i);
}

void s21::Facade::s21_moveX(double **vertex, double move_x, unint count_v) {
  model_.s21_moveX(vertex, move_x, count_v);
}

void s21::Facade::s21_moveY(double **vertex, double move_y, unint count_v) {
  model_.s21_moveY(vertex, move_y, count_v);
}

void s21::Facade::s21_moveZ(double **vertex, double move_z, unint count_v) {
  model_.s21_moveZ(vertex, move_z, count_v);
}

void s21::Facade::s21_scale(double **vertex, float scale, unint count_v) {
  model_.s21_scale(vertex, scale, count_v);
}