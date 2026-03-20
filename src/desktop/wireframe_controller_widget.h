#ifndef DESKTOP_H
#define DESKTOP_H

#include <QtWidgets>

namespace s21 {
class SlidersGroup;
class Slider;
class WifeframeInfo;

class WireframeControllerWidget : public QWidget {
  Q_OBJECT

 private:
  SlidersGroup *move_sliders_ = nullptr;
  SlidersGroup *rotate_sliders_ = nullptr;
  SlidersGroup *scale_slider_ = nullptr;
  QPushButton *choose_file_btn_ = nullptr;
  WifeframeInfo *wifeframe_info_ = nullptr;
  QFileDialog *choose_file_dialog_ = nullptr;

  void AddMoveSliders();
  void AddRotateSliders();
  void AddScaleSliders();
  void AddChooseFileButton();
  void AddChooseFileDialog();

 public:
  WireframeControllerWidget(QWidget *parent);
  void UpdateWireframeInfo(std::string filename, int vertices_count,
                           int edges_count);

 public slots:
  void OpenChooseFileDialog();

 signals:
  void MoveXChanged(int value);
  void MoveYChanged(int value);
  void MoveZChanged(int value);

  void RotateXChanged(int value);
  void RotateYChanged(int value);
  void RotateZChanged(int value);

  void ScaleChanged(int value);
};

class SlidersGroup : public QWidget {
  Q_OBJECT

 private:
  QLabel *label_;
  QVBoxLayout *layout_;

 public:
  SlidersGroup(QWidget *parent, QString label);
  void AddSlider(Slider *slider);
  void AddStretch();
};

class Slider : public QWidget {
  Q_OBJECT

 private:
  QSlider *slider_ = new QSlider(Qt::Horizontal);
  QLabel *left_label_ = new QLabel("");
  QLabel *right_label_ = new QLabel("");

 public:
  Slider(QWidget *parent, QString left_label = "", QString right_label = "");
  void SetRange(int min, int max);
  void SetValue(int value);

 signals:
  void ValueChanged(int value);
};

class WifeframeInfo : public QWidget {
  Q_OBJECT

 private:
  QLabel *filename_label_ = new QLabel("File: ");
  QLabel *vertices_label_ = new QLabel("Vrtices: ");
  QLabel *edges_label_ = new QLabel("Edges: ");

  QLabel *filename_value_ = new QLabel("not selected");
  QLabel *vertices_value_ = new QLabel("0");
  QLabel *edges_value_ = new QLabel("0");

 public:
  WifeframeInfo(QWidget *parent);
  void UpdateWireframeInfo(std::string filename, int vertices_count,
                           int edges_count);
};
}  // namespace s21

#endif