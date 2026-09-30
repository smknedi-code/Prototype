cmake_minimum_required(VERSION 3.22.1)

# =========================================================================
# === BISA KAMU UBAH DI SINI (NAMA PROJECT) ==============================
# =========================================================================
project("mynativeapp")

add_library(
        native-lib
        SHARED
        native-lib.cpp)

# Tambahkan file .cpp lain di sini jika kamu memecah kodingan menjadi beberapa file:
# SHARED native-lib.cpp file2.cpp file3.cpp

find_library(
        log-lib
        log)

target_link_libraries(
        native-lib
        ${log-lib})