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

#ifndef Patternist_ArgumentConverter_H
#define Patternist_ArgumentConverter_H

#include "quntypedatomicconverter_p.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

namespace QPatternist
{

    /**
     * @short UntypedAtomicConverter for ArgumentReference, if needed.
     *
     * If an argument inside a user function has no type declared, its type
     * is @c item(). It's atomized type would be inferred to @c
     * xs:anyAtomicType, but that is not necessarily correct, since the actual
     * value can be anything, nodes or atomic values.
     *
     * This extremely dynamic case is handled by ArgumentConverter which is inserted for
     * ArgumentReference that has the static type @c item(), when atomic value are asked
     * for. At runtime it atomizes/let values through appropriately.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     * @ingroup Patternist_expressions
     */
    class ArgumentConverter : public UntypedAtomicConverter
    {
    public:
        ArgumentConverter(const Expression::Ptr &operand,
                          const ItemType::Ptr &reqType);

        virtual Item evaluateSingleton(const DynamicContext::Ptr &) const;
        virtual Item::Iterator::Ptr evaluateSequence(const DynamicContext::Ptr &) const;
        virtual ExpressionVisitorResult::Ptr accept(const ExpressionVisitor::Ptr &visitor) const;
        inline Item::Iterator::Ptr mapToSequence(const Item &item,
                                                 const DynamicContext::Ptr &context) const;
        virtual SequenceType::List expectedOperandTypes() const;
        virtual SequenceType::Ptr staticType() const;

    private:
        typedef QExplicitlySharedDataPointer<const ArgumentConverter> ConstPtr;

    };
}

QT_END_NAMESPACE

QT_END_HEADER

#endif
