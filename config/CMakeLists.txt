add_library(config STATIC ConvertUTF.c ConvertUTF.h cxxopts.hpp SimpleIni.h)
target_include_directories(config PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
