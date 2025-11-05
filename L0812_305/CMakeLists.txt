# =============================================================================
#                     ИНСТРУКЦИЯ ПО СБОРКЕ ПРОГРАММЫ  
#  Автор: Копылов Кирилл MX-201 2025
# =============================================================================

# 0 Минимальная требуемая версия CMake
cmake_minimum_required(VERSION 3.10)
# ^-- "Для работы нужен CMake версии 3.10 или новее"


# 1 Название и версия проекта
project(FloydAlgorithm VERSION 1.0.0 LANGUAGES CXX)
# ^-- "Создаем проект 'FloydAlgorithm'"
#     VERSION 1.0.0 - версия проекта
#     LANGUAGES CXX - используем язык C++

# 2 Установка стандарта C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# ^-- "Используй стандарт C++11"


# 3 Включение текущей папки для поиска заголовочных файлов
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
# ^-- "Ищи файлы .h в этой же папке"
#     Чтобы компилятор нашел graph.h

# 4 Создание исполняемого файла
add_executable(floyd_program graph.cpp)
# ^-- "Создай программу 'floyd_program' из файла graph.cpp"
#     graph.h подключится автоматически через #include в graph.cpp

# 5 Переименование выходного файла
set_target_properties(floyd_program PROPERTIES OUTPUT_NAME "floyd")
# ^-- "Внутреннее имя: floyd_program, но выходной файл назови 'floyd'"
#     На Windows будет floyd.exe, на Linux/Mac - floyd

# 6 Настройки для Windows
if(WIN32)
    set_target_properties(floyd_program PROPERTIES WIN32_EXECUTABLE FALSE)
endif()
# ^-- "На Windows создавай консольное приложение, а не оконное"
#     Чтобы было обычное окно терминала, а не графическое окно

# 7 Включение дополнительных предупреждений компилятора
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(floyd_program PRIVATE -Wall -Wextra -pedantic)
endif()
# ^-- "Для компиляторов GCC и Clang включи ВСЕ предупреждения"
#     -Wall    - основные предупреждения
#     -Wextra  - дополнительные предупреждения  
#     -pedantic - строгая проверка стандарта
#     Помогает найти потенциальные ошибки в коде

# 8 Режим сборки по умолчанию (если не указан)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
# ^-- "Если тип сборки не указан, используй Debug"
#     Debug - с отладочной информацией 


# 9 Вывод информации о конфигурации
message(STATUS "==========================================")
message(STATUS " > Проект: ${PROJECT_NAME}")
message(STATUS " > Версия: ${PROJECT_VERSION}")
message(STATUS " > Компилятор: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS " > Стандарт C++: ${CMAKE_CXX_STANDARD}")
message(STATUS " > Тип сборки: ${CMAKE_BUILD_TYPE}")
message(STATUS " > Выходной файл: floyd")
message(STATUS "==========================================")
#     STATUS - выводит как информационное сообщение