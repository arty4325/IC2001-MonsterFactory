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
