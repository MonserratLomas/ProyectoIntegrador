#include "Pelicula.h"

Pelicula::Pelicula(const std::string& id, const std::string& nombre, int duracion, const std::string& genero)
    : Video(id, nombre, duracion, genero) {}
