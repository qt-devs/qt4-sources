/****************************************************************************
**
** Copyright (C) 2012 Research In Motion
** Contact: http://www.qt-project.org/
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qbbengine.h"

#include <QtNetwork/private/qbearerplugin_p.h>

#ifndef QT_NO_BEARERMANAGEMENT

QT_BEGIN_NAMESPACE

class QBBEnginePlugin : public QBearerEnginePlugin
{
public:
    QBBEnginePlugin();
    ~QBBEnginePlugin();

    QStringList keys() const;
    QBearerEngine *create(const QString &key) const;
};

QBBEnginePlugin::QBBEnginePlugin()
{
}

QBBEnginePlugin::~QBBEnginePlugin()
{
}

QStringList QBBEnginePlugin::keys() const
{
    return QStringList() << QLatin1String("blackberry");
}

QBearerEngine *QBBEnginePlugin::create(const QString &key) const
{
    if (key == QLatin1String("blackberry"))
        return new QBBEngine;

    return 0;
}

Q_EXPORT_STATIC_PLUGIN(QBBEnginePlugin)
Q_EXPORT_PLUGIN2(qbbbearer, QBBEnginePlugin)

QT_END_NAMESPACE

#endif // QT_NO_BEARERMANAGEMENT
