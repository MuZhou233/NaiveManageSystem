# cmake_minimum_required(VERSION <specify CMake version here>)
project(kechengsheji C)

set(CMAKE_C_STANDARD 11)

add_executable(kechengsheji main.c Model/UserModel.h Model/StatusModel.h Model/DataModel.h Model/MetaModel.h Model/ItemModel.h Controller/FileController.h Controller/UserController.h Controller/UserController.c Model/DataModel.c Base.h Model/StatusModel.c Controller/FileController.c Controller/ItemController.h Controller/ItemController.c)