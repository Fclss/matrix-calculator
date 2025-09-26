FROM gcc:12.2.0

# Установка зависимостей
RUN apt-get update && apt-get install -y \
    doxygen \
    graphviz \
    && rm -rf /var/lib/apt/lists/*

# Рабочая директория
WORKDIR /app

# Копирование исходников
COPY src/ ./src/
COPY Makefile Doxyfile ./

# Сборка
RUN make all

# Документация
RUN make docs

# Точка входа
CMD ["./test_app"]