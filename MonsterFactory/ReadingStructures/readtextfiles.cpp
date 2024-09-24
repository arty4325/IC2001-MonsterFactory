#include "readtextfiles.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QCoreApplication>

readTextFiles::readTextFiles() {}

void readTextFiles::readTextFilesInFolder() {
    QString folderPath = "C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/ReadingStructures/ClientFiles";
    QDir directory(folderPath);
    QStringList filters;
    filters << "*.txt";
    QStringList txtFiles = directory.entryList(filters, QDir::Files);
    for (const QString& fileName : txtFiles) {
        QString filePath = directory.absoluteFilePath(fileName);
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            qDebug() << "Contenido del archivo:" << fileName;
            qDebug() << in.readAll();
            file.close();
        } else {
            qDebug() << "No se pudo abrir el archivo:" << fileName;
        }
    }
}
