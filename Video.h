/*
 * Video.h
 * 
 * Declaración de la clase base Video.
 * 
 * Proyecto: Proyecto Integrador - Programación Orientada a Objetos
 * Autor: Monserrat Hernández Lomas
 * Fecha: Junio 2025
 */

#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <vector>
#include <numeric>
#include <stdexcept>

/**
 * @class Video
 * @brief Clase base que representa un video genérico.
 * 
 * Contiene información básica del video como id, nombre, duración y género,
 * así como un sistema para almacenar y calcular calificaciones.
 */
class Video {
protected:
    std::string id;                  /**< Identificador único del video */
    std::string nombre;              /**< Nombre o título del video */
    int duracion;                   /**< Duración del video en minutos */
    std::string genero;              /**< Género del video */
    std::vector<int> calificaciones;/**< Vector que almacena las calificaciones otorgadas */

public:
    /**
     * @brief Constructor de la clase Video.
     * @param id Identificador único del video.
     * @param nombre Nombre o título del video.
     * @param duracion Duración del video en minutos (debe ser positiva).
     * @param genero Género al que pertenece el video.
     * @throws std::invalid_argument si la duración es negativa o cero.
     */
    Video(const std::string& id, const std::string& nombre, int duracion, const std::string& genero);

    /**
     * @brief Obtiene el identificador del video.
     * @return Cadena con el id del video.
     */
    std::string GetId() const;

    /**
     * @brief Obtiene el nombre del video.
     * @return Cadena con el nombre del video.
     */
    std::string GetNombre() const;

    /**
     * @brief Obtiene la duración del video.
     * @return Duración en minutos.
     */
    int GetDuracion() const;

    /**
     * @brief Obtiene el género del video.
     * @return Cadena con el género del video.
     */
    std::string GetGenero() const;

    /**
     * @brief Agrega una calificación al video.
     * @param cal Valor de la calificación (usualmente en un rango definido, por ejemplo 1 a 10).
     */
    virtual void AgregarCalificacion(int cal);

    /**
     * @brief Calcula y obtiene la calificación promedio del video.
     * @return Promedio de las calificaciones. Retorna 0 si no hay calificaciones.
     */
    virtual double GetCalificacion() const;
};

#endif
