/*
 * Episodio.h
 * 
 * Declaración de la clase Episodio utilizada en una Serie.
 * 
 * Proyecto: Proyecto Integrador - Programación Orientada a Objetos
 * Autor: Monserrat Hernández Lomas
 * Fecha: Junio 2025
 */

#ifndef EPISODIO_H
#define EPISODIO_H

#include <string>
#include <vector>
#include <numeric>
#include <stdexcept>

/**
 * @class Episodio
 * @brief Representa un episodio de una serie con calificaciones.
 */
class Episodio {
private:
    std::string titulo;                 ///< Título del episodio
    int temporada;                     ///< Número de la temporada
    std::vector<int> calificaciones;   ///< Lista de calificaciones recibidas

public:
    /**
     * @brief Constructor para crear un episodio.
     * @param titulo Título del episodio.
     * @param temporada Número de la temporada.
     */
    Episodio(const std::string& titulo, int temporada);

    /**
     * @brief Obtiene el título del episodio.
     * @return Título.
     */
    std::string getTitulo() const;

    /**
     * @brief Obtiene el número de temporada del episodio.
     * @return Número de temporada.
     */
    int getTemporada() const;

    /**
     * @brief Agrega una calificación al episodio.
     * @param valor Calificación a agregar (por ejemplo, de 1 a 10).
     */
    void calificar(int valor);

    /**
     * @brief Calcula el promedio de calificaciones.
     * @return Promedio de las calificaciones, o 0 si no hay ninguna.
     */
    double obtenerCalificacionPromedio() const;
};

#endif
