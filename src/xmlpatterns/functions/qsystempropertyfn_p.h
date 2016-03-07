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

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef Patternist_SystemPropertyFN_H
#define Patternist_SystemPropertyFN_H

#include "qstaticnamespacescontainer_p.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Implements XSL-T 2.0's XPath function <tt>fn:system-property()</tt>.
     *
     * @see <a href="http://www.w3.org/TR/xslt20/#system-property">XSL Transformations
     * (XSLT) Version 2.0, 16.6.5 system-property</a>
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_functions
     */
    class SystemPropertyFN : public StaticNamespacesContainer
    {
    public:
        virtual Item evaluateSingleton(const DynamicContext::Ptr &context) const;

    private:
        /**
         * Returns a string representation for @p property as defined
         * for the system properties in "XSL Transformations (XSLT)
         * Version 2.0, 16.6.5 system-property". Hence, this function
         * handles only the properties specified in the XSL namespace, and returns
         * an empty string if an unrecognized property is asked for.
         */
        static QString retrieveProperty(const QXmlName name);
    };
}

QT_END_NAMESPACE

QT_END_HEADER

#endif
