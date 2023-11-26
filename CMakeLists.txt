
cmake_minimum_required(VERSION 3.18.0)
project(sisfml LANGUAGES CXX)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    add_compile_options(-Wall -Wpedantic)
endif()

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(sisfml main.cpp taille.cpp taille.h jeu.h jeu.cpp position.cpp position.h invader.cpp invader.h projectile.cpp projectile.h joueur.cpp joueur.h taille.cpp objet.cpp objet_actif.h  objet_actif.cpp objet.h)

target_link_libraries(sisfml PRIVATE sfml-graphics sfml-window sfml-system)

target_compile_features(sisfml PRIVATE cxx_std_17)
