/*
 * test_serie.cpp
 * 
 * Pruebas unitarias para la clase Serie.
 * 
 * Proyecto: Proyecto Integrador - Programación Orientada a Objetos
 * Autor: Monserrat Hernández Lomas
 * Fecha: Junio 2025
 */
#include <gtest/gtest.h>
#include "../Serie.h"

TEST(SerieTest, CreaSerieCorrectamente) {
    Serie serie("010", "Breaking Bad", 45, "Drama", 1, "Pilot");

    EXPECT_EQ(serie.GetId(), "010");
    EXPECT_EQ(serie.GetNombre(), "Breaking Bad");
    EXPECT_EQ(serie.GetDuracion(), 45);
    EXPECT_EQ(serie.GetGenero(), "Drama");
    EXPECT_EQ(serie.GetTemporada(), 1);
    EXPECT_EQ(serie.GetTituloEpisodio(), "Pilot");
}

TEST(SerieTest, HeredaCalificacionDeVideo) {
    Serie serie("011", "Stranger Things", 50, "Ciencia Ficción", 2, "Chapter One");

    EXPECT_DOUBLE_EQ(serie.GetCalificacion(), 0.0);

    serie.AgregarCalificacion(3);
    serie.AgregarCalificacion(4);

    EXPECT_DOUBLE_EQ(serie.GetCalificacion(), 3.5);
}

TEST(SerieTest, RechazaCalificacionesInvalidas) {
    Serie serie("012", "The Witcher", 55, "Fantasía", 3, "The End's Beginning");

    EXPECT_THROW(serie.AgregarCalificacion(0), std::out_of_range);
    EXPECT_THROW(serie.AgregarCalificacion(6), std::out_of_range);
}
