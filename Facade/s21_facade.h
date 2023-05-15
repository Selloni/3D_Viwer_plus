#ifndef SRC_FACADE_H_
#define SRC_FACADE_H_

//#include "../Controller/s21_controller.h"
#include "../parsing/s21_viewer.h"
// #include "../3DWieve/mainwindow.h"

namespace s21 {

class Strategy {
    public:
    using unint = unsigned int;
  virtual void transform(double **vertex, char xyz, double angle, unint count) = 0;
};

class Move: public Strategy {
  public:
  void transform(double **vertex, char xyz, double angle, unint count)override;
};

class Scale: public Strategy {
  public:
  void transform(double **vertex, char xyz, double angle, unint count)override;
};

class Rotate: public Strategy {
  public:
  void transform(double **vertex, char xyz, double angle, unint count)override;
};


class Facade {
  private:
    // Model model_;
  public:
    using unint = unsigned int ;
    Facade() {}
    ~Facade(){}
    void transform(s21::Strategy &transform,double **vertex, char xyz, double angle, unint count);
}; // Facade


} // s21

#endif // SRC_FACADE_H_
