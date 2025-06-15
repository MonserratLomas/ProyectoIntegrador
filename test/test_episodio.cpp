/*
 * test_episodio.cpp
 * 
 * Pruebas unitarias para la clase Episodio.
 * 
 * Proyecto: Proyecto Integrador - Programación Orientada a Objetos
 * Autor: Monserrat Hernández Lomas
 * Fecha: Junio 2025
 */
#include <gtest/gtest.h>
#include "../Episodio.h"

TEST(EpisodioTest, CreaEpisodioCorrectamente) {
    Episodio episodio("El comienzo", 1);

    EXPECT_EQ(episodio.GetTitulo(), "El comienzo");
    EXPECT_EQ(episodio.GetTemporada(), 1);
}

TEST(EpisodioTest, CalificacionPromedioInicialEsCero) {
    Episodio episodio("Capítulo 2", 1);

    EXPECT_DOUBLE_EQ(episodio.ObtenerCalificacionPromedio(), 0.0);
}

TEST(EpisodioTest, AgregaCalificacionesValidas) {
    Episodio episodio("Capítulo 3", 1);

    episodio.Calificar(3);
    episodio.Calificar(5);

    EXPECT_DOUBLE_EQ(episodio.ObtenerCalificacionPromedio(), 4.0);
}

TEST(EpisodioTest, RechazaCalificacionesInvalidas) {
    Episodio episodio("Capítulo 4", 2);

    EXPECT_THROW(episodio.Calificar(0), std::out_of_range);
    EXPECT_THROW(episodio.Calificar(6), std::out_of_range);
}
