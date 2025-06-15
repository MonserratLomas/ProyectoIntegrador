/*
 * main.cpp
 * 
 * Función principal que inicia la ejecución del programa del Proyecto Integrador.
 * 
 * Proyecto: Proyecto Integrador - Programación Orientada a Objetos
 * Autor: Monserrat Hernández Lomas
 * Fecha: Junio 2025
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"

using namespace std;

// Función para recortar espacios en blanco al inicio y final
string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    return (start == string::npos) ? "" : s.substr(start, end - start + 1);
}

// Convierte una cadena a minúsculas
string toLower(const string& s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(),
              [](unsigned char c){ return tolower(c); });
    return result;
}

vector<Video*> cargarVideos(const string& nombreArchivo) {
    vector<Video*> videos;
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
        exit(1);
    }

    string linea;
    getline(archivo, linea); // Saltar encabezado

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string tipo, id, nombre, duracion_str, genero, temporada_str, titulo_episodio;

        getline(ss, tipo, ',');
        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, duracion_str, ',');
        getline(ss, genero, ',');
        getline(ss, temporada_str, ',');
        getline(ss, titulo_episodio, ',');

        tipo = trim(tipo);
        id = trim(id);
        nombre = trim(nombre);
        duracion_str = trim(duracion_str);
        genero = trim(genero);
        temporada_str = trim(temporada_str);
        titulo_episodio = trim(titulo_episodio);

        int duracion = 0;
        int temporada = 0;

        try {
            duracion = stoi(duracion_str);
        } catch (...) {
            duracion = 0;
        }
        try {
            if (!temporada_str.empty())
                temporada = stoi(temporada_str);
        } catch (...) {
            temporada = 0;
        }

        if (tipo == "pelicula") {
            videos.push_back(new Pelicula(id, nombre, duracion, genero));
        } else if (tipo == "serie") {
            videos.push_back(new Serie(id, nombre, duracion, genero, temporada, titulo_episodio));
        }
    }

    return videos;
}

void mostrarVideos(const vector<Video*>& videos, int calMin, const string& generoFiltro) {
    for (auto v : videos) {
        if (v->getCalificacion() >= calMin && (generoFiltro.empty() || toLower(v->getGenero()) == toLower(generoFiltro))) {
            cout << "ID: " << v->getId() << ", Nombre: " << v->getNombre()
                 << ", Duración: " << v->getDuracion() << ", Género: " << v->getGenero()
                 << ", Calificación: " << v->getCalificacion() << endl;
        }
    }
}

void mostrarEpisodiosSerie(const vector<Video*>& videos, const string& nombreSerie, int calMin) {
    for (auto v : videos) {
        Serie* s = dynamic_cast<Serie*>(v);
        if (s && toLower(s->getNombre()) == toLower(nombreSerie) && s->getCalificacion() >= calMin) {
            cout << "ID: " << s->getId() << ", Nombre: " << s->getNombre()
                 << ", Temporada: " << s->getTemporada()
                 << ", Título episodio: " << s->getTituloEpisodio()
                 << ", Calificación: " << s->getCalificacion() << endl;
        }
    }
}

void mostrarPeliculas(const vector<Video*>& videos, int calMin) {
    for (auto v : videos) {
        Pelicula* p = dynamic_cast<Pelicula*>(v);
        if (p && p->getCalificacion() >= calMin) {
            cout << "ID: " << p->getId() << ", Nombre: " << p->getNombre()
                 << ", Duración: " << p->getDuracion()
                 << ", Género: " << p->getGenero()
                 << ", Calificación: " << p->getCalificacion() << endl;
        }
    }
}

void calificarVideo(vector<Video*>& videos) {
    cout << "Ingresa el título del video a calificar: ";
    string titulo;
    getline(cin, titulo);

    auto it = find_if(videos.begin(), videos.end(), [&](Video* v) {
        return toLower(trim(v->getNombre())) == toLower(trim(titulo));
    });

    if (it != videos.end()) {
        int cal;
        cout << "Ingresa la calificación (1-5): ";
        cin >> cal;
        cin.ignore();  // limpiar buffer

        if (cal >= 1 && cal <= 5) {
            (*it)->agregarCalificacion(cal);
            cout << "Calificación agregada correctamente." << endl;
        } else {
            cout << "Calificación inválida." << endl;
        }
    } else {
        cout << "Video no encontrado." << endl;
    }
}

int main() {
    vector<Video*> videos;
    int opcion;

    do {
        cout << "\nMenu:\n"
             << "1. Cargar archivo de datos\n"
             << "2. Mostrar videos con calificación mínima o género\n"
             << "3. Mostrar episodios de una serie con calificación mínima\n"
             << "4. Mostrar películas con calificación mínima\n"
             << "5. Calificar un video\n"
             << "0. Salir\n"
             << "Elige una opción: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: {
                cout << "Ingresa nombre del archivo CSV: ";
                string archivo;
                getline(cin, archivo);
                videos = cargarVideos(archivo);
                cout << "Videos cargados: " << videos.size() << endl;
                break;
            }
            case 2: {
                cout << "Calificación mínima (1-5): ";
                int cal;
                cin >> cal;
                cin.ignore();
                cout << "Género (deja vacío para no filtrar): ";
                string genero;
                getline(cin, genero);
                mostrarVideos(videos, cal, genero);
                break;
            }
            case 3: {
                cout << "Nombre de la serie: ";
                string nombreSerie;
                getline(cin, nombreSerie);
                cout << "Calificación mínima (1-5): ";
                int cal;
                cin >> cal;
                cin.ignore();
                mostrarEpisodiosSerie(videos, nombreSerie, cal);
                break;
            }
            case 4: {
                cout << "Calificación mínima (1-5): ";
                int cal;
                cin >> cal;
                cin.ignore();
                mostrarPeliculas(videos, cal);
                break;
            }
            case 5:
                calificarVideo(videos);
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }

    } while (opcion != 0);

    // Liberar memoria
    for (auto v : videos) {
        delete v;
    }
    videos.clear();

    return 0;
}
