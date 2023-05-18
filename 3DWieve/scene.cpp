#include "scene.h"
//#include <iostream>

Scene::Scene(QWidget* parent)
    : QOpenGLWidget(parent)

{
  settings = new QSettings(QDir::homePath() + "/save_config/settings.conf",
                           QSettings::IniFormat);
}

void Scene::free_mem() {
  if (controller_.obj.facets != NULL && controller_.obj.vertexes != NULL) {
    delete[] controller_.obj.facets;
    delete[] controller_.obj.vertexes;
    controller_.obj.facets = 0;
    controller_.obj.vertexes = 0;
    controller_.obj.count_facets = 0;
    controller_.obj.count_vert = 0;
    qcount_facets = 0;
    qcount_vert = 0;
    qvertexes = 0;
    qfacets = 0;
  }
}

void Scene::read_file(char* path_file) {
  free_mem();
  int err_flag = 1;
  err_flag = controller_.set_path_file(path_file);
  if (err_flag) {
    QMessageBox msgBox;
    msgBox.setText("The file was not considered");
    msgBox.exec();
  } else {
    controller_.open(path_file);
    qcount_facets = controller_.obj.count_facets;
    qcount_vert = controller_.obj.count_vert;
    qvertexes = controller_.obj.vertexes;
    qfacets = controller_.obj.facets;
  }
}

void Scene::initializeGL() {
  glEnable(GL_DEPTH_TEST);  // буфер глубины
}

void Scene::resizeGL(int w, int h) {
  // Set Viewport to window dimensions
  glViewport(0, 0, w, h);
}

void Scene::paintGL() {
  projection(proj);
  glClearColor(back_red / 255.0f, back_green / 255.0f, back_blue / 255.0f,
               back_alpha / 255.0f);  //  colo bakcground
  if (controller_.obj.count_facets > 3) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, 0, -3);
    glRotatef(xRot, 1, 0, 0);  // для движения мышью
    glRotatef(yRot, 0, 1, 0);
    glRotatef(zRot, 0, 0, 1);
    draw();
    //        update();
    //        saveSetting();
  }
}
void Scene::draw() {
  if (controller_.obj.count_facets > 3) {
    glVertexPointer(3, GL_DOUBLE, 0, qvertexes);
    glEnableClientState(GL_VERTEX_ARRAY);
    veretex_stile(v_s);
    vertex_color(v_c);
    if (v_s != 0) {
      glPointSize(v_w);  // size point
      glDrawArrays(GL_POINTS, 0, controller_.obj.count_vert);
    }
    line_color(l_c);
    line_style(l_s);
    glDrawElements(GL_LINES, (qcount_facets * 2), GL_UNSIGNED_INT, qfacets);
    glLineWidth(l_w);  // size line
    glDisableClientState(GL_VERTEX_ARRAY);
  }
}

void Scene::line_color(int l_c) {
  if (l_c == 0) {
    glColor3f(1, 1, 1);
  } else if (l_c == 1) {
    glColor3f(0, 0, 0.2);
  } else if (l_c == 2) {
    glColor3f(0.5, 0, 0);
  } else if (l_c == 3) {
    glColor3f(0.1, 1, 0.7);
  } else if (l_c == 4) {
    glColor3f(0.1, 0, 1);
  }
}

void Scene::line_style(int l_s) {
  if (l_s == 1) {
    glDisable(GL_LINE_STIPPLE);
    glEnable(GL_LINE);
  } else if (l_s == 0) {
    glLineStipple(1, 0x00ff);
    glEnable(GL_LINE_STIPPLE);  // пунктирная линия
  }
}

void Scene::vertex_color(int w_c) {
  if (w_c == 0) {
    glColor3f(1, 1, 1);
  } else if (w_c == 1) {
    glColor3f(0, 0, 0.2);
  } else if (w_c == 2) {
    glColor3f(0.5, 0, 0);
  } else if (w_c == 3) {
    glColor3f(0.1, 1, 0.7);
  } else if (w_c == 4) {
    glColor3f(0.1, 0, 1);
  }
}

void Scene::veretex_stile(int v_s) {
  if (v_s == 1) {
    glEnable(GL_POINT_SMOOTH);  // круглые точки
  } else if (v_s == 2) {
    glDisable(GL_POINT_SMOOTH);
    glEnable(GL_POINT);  // точки
  }
}

void Scene::projection(int proj) {
  // Создаем проекцию
  glMatrixMode(GL_PROJECTION);  // ортоганальая поекция
  glLoadIdentity();             // загружаем матрицу
  if (proj) {
    // Establish clipping volume (left, right, bottom, top, near, far)
    glFrustum(-1, 1, -1, 1, 1, 99999);  //  перспективная проекция
  } else {
    glOrtho(-1, 1, -1, 1, -1, 99999);  // отоганальная
  }
}

void Scene::mousePressEvent(QMouseEvent* mouse) {
  switch (mouse->button()) {
    case Qt::LeftButton:
      moving = true;
      dragging = false;
      break;
    case Qt::MiddleButton:
      dragging = true;
      moving = false;
      break;
    default:
      moving = false;
      dragging = false;
      break;
  }
  start_x = mouse->pos().x();
  start_y = mouse->pos().y();
}

void Scene::mouseMoveEvent(QMouseEvent* mouse) {
  if (moving) {
    yRot = yRot + (mouse->pos().x() - start_x);
    xRot = xRot + (mouse->pos().y() - start_y);
  }
  if (dragging) {
    x_trans = x_trans + (mouse->pos().x() - start_x) / 4.f;
    y_trans = y_trans - (mouse->pos().y() - start_y) / 4.f;
  }
  start_x = mouse->pos().x();
  start_y = mouse->pos().y();
  update();
}

void Scene::saveSetting() {
  settings->setValue("l_c", l_c);
  settings->setValue("l_s", l_s);
  settings->setValue("l_w", l_w);
  settings->setValue("v_c", v_c);
  settings->setValue("v_s", v_s);
  settings->setValue("v_w", v_w);
  settings->setValue("l_c", l_c);
  settings->setValue("proj", proj);
  settings->setValue("back_red", back_red);
  settings->setValue("back_green", back_green);
  settings->setValue("back_blue", back_blue);
  settings->setValue("back_alpha", back_alpha);
}

void Scene::loadSetting() {
  l_c = settings->value("l_c", 0).toInt();
  l_s = settings->value("l_s", 0).toInt();
  l_w = settings->value("l_w", 0).toInt();
  v_c = settings->value("v_c", 0).toInt();
  v_s = settings->value("v_s", 0).toInt();
  v_w = settings->value("v_w", 0).toInt();
  proj = settings->value("proj", proj).toInt();
  back_red = settings->value("back_red", back_red).toFloat();
  back_green = settings->value("back_green", back_green).toFloat();
  back_blue = settings->value("back_blue", back_blue).toFloat();
  back_alpha = settings->value("back_alpha", back_alpha).toFloat();
}
