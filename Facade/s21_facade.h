#ifndef SRC_FACADE_H_
#define SRC_FACADE_H_

//#include "../Controller/s21_controller.h"
#include "../parsing/s21_viewer.h"
// #include "../3DWieve/mainwindow.h"

namespace s21 {


class Strategy {
    public:
    using unint = unsigned int;
  virtual void transform(double **vertex, double angle, unint count) = 0;
  virtual ~Strategy() = default;
};

class MoveX: public Strategy {
  MoveX(){}
  public:
  static MoveX& GetInstance() {
    static MoveX instance;
    return instance;
  }
  void transform(double **vertex, double angle, unint count)override;
  ~MoveX()override{} 
};

class MoveY: public Strategy {
  MoveY(){}
  public:
  static MoveY& GetInstance() {
    static MoveY instance;
    return instance;
  }
  void transform(double **vertex, double angle, unint count)override;
  ~MoveY()override{}
};

class MoveZ: public Strategy {
  MoveZ(){}
  public:
   static MoveZ& GetInstance() {
    static MoveZ instance;
    return instance;
  }
  void transform(double **vertex, double angle, unint count)override;
  ~MoveZ()override{}
};

class Scale: public Strategy {
  Scale(){}
  public:
    static Scale& GetInstance() {
    static Scale instance;
    return instance;
  }
  void transform(double **vertex, double angle, unint count)override;
  ~Scale()override{}
};


class RotateX: public Strategy {
  RotateX(){}
  public:
  public:
   static RotateX& GetInstance() {
    static RotateX instance;
    return instance;
  }
  void transform(double **vertex, double angle, unint count)override;
  ~RotateX()override{}
};

class RotateY: public Strategy {
  RotateY(){}
  public:
   static RotateY& GetInstance() {
    static RotateY instance;
    return instance;
  }
  void transform(double **vertex, double angle, unint count)override;
  ~RotateY()override{}
};

class RotateZ: public Strategy {
  RotateZ(){}
  public:
   static RotateZ& GetInstance() {
    static RotateZ instance;
    return instance;
  }
  void transform(double **vertex, double angle, unint count)override;
  ~RotateZ()override{}
};


class Facade {
  private:
  public:
    using unint = unsigned int ;
    void transform(s21::Strategy &transform,double **vertex, double angle, unint count);
}; // Facade


} // s21

#endif // SRC_FACADE_H_
