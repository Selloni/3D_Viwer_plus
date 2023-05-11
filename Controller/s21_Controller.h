#ifndef SRC_CONTROLLER_S21_CONTROLLER_H_
#define SRC_CONTROLLER_S21_CONTROLLER_H_
#include "../parsing/s21_viewer.h"
#include <vector>

namespace s21{
class Controller {
  protected:
  s21::Model::data_t obj;
  s21::Model model_;
  public:
  // using unit = unsigned int;
  // unit get_count_vertex() {return obj.count_vert;}
  // unit get_count_facets() {return obj.count_facets;}
  // double *get_arr_vertex() {return obj.vertexes;}
  // unit *get_arr_facets() {return obj.facets;}
  bool set_path_file(std::string str) {
    return model_.s21_count_v_f(str, &obj);
  }
  void free(){
    delete[] obj.facets;
    delete[] obj.vertexes;
  }
  void open(std::string str) {
    model_.s21_read(str, &obj);
  }
}; // Controller

// class Controller {
//   private:
//     Model model_;
//     // Model::data_t obj;

//   public:
//     using unit = unsigned int;

//     unit get_count_vertex() {return obj.count_vert;}
//     unit get_count_facets() {return obj.count_facets;}
//     double *get_arr_vertex() {return obj.vertexes;}
//     unit *get_arr_facets() {return obj.facets;}

//     bool set_path_file(std::string file_name, Model::DATA *data) { 
//       return model_.s21_count_v_f(file_name, data); 
//     }


//     void open(std::string file_name, Model::DATA *data) { 
//       return model_.s21_read(file_name, data); 
//     }

//     void moveVertices(double **vertex, double move, Model::unint count_v, char direction) { 
//       return model_.s21_move(vertex, move, count_v, direction); 
//     }

//     void free(Model::DATA *obj) {
//       return model_.free(obj);
//     }
// };


} // s21

#endif // SRC_CONTROLLER_S21_CONTROLLER_H_