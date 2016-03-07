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

#ifndef PHONON_MMF_ABSTRACTEFFECT_H
#define PHONON_MMF_ABSTRACTEFFECT_H

#include <QScopedPointer>

#include <AudioEffectBase.h>

#include <Phonon/effectinterface.h>
#include <Phonon/effectparameter.h>

#include "audioplayer.h"
#include "mmf_medianode.h"
#include "mmf_videoplayer.h"

QT_BEGIN_NAMESPACE

namespace Phonon
{
namespace MMF
{
class AbstractMediaPlayer;

/**
 * @short Base class for all effects for MMF.
 *
 * Adhering to Phonon with MMF is cumbersome because of a number of reasons:
 *
 * - MMF has no concept of effect chaining. Simply, an effect is a applied
 *   to PlayerUtility, that's it. This means that the order of effects is
 *   undefined.
 * - We apply an effect to a PlayerUtility, and MediaObject has that one.
 *   However, effects might be created before MediaObject, but nevertheless
 *   needs to work. We solve this by that we are aware of the whole connection
 *   chain, and whenever a connection happens, we walk the chain, find effects
 *   that aren't applied, and apply it if we have a media object.
 * - There are plenty of corner cases which we don't handle and where behavior
 *   are undefined. For instance, graphs with more than one MediaObject.
 */
class AbstractAudioEffect : public MediaNode
                          , public EffectInterface
{
    Q_OBJECT
    Q_INTERFACES(Phonon::EffectInterface)
public:
    AbstractAudioEffect(QObject *parent,
                        const QList<EffectParameter> &params);

    virtual QList<EffectParameter> parameters() const;
    virtual QVariant parameterValue(const EffectParameter &param) const;
    virtual void setParameterValue(const EffectParameter &,
                                   const QVariant &newValue);

    enum Type
    {
        EffectAudioEqualizer = 1,
        EffectBassBoost,
        EffectDistanceAttenuation,
        EffectEnvironmentalReverb,
        EffectListenerOrientation,
        EffectLoudness,
        EffectSourceOrientation,
        EffectStereoWidening
    };

protected:
    // MediaNode
    void connectMediaObject(MediaObject *mediaObject);
    void disconnectMediaObject(MediaObject *mediaObject);

    virtual void connectAudioPlayer(AudioPlayer::NativePlayer *player) = 0;
    virtual void applyParameters() = 0;

    virtual void parameterChanged(const int id,
                                  const QVariant &value) = 0;

protected:
    QScopedPointer<CAudioEffect>    m_effect;

private:
    AbstractMediaPlayer *           m_player;
    const QList<EffectParameter>    m_params;
    QHash<int, QVariant>            m_values;
};

}
}

QT_END_NAMESPACE

#endif

