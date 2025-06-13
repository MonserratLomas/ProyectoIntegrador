#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula : public Video {
public:
    Pelicula(const std::string& id, const std::string& nombre, int duracion, const std::string& genero);
};

#endif
