#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void fichero_leido_linea_a_linea(std::string const &rutaDelArchivo)
{
    std::ifstream fichero{rutaDelArchivo};

    if (fichero.is_open())
    {
        std::string linea;

        while (std::getline(fichero, linea))
        {
            // Procesar cada una de las lineas
            std::cout << linea << std::endl;
        }

        fichero.close();
    }
    else
    {
        std::cerr << "No se ha podido abrir el fichero: " << rutaDelArchivo << std::endl;
    }
}

std::string leer_fichero_completo(std::string const &rutaDelArchivo)
{
    std::ifstream fichero(rutaDelArchivo);

    if (fichero.is_open())
    {
        std::string contenido((std::istreambuf_iterator<char>(fichero)), 
                               std::istreambuf_iterator<char>());
        
        fichero.close();

        return contenido;
    }
    else
    {
        std::cerr << "No se ha podido abrir el fichero: " << rutaDelArchivo << std::endl;
        return {};
    }
}

int main()
{
    const auto rutaDelArchivo{fs::current_path() / "ejemplo.txt"};

    std::cout << "Fichero leido linea a linea: \n\n";
    fichero_leido_linea_a_linea(rutaDelArchivo.string());

    std::cout << "\nFichero completo leido: \n\n";
    std::cout << leer_fichero_completo(rutaDelArchivo.string()) << '\n';

    return EXIT_SUCCESS;
}
