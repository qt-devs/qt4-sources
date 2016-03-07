/****************************************************************************
**
** Copyright (C) 2012 Research In Motion <blackberry-qt@qnx.com>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtCore module of the Qt Toolkit.
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
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qbbnativeinterface.h"

#include "qbbintegration.h"
#include "qbbscreen.h"
#include <QtGui/QWidget>
#include <screen/screen.h>

QT_BEGIN_NAMESPACE

QBBNativeInterface::QBBNativeInterface(QBBIntegration *integration)
    : mIntegration(integration)
{
}

void *QBBNativeInterface::nativeResourceForWidget(const QByteArray &resource, QWidget *widget)
{
    if (resource == "windowGroup" && widget) {
        const QWidget * const nativeWidget = widget->nativeParentWidget();
        const screen_window_t window = reinterpret_cast<screen_window_t>(nativeWidget->winId());
        const QBBScreen * const screen = mIntegration->screenForWindow(window);
        if (screen) {
            // We can't just call data() instead of constData() here, since that would detach
            // and the lifetime of the char * would not be long enough. Therefore the const_cast.
            return const_cast<char *>(screen->rootWindow()->groupName().constData());
        }
    }

    return 0;
}

QT_END_NAMESPACE
