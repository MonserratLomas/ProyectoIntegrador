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

TEST(EpisodioTest, NoAgregaCalificacionesInvalidas) {
    Episodio episodio("Capítulo 4", 2);

    episodio.calificar(0);  // inválida, no debe agregarse
    episodio.calificar(6);  // inválida, no debe agregarse

    EXPECT_DOUBLE_EQ(episodio.obtenerCalificacionPromedio(), 0.0);
}
