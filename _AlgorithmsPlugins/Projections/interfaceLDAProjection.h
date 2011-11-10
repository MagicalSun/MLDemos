#ifndef INTERFACELDAPROJECTION_H
#define INTERFACELDAPROJECTION_H

#include <vector>
#include <interfaces.h>
#include "ui_paramsLDA.h"

class LDAProjection : public QObject, public ProjectorInterface
{
    Q_OBJECT
    Q_INTERFACES(ProjectorInterface)
private:
    Ui::paramsLDA *params;
    QWidget *widget;
public:
    LDAProjection();
    // virtual functions to manage the algorithm creation
    Projector *GetProjector();
    void DrawInfo(Canvas *canvas, QPainter &painter, Projector *projector);
    void DrawModel(Canvas *canvas, QPainter &painter, Projector *projector);

    // virtual functions to manage the GUI and I/O
    QString GetName(){return QString("LDA");}
    QString GetAlgoString();
    QString GetInfoFile(){return "LDA.html";}
    QWidget *GetParameterWidget(){return widget;}
    void SetParams(Projector *projector);
    void SaveOptions(QSettings &settings);
    bool LoadOptions(QSettings &settings);
    void SaveParams(QTextStream &stream);
    bool LoadParams(QString name, float value);
};

#endif // INTERFACELDAPROJECTION_H