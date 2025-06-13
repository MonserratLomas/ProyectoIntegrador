#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <vector>
#include <numeric>

class Video {
protected:
    std::string id;
    std::string nombre;
    int duracion;
    std::string genero;
    std::vector<int> calificaciones;

public:
    Video(const std::string& id, const std::string& nombre, int duracion, const std::string& genero);
    virtual ~Video() {}

    std::string getId() const;
    std::string getNombre() const;
    int getDuracion() const;
    std::string getGenero() const;
    void agregarCalificacion(int cal);
    double getCalificacion() const;
};

#endif
