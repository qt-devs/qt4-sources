/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtGui>

//! [0]
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QPushButton button;
    QStateMachine machine;
//! [0]

//! [1]
    QState *off = new QState();
    off->assignProperty(&button, "text", "Off");
    off->setObjectName("off");

    QState *on = new QState();
    on->setObjectName("on");
    on->assignProperty(&button, "text", "On");
//! [1]

//! [2]
    off->addTransition(&button, SIGNAL(clicked()), on);
    on->addTransition(&button, SIGNAL(clicked()), off);
//! [2]

//! [3]
    machine.addState(off);
    machine.addState(on);
//! [3]

//! [4]
    machine.setInitialState(off);
    machine.start();
//! [4]

//! [5]
#if defined(Q_OS_SYMBIAN)
    button.showMaximized();
#elif defined(Q_WS_MAEMO_5) || defined(Q_WS_SIMULATOR)
    button.show();
#else
    button.resize(100, 50);
    button.show();
#endif
    return app.exec();
}
//! [5]
