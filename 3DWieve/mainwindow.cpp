#include "mainwindow.h"

#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  setWindowTitle("3DViewer");
  ui->setupUi(this);
  this->setFixedSize(this->size());  //  не изменяемый размер окна
  ui->line_width->setRange(1, 40);
  time = 0.0;
  record_time = new QTimer(this);
  is_recording = false;
  connect(record_time, &QTimer::timeout, this, &MainWindow::recording);
  connect(record_time, &QTimer::timeout, this, &MainWindow::updateCountdown);
}

MainWindow::~MainWindow() {
  delete ui;
  ui->sceneWidget->freeMem();
}

void MainWindow::on_pushButton_clicked() {
  qpath_file =
      QFileDialog::getOpenFileName(0, "Open File .obj", "/Users/", "*.obj");
  QByteArray ba = qpath_file.toLocal8Bit();  // перевод из Qstring in *str
  char *path_file = ba.data();
  ui->sceneWidget->readFile(path_file);
}

void MainWindow::on_line_color_activated(int index) {
  ui->sceneWidget->lC = index;
  ui->sceneWidget->update();
}

void MainWindow::on_line_solid_clicked() {
  ui->sceneWidget->lS = 1;
  ui->sceneWidget->update();
}

void MainWindow::on_line_dashed_clicked() {
  ui->sceneWidget->lS = 0;
  ui->sceneWidget->update();
}

void MainWindow::on_line_width_valueChanged(int value) {
  ui->sceneWidget->lW = value;
  ui->line_progress->setValue(value);
  ui->sceneWidget->update();
}

void MainWindow::on_vertex_color_activated(int index) {
  ui->sceneWidget->vC = index;
  ui->sceneWidget->update();
}

void MainWindow::on_vertex_circle_clicked() {
  ui->sceneWidget->vS = 1;
  ui->sceneWidget->update();
}

void MainWindow::on_vertex_no_clicked() {
  ui->sceneWidget->vS = 0;
  ui->sceneWidget->update();
}

void MainWindow::on_vertex_square_clicked() {
  ui->sceneWidget->vS = 2;
  ui->sceneWidget->update();
}

void MainWindow::on_vertex_wigth_valueChanged(int value) {
  ui->sceneWidget->vW = value;
  ui->sceneWidget->update();
}

void MainWindow::on_background_clicked() {
  QColor color = QColorDialog::getColor(Qt::blue).toRgb();
  ui->sceneWidget->backRed = color.red();
  ui->sceneWidget->backGreen = color.green();
  ui->sceneWidget->backBlue = color.blue();
  ui->sceneWidget->backAlpha = color.alpha();
  ui->sceneWidget->update();
}

void MainWindow::on_rotateX_valueChanged(double arg1) {
  ui->sceneWidget->controller.fasade.transform(
      rotate_x_, &ui->sceneWidget->qVertexes, arg1,
      ui->sceneWidget->qcountVert);
  ui->sceneWidget->update();
}

void MainWindow::on_rotetaY_valueChanged(double arg1) {
  ui->sceneWidget->controller.fasade.transform(
      rotate_y_, &ui->sceneWidget->qVertexes, arg1,
      ui->sceneWidget->qcountVert);
  ui->sceneWidget->update();
}

void MainWindow::on_rotateZ_valueChanged(double arg1) {
  ui->sceneWidget->controller.fasade.transform(
      rotate_z_, &ui->sceneWidget->qVertexes, arg1,
      ui->sceneWidget->qcountVert);
  ui->sceneWidget->update();
}

void MainWindow::on_doubleSpinBox_6_valueChanged(double arg1) {
  ui->sceneWidget->controller.fasade.transform(
      move_x_, &ui->sceneWidget->qVertexes, arg1, ui->sceneWidget->qcountVert);
  ui->sceneWidget->update();
}

void MainWindow::on_doubleSpinBox_5_valueChanged(double arg1) {
  ui->sceneWidget->controller.fasade.transform(
      move_y_, &ui->sceneWidget->qVertexes, arg1, ui->sceneWidget->qcountVert);
  ui->sceneWidget->update();
  ;
}

