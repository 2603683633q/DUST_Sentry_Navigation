# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/rmsentry/ros_ws/build/small_gicp_relocalization/_deps/small_gicp-src"
  "/home/rmsentry/ros_ws/build/small_gicp_relocalization/_deps/small_gicp-build"
  "/home/rmsentry/ros_ws/build/small_gicp_relocalization/_deps/small_gicp-subbuild/small_gicp-populate-prefix"
  "/home/rmsentry/ros_ws/build/small_gicp_relocalization/_deps/small_gicp-subbuild/small_gicp-populate-prefix/tmp"
  "/home/rmsentry/ros_ws/build/small_gicp_relocalization/_deps/small_gicp-subbuild/small_gicp-populate-prefix/src/small_gicp-populate-stamp"
  "/home/rmsentry/ros_ws/build/small_gicp_relocalization/_deps/small_gicp-subbuild/small_gicp-populate-prefix/src"
  "/home/rmsentry/ros_ws/build/small_gicp_relocalization/_deps/small_gicp-subbuild/small_gicp-populate-prefix/src/small_gicp-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/rmsentry/ros_ws/build/small_gicp_relocalization/_deps/small_gicp-subbuild/small_gicp-populate-prefix/src/small_gicp-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/rmsentry/ros_ws/build/small_gicp_relocalization/_deps/small_gicp-subbuild/small_gicp-populate-prefix/src/small_gicp-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
