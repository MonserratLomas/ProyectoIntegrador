#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <vector>
#include <numeric>
#include <stdexcept>

class Video {
protected:
    std::string id;
    std::string nombre;
    int duracion;
    std::string genero;
    std::vector<int> calificaciones;

public:
    Video(const std::string& id, const std::string& nombre, int duracion, const std::string& genero);

    std::string getId() const;
    std::string getNombre() const;
    int getDuracion() const;
    std::string getGenero() const;

    virtual void agregarCalificacion(int cal);
    virtual double getCalificacion() const;
};

#endif
