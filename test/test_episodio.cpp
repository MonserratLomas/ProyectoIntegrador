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

    EXPECT_EQ(episodio.getTitulo(), "El comienzo");
    EXPECT_EQ(episodio.getTemporada(), 1);
}

TEST(EpisodioTest, CalificacionPromedioInicialEsCero) {
    Episodio episodio("Capítulo 2", 1);

    EXPECT_DOUBLE_EQ(episodio.obtenerCalificacionPromedio(), 0.0);
}

TEST(EpisodioTest, AgregaCalificacionesValidas) {
    Episodio episodio("Capítulo 3", 1);

    episodio.calificar(3);
    episodio.calificar(5);

    EXPECT_DOUBLE_EQ(episodio.obtenerCalificacionPromedio(), 4.0);
}

TEST(EpisodioTest, RechazaCalificacionesInvalidas) {
    Episodio episodio("Capítulo 4", 2);

    EXPECT_THROW(episodio.calificar(0), std::out_of_range);
    EXPECT_THROW(episodio.calificar(6), std::out_of_range);
}
