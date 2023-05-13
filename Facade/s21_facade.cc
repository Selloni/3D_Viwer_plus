#include "s21_facade.h"

bool s21::Facade::set_path(std::string str) {
//  free();
  bool flag = controller_.set_path_file(str);
  if (!flag) controller_.open(str);
  return flag;  // 0 success
}

void s21::Facade::fmove(s21::Strategy &move, double offset, char direction) {
  move.s21_move(&controller_.obj.vertexes, offset, controller_.obj.count_vert * 3, direction); 
}

void s21::Facade::free(){
  controller_.free();
}
