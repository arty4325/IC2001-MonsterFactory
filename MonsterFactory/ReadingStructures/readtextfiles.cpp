#include "readtextfiles.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QCoreApplication>

readTextFiles::readTextFiles() {}

QString readTextFiles::readTextFilesInFolder() { // Esta funcion permite leer todo lo de todos los txt que estan en un folder
    QString folderPath = "C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/ReadingStructures/ClientFiles"; // La direccion a la que se lee
    QDir directory(folderPath);
    QStringList filters;
    QString retVar = "";
    filters << "*.txt"; // Y que es a una direccion de tipo txt
    QStringList txtFiles = directory.entryList(filters, QDir::Files);

    for (const QString& fileName : txtFiles) { // Se itera sobre los archivos que estan en el archivo
        // Verificar si el archivo ya fue renombrado con '=read'
        if (fileName.endsWith("=read.txt")) {
            continue;  // Saltar el archivo si ya fue leído
        }

        QString filePath = directory.absoluteFilePath(fileName); // En el caso en el que el archivo no haya sido leido se continua
        QFile file(filePath);

        // Abre el archivo y lo lee
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            retVar += in.readAll() +"\n" + fileName + "t=";
            file.close();  // Cierra el archivo después de leerlo

            // Quiero ponerle a los archivos que ya lei, la terminacion =read para no volver a leerlos
            QString baseName = fileName.left(fileName.lastIndexOf('.'));  // Obtener el nombre sin la extensión
            QString newFileName = baseName + "=read.txt";  // Agregar '=read' antes de la extensión
            QString newFilePath = directory.absoluteFilePath(newFileName);

            if (!file.rename(newFilePath)) {
                // No se pudo renombrar el archivo
            } else {
                // El archivo fue renombrado con exito
            }
        } else {
            // En este caso no se pudo leer el archivo
        }
    }

    return retVar;
}

void readTextFiles::appendTextToFile(const QString& filePath, const QString& textToAdd) { // Esta funcion lo que quiere es a un archivo, agregarle texto
    QFile file(filePath);
    QDir dir = QFileInfo(filePath).absoluteDir();

    // Si el filePath que se esta pasando no existe, es creado
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            // Esto ocurre si no se pudo crear el directorio por alguna razon
            return;
        }
    }

    // Se abre el archivo, observe que esta en writeOnly, y Append para que no se pierda lo qeu se tiene
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << textToAdd << "\n";  // Escribe el texto en el archivo y añade un salto de línea
        file.close();
    } else {
        // Esto se ejecuta si no se pudo completar la accion
    }
}

QString readTextFiles::read(int option) { // Funcion unicamente lee todo lo que esta en un txt dada una clave de su direccion
    QString filePath;

    // Seleccionar archivo basado en el número de opción
    switch (option) {
    case 1:
        filePath = "C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/colaMounstros.txt";
        break;
    case 2:
        filePath = "C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/hornoBitacora.txt";
        break;
    case 3:
        filePath = "C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/primerInspector.txt";
        break;
    case 4:
        filePath = "C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/segundoInspector.txt";
        break;
    case 5:
        filePath = "C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/historiaEntregados.txt";
        break;
    case 6:
        filePath = "C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/colaPedidosItinerario.txt";
    default:
        return "";
    }

    // Intentar abrir el archivo seleccionado
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // No se pudo abrir el archivo seleccionado
        return "";
    }

    // Leer el contenido del archivo
    QTextStream in(&file);
    QString content = in.readAll();
    file.close();  // Cerrar el archivo

    return content; // Se devuelve todo el contenido del archivo plano de texto
}

