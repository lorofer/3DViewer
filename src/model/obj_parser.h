#ifndef OBJ_PARSER_H
#define OBJ_PARSER_H

#include <string>

#include "wireframe.h"

namespace s21 {
class ObjParser {
  Wireframe wireframe_;

 public:
  Wireframe ParseObj(const std::string filename) noexcept;

 private:
  void VarticesParsing(std::ifstream& obj_file) noexcept;

  void FacesParsing(std::ifstream& obj_file) noexcept;
  int GetIndexFromFaceLine(std::string& vertex_data) const noexcept;
  int IndexOfVerterToPositiveForm(int index) const noexcept;
};
}  // namespace s21

#endif