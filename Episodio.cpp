#include "Episodio.h"

Episodio::Episodio(const std::string& titulo, int temporada)
    : titulo(titulo), temporada(temporada) {}

std::string Episodio::getTitulo() const { return titulo; }
int Episodio::getTemporada() const { return temporada; }

void Episodio::calificar(int valor) {
    if (valor < 1 || valor > 5) {
        throw std::out_of_range("Calificación debe estar entre 1 y 5");
    }
    calificaciones.push_back(valor);
}

double Episodio::obtenerCalificacionPromedio() const {
    if (calificaciones.empty()) return 0.0;
    return static_cast<double>(std::accumulate(calificaciones.begin(), calificaciones.end(), 0)) / calificaciones.size();
}
