/***************************************************
 ** PropViewFuncArea
 ** @brief: the property view for funcAreas
 ** @author: gaimeng
 ** @date: Jan, 2015
 **
 ****************************************************/
#ifndef PROPVIEWFUNCAREA_H
#define PROPVIEWFUNCAREA_H

#include "propertyview.h"

class FuncArea;
QT_FORWARD_DECLARE_CLASS(QLineEdit)

class PropViewFuncArea : public PropertyView
{
    Q_OBJECT
public:
    explicit PropViewFuncArea(QWidget *parent = 0);
    virtual bool match(const MapEntity *mapEntity) const;
    virtual void setMapEntity(MapEntity * mapEntity);
public slots:
   void updateShopNo(const QString &shopNo);
   void updateArea(const QString &area);
   void updateDianpingId(const QString &dpId);

private:
    QLineEdit* m_shopNoEdit;
    QLineEdit* m_areaEdit;
    QLineEdit* m_dianpingIdEdit;
};

#endif // PROPVIEWFUNCAREA_H