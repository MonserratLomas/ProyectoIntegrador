/*
 * Serie.h
 * 
 * Declaración de la clase Serie que hereda de Video.
 * 
 * Proyecto: Proyecto Integrador - Programación Orientada a Objetos
 * Autor: Monserrat Hernández Lomas
 * Fecha: Junio 2025
 */
#ifndef SERIE_H
#define SERIE_H

#include "Video.h"
#include <string>

class Serie : public Video {
private:
    int temporada;
    std::string tituloEpisodio;

public:
    Serie(const std::string& id, const std::string& nombre, int duracion, const std::string& genero, int temporada, const std::string& tituloEpisodio);

    int getTemporada() const;
    std::string getTituloEpisodio() const;
};

#endif
