#include "Video.h"

Video::Video(const std::string& id, const std::string& nombre, int duracion, const std::string& genero)
    : id(id), nombre(nombre), duracion(duracion), genero(genero) {
    if (duracion < 0) {
        throw std::invalid_argument("Duración no puede ser negativa");
    }
}

std::string Video::getId() const { return id; }
std::string Video::getNombre() const { return nombre; }
int Video::getDuracion() const { return duracion; }
std::string Video::getGenero() const { return genero; }

void Video::agregarCalificacion(int cal) {
    if (cal < 1 || cal > 5) {
        throw std::out_of_range("Calificación debe estar entre 1 y 5");
    }
    calificaciones.push_back(cal);
}

double Video::getCalificacion() const {
    if (calificaciones.empty()) return 0.0;
    return static_cast<double>(std::accumulate(calificaciones.begin(), calificaciones.end(), 0)) / calificaciones.size();
}
