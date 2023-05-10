#ifndef SRC_S21_VIEWER_H_
#define SRC_S21_VIEWER_H_

#include <cmath>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include <fstream>
#include <iostream>
#include <string>
// #include <vector>
#include <sstream>

namespace s21 {
  class Model {
    public:
      using unint = unsigned int;

      typedef struct DATA {
        unint count_vert = 0;
        unint count_facets = 0;
        double *vertexes = 0;
        unint *facets = 0;
      } data_t;

    public:
      Model() {}
      ~Model() {}
      bool s21_count_v_f(std::string file_name, DATA *obj);
      void s21_read(std::string file_name, DATA *obj);
      void s21_move(double **vertex, double move, unint count_v, char direction);
      // virtual void s21_scale(double **vertex, float scale, unint count_v);

    private:
      unint s21_space_for_Fsupp(std::string ch);
      unint s21_Fconnect(DATA *obj, std::string ch, unint index_f);
      int s21_digit_supp(char ind);

  };

  class Move : public Model {
    public:
      void s21_move(double **vertex, double move, unint count_v, char direction);
  };

  class Rotate : public Model {
    public:
      void s21_move(double **vertex, double move, unint count_v, char direction);
  };

  class Scale : public Model {
    public:
      void s21_move(double **vertex, double move, unint count_v);
  };

}  // namespace s21

#endif  // SRC_S21_VIEWER_H_
