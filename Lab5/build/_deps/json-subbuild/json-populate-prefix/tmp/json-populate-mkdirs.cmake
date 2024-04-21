# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/media/SharedFiles/Lab5/build/_deps/json-src"
  "/media/SharedFiles/Lab5/build/_deps/json-build"
  "/media/SharedFiles/Lab5/build/_deps/json-subbuild/json-populate-prefix"
  "/media/SharedFiles/Lab5/build/_deps/json-subbuild/json-populate-prefix/tmp"
  "/media/SharedFiles/Lab5/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp"
  "/media/SharedFiles/Lab5/build/_deps/json-subbuild/json-populate-prefix/src"
  "/media/SharedFiles/Lab5/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/media/SharedFiles/Lab5/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/media/SharedFiles/Lab5/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
