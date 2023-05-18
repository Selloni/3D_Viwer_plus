
#include "../Controller/s21_Controller.h"
#include "../Facade/s21_facade.h"


int main () {
  s21::Facade ff = s21::Facade::getInstance();
  std::string file_path = "obj/cub.obj";
  ff.set_path(file_path);
  s21::Move move;
  ff.fmove(move, 0.9, 'x');
  // mv.s21_move(&obj.vertexes, 0.9, obj.count_vert * 3, 'x');
  double vertex_1[] = {1.900000,  -1.000000, -1.000000, 1.900000,  -1.000000,
                       1.000000,  -0.100000, -1.000000, 1.000000,  -0.100000,
                       -1.000000, -1.000000, 1.900000,  1.000000,  -0.999999,
                       1.899999,  1.000000,  1.000001,  -0.100000, 1.000000,
                       1.000000,  -0.100000, 1.000000,  -1.000000}; 
  for (size_t i = 0; i < 24; i++) {
    std::cout << ff.get_arr_vertex()[i] <<"  "<<  vertex_1[i] << "\n" ;
  }
  ff.free();

}
