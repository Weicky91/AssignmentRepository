include_directories(${PROJECT_SOURCE_DIR}/header)

cmake_minimum_required(VERSION 3.20)

project(queue_stack)

add_executable(queue_stack src/main.c src/queue.c src/stack.c)