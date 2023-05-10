#include "s21_viewer.h"

bool s21_count_v_f(std::string file_name, data_t *obj) {  // открыли и посчитали, сколько нам потребуется памяти
  std::ifstream text;
  std::string ch;
  // int len = ch.length();  //длина строки
  bool result = 0;
  text.open(file_name, std::ios::in);
  if (text.is_open()) {
    while (std::getline(text, ch)) {
      if (ch[0] == 'v' && ch[1] == ' ') {  // vertex
        obj->count_vert++;
      } else if (ch[0] == 'f' && ch[1] == ' ') {  // facets
        obj->count_facets += s21_space_for_Fsupp(ch);
      }
    }
    text.close();
  } else {
    result = 1;
  }
  if (obj->count_vert < 3) {
    result = 1;
  }
  return result;
}

unint s21_space_for_Fsupp(std::string ch) {
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

void s21_read(std::string file_name, data_t *obj) {
  std::ifstream text;
  int index_v = 0;
  unint index_f = 0;
  std::string ch;
  std::string tmp;
  obj->vertexes = new double[obj->count_vert * 3 + 1]; 
  obj->facets = new unint[obj->count_facets * 2 + 1] ;
  double v1 = 0, v2 = 0, v3 = 0;
  text.open(file_name, std::ios::in);
  if (text.is_open()) {  // считываем построчно
    while (std::getline(text, ch)) {
      std::stringstream os_tream(ch);
          if (ch[0] == 'v' && ch[1] == ' ') {
            double double_num;
            cout << "ch:" << ch  << " " << "\n";
            // os_tream >> tmp >> v1 >> v2 >> v3;
            // obj->vertexes[index_v] = v1;
            // obj->vertexes[++index_v] = v2;
            // obj->vertexes[++index_v] = v3;
            // ++index_v;
                  while(std::getline(os_tream, tmp, ' ')){
                    if (tmp == "v") {
                      continue;
                    } else {
                    obj->vertexes[index_v] = std::stod(tmp);
                    ++index_v;
                    }
                  }
                  cout <<"\n";
            cout << tmp << " " << obj->vertexes[index_v - 2] << " " << obj->vertexes[index_v -1 ] << " " << obj->vertexes[index_v];
            cout << "\n";
          } else if (ch[0] == 'f' && ch[1] == ' ') {
            index_f = s21_Fconnect(obj, ch, index_f);
          }
        }
  }
  text.close();
}

unint s21_Fconnect(data_t *obj, std::string ch, unint index_f) {
  int closure_val = '\0';  // для замыкания полигона
  int i_flag = 0;  // порядковый номер записанного числа
  for (unint i = 0; i < ch.length(); i++) {
    long int val = 0;  // для дублирования чисел
    if (ch[i] == ' ' && s21_digit_supp(ch[i++])) {
      ++i_flag;
      char str[10] = {'\0'};
      int j = 0;
      while (s21_digit_supp(ch[i])) {
        str[j] = ch[i];
        ++i;
        ++j;
      }
      val = std::stod(str) - 1;
      obj->facets[index_f] = val;
      cout << obj->facets[index_f] << "\n";
      if (i_flag == 1) {
        closure_val = val;
        ++index_f;
      }
      if (i_flag != 1) {
        obj->facets[++index_f] = val;
        ++index_f;
      }
    }
  }
  obj->facets[index_f++] = closure_val;
  return (index_f);
}

int s21_digit_supp(char ind) {
  int result = 0;
  if (ind >= '0' && ind <= '9') {
    result = 1;
  }
  return result;
}

void s21_rotate(double **vertex, char xyz, double angle, unint count_v) {
  double temp_x = 0.0;
  double temp_y = 0.0;
  double temp_z = 0.0;
  switch (xyz) {
    case 'x':
      for (unint i = 0; i < count_v * 3; i += 3) {
        temp_x = (*vertex)[i];
        temp_y = (*vertex)[i + 1];
        temp_z = (*vertex)[i + 2];

        (*vertex)[i] = temp_x;
        (*vertex)[i + 1] = cos(angle) * temp_y - sin(angle) * temp_z;
        (*vertex)[i + 2] = sin(angle) * temp_y + cos(angle) * temp_z;
      }
      break;
    case 'y':
      for (unint i = 0; i < count_v * 3; i += 3) {
        temp_x = (*vertex)[i];
        temp_y = (*vertex)[i + 1];
        temp_z = (*vertex)[i + 2];

        (*vertex)[i] = cos(angle) * temp_x + sin(angle) * temp_z;
        (*vertex)[i + 1] = temp_y;
        (*vertex)[i + 2] = -sin(angle) * temp_x + cos(angle) * temp_z;
      }
      break;
    case 'z':
      for (unint i = 0; i < count_v * 3; i += 3) {
        temp_x = (*vertex)[i];
        temp_y = (*vertex)[i + 1];
        temp_z = (*vertex)[i + 2];

        (*vertex)[i] = cos(angle) * temp_x - sin(angle) * temp_y;
        (*vertex)[i + 1] = sin(angle) * temp_x + cos(angle) * temp_y;
        (*vertex)[i + 2] = temp_z;
      }
      break;
  }
}

void s21_moveX(double **vertex, double move_x, unint count_v) {
  static double diff = 0;
  for (unint i = 0; i < count_v * 3; i += 3) (*vertex)[i] += move_x - diff;
  diff = move_x;
}

void s21_moveY(double **vertex, double move_y, unint count_v) {
  static double diff = 0;
  for (unint i = 1; i < count_v * 3; i += 3) (*vertex)[i] += move_y - diff;
  diff = move_y;
}

void s21_moveZ(double **vertex, double move_z, unint count_v) {
  static double diff = 0;
  for (unint i = 2; i < count_v * 3; i += 3) (*vertex)[i] += move_z - diff;
  diff = move_z;
}

void s21_scale(double **vertex, float scale, unint count_v) {
  if (scale == 0.0) return;
  for (unint i = 0; i < count_v * 3; ++i) {
    (*vertex)[i] *= scale;
  }
}
