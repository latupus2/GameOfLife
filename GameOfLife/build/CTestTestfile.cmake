# CMake generated Testfile for 
# Source directory: F:/VScode/NSU/OOP/GameLife/Make
# Build directory: F:/VScode/NSU/OOP/GameLife/Make/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(GameOfLifeTests "F:/VScode/NSU/OOP/GameLife/Make/build/Debug/runTests.exe")
  set_tests_properties(GameOfLifeTests PROPERTIES  _BACKTRACE_TRIPLES "F:/VScode/NSU/OOP/GameLife/Make/CMakeLists.txt;30;add_test;F:/VScode/NSU/OOP/GameLife/Make/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(GameOfLifeTests "F:/VScode/NSU/OOP/GameLife/Make/build/Release/runTests.exe")
  set_tests_properties(GameOfLifeTests PROPERTIES  _BACKTRACE_TRIPLES "F:/VScode/NSU/OOP/GameLife/Make/CMakeLists.txt;30;add_test;F:/VScode/NSU/OOP/GameLife/Make/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(GameOfLifeTests "F:/VScode/NSU/OOP/GameLife/Make/build/MinSizeRel/runTests.exe")
  set_tests_properties(GameOfLifeTests PROPERTIES  _BACKTRACE_TRIPLES "F:/VScode/NSU/OOP/GameLife/Make/CMakeLists.txt;30;add_test;F:/VScode/NSU/OOP/GameLife/Make/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(GameOfLifeTests "F:/VScode/NSU/OOP/GameLife/Make/build/RelWithDebInfo/runTests.exe")
  set_tests_properties(GameOfLifeTests PROPERTIES  _BACKTRACE_TRIPLES "F:/VScode/NSU/OOP/GameLife/Make/CMakeLists.txt;30;add_test;F:/VScode/NSU/OOP/GameLife/Make/CMakeLists.txt;0;")
else()
  add_test(GameOfLifeTests NOT_AVAILABLE)
endif()
