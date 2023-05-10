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
  // class Model {
  //   private:
  //   // typedef unsigned int unint;
  //     using unint = unsigned int;

  //   public:
  //     typedef struct DATA {
  //       unint count_vert = 0;    // количество v
  //       unint count_facets = 0;  // количество f
  //       // std::vector<double> vertexex;
  //       // std::vector<unint> facetc;
  //       double *vertexes = 0;    // хранятся в, цифры
  //       unint *facets = 0;  // массив, в нем полигоны, эфки 122331
  //     } data_t;
      
  //     ////parser
  //     // unint index_f;
  //     // unint index_v;
  //     Model() {};
  //     bool s21_count_v_f(std::string file_name, DATA *obj);
  //     void s21_read(std::string file_name, DATA *obj);
  //     void s21_rotate(double **vertex, char xyz, double angle, unint i);
  //     void s21_moveX(double **vertex, double move_x, unint count_v);
  //     void s21_moveY(double **vertex, double move_y, unint count_v);
  //     void s21_moveZ(double **vertex, double move_z, unint count_v);
  //     void s21_scale(double **vertex, float scale, unint count_v);

  //   private:
  //     unint s21_space_for_Fsupp(std::string ch);
  //     unint s21_Fconnect(DATA *obj, std::string ch, unint index_f);
  //     int s21_digit_supp(char ind);
  // };
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
      virtual ~Model() {}
      bool s21_count_v_f(std::string file_name, DATA *obj);
      void s21_read(std::string file_name, DATA *obj);
      virtual void s21_move(double **vertex, double move, unint count_v, char direction) = 0;
      // virtual void s21_scale(double **vertex, float scale, unint count_v);

    private:
      unint s21_space_for_Fsupp(std::string ch);
      unint s21_Fconnect(DATA *obj, std::string ch, unint index_f);
      int s21_digit_supp(char ind);

  };

  class Move : public Model {
    public:
      void s21_move(double **vertex, double move, unint count_v, char direction) override;
  };

  class Rotate : public Model {
    public:
      void s21_move(double **vertex, double move, unint count_v, char direction) override;
  };

  class Scale : public Model {
    public:
      void s21_move(double **vertex, double move, unint count_v) override;
  };

}  // namespace s21

#endif  // SRC_S21_VIEWER_H_
