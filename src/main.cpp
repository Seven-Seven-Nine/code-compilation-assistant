#include "../headers/argument_handler/ArgumentHandler.hpp"
#include "../headers/code_compilation_assistant/CodeCompilationAssistant.hpp"

int main(int argc, char* argv[]) {
  ArgumentHandler argumentHandler(argc, argv);
  argumentHandler.set_default_argument_name_compiler("clang++");
  argumentHandler.set_default_argument_name_version_language("20");

  CodeCompilationAssistant codeCompilationAssistant(
    argumentHandler.get_value_argument_path_src(),
    argumentHandler.get_value_argument_path_bin(),
    argumentHandler.get_value_argument_name_compiler(),
    argumentHandler.get_value_argument_version_language(),
    argumentHandler.get_value_argument_file_name()
  );
  
  codeCompilationAssistant.building_project();
  
  return 0;
}