void MainWindow::on_doubleSpinBox_4_valueChanged(double arg1) {
  ui->sceneWidget->controller.fasade.transform(
      move_z_, &ui->sceneWidget->qVertexes, arg1, ui->sceneWidget->qcountVert);
  ui->sceneWidget->update();
}

void MainWindow::on_setting_scale_valueChanged(double arg1) { tmp = arg1; }

void MainWindow::on_but_scale_clicked() {
  ui->sceneWidget->controller.fasade.transform(
      scale_, &ui->sceneWidget->qVertexes, tmp, ui->sceneWidget->qcountVert);
  ui->sceneWidget->update();
}

void MainWindow::on_actioninfo_triggered() {
  QString a = QString::number(ui->sceneWidget->qcountVert);
  QString b = QString::number(ui->sceneWidget->qcountFacets);
  QString info = "Name: " + qpath_file + '\n' + "Vertex: " + a + '\n' +
                 "Facets: " + b + '\n' + "Authors: Sabina and Yakov" + '\n' +
                 '\n' + "❤ и ты симпатяшка ❤";

  QMessageBox::information(this, tr("Info"), info);
}

void MainWindow::on_actionSol_triggered() {
  if (ui->sceneWidget->proj) {
    ui->sceneWidget->proj = 0;
  } else {
    ui->sceneWidget->proj = 1;
  }
  ui->sceneWidget->update();
}

void MainWindow::on_actionSave_settings_triggered() {
  ui->sceneWidget->saveSetting();
}

void MainWindow::on_actionLoad_settings_triggered() {
  ui->sceneWidget->loadSetting();
  ui->sceneWidget->update();
}

void MainWindow::on_actionjpeg_triggered() {
  QString path = (QDir::homePath() + "/save_config/");
  QDir dir(path);
  if (!dir.exists()) dir.mkpath(path);
  ui->sceneWidget->grab().save(path + "you_are_Zanuda.jpeg");
}

void MainWindow::on_actionbmp_triggered() {
  QString path = (QDir::homePath() + "/save_config/");
  QDir dir(path);
  if (!dir.exists()) dir.mkpath(path);
  ui->sceneWidget->grab().save(path + "you_are_Zanuda.bmp");
}

void MainWindow::on_actionGif_2_triggered() {
  if (!is_recording) {
    is_recording = true;
    record_time->start(100);
  }
}

void MainWindow::recording() {
  if (is_recording && time <= 5.0) {
    GIF.push_back(ui->sceneWidget->grab().toImage());
    time += 0.1;
  } else {
    saveGIF();
    record_time->stop();
  }
}

void MainWindow::updateCountdown() {
  countdown_++;
  if (countdown_ == 0) {
    ui->countdownLabel->setText("Запись\n5 секунд");
  } else if (countdown_ == 10) {
    ui->countdownLabel->setText("Запись\n4 секунды");
  } else if (countdown_ == 20) {
    ui->countdownLabel->setText("Запись\n3 секунды");
  } else if (countdown_ == 30) {
    ui->countdownLabel->setText("Запись\n2 секунды");
  } else if (countdown_ == 40) {
    ui->countdownLabel->setText("Запись\n1 секунда");
  } else if (countdown_ == 50) {
    ui->countdownLabel->setText("Запись\n0 секунд");
  }
  if (countdown_ == 51) {
    ui->countdownLabel->clear();
    countdown_ = 0;
  }
}

void MainWindow::saveGIF() {
  QString str = QFileDialog::getSaveFileName(
      this, tr("Save GIF"), QDir::homePath(), tr("GIF (*.gif)"));
  if (str != "") {
    QGifImage gif(QSize(1582, 1322));

    gif.setDefaultTransparentColor(Qt::black);
    gif.setDefaultDelay(100);

    for (QVector<QImage>::Iterator frame = GIF.begin(); frame != GIF.end();
         frame++) {
      gif.addFrame(*frame);
    }

    gif.save(str);
    GIF.clear();
  }
  time = 0.0;
  is_recording = false;
}

void MainWindow::on_action_triggered() {
  QString link = "https://github.com/Selloni";
  QDesktopServices::openUrl(QUrl(link));
}
