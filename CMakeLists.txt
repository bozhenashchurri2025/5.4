# Встановлюємо мінімальну необхідну версію CMake
cmake_minimum_required(VERSION 3.14)

# Назва вашого проєкту
project(SummationProject)

# Встановлюємо стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Налаштування Google Test ---
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# --- Збірка основної програми ---
add_executable(MyApp 5.4.cpp functions.cpp)

# --- Збірка тестів ---
enable_testing()

# Додаємо виконуваний файл для тестів
# (Використовуємо ваш шлях до файлу UnitTest.cpp)
add_executable(runTests tests/UnitTest.cpp functions.cpp)

# -- ✅ ОСЬ ВИПРАВЛЕННЯ ✅ --
# Вказуємо, де шукати заголовочні файли (.h) для тестів
target_include_directories(runTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Підключаємо бібліотеки Google Test до нашого тестового файлу
target_link_libraries(runTests PRIVATE GTest::gtest_main)

# Додаємо тест до системи CTest
include(GoogleTest)
gtest_discover_tests(runTests)