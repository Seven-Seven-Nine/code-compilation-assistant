#include "../../headers/code_compilation_assistant/CodeCompilationAssistant.hpp"

#include <cstdlib>
#include <exception>
#include <filesystem>
#include <iostream>
#include <format>

void CodeCompilationAssistant::initializing_src_file_paths() {
  try {
    if (this->path_src.empty()) {
      std::cerr << "Ошибка: не удалось получить путь директории с исходным кодом." << std::endl;
      std::exit(EXIT_FAILURE);
    }
    
    if (!std::filesystem::exists(this->path_src)) {
      std::cerr << std::format("Ошибка: директории по пути \"{}\" не существует.", path_src) << std::endl;
      std::exit(EXIT_FAILURE);
    }

    this->src_file_paths.clear();

    for (const auto& entry : std::filesystem::recursive_directory_iterator(this->path_src)) {
      if (entry.is_regular_file() && entry.path().extension() == ".cpp") {
        this->src_file_paths.push_back(entry.path().string());
        #ifdef DEBUG
        std::cout << std::format("Режим отладки: найден файл по пути: \"{}\".", entry.path().string()) << std::endl;
        #endif
      }
    }

    if (this->src_file_paths.empty()) {
      std::cerr << std::format("Ошибка: в директории \"{}\" не найдены файлы исходного кода. Компиляция не возможна.", this->path_src) << std::endl;
      std::exit(EXIT_FAILURE);
    }

    #ifdef DEBUG
    std::cout << std::format("Режим отладки: всего найдено {} файлов исходного кода.", this->src_file_paths.size()) << std::endl;
    #endif
  } catch (const std::filesystem::filesystem_error& error) {
    std::cerr << std::format("Ошибка файловой системы: {}.", error.what()) << std::endl;
    std::exit(EXIT_FAILURE);
  } catch (const std::exception& error) {
    std::cerr << std::format("Ошибка при инициализации файлов исходного кода: {}.", error.what()) << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

void CodeCompilationAssistant::compiling_source_code() {
  if (this->path_bin.empty()) {
    std::cerr << "Ошибка: не удалось получить путь директории для компиляции исходного кода." << std::endl;
    std::exit(EXIT_FAILURE);
  }

  if (this->src_file_paths.empty()) {
    std::cerr << "Ошибка: вектор с путями файлов с исходным кодом пуст!" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  std::string source_code_file_paths = "";

  for (std::string& relative_path_src : this->src_file_paths) {
    if (relative_path_src == this->src_file_paths.back()) {
      source_code_file_paths += relative_path_src;
    } else {
       source_code_file_paths += relative_path_src + " "; 
    }
  }
  
  std::string compilation_command = std::format("{} -std=c++{} {} -o {}/{}", this->name_compiler, this->version_language, source_code_file_paths, this->path_bin, this->file_name);

  #ifdef DEBUG
  std::cout << std::format("Режим отладки: созданная команда для компиляции исходного кода — \"{}\".", compilation_command) << std::endl;
  #endif

  int result_command_execution = std::system(compilation_command.c_str());

  if (result_command_execution == 0) {
    std::cout << "Компиляция исходного кода в исполняемый файл завершена успешно." << std::endl;
  } else {
    std::cerr << "Ошибка: компиляция исполняемого файла завершилось ошибкой!" << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

void CodeCompilationAssistant::copying_assets() {}

CodeCompilationAssistant::CodeCompilationAssistant(std::string path_src, std::string path_bin, std::string name_compiler, std::string version_language, std::string file_name) {
  this->path_src = path_src;
  this->path_bin = path_bin;
  this->name_compiler = name_compiler;
  this->version_language = version_language;
  this->file_name = file_name;
}

void CodeCompilationAssistant::building_project() {
  this->initializing_src_file_paths();
  this->compiling_source_code();
  this->copying_assets();
}
