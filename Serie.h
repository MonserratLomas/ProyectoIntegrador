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

/**
 * @class Serie
 * @brief Clase que representa una serie de televisión o similar, hereda de Video.
 * 
 * Contiene información adicional específica como temporada y título del episodio.
 */
class Serie : public Video {
private:
    int temporada;               ///< Número de la temporada
    std::string tituloEpisodio; ///< Título del episodio

public:
    /**
     * @brief Constructor de la clase Serie.
     * @param id Identificador único de la serie.
     * @param nombre Nombre de la serie.
     * @param duracion Duración del episodio en minutos.
     * @param genero Género de la serie.
     * @param temporada Número de la temporada del episodio.
     * @param tituloEpisodio Título del episodio.
     */
    Serie(const std::string& id, const std::string& nombre, int duracion, const std::string& genero, int temporada, const std::string& tituloEpisodio);

    /**
     * @brief Obtiene el número de temporada del episodio.
     * @return Número de temporada.
     */
    int getTemporada() const;

    /**
     * @brief Obtiene el título del episodio.
     * @return Título del episodio.
     */
    std::string getTituloEpisodio() const;
};

#endif
