#ifndef DOCUMENTVIEW_H
#define DOCUMENTVIEW_H

#include <QGraphicsView>
#include <QModelIndex>

QT_FORWARD_DECLARE_CLASS(QUndoStack)
QT_FORWARD_DECLARE_CLASS(QGraphicsScene)
QT_FORWARD_DECLARE_CLASS(QGraphicsObject)
QT_FORWARD_DECLARE_CLASS(QPrinter)

class Floor;
class Building;
class MapEntity;
class Scene;

class DocumentView : public QGraphicsView
{

    Q_OBJECT
public:
    enum ViewFlag{
        StyleShowShopName =                0x00000001,
        StyleShowCenter =             0x00000002,
        //TODO more styles
        StyleDefault = 0 | StyleShowShopName | StyleShowCenter
    };
    Q_DECLARE_FLAGS(ViewStyle, ViewFlag)

    DocumentView();
    ~DocumentView();
    Scene * scene() const;
    bool isModified();
    void setModified(bool b);
    void clear();
    void setSelectable(bool b);
    Building* building();
    static ViewStyle viewStyle();

signals:
    void selectionChanged(MapEntity * mapEntity);

public slots:
    void printScene(QPrinter *printer);
    void updateSelection(const QModelIndex & index);
    void updateSelection();
    void showTexts(bool show);
private:
    QUndoStack *m_undoStack;
    Scene *m_scene;
    bool m_isModified;
    bool m_selectable;
    static ViewStyle m_style;
};

#endif // DOCUMENTVIEW_H
