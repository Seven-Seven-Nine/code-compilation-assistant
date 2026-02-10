#pragma once

#include <string>

class ArgumentHandler {
  private:
    std::string value_argument_path_src;
    std::string value_argument_path_bin;
    std::string value_argument_name_compiler;
    std::string value_argument_version_language;
    std::string value_argument_file_name;
  public:
    ArgumentHandler(int argc, char* argv[]);
    std::string get_value_argument_path_src() const;
    std::string get_value_argument_path_bin() const;
    std::string get_value_argument_name_compiler() const;
    std::string get_value_argument_version_language() const;
    std::string get_value_argument_file_name() const;
    void set_default_argument_path_src(std::string value);
    void set_default_argument_path_bin(std::string value);
    void set_default_argument_name_compiler(std::string value);
    void set_default_argument_name_version_language(std::string value);
    void set_default_argument_file_name(std::string value);
};
