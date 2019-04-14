# cmake_minimum_required(VERSION <specify CMake version here>)
project(cflamemaker)

set(CMAKE_CXX_STANDARD 17)

add_executable(cflamemaker src/main.cpp src/geometry2d/Point.cpp src/geometry2d/Point.h src/geometry2d/Rectangle.cpp src/geometry2d/Rectangle.h src/color/Palette.cpp src/color/Palette.h src/color/Color.cpp src/color/Color.h src/geometry2d/AffineTransformation.cpp src/geometry2d/AffineTransformation.h src/color/InterpolatedPalette.cpp src/color/InterpolatedPalette.h src/color/RandomPalette.cpp src/color/RandomPalette.h src/flame/FlameTransformation.cpp src/flame/FlameTransformation.h src/geometry2d/Transformation.h src/flame/Variation.cpp src/flame/Variation.h src/flame/FlameAccumulator.cpp src/flame/FlameAccumulator.h src/flame/Flame.cpp src/flame/Flame.h)