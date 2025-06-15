#ifndef EPISODIO_H
#define EPISODIO_H

#include <string>
#include <vector>
#include <numeric>
#include <stdexcept>

class Episodio {
private:
    std::string titulo;
    int temporada;
    std::vector<int> calificaciones;

public:
    Episodio(const std::string& titulo, int temporada);

    std::string getTitulo() const;
    int getTemporada() const;

    void calificar(int valor);
    double obtenerCalificacionPromedio() const;
};

#endif
