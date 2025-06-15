/*
 * Pelicula.cpp
 * 
 * Implementación de la clase Pelicula, que hereda de Video y añade duración.
 * 
 * Proyecto: Proyecto Integrador - Programación Orientada a Objetos
 * Autor: Monserrat Hernández Lomas
 * Fecha: Junio 2025
 */
#include "Pelicula.h"

Pelicula::Pelicula(const std::string& id, const std::string& nombre, int duracion, const std::string& genero)
    : Video(id, nombre, duracion, genero) {}
