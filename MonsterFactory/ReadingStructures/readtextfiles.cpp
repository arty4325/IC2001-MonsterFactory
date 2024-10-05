#include "readtextfiles.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QCoreApplication>

readTextFiles::readTextFiles() {}

QString readTextFiles::readTextFilesInFolder() {
    QString folderPath = "C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/ReadingStructures/ClientFiles";
    QDir directory(folderPath);
    QStringList filters;
    QString retVar = "";
    filters << "*.txt";
    QStringList txtFiles = directory.entryList(filters, QDir::Files);

    for (const QString& fileName : txtFiles) {
        // Verificar si el archivo ya fue renombrado con '=read'
        if (fileName.endsWith("=read.txt")) {
            //qDebug() << "Saltando archivo ya leído:" << fileName;
            continue;  // Saltar el archivo si ya fue leído
        }

        QString filePath = directory.absoluteFilePath(fileName);
        QFile file(filePath);

        // Abre el archivo y lo lee
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            retVar += in.readAll() +"\n" + fileName + "t=";
            file.close();  // Cierra el archivo después de leerlo

            // Renombra el archivo: insertamos '=read' antes de la extensión .txt
            QString baseName = fileName.left(fileName.lastIndexOf('.'));  // Obtener el nombre sin la extensión
            QString newFileName = baseName + "=read.txt";  // Agregar '=read' antes de la extensión
            QString newFilePath = directory.absoluteFilePath(newFileName);

            if (!file.rename(newFilePath)) {
                //qDebug() << "No se pudo renombrar el archivo:" << fileName;
            } else {
                qDebug() << "Archivo renombrado a:" << newFileName;
            }
        } else {
            //qDebug() << "No se pudo abrir el archivo:" << fileName;
        }
    }

    return retVar;
}

void readTextFiles::appendTextToFile(const QString& filePath, const QString& textToAdd) {
    QFile file(filePath);
    QDir dir = QFileInfo(filePath).absoluteDir();

    // Crear directorios si no existen
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            qDebug() << "No se pudieron crear los directorios:" << dir.path();
            return;
        }
    }

    // Abrir el archivo en modo de escritura (WriteOnly) y añadir al final (Append)
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << textToAdd << "\n";  // Escribe el texto en el archivo y añade un salto de línea
        file.close();
        qDebug() << "Texto añadido correctamente a:" << filePath;
    } else {
        qDebug() << "No se pudo abrir el archivo para escribir:" << filePath;
    }
}

QString readTextFiles::read(int option) {
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
        break;
    // ME FALTA ALMACEN Y COLA PEDIDOS CLIENTES

    // Agrega más casos para otras opciones
    // case 3:
    //     filePath = "ruta/a/otroArchivo.txt";
    //     break;
    default:
        qDebug() << "Opción no válida.";
        return "";
    }

    // Intentar abrir el archivo seleccionado
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo:" << filePath;
        return "";
    }

    // Leer el contenido del archivo
    QTextStream in(&file);
    QString content = in.readAll();
    file.close();  // Cerrar el archivo

    return content;
}

