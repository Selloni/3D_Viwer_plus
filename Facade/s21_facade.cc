#include "s21_facade.h"

bool set_path(std::string str) {
  bool flag = controller_.set_path_file(str);
  if (flag) controller_.open(str);
  return flag;  // 0 success
}
