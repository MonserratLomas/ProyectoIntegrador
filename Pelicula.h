/*
 * Pelicula.h
 * 
 * Declaración de la clase Pelicula que hereda de Video.
 * 
 * Proyecto: Proyecto Integrador - Programación Orientada a Objetos
 * Autor: Monserrat Hernández Lomas
 * Fecha: Junio 2025
 */
#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula : public Video {
public:
    Pelicula(const std::string& id, const std::string& nombre, int duracion, const std::string& genero);
};

#endif
