# Переменные
CXX = g++
CXXFLAGS = -Wall -Werror -Wpedantic -g -std=c++23 -I./src -I./submodules/pybind11/include/pybind11 $(python3 -m pybind11 --includes) $(shell python3-config --includes)
LDFLAGS = -lgtest -lgtest_main -pthread $(shell python3-config --ldflags) $(python3-config --extension-suffix)

# Директории
PREF_SRC = ./src/
PREF_OBJ = ./obj/
PREF_TST = ./tests/
PREF_SH = ./

# Списки всех файлов
SRC = $(wildcard $(PREF_SRC)*.cpp)                             # Исходные файлы
OBJ = $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(SRC))     # Объектные файлы
TST = $(wildcard $(PREF_TST)*.cpp)                             # Файлы тестов
TST_OBJ = $(patsubst $(PREF_TST)%.cpp, $(PREF_OBJ)%.o, $(TST)) # Объектные файлы тестов
SH = $(wildcard $(PREF_SH)*.sh)                                # Скрипты

# Исполняемые файлы
TARGET = output
TARGET_TST = output_tst


# Цель по умолчанию
all: setup $(TARGET) clean

# Подключение скриптов
setup:
	if [ -n "$(SH)" ]; then chmod +x $(SH); fi

# Создание папки для объектных файлов
$(PREF_OBJ):
	mkdir -p $(PREF_OBJ)

# Компиляция основного кода
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(PREF_OBJ)%.o: $(PREF_SRC)%.cpp | $(PREF_OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Сборка и запуск тестов
build: $(TARGET_TST) all

$(TARGET_TST): $(filter-out $(PREF_OBJ)main.o, $(OBJ)) $(TST_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(PREF_OBJ)%.o: $(PREF_TST)%.cpp | $(PREF_OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(PREF_OBJ)*.o

cleanall: clean
	rm -f $(TARGET) $(TARGET_TST)

# Запуск основного приложения
run: $(TARGET)
	./$(TARGET)

# Запуск тестов
runtest: $(TARGET_TST)
	./$(TARGET_TST)

# Форматирование кода
format:
	find ./src/ -name '*.cpp' -exec astyle --options=style.astylerc {} \;
	find ./tests/ -name '*.cpp' -exec astyle --options=style.astylerc {} \;

.PHONY: all setup test clean cleanall run runtest format
