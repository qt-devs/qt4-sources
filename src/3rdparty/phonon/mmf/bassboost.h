/*  This file is part of the KDE project.

Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).

This library is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 2.1 or 3 of the License.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef PHONON_MMF_BASSBOOST_H
#define PHONON_MMF_BASSBOOST_H

#include "abstractaudioeffect.h"

QT_BEGIN_NAMESPACE

namespace Phonon
{
namespace MMF
{
/**
 * @short An "bass boost" effect.
 *
 * The documentation does not say what "bass boost" is, neither has it anykind
 * of setting. It's an on or off thing.
 */
class BassBoost : public AbstractAudioEffect
{
    Q_OBJECT
public:
    BassBoost(QObject *parent);

protected:
    // AbstractAudioEffect
    virtual void connectAudioPlayer(AudioPlayer::NativePlayer *player);
    virtual void applyParameters();
    virtual void parameterChanged(const int id, const QVariant &value);

};
}
}

QT_END_NAMESPACE

#endif

