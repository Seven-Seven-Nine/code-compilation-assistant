#include "../../headers/argument_handler/ArgumentHandler.hpp"

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <format>

ArgumentHandler::ArgumentHandler(int argc, char* argv[]) {
  #ifdef DEBUG
  std::cout << std::format("Режим отладки: количество переданных аргументов — {}.", argc) << std::endl;
  #endif

  for (int index = 1; index < argc; ++index) {
    std::string argument = argv[index];

    if (argument.rfind("--", 0) == 0) {
      size_t equal_position = argument.find('=');
      if (equal_position != std::string::npos) {
        std::string key = argument.substr(2, equal_position - 2);
        std::string value = argument.substr(equal_position + 1);

        #ifdef DEBUG
        std::cout << std::format("Режим отладки: найден переданный аргумент \"{}\", значение равно \"{}\"", key, value) << std::endl;
        #endif

        if (key == "path-src") {
          this->value_argument_path_src = value;
        } else if (key == "path-bin") {
          this->value_argument_path_bin = value;
        } else if (key == "name-compiler") {
          this->value_argument_name_compiler = value;
        } else if (key == "version-language") {
          this->value_argument_version_language = value;
        } else if (key == "file-name") {
          this->value_argument_file_name = value;
        }
      }
    }
  }
}
std::string ArgumentHandler::get_value_argument_path_src() const {
  if (this->value_argument_path_src.empty()) {
    std::cout << "Ошибка: значение аргумента \"path-src\" пустое!" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  return this->value_argument_path_src;
}

std::string ArgumentHandler::get_value_argument_path_bin() const {
  if (this->value_argument_path_bin.empty()) {
    std::cout << "Ошибка: значение аргумента \"path-bin\" пустое!" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  return this->value_argument_path_bin;
}

std::string ArgumentHandler::get_value_argument_name_compiler() const {
  if (this->value_argument_name_compiler.empty()) {
    std::cout << "Ошибка: значение аргумента \"name-compiler\" пустое!" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  return this->value_argument_name_compiler;
}

std::string ArgumentHandler::get_value_argument_version_language() const {
  if (this->value_argument_version_language.empty()) {
    std::cout << "Ошибка: значение аргумента \"version-language\" пустое!" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  return this->value_argument_version_language;
}

std::string ArgumentHandler::get_value_argument_file_name() const {
  if (this->value_argument_file_name.empty()) {
    std::cout << "Ошибка: значение переданного аргумента \"file_name\" пустое!" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  return this->value_argument_file_name;
}

void ArgumentHandler::set_default_argument_path_src(std::string value) {
  if (this->value_argument_path_src.empty()) {
    this->value_argument_path_src = value;
    #ifdef DEBUG
    std::cout << std::format("Режим отладки: установлено значение по умолчанию для аргумента \"path-src\": \"{}\".", value) << std::endl;
    #endif
  }
}

void ArgumentHandler::set_default_argument_path_bin(std::string value) {
  if (this->value_argument_path_bin.empty()) {
    this->value_argument_path_bin = value;
    #ifdef DEBUG
    std::cout << std::format("Режим отладки: установлено значение по умолчанию для аргумента \"path-bin\": \"{}\".", value) << std::endl;
    #endif
  }
}

void ArgumentHandler::set_default_argument_name_compiler(std::string value) {
  if (this->value_argument_name_compiler.empty()) {
    this->value_argument_name_compiler = value;
    #ifdef DEBUG    
    std::cout << std::format("Режим отладки: установлено значение по умолчанию для аргумента \"name-compiler\": \"{}\".", value) << std::endl;
    #endif
  }
}

void ArgumentHandler::set_default_argument_name_version_language(std::string value) {
  if (this->value_argument_version_language.empty()) {
    this->value_argument_version_language = value;
    #ifdef DEBUG
    std::cout << std::format("Режим отладки: установлено значение по умолчанию для аргумента \"version-language\": \"{}\".", value) << std::endl;
    #endif
  }
}

void ArgumentHandler::set_default_argument_file_name(std::string value) {
  if (this->value_argument_file_name.empty()) {
    this->value_argument_file_name = value;
    #ifdef DEBUG
    std::cout << std::format("Режим отладки: установлено значение по умолчанию для аргумента \"file-name\": \"{}\".", value) << std::endl;
    #endif
  }
}
