/*
 * Episodio.cpp
 * 
 * Implementación de la clase Episodio, parte de una Serie.
 * 
 * Proyecto: Proyecto Integrador - Programación Orientada a Objetos
 * Autor: Monserrat Hernández Lomas
 * Fecha: Junio 2025
 */
#include "Episodio.h"

Episodio::Episodio(const std::string& titulo, int temporada)
    : titulo(titulo), temporada(temporada) {}

std::string Episodio::GetTitulo() const { return titulo; }
int Episodio::GetTemporada() const { return temporada; }

void Episodio::Calificar(int valor) {
    if (valor < 1 || valor > 5) {
        throw std::out_of_range("Calificación debe estar entre 1 y 5");
    }
    calificaciones.push_back(valor);
}

double Episodio::ObtenerCalificacionPromedio() const {
    if (calificaciones.empty()) return 0.0;
    return static_cast<double>(std::accumulate(calificaciones.begin(), calificaciones.end(), 0)) / calificaciones.size();
}
