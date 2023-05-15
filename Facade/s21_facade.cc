#include "s21_facade.h"


void s21::RotateX::transform(double **vertex, double angle, unint count_v) {
  double temp_x = 0.0;
  double temp_y = 0.0;
  double temp_z = 0.0;
      for (unint i = 0; i < count_v * 3; i += 3) {
        temp_x = (*vertex)[i];
        temp_y = (*vertex)[i + 1];
        temp_z = (*vertex)[i + 2];

        (*vertex)[i] = temp_x;
        (*vertex)[i + 1] = cos(angle) * temp_y - sin(angle) * temp_z;
        (*vertex)[i + 2] = sin(angle) * temp_y + cos(angle) * temp_z;
  }
}

void s21::RotateY::transform(double **vertex, double angle, unint count_v) {
  double temp_x = 0.0;
  double temp_y = 0.0;
  double temp_z = 0.0;
      for (unint i = 0; i < count_v * 3; i += 3) {
        temp_x = (*vertex)[i];
        temp_y = (*vertex)[i + 1];
        temp_z = (*vertex)[i + 2];

        (*vertex)[i] = cos(angle) * temp_x + sin(angle) * temp_z;
        (*vertex)[i + 1] = temp_y;
        (*vertex)[i + 2] = -sin(angle) * temp_x + cos(angle) * temp_z;
  }
}

void s21::RotateZ::transform(double **vertex, double angle, unint count_v) {
  double temp_x = 0.0;
  double temp_y = 0.0;
  double temp_z = 0.0;
      for (unint i = 0; i < count_v * 3; i += 3) {
        temp_x = (*vertex)[i];
        temp_y = (*vertex)[i + 1];
        temp_z = (*vertex)[i + 2];

        (*vertex)[i] = cos(angle) * temp_x - sin(angle) * temp_y;
        (*vertex)[i + 1] = sin(angle) * temp_x + cos(angle) * temp_y;
        (*vertex)[i + 2] = temp_z;
}
}

void s21::MoveX::transform(double **vertex, double angle, unint count) {
    static double diff1 = 0;
    for (unint i = 0; i < count * 3; i += 3) (*vertex)[i] += angle - diff1;
    diff1 = angle;
}

void s21::MoveY::transform(double **vertex, double angle, unint count) {
    static double diff2 = 0;
    for (unint i = 1; i < count * 3; i += 3) (*vertex)[i] += angle - diff2;
    diff2 = angle;
}

void s21::MoveZ::transform(double **vertex, double angle, unint count) {
    static double diff3 = 0;
    for (unint i = 2; i < count * 3; i += 3) (*vertex)[i] += angle - diff3;
    diff3 = angle;
}


void s21::Scale::transform(double **vertex, double angle, unint count) {
  if (angle == 0.0) return;
  for (unint i = 0; i < count * 3; ++i) {
    (*vertex)[i] *= angle;
  }

}

void s21::Facade::transform(s21::Strategy &transform,double **vertex, double angle, unint count) {
   transform.transform(vertex, angle, count);
}