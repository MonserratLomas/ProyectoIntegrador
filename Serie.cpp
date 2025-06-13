#include "Serie.h"

Serie::Serie(const std::string& id, const std::string& nombre, int duracion, const std::string& genero, int temporada, const std::string& tituloEpisodio)
    : Video(id, nombre, duracion, genero), temporada(temporada), tituloEpisodio(tituloEpisodio) {}

int Serie::getTemporada() const { return temporada; }
std::string Serie::getTituloEpisodio() const { return tituloEpisodio; }
