/*
 * test_video.cpp
 * 
 * Pruebas unitarias para la clase Video.
 * 
 * Proyecto: Proyecto Integrador - Programación Orientada a Objetos
 * Autor: Monserrat Hernández Lomas
 * Fecha: Junio 2025
 */
#include <gtest/gtest.h>
#include "../Video.h"

TEST(VideoTest, CreaVideoCorrectamente) {
    Video video("001", "Matrix", 120, "Acción");

    EXPECT_EQ(video.GetId(), "001");
    EXPECT_EQ(video.GetNombre(), "Matrix");
    EXPECT_EQ(video.GetDuracion(), 120);
    EXPECT_EQ(video.GetGenero(), "Acción");
}

TEST(VideoTest, CalificacionVaciaDevuelveCero) {
    Video video("002", "Vacío", 90, "Drama");

    EXPECT_DOUBLE_EQ(video.GetCalificacion(), 0.0);
}

TEST(VideoTest, AgregaCalificacionesValidas) {
    Video video("003", "Test", 100, "Comedia");

    video.AgregarCalificacion(4);
    video.AgregarCalificacion(5);

    EXPECT_DOUBLE_EQ(video.GetCalificacion(), 4.5);
}

TEST(VideoTest, RechazaCalificacionesInvalidas) {
    Video video("004", "Test", 100, "Comedia");

    EXPECT_THROW(video.AgregarCalificacion(0), std::out_of_range);
    EXPECT_THROW(video.AgregarCalificacion(6), std::out_of_range);
}

TEST(VideoTest, LanzaExcepcionDuracionNegativa) {
    EXPECT_THROW(Video("005", "Error", -10, "Terror"), std::invalid_argument);
}
