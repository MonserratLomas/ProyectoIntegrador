#include <gtest/gtest.h>
#include "../Serie.h"

TEST(SerieTest, CreaSerieCorrectamente) {
    Serie serie("010", "Breaking Bad", 45, "Drama", 1, "Pilot");

    EXPECT_EQ(serie.getId(), "010");
    EXPECT_EQ(serie.getNombre(), "Breaking Bad");
    EXPECT_EQ(serie.getDuracion(), 45);
    EXPECT_EQ(serie.getGenero(), "Drama");
    EXPECT_EQ(serie.getTemporada(), 1);
    EXPECT_EQ(serie.getTituloEpisodio(), "Pilot");
}

TEST(SerieTest, HeredaCalificacionDeVideo) {
    Serie serie("011", "Stranger Things", 50, "Ciencia Ficción", 2, "Chapter One");

    EXPECT_DOUBLE_EQ(serie.getCalificacion(), 0.0);

    serie.agregarCalificacion(3);
    serie.agregarCalificacion(4);

    EXPECT_DOUBLE_EQ(serie.getCalificacion(), 3.5);
}

TEST(SerieTest, RechazaCalificacionesInvalidas) {
    Serie serie("012", "The Witcher", 55, "Fantasía", 3, "The End's Beginning");

    EXPECT_THROW(serie.agregarCalificacion(0), std::out_of_range);
    EXPECT_THROW(serie.agregarCalificacion(6), std::out_of_range);
}
