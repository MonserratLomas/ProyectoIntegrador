/*
 * Serie.cpp
 * 
 * Implementación de la clase Serie, que hereda de Video y contiene episodios.
 * 
 * Proyecto: Proyecto Integrador - Programación Orientada a Objetos
 * Autor: Monserrat Hernández Lomas
 * Fecha: Junio 2025
 */
#include "Serie.h"

Serie::Serie(const std::string& id, const std::string& nombre, int duracion, const std::string& genero, int temporada, const std::string& tituloEpisodio)
    : Video(id, nombre, duracion, genero), temporada(temporada), tituloEpisodio(tituloEpisodio) {}

int Serie::GetTemporada() const { return temporada; }
std::string Serie::GetTituloEpisodio() const { return tituloEpisodio; }
