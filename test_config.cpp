#include <iostream>
#include <string>
#include <vector>

#include "SimpleIni.h"
#include "cxxopts.hpp"

int main(int argc, char* argv[]) {
  try {
    cxxopts::Options options(argv[0], "help string");
    options.positional_help("[optional args]").show_positional_help();

    options.allow_unrecognised_options().add_options()(
        "i,input", "input value", cxxopts::value<std::string>())(
        "f,floats", "float numbers",
        cxxopts::value<std::vector<float>>()->default_value(
            "1.0f, 2.3f, 4.56f"));

    options.add_options()("b,bool", "");
    options.add_options()(
        "pos", "positional",
        cxxopts::value<std::vector<int>>()->default_value("10"));

    options.add_options()("m", "marker",
                          cxxopts::value<std::string>()->default_value("mark"));

    options.add_options("Group")("h,help", "help");

    options.parse_positional({"m", "pos"});

    cxxopts::ParseResult result = options.parse(argc, argv);
    if (result.count("input")) {
      std::cout << result["input"].as<std::string>() << std::endl;
    }

    {
      auto nums = result["f"].as<std::vector<float>>();
      for (int i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << " ";
      }
      std::cout << std::endl;
    }

    if (result.count("bool")) {
      std::cout << result["bool"].as<bool>() << std::endl;
    }

    if (result.count("m")) {
      std::cout << result["m"].as<std::string>() << std::endl;
    }

    if (result.count("pos")) {
      auto nums = result["pos"].as<std::vector<int>>();
      for (int i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << " ";
      }
      std::cout << std::endl;
    }

    std::cout << options.help() << std::endl;

  } catch (const cxxopts::OptionException& e) {
    std::cerr << "error parsing options: " << e.what() << std::endl;
    exit(1);
  }

  CSimpleIni ini;
  ini.SetMultiKey(true);
  ini.LoadFile("test.ini");

  CSimpleIni::TNamesDepend values;
  ini.GetAllValues("section", "str1", values);

  double num = ini.GetDoubleValue("section2", "number", 0.0);

  ini.SetValue("section", "str1", "mystr1", nullptr, true);
  ini.SetValue("section", "str1", "mystr2");
  ini.SetValue("section", "str1", "mystr3");
  ini.SetValue("section", "str2", "string", "; string comment", true);
  ini.SetDoubleValue("section2", "number", 1.23, nullptr, true);
  ini.SaveFile("test.ini");
 
  return 0;
}