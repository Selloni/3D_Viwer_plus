#include "s21_viewer.h"

namespace s21 {
bool Model::s21_count_v_f(std::string file_name, data_t &obj) {  // открыли и посчитали, сколько нам потребуется памяти
  std::ifstream text;
  std::string ch;
  // int len = ch.length();  //длина строки
  bool result = 0;
  text.open(file_name, std::ios::in);
  if (text.is_open()) {
    while (std::getline(text, ch)) {
      if (ch[0] == 'v' && ch[1] == ' ') {  // vertex
        obj.count_vert++;
      } else if (ch[0] == 'f' && ch[1] == ' ') {  // facets
        obj.count_facets += s21_space_for_Fsupp(ch);
        // std::cout << " МЕНЯ = " << obj.count_facets << std::endl;
      }
    }
    text.close();
  } else {
    result = 1;
  }
  if (obj.count_vert < 3) {
    result = 1;
  }
  return result;
}

Model::unint Model::s21_space_for_Fsupp(std::string ch) {
  int i = 2;
  unint space_count = 1;
  while (ch[i] != '\n' && ch[i] != EOF && ch[i] != '\0') {
    if (ch[i] == ' ') {
      space_count++;
    }
    i++;
  }
  return space_count;
}

using namespace std;

void Model::s21_read(std::string file_name, data_t &obj) {
  std::ifstream text;
  unint index_v = 0;
  unint index_f = 0;
  std::string ch;
  std::string tmp;
  obj.vertexes = new double[obj.count_vert * 3 + 1];
  obj.facets = new unint[obj.count_facets * 2 + 1] ;
  text.open(file_name, std::ios::in);
  if (text.is_open()) {  // считываем построчно
    while (std::getline(text, ch)) {
      std::stringstream os_tream(ch);
          if (ch[0] == 'v' && ch[1] == ' ') {
            while(std::getline(os_tream, tmp, ' ')){
              if (tmp == "v") {
                continue;
              } else {
              obj.vertexes[index_v] = std::stod(tmp);
              ++index_v;
              }
            }
          } else if (ch[0] == 'f' && ch[1] == ' ') {
            index_f = s21_Fconnect(obj, ch, index_f);
          }
        }
  }
  text.close();
}

Model::unint Model::s21_Fconnect(data_t obj, std::string ch, unint index_f) {
  int closure_val{};  // для замыкания полигона
  int i_flag = 0;  // порядковый номер записанного числа
  for (unint i = 0; i < ch.length(); ++i) {
    unint val = 0;  // для дублирования чисел
    if (ch[i] == ' ' && s21_digit_supp(ch[i+1])) {
      ++i_flag;
      std::string str{};
      int j = 0;
      while (s21_digit_supp(ch[++i])) {
        str.push_back(ch[i]);
        // ++i;
        ++j;
      }
      val =( std::stod(str)) - 1;
      obj.facets[index_f] = val;
      if (i_flag == 1) {
        closure_val = val;
        ++index_f;
      }
      if (i_flag != 1) {
        obj.facets[++index_f] = val;
        ++index_f;
      }
    }
  }
  obj.facets[index_f++] = closure_val;
  return (index_f);
}

int Model::s21_digit_supp(char ind) {
  int result = 0;
  if (ind >= '0' && ind <= '9') {
    result = 1;
  }
  return result;
}

// поменялись местами аргументы, теперь направление передается последним аргументом, остальное в таком же порядке
// void Rotate::s21_move(double **vertex, double move, unint count_v, char direction) {
  // double temp_x = 0.0;
  // double temp_y = 0.0;
  // double temp_z = 0.0;
  // switch (direction) {
  //   case 'x':
  //     for (unint i = 0; i < count_v * 3; i += 3) {
  //       temp_x = (*vertex)[i];
  //       temp_y = (*vertex)[i + 1];
  //       temp_z = (*vertex)[i + 2];

  //       (*vertex)[i] = temp_x;
  //       (*vertex)[i + 1] = cos(move) * temp_y - sin(move) * temp_z;
  //       (*vertex)[i + 2] = sin(move) * temp_y + cos(move) * temp_z;
  //     }
  //     break;
  //   case 'y':
  //     for (unint i = 0; i < count_v * 3; i += 3) {
  //       temp_x = (*vertex)[i];
  //       temp_y = (*vertex)[i + 1];
  //       temp_z = (*vertex)[i + 2];

  //       (*vertex)[i] = cos(move) * temp_x + sin(move) * temp_z;
  //       (*vertex)[i + 1] = temp_y;
  //       (*vertex)[i + 2] = -sin(move) * temp_x + cos(move) * temp_z;
  //     }
  //     break;
  //   case 'z':
  //     for (unint i = 0; i < count_v * 3; i += 3) {
  //       temp_x = (*vertex)[i];
  //       temp_y = (*vertex)[i + 1];
  //       temp_z = (*vertex)[i + 2];

  //       (*vertex)[i] = cos(move) * temp_x - sin(move) * temp_y;
  //       (*vertex)[i + 1] = sin(move) * temp_x + cos(move) * temp_y;
  //       (*vertex)[i + 2] = temp_z;
  //     }
  //     break;
  // }
// }

// void Move::s21_move(double **vertex, double move, unint count_v, char direction) {
  // static double diff = 0;
  // unint i;
  // i = (direction == 'x') ? 0 : ((direction == 'y') ? 1 : ((direction == 'z') ? 2 : 0));
  // for (i = 0; i < count_v * 3; i += 3) (*vertex)[i] += move - diff;
  // diff = move;
// }

// void Scale::s21_move(double **vertex, double scale, unint count_v, char direction) {
//   if (scale == 0.0) return;
//   direction = direction;
//   for (unint i = 0; i < count_v * 3; ++i) {
//     (*vertex)[i] *= scale;
//   }
// }

}  // namespace s21
