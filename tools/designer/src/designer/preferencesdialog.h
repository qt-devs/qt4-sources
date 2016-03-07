/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the Qt Designer of the Qt Toolkit.
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

#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QtGui/QDialog>

QT_BEGIN_NAMESPACE

class QPushButton;
class QDesignerFormEditorInterface;
class QDesignerOptionsPageInterface;

namespace Ui {
    class PreferencesDialog;
}

class PreferencesDialog: public QDialog
{
    Q_OBJECT
public:
    explicit PreferencesDialog(QDesignerFormEditorInterface *core, QWidget *parentWidget = 0);
    ~PreferencesDialog();


private slots:
    void slotAccepted();
    void slotRejected();
    void slotApply();
    void slotUiModeChanged(bool modified);

private:
    QPushButton *applyButton() const;
    void closeOptionPages();

    Ui::PreferencesDialog *m_ui;
    QDesignerFormEditorInterface *m_core;
    QList<QDesignerOptionsPageInterface*> m_optionsPages;
};

QT_END_NAMESPACE

#endif // PREFERENCESDIALOG_H
