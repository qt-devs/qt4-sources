/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtXmlPatterns module of the Qt Toolkit.
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

#include <QUrl>


#include "qresourceloader_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

ResourceLoader::~ResourceLoader()
{
}

bool ResourceLoader::isUnparsedTextAvailable(const QUrl &uri,
                                             const QString &encoding)
{
    Q_ASSERT(uri.isValid());
    Q_ASSERT(!uri.isRelative());
    Q_UNUSED(uri); /* Needed when compiling in release mode. */
    Q_UNUSED(encoding);
    return false;
}

ItemType::Ptr ResourceLoader::announceUnparsedText(const QUrl &uri)
{
    Q_ASSERT(uri.isValid());
    Q_ASSERT(!uri.isRelative());
    Q_UNUSED(uri); /* Needed when compiling in release mode. */
    return ItemType::Ptr();
}

Item ResourceLoader::openUnparsedText(const QUrl &uri,
                                      const QString &encoding,
                                      const ReportContext::Ptr &context,
                                      const SourceLocationReflection *const where)
{
    Q_ASSERT(uri.isValid());
    Q_ASSERT(!uri.isRelative());
    Q_UNUSED(uri); /* Needed when compiling in release mode. */
    Q_UNUSED(encoding);
    Q_UNUSED(context);
    Q_UNUSED(where);
    return Item();
}

Item ResourceLoader::openDocument(const QUrl &uri,
                                  const ReportContext::Ptr &context)
{
    Q_ASSERT(uri.isValid());
    Q_ASSERT(!uri.isRelative());
    Q_UNUSED(uri); /* Needed when compiling in release mode. */
    Q_UNUSED(context); /* Needed when compiling in release mode. */
    return Item();
}

SequenceType::Ptr ResourceLoader::announceDocument(const QUrl &uri, const Usage)
{
    Q_ASSERT(uri.isValid());
    Q_ASSERT(!uri.isRelative());
    Q_UNUSED(uri); /* Needed when compiling in release mode. */
    return SequenceType::Ptr();
}

bool ResourceLoader::isDocumentAvailable(const QUrl &uri)
{
    Q_ASSERT(uri.isValid());
    Q_ASSERT(!uri.isRelative());
    Q_UNUSED(uri); /* Needed when compiling in release mode. */
    return false;
}

Item::Iterator::Ptr ResourceLoader::openCollection(const QUrl &uri)
{
    Q_ASSERT(uri.isValid());
    Q_ASSERT(!uri.isRelative());
    Q_UNUSED(uri); /* Needed when compiling in release mode. */
    return Item::Iterator::Ptr();
}

SequenceType::Ptr ResourceLoader::announceCollection(const QUrl &uri)
{
    Q_ASSERT(uri.isValid());
    Q_ASSERT(!uri.isRelative());
    Q_UNUSED(uri); /* Needed when compiling in release mode. */
    return SequenceType::Ptr();
}

void ResourceLoader::clear(const QUrl &uri)
{
    Q_UNUSED(uri);
}

QT_END_NAMESPACE
