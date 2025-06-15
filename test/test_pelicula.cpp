/*
 * test_pelicula.cpp
 * 
 * Pruebas unitarias para la clase Pelicula.
 * 
 * Proyecto: Proyecto Integrador - Programación Orientada a Objetos
 * Autor: Monserrat Hernández Lomas
 * Fecha: Junio 2025
 */
#include <gtest/gtest.h>
#include "../Pelicula.h"

TEST(PeliculaTest, CreaPeliculaCorrectamente) {
    Pelicula pelicula("100", "Inception", 148, "Ciencia Ficción");

    EXPECT_EQ(pelicula.GetId(), "100");
    EXPECT_EQ(pelicula.GetNombre(), "Inception");
    EXPECT_EQ(pelicula.GetDuracion(), 148);
    EXPECT_EQ(pelicula.GetGenero(), "Ciencia Ficción");
}

TEST(PeliculaTest, CalificacionInicialEsCero) {
    Pelicula pelicula("101", "Interstellar", 169, "Ciencia Ficción");

    EXPECT_DOUBLE_EQ(pelicula.GetCalificacion(), 0.0);
}

TEST(PeliculaTest, AgregaCalificacionesYCalculaPromedio) {
    Pelicula pelicula("102", "The Matrix", 136, "Acción");

    pelicula.AgregarCalificacion(5);
    pelicula.AgregarCalificacion(4);

    EXPECT_DOUBLE_EQ(pelicula.GetCalificacion(), 4.5);
}

TEST(PeliculaTest, RechazaCalificacionesInvalidas) {
    Pelicula pelicula("103", "Gladiator", 155, "Acción");

    EXPECT_THROW(pelicula.AgregarCalificacion(0), std::out_of_range);
    EXPECT_THROW(pelicula.AgregarCalificacion(6), std::out_of_range);
}
