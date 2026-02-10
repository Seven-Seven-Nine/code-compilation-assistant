#pragma once

#include <string>
#include <vector>

class CodeCompilationAssistant {
  private:
    std::string path_src;
    std::string path_bin;
    std::string name_compiler;
    std::string version_language;
    std::string file_name;
    std::vector<std::string> src_file_paths;
    /**
     * Инициализирет файлы исходного кода, ищет все файлы в директории с исходным кодом и создаёт пути до них, в конце добавляя каждый путь исходного файла в вектор путей исходных файлов.
     */
    void initializing_src_file_paths();
    /**
     * Компиляция исходного кода с помощью составления команды в виде строки и исполнения её в системе через API, например через clang или черех gcc.
     */
    void compiling_source_code();
    /**
     * Копирование ассетов в директорию для компиляции.
     */
    void copying_assets();
  public:
    CodeCompilationAssistant(std::string path_src, std::string path_bin, std::string name_compiler, std::string version_language, std::string file_name);
    /**
     * Сборка проекта, в начале выполняется инициализация файлов исходного кода, потом компиляция исходного кода, а потом уже копирование дополнительных ресурсов.
     */
    void building_project();
};
