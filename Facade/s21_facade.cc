#include "s21_facade.h"


void s21::Rotate::transform(double **vertex, char xyz, double angle, unint count_v) {
  double temp_x = 0.0;
  double temp_y = 0.0;
  double temp_z = 0.0;
  switch (xyz) {
    case 'x':
      for (unint i = 0; i < count_v * 3; i += 3) {
        temp_x = (*vertex)[i];
        temp_y = (*vertex)[i + 1];
        temp_z = (*vertex)[i + 2];

        (*vertex)[i] = temp_x;
        (*vertex)[i + 1] = cos(angle) * temp_y - sin(angle) * temp_z;
        (*vertex)[i + 2] = sin(angle) * temp_y + cos(angle) * temp_z;
      }
      break;
    case 'y':
      for (unint i = 0; i < count_v * 3; i += 3) {
        temp_x = (*vertex)[i];
        temp_y = (*vertex)[i + 1];
        temp_z = (*vertex)[i + 2];

        (*vertex)[i] = cos(angle) * temp_x + sin(angle) * temp_z;
        (*vertex)[i + 1] = temp_y;
        (*vertex)[i + 2] = -sin(angle) * temp_x + cos(angle) * temp_z;
      }
      break;
    case 'z':
      for (unint i = 0; i < count_v * 3; i += 3) {
        temp_x = (*vertex)[i];
        temp_y = (*vertex)[i + 1];
        temp_z = (*vertex)[i + 2];

        (*vertex)[i] = cos(angle) * temp_x - sin(angle) * temp_y;
        (*vertex)[i + 1] = sin(angle) * temp_x + cos(angle) * temp_y;
        (*vertex)[i + 2] = temp_z;
      }
      break;
  }
}

void s21::Move::transform(double **vertex, char xyz, double angle, unint count) {
  if (xyz = 'x') {
    static double diff1 = 0;
    for (unint i = 0; i < count * 3; i += 3) (*vertex)[i] += angle - diff1;
    diff1 = angle;
  } else if (xyz = 'y'){
    static double diff2 = 0;
    for (unint i = 1; i < count * 3; i += 3) (*vertex)[i] += angle - diff2;
    diff2 = angle;
  } else {
    static double diff3 = 0;
    for (unint i = 2; i < count * 3; i += 3) (*vertex)[i] += angle - diff3;
    diff3 = angle;
  }
}

void s21::Scale::transform(double **vertex, char xyz, double angle, unint count) {
  if (angle == 0.0) return;
  xyz=xyz;
  for (unint i = 0; i < count * 3; ++i) {
    (*vertex)[i] *= angle;
  }

}

void s21::Facade::transform(s21::Strategy &transform,double **vertex, char xyz, double angle, unint count) {
   transform.transform(vertex, xyz, angle, count);
}


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

// void s21::Facade::s21_rotate(double **vertex, char xyz, double angle, unint i) {
//   model_.s21_rotate(vertex, xyz, angle, i);
// }

// void s21::Facade::s21_moveX(double **vertex, double move_x, unint count_v) {
//   model_.s21_moveX(vertex, move_x, count_v);
// }

// void s21::Facade::s21_moveY(double **vertex, double move_y, unint count_v) {
//   model_.s21_moveY(vertex, move_y, count_v);
// }

// void s21::Facade::s21_moveZ(double **vertex, double move_z, unint count_v) {
//   model_.s21_moveZ(vertex, move_z, count_v);
// }

// void s21::Facade::s21_scale(double **vertex, float scale, unint count_v) {
//   model_.s21_scale(vertex, scale, count_v);
// }
