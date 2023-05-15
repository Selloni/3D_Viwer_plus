#ifndef SRC_FACADE_H_
#define SRC_FACADE_H_

//#include "../Controller/s21_controller.h"
#include "../parsing/s21_viewer.h"
// #include "../3DWieve/mainwindow.h"

namespace s21 {
using unit = unsigned int;

class Facade {
  private:
    Model model_;
  public:
    using unint = unsigned int ;
    Facade() {}
    ~Facade(){}
    // void s21_rotate(double **vertex, char xyz, double angle, unint i);
    // void s21_moveX(double **vertex, double move_x, unint count_v);
    // void s21_moveY(double **vertex, double move_y, unint count_v);
    // void s21_moveZ(double **vertex, double move_z, unint count_v);
    // void s21_scale(double **vertex, float scale, unint count_v);
}; // Facade

class Straregy {
  virtual void transform(double **vertex, char xyz, double angle, unint count) = 0;
};

class Move: public Straregy {
  void transform(double **vertex, char xyz, double angle, unint count)
};

class Scale: public Straregy {
  void transform(double **vertex, char xyz, double angle, unint count)
};

class Rotate: public Straregy {
  void transform(double **vertex, char xyz, double angle, unint count)
};



} // s21

#endif // SRC_FACADE_H_
