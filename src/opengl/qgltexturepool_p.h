/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtOpenVG module of the Qt Toolkit.
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

#ifndef QGLTEXTUREPOOL_P_H
#define QGLTEXTUREPOOL_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of other Qt classes.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qgl.h"
#include <QtCore/qscopedpointer.h>

QT_BEGIN_NAMESPACE

class QGLTexture;
class QGLTexturePoolPrivate;

class QGLTexturePool
{
public:
    QGLTexturePool();
    virtual ~QGLTexturePool();

    static QGLTexturePool *instance();

    // Create a new texture with the specified parameters and associate
    // it with "texture".  The QGLTexture will be notified when the
    // texture needs to be reclaimed by the pool.
    //
    // This function will call reclaimSpace() when texture creation fails.
    GLuint createTexture(GLenum target,
                                            GLint level,
                                            GLint internalformat,
                                            GLsizei width,
                                            GLsizei height,
                                            GLenum format,
                                            GLenum type,
                                            QGLTexture *texture);

    // Create a permanent texture with the specified parameters.
    // If there is insufficient space for the texture,
    // then this function will call reclaimSpace() and try again.
    //
    // The caller is responsible for calling glDeleteTextures()
    // when it no longer needs the texture, as the texture is not
    // recorded in the texture pool.
    bool createPermanentTexture(GLuint texture,
                                            GLenum target,
                                            GLint level,
                                            GLint internalformat,
                                            GLsizei width,
                                            GLsizei height,
                                            GLenum format,
                                            GLenum type,
                                            const GLvoid *data);

    // Notify the pool that a QGLTexture object is using
    // an texture again.  This allows the pool to move the texture
    // within a least-recently-used list of QGLTexture objects.
    void useTexture(QGLTexture *texture);

    // Notify the pool that the texture associated with a
    // QGLTexture is being detached from the pool.  The caller
    // will become responsible for calling glDeleteTextures().
    void detachTexture(QGLTexture *texture);

    // Reclaim space for an image allocation with the specified parameters.
    // Returns true if space was reclaimed, or false if there is no
    // further space that can be reclaimed.  The "texture" parameter
    // indicates the texture that is trying to obtain space which should
    // not itself be reclaimed.
    bool reclaimSpace(GLint internalformat,
                                GLsizei width,
                                GLsizei height,
                                GLenum format,
                                GLenum type,
                                QGLTexture *data);

    // Hibernate the texture pool because the context is about to be
    // destroyed.  All textures left in the pool should be released.
    void hibernate();

protected:
    // Helper functions for managing the LRU list of QGLTexture objects.
    void moveToHeadOfLRU(QGLTexture *texture);
    void removeFromLRU(QGLTexture *texture);
    QGLTexture *textureLRU();

private:
    QScopedPointer<QGLTexturePoolPrivate> d_ptr;

    Q_DECLARE_PRIVATE(QGLTexturePool)
    Q_DISABLE_COPY(QGLTexturePool)
};

QT_END_NAMESPACE

#endif
