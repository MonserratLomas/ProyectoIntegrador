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

/**
 * @class Pelicula
 * @brief Clase que representa una película, hereda de Video.
 * 
 * Implementa características específicas para películas.
 */
class Pelicula : public Video {
public:
    /**
     * @brief Constructor de la clase Pelicula.
     * @param id Identificador único de la película.
     * @param nombre Nombre o título de la película.
     * @param duracion Duración de la película en minutos.
     * @param genero Género de la película.
     */
    Pelicula(const std::string& id, const std::string& nombre, int duracion, const std::string& genero);
};

#endif
