/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtGui module of the Qt Toolkit.
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

#include <QtGui/qpaintdevice.h>
#include <QtGui/qpixmap.h>
#include <QtGui/qwidget.h>

#include "qegl_p.h"
#include "qeglcontext_p.h"

#include <windows.h>


QT_BEGIN_NAMESPACE

EGLNativeDisplayType QEgl::nativeDisplay()
{
    HDC myDc = GetDC(0);
    if (!myDc) {
        qWarning("QEglContext::nativeDisplay(): WinCE display is not open");
        return EGLNativeDisplayType(EGL_DEFAULT_DISPLAY);
    }
    return EGLNativeDisplayType(myDc);
}

EGLNativeWindowType QEgl::nativeWindow(QWidget* widget)
{
    return (EGLNativeWindowType)(widget->winId());
}

EGLNativePixmapType QEgl::nativePixmap(QPixmap*)
{
    qWarning("QEgl: EGL pixmap surfaces not supported on WinCE");
    return (EGLNativePixmapType)0;
}

// Set pixel format and other properties based on a paint device.
void QEglProperties::setPaintDeviceFormat(QPaintDevice *dev)
{
    int devType = dev->devType();
    if (devType == QInternal::Image)
        setPixelFormat(static_cast<QImage *>(dev)->format());
    else
        setPixelFormat(QImage::Format_RGB16); // XXX
}

QT_END_NAMESPACE
