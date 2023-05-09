
#include "s21_viewer.h"

int main () {
  data_t obj;
  std::string file_path = "../obj/cub.obj";
  s21_count_v_f(file_path, &obj);
  s21_read(file_path, &obj);
  double vertex[24] = {1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000,
                       1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000,
                       -1.000000, -1.000000, 1.000000,  1.000000,  -0.999999,
                       0.999999,  1.000000,  1.000001,  -1.000000, 1.000000,
                       1.000000,  -1.000000, 1.000000,  -1.000000};
  for (int i = 0; i < 24; i++) {
    std::cout << obj.vertexes[i] << vertex[i] << '\n';
  }
  delete(obj.facets);
  delete(obj.vertexes);
}