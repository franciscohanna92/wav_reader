cmake_minimum_required(VERSION 3.12)
project(wav_reader C)

set(CMAKE_C_STANDARD 99)

add_executable(wav_reader main.c lib/wav_reader_methods.c lib/wav_reader_methods.h lib/wav_reader_types.h)