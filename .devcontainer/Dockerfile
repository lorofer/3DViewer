FROM mcr.microsoft.com/devcontainers/base:debian

# Добавляем contrib и non-free секции
RUN sed -i 's/main/main contrib non-free/g' /etc/apt/sources.list.d/debian.sources

# Устанавливаем базовые пакеты и все зависимости для Qt/XCB
RUN apt-get update && apt-get install -y \
    # Компиляторы и базовые инструменты
    g++ \
    pkg-config \
    make \
    cmake \
    # Qt6
    qt6-base-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    # Все XCB зависимости для Qt плагина xcb
    libxcb-cursor0 \
    libxcb-randr0-dev \
    libxcb-render0-dev \
    libxcb-shape0-dev \
    libxcb-sync0-dev \
    libxcb-xfixes0-dev \
    libxcb-xinerama0-dev \
    libxcb-xkb-dev \
    libxcb-cursor-dev \
    libxcb-icccm4-dev \
    libxcb-image0-dev \
    libxcb-keysyms1-dev \
    libxcb-render-util0-dev \
    libxcb-util-dev \
    libxcb-xinput-dev \
    libxcb-xtest0-dev \
    libxkbcommon-x11-dev \
    # Исходные пакеты (для полноты)
    valgrind \
    clang-format \
    iwyu \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install -y \
    libgtest-dev \
    && cd /usr/src/gtest \
    && cmake CMakeLists.txt \
    && make \
    && cp lib/*.a /usr/lib \
    && rm -rf /usr/src/gtest